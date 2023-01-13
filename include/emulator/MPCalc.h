#ifndef CPP_SP2_MPCALC_H
#define CPP_SP2_MPCALC_H

#include "emulator/MPInt.h"
#include "emulator/util/concepts.h"
#include "emulator/exceptions/InvalidOptionException.h"
#include "emulator/exceptions/OverflowException.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <regex>
#include <deque>
#include <string>
#include <vector>


constexpr auto PROMPT_HEAD = "> ";
constexpr auto BANK_SIZE = 5;

static const std::regex OPERATION_REGEX(std::string(R"(^(\$[1-5]|[\-+]?[0-9]+)([+\-*/!])(\$[1-5]|[0-9]*)$)"),
                                        std::regex_constants::ECMAScript);

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

template<size_t T> requires AtLeastFourBytes<T>
class MPCalc {
private:
    std::deque<MPInt<T>> bank;
public:

    constexpr ECommands getCommandCode(std::string const &string);

    constexpr int getBankIndex(std::string const &string);

    bool handleUserInput(std::stringstream &arguments);

    bool applyCommand(std::stringstream &arguments);

    void addToBank(const MPInt<T> &num);

    void printBank();

    void startConsole();

    void loadScript(const std::filesystem::path &path);
};

#endif //CPP_SP2_MPCALC_H
