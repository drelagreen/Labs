#include "Stack.h"
#include <iostream>
#include "MyExceptions.h"
#include "StackUserInterface.h"
    
    int StackUserInterface::getNextInt() {
        int t;
        std::cout << "Введите значение, помещаемое в стэк> ";
        std::cin >> t;
        return t;
    }

    void StackUserInterface::printExceptionMessage(std::exception &e) {
        std::cout << "Поймано исключение [" << e.what() << "]" << std::endl;
    }

    int StackUserInterface::getStackSize() {
        int n;
        std::cout << "Введите размер стэка> ";
        std::cin >> n;
        if (n < 0) {
            std::cout << "Размер должен быть >= 0!" << std::endl;
            return getStackSize();
        }
        return n;
    }

    void StackUserInterface::start() {
        _stack = new Stack(getStackSize());
        bool running = true;
        int choice;
        while (running) {
            std::cout << "1 - pop\n2 - push\n3 - back\n4 - isEmpty()?\n5 - exit\n";
            std::cin >> choice;
            try {
                switch (choice) {
                    case 1:
                        std::cout << _stack->pop() << std::endl;
                        break;
                    case 2:
                        _stack->push(getNextInt());
                        break;
                    case 3:
                        std::cout << _stack->back() << std::endl;
                        break;
                    case 4:
                        std::cout << (_stack->isEmpty() ? "true" : "false") << std::endl;
                        break;
                    case 5:
                        running = false;
                        break;
                    default:
                        continue;
                }
            } catch (StackOverflowException &e0) {
                printExceptionMessage(e0);
                std::cout << "Попытка переполнения стэка с размером - " << _stack->getMaxSize() << std::endl;

            } catch (StackUnderflowException &e1) {
                printExceptionMessage(e1);
                std::cout << "Попытка взять элемент из пустого стэка" << std::endl;

            } catch (std::exception &e2) {
                printExceptionMessage(e2);

            }
        }
    }

    StackUserInterface::~StackUserInterface() {
        delete (_stack);
    }

