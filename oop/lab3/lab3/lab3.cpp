#include "Interactor.h"
#include <vld.h>
int main()
{
    Interactor* interactor = new Interactor();
    interactor->loop();
    delete interactor;

}




