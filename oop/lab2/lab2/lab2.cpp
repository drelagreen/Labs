#include <vld.h>
#include <iostream>
#include "Memories.h"
#include "Time.h"
#include "Date.h"
#include "TriadNumber.h"
#include "Interaction.h"

int main()
{

    Interaction* interaction = new Interaction();
    interaction->start();
    delete interaction;
}
