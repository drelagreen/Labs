#pragma once
#include "exception"

class TriadDataException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad data";
    }
};

class MemoriesException : public std::exception {
private:
    const char* reason;
public:
    MemoriesException(const char* reason) {
        this->reason = reason;
    }
    const char* what() const noexcept override {
        return reason;
    }
};