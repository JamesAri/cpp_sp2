#ifndef CPP_SP2_MPCALC_H
#define CPP_SP2_MPCALC_H

#include <iostream>
#include <string>
#include <vector>

#include "MPInt.h"
#include "emulator/util/concepts.h"
#include "emulator/util/string-utils.h"
#include "emulator/exceptions/InvalidOptionException.h"
#include "emulator/util/FixedQueue.h"

constexpr auto PROMPT_HEAD = " > ";
constexpr auto BANK_SIZE = 5;

template <size_t T> requires AtLeastFourBytes<T>
class MPCalc {
private:
//    FixedQueue<MPInt<T>, BANK_SIZE> bank;
public:
    enum class ECommands {
        plus,
        minus,
        multiply,
        divide,
        bank,
        exit,
        unknown,
    };

    constexpr ECommands getCommandCode(std::string const &string) {
        if (string == "+") return ECommands::plus;
        if (string == "-") return ECommands::minus;
        if (string == "*") return ECommands::multiply;
        if (string == "/") return ECommands::divide;
        if (string == "bank") return ECommands::bank;
        if (string == "exit") return ECommands::exit;
        return ECommands::unknown;
    }

    bool handleUserInput(std::vector<std::string> arguments) {
        if (arguments.empty()) return true;

        auto command = arguments[0];
        const auto options = std::vector<std::string>(arguments.begin() + 1, arguments.end());

        switch (getCommandCode(command)) {
            case ECommands::plus:
                break;
            case ECommands::minus:
                break;
            case ECommands::multiply:
                break;
            case ECommands::divide:
                break;
            case ECommands::bank:
                break;
            case ECommands::exit:
                return false;
            case ECommands::unknown:
                std::cout << "calc: Unknown command: " << command << std::endl;
                break;
        }
        return true;
    }

    void startConsole() {
        bool run = true;
        std::string sInput;
        std::vector<std::string> args;
        do {
            std::cout << PROMPT_HEAD;
            std::getline(std::cin, sInput);
            args = split(sInput, ' ');
            try {
                run = handleUserInput(args);
            } catch (InvalidOptionException &ex) {
                std::cout << "calc: " << ex.what() << std::endl;
            }
        } while (run);
    }
};

#endif //CPP_SP2_MPCALC_H
