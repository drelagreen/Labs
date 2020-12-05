#include <iostream>
#include "Memories.h"
#include "Time.h"
#include "Date.h"
#include "TriadNumber.h"
#include "Interaction.h"

void menu() {

}

int main()
{
    Interaction* interaction = new Interaction();
    interaction->start();
    delete interaction;
}
