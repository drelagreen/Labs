#include "StackUserInterface.h"
#include <locale>
#include <vld.h>
int main(){
    setlocale(LC_ALL, "Russian");
    StackUserInterface* stackInterface = new StackUserInterface();
    stackInterface->start();
    delete (stackInterface);
    system("pause");
    return 0;
}

