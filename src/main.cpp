#include "emulator/MPCalc.h"
#include "emulator/tests/tests.h"

enum MODES {
    UNLIMITED = 1,
    INT32 = 2,
    DEMO = 3,
    TESTS = 4,
};

void exitWithUsage(std::string &&invalidMode) {
    std::cerr << invalidMode << " is not a valid mode, (1 - unlimited, 2 - 32bit integer, 3 - demo)." << std::endl;
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid argument. Modes: 1 - unlimited, 2 - 32bit integer, 3 - demo\n"
                     "Usage: <executable> <mode>" << std::endl;
    }

    std::stringstream ss(argv[1]);
    size_t result;
    if (!(ss >> result))
        exitWithUsage(argv[1]);

    auto calcUnlimited = MPCalc<MPINT_UNLIMITED>();
    auto calc32Bit = MPCalc<4>();
    auto calcDemo = MPCalc<MPINT_UNLIMITED>();

    switch (result) {
        case UNLIMITED:
            calcUnlimited.startConsole();
            break;
        case INT32:
            calc32Bit.startConsole();
            break;
        case DEMO:
            calcDemo.loadScript("showcase.txt");
            break;
        case TESTS:
            runTests();
            std::cout << "Tests OK" << std::endl;
            break;
        default:
            exitWithUsage(argv[1]);
            break;
    }
}
