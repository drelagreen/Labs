#include "exception"

class StackOverflowException : public std::exception {
public:
    const char * what() const noexcept override{
        return "Stack overflow exception";
    }
};

class StackUnderflowException : public std::exception {
public:
    const char * what() const noexcept override{
        return "Stack underflow exception";
    }
};

