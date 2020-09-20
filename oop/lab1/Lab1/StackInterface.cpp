#include "Stack.h"
#include <iostream>
#include "MyExceptions.h"
#include "StackInterface.h"
    int StackInterface::getNextInt() {
        int t;
        std::cout << "Введите значение, помещаемое в стэк> ";
        std::cin >> t;
        return t;
    }

    void StackInterface::printExceptionMessage(std::exception &e) {
        std::cout << "Поймано исключение [" << e.what() << "]" << std::endl;
    }

    int StackInterface::getStackSize() {
        int n;
        std::cout << "Введите размер стэка> ";
        std::cin >> n;
        if (n < 0) {
            std::cout << "Размер должен быть >= 0!" << std::endl;
            return getStackSize();
        }
        return n;
    }

    Stack* stack;
    void StackInterface::start() {
        stack = new Stack(getStackSize());
        bool running = true;
        int choice;
        while (running) {
            std::cout << "1 - pop\n2 - push\n3 - back\n4 - isEmpty()?\n5 - exit\n";
            std::cin >> choice;
            try {
                switch (choice) {
                    case 1:
                        std::cout << stack->pop() << std::endl;
                        break;
                    case 2:
                        stack->push(getNextInt());
                        break;
                    case 3:
                        std::cout << stack->back() << std::endl;
                        break;
                    case 4:
                        std::cout << (stack->isEmpty() ? "true" : "false") << std::endl;
                        break;
                    case 5:
                        running = false;
                        break;
                    default:
                        continue;
                }
            } catch (StackOverflowException &e0) {
                printExceptionMessage(e0);
                std::cout << "Попытка переполнения стэка с размером - " << stack->getMaxSize() << std::endl;

            } catch (StackUnderflowException &e1) {
                printExceptionMessage(e1);
                std::cout << "Попытка взять элемент из пустого стэка" << std::endl;
            } catch (std::exception &e2) {
                printExceptionMessage(e2);
            }
        }
    }

    StackInterface::~StackInterface() {
        delete (stack);
    }

