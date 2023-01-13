#ifndef CPP_SP2_MPCALC_H
#define CPP_SP2_MPCALC_H

#include "emulator/MPInt.h"
#include "emulator/util/concepts.h"
#include "emulator/exceptions/InvalidOptionException.h"
#include "emulator/exceptions/OverflowException.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <deque>
#include <regex>

constexpr auto PROMPT_HEAD = "> ";
constexpr auto BANK_SIZE = 5;

static const std::regex OPERATION_REGEX(std::string(R"(^(\$[1-5]|[\-+]?[0-9]+)([+\-*/!])(\$[1-5]|[0-9]*)$)"),
                                        std::regex_constants::ECMAScript);


template<size_t T> requires AtLeastFourBytes<T>
class MPCalc {
private:
    std::deque<MPInt<T>> bank;
public:

    enum class ECommands {
        plus,
        minus,
        multiply,
        divide,
        factorial,
        bank,
        exit,
        unknown,
    };

    constexpr ECommands getCommandCode(std::string const &string) {
        if (string == "+") return ECommands::plus;
        if (string == "-") return ECommands::minus;
        if (string == "*") return ECommands::multiply;
        if (string == "/") return ECommands::divide;
        if (string == "!") return ECommands::factorial;
        if (string == "bank") return ECommands::bank;
        if (string == "exit") return ECommands::exit;
        return ECommands::unknown;
    }

    constexpr int getBankIndex(std::string const &string) {
        if (string == "$1") return 0;
        if (string == "$2") return 1;
        if (string == "$3") return 2;
        if (string == "$4") return 3;
        if (string == "$5") return 4;
        return -1;
    }

    bool handleUserInput(std::stringstream &arguments) {
        try {
            return applyCommand(arguments);
        } catch (InvalidOptionException &ex) {
            std::cout << "calc: " << ex.what() << std::endl;
        } catch (OverflowException &ex) {
            std::cout << "calc: " << ex.what() << std::endl;
        } catch (std::logic_error &ex) {
            std::cout << "calc: logic error: " << ex.what() << std::endl;
        } catch (...) {
            std::cout << "calc: an unknown error occurred" << std::endl;
        }
        return true;
    }

    // TODO: function decomposition
    bool applyCommand(std::stringstream &arguments) {
        std::string command;
        arguments >> std::ws >> command;

        if (command.empty()) return true;

        switch (getCommandCode(command)) {
            case ECommands::bank:
                printBank();
                return true;
            case ECommands::exit:
                return false;
            default:
                break;
        }

        std::string testString;
        if (arguments >> std::ws >> testString) {
            std::cout << "calc: too many arguments" << std::endl;
            return true;
        }

        std::smatch matches;
        if (!std::regex_search(command, matches, OPERATION_REGEX)) {
            std::cout << "calc: Unknown command : " << command << std::endl;
            return true;
        }

        MPInt<T> result, num1, num2;
        std::string lhs = matches[1], op = matches[2], rhs = matches[3];

        int index1 = getBankIndex(lhs);
        if (bank.size() > index1) {
            num1 = bank[index1];
        } else {
            num1 = lhs;
        }

        bool isUnary = rhs.empty();

        if (!isUnary) {
            int index2 = getBankIndex(rhs);
            if (bank.size() > index2) {
                num2 = bank[index2];
            } else {
                num2 = rhs;
            }
        }

        if (isUnary) {
            // lhs op (unary operation)
            switch (getCommandCode(op)) {
                case ECommands::factorial:
                    result = factorial(num1);
                    break;
                default:
                    std::cout << "calc: Unknown command: " << command << std::endl;
                    return true;
            }
        } else {
            // lhs op rhs (binary operation)
            switch (getCommandCode(op)) {
                case ECommands::plus:
                    result = num1 + num2;
                    break;
                case ECommands::minus:
                    result = num1 - num2;
                    break;
                case ECommands::multiply:
                    result = num1 * num2;
                    break;
                case ECommands::divide:
                    result = num1 / num2;
                    break;
                default:
                    std::cout << "calc: Unknown command: " << command << std::endl;
                    return true;
            }
        }
        addToBank(result);
        std::cout << result << std::endl;
        return true;
    }

    void addToBank(const MPInt<T> &num) {
        if (bank.size() >= BANK_SIZE) {
            bank.pop_back();
        }
        bank.push_front(num);
    }

    void printBank() {
        auto index = 0;
        for (auto &num: bank) {
            index++;
            std::cout << "$" << index << " = " << num << std::endl;
        }
    }

    void startConsole() {
        bool run = true;
        std::string line;
        do {
            std::cout << PROMPT_HEAD;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            run = handleUserInput(ss);
        } while (run);
    }

    void loadScript(const std::filesystem::path &path) {
        std::ifstream stream(path);

        if (!stream.good()) {
            std::cerr << "Couldn't find file: " + path.string() << std::endl;
            exit(EXIT_FAILURE);
        }

        bool run = true;
        std::string line;

        while (getline(stream, line) and run) {
            std::stringstream ss(line);
            std::cout << PROMPT_HEAD << line << "\n";
            run = handleUserInput(ss);
        }

        stream.close();

        if (run)
            startConsole();
    };
};


#endif //CPP_SP2_MPCALC_H
