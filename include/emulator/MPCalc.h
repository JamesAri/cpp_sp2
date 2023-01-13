#ifndef CPP_SP2_MPCALC_H
#define CPP_SP2_MPCALC_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "MPInt.h"
#include "emulator/util/concepts.h"
#include "emulator/util/string-utils.h"
#include "emulator/exceptions/InvalidOptionException.h"
#include "emulator/util/FixedQueue.h"

constexpr auto PROMPT_HEAD = " > ";
constexpr auto BANK_SIZE = 5;

static const std::regex OPERATION_REGEX(std::string(R"(^([0-9]+)([+\-*/!])([0-9]*)$)"),
                                        std::regex_constants::ECMAScript);

template<size_t T> requires AtLeastFourBytes<T>
class MPCalc {
private:
    FixedQueue<MPInt<T>, BANK_SIZE> bank;
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

    bool handleUserInput(std::stringstream &arguments) {
        std::string command;
        arguments >> std::ws >> command;

        if (command.empty()) return true;

        switch (getCommandCode(command)) {
            case ECommands::bank:
                return true;
            case ECommands::exit:
                return false;
            default:
                // continue
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

        num1 = lhs;

        bool isUnary = true;

        if(!rhs.empty()) {
            num2 = rhs;
            isUnary = false;
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
        std::cout << result << std::endl;
        return true;
    }

    void startConsole() {
        bool run = true;
        std::string line;
        std::vector<std::string> args;
        do {
            std::cout << PROMPT_HEAD;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            try {
                run = handleUserInput(ss);
            } catch (InvalidOptionException &ex) {
                std::cout << "calc: " << ex.what() << std::endl;
            }
        } while (run);
    }
};

#endif //CPP_SP2_MPCALC_H
