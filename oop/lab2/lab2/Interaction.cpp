#include "Interaction.h"
#include <iostream>
#include <string>
#include "Memories.h"
#include "Date.h"
#include "Time.h"
#include "Exceptions.h"
#include "TriadFactory.h"

Interaction::Interaction(Memories* memories) {

	this->memories = memories;
}

void Interaction::menu1() {
	std::cout << "1 - Create \"Memories\" \n";
	std::cout << "2 - Create \"Pare\" and put into \"Memories\" \n";
	std::cout << "3 - increment\n";
	std::cout << "4 - decrement\n";
	std::cout << "0 - exit\n";
	std::cout << "\n\n";
	printData();
	std::cout << "\n\n";
}

bool Interaction::menu2(int x) {
	bool incrementFlag = false;
	switch (x)
	{
	case (0):
		return false;
	case (1):
		std::cout << "size: ";
		int size;
		size = scan();
		if (memories) {
			delete memories;
		}
		memories = new Memories(size);
		break;
	case (2):
		if (memories) {
			std::cout << "Pare #1 (3 nums, Date, DD-MM-YYYY) - ";
			int a = scan();
			int b = scan();
			int c = scan();

			//FACTORY METHOD 1
			//Date* date = new Date(a,b,c);
			Date* date = TriadFactory<Date>::getTriad(a, b, c);


			std::cout << "Pare #1 (3 nums, Timme, HH-MM-SS) - ";
			c = scan();
			b = scan();
			a = scan();

			//FACTORY METHOD
			//Time* time = new Time(a,b,c);
			Time* time = TriadFactory<Time>::getTriad(a, b, c);
			Pare* p = new Pare(date, time);
			std::cout << "Index - ";
			int index = scan();
			memories->setPare(index, p);
			std::cout << "\nSuccessful!\n";
		}
		else {
			std::cout << "\"Memories\" == NULL !\n";
		}
		break;
	case (3):
		incrementFlag = true;
	case (4):
		if (memories) {
			int type;
			int position;
			int index;
			TriadNumber enumPosition;

			std::cout << "Index > ";
			index = scan();
			if (!memories->getPare(index)) {
				std::cout << "\nPare == NULL!\n";
				break;
			}
			std::cout << "1 - Date, 2 - Time\n";
			type = scan();
			if (type == 1)
				std::cout << "1 - Day, 2 - Month, 3 - Year\n";
			else if (type == 2)
				std::cout << "1 - Seconds, 2 - Minutes, 3 - Hours\n";
			else {
				std::cout << "Incorrect type!\n";
				break;
			}
			position = scan();
			if (position == 1)
				enumPosition = FIRST;
			else if (position == 2)
				enumPosition = SECOND;
			else if (position == 3)
				enumPosition = THIRD;
			else {
				break;
			}

			if (incrementFlag) {
				if (type == 1) {
					memories->getPare(index)->getKey()->incrementAndGet(enumPosition);
				}
				else {
					memories->getPare(index)->getValue()->incrementAndGet(enumPosition);
				}
			}
			else {
				if (type == 1) {
					memories->getPare(index)->getKey()->decrementAndGet(enumPosition);
				}
				else {
					memories->getPare(index)->getValue()->decrementAndGet(enumPosition);
				}
			}
		}
		else {
			std::cout << "\"Memories\" == NULL !\n";
		}
		break;
	default:
		break;
	}
	return true;
}

int Interaction::scan() {
	int x;
	std::cin >> x;
	return x;
}

void Interaction::printData()
{	
	if (memories == NULL) {
		std::cout << "MEMORIES == NULL\n";
	}
	else {
		for (int i = 0; i < memories->getMaxSize(); i++) {
			Pare* p = memories->getPare(i);
			if (p) { 
				Triad* t1 = p->getKey();
				Triad* t2 = p->getValue();
				if (t1 && t2) {
					std::cout << i << ") ";
					printf_s("%2.2d-%2.2d-%4.4d ", t1->get(FIRST), t1->get(SECOND), t1->get(THIRD));
					printf_s("%2.2d:%2.2d:%2.2d\n", t2->get(THIRD), t2->get(SECOND), t2->get(FIRST));
				}
				else {
					std::cout << i << ") NULL\n";
				}
			}
			else {
				std::cout << i << ") NULL\n";
			}
		}
	}
}

void Interaction::start() {
	while (runningFlag) {
		menu1();
		try {
			runningFlag = menu2(scan());
		}
		catch (MemoriesException &e) {
			std::cout << "/n" << e.what() << "\n";
		}
		catch (TriadDataException& e1) {
			std::cout << "/n" << e1.what() << "\n";
		}
		std::cout << "\n";
	}
}