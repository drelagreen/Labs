#pragma once
#include <exception>

class MyException : public std::exception {
private:
    const char* reason;
public:
    MyException(const char* reason) {
        this->reason = reason;
    }
    const char* what() const noexcept override {
        return reason;
    }
};