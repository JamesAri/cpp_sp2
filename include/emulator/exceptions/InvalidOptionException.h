#ifndef CPP_SP2_INVALIDOPTIONEXCEPTION_H
#define CPP_SP2_INVALIDOPTIONEXCEPTION_H

#include <exception>
#include <string>

class InvalidOptionException : public std::exception {
private:
    std::string mErrMsg;
public:
    InvalidOptionException() : mErrMsg("invalid option(s)") {}

    explicit InvalidOptionException(std::string &&errMsg) : mErrMsg(errMsg) {}

    explicit InvalidOptionException(const std::string &errMsg) : mErrMsg(errMsg) {}

    [[nodiscard]] const char *what() const _NOEXCEPT override {
            return this->mErrMsg.c_str();
    }
};

#endif //CPP_SP2_INVALIDOPTIONEXCEPTION_H
