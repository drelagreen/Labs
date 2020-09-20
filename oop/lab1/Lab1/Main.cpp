#include "StackInterface.h"
#include <locale>
#include <vld.h>
int main(){
    setlocale(LC_ALL, "Russian");
    auto* stackInterface = new StackInterface();
    stackInterface->start();
    delete (stackInterface);
    system("pause");
}

