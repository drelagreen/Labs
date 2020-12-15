#include "Interactor.h"
#include "MyException.h"
#include <iostream>

using namespace std;
void Interactor::showMenu() {
    cout<<"1 - Create/recreate\n"
        <<"2 - Get type\n"
        <<"3 - Get coords\n"
        <<"4 - Get area\n"
        <<"5 - Get radius of the circumscribed circle\n"
        <<"6 - Move\n"
        <<"7 - Rotate\n"
        <<"8 - Compare\n"
        <<"9 - Center of mass\n"
        <<"0 - Exit\n";
}

int Interactor::getMenuNum() {
    int x;
    cin >> x;
    if (x<0 || x>10){
        throw MyException("Incorrect menu number!");
    }
    return x;
}

void Interactor::execute(int cmd) {
    bool b;
    MyShape** localShape = nullptr;
    if (cmd != 8 && cmd != 0) {
        if (boolChoice("Choice figure", "First", "Second")) {
            localShape = &shape1;
        } else {
            localShape = &shape2;
        }
        if (cmd!=1 && (*localShape == nullptr || localShape == nullptr)) {
            throw MyException("Shape is not initialized!");
        }
    }

    switch (cmd) {
        case 1: {
            int c;
            cout << "Enter count of points (2-4):\n";
            cin >> c;
            if (c <= 0){
                throw MyException("Incorrect count of points!");
                break;
            }
            Point** points = new Point * [c] {};
            for (int i = 0; i < c; i++) {
                if (points[i] && points[i] != nullptr) {
                    delete points[i];
                }
                points[i] = new Point();
         
                cout << "\nPoint " << i + 1 << "\n";
                cout << "X>\n";
                int x;
                cin >> x;
                points[i]->setX(x);

                cout << "Y>\n";
                int y;
                cin >> y;
                points[i]->setY(y);
                cout<<"\n";
            }
            if (*localShape!=nullptr)
                delete *localShape;
            try {
                *localShape = Shapes::createShape(c, points);
            }
            catch (MyException& e) {
                cout << "\n" << e.what() << "\n";
                delete (*localShape);
                *localShape = nullptr;
                break;
            }
            cout << "OK\n";
            break;
        }
        case 2:
            cout<< (((*localShape)->getType() == SQUARE) ? "\nSQUARE\n" : (((*localShape)->getType() == RECTANGLE) ?  "\nRECTANGLE\n" : "NONE"));
            break;
        case 3:
            for (int i = 0; i < (*localShape)->getCount(); i++) {
                cout<<"\nPoint "<<i<<"\n";
                cout << "X - "
                     <<(*localShape)->getPoint(i)->getX()
                     <<"\nY - "
                     <<(*localShape)->getPoint(i)->getY()
                     <<"\n";
            }
            break;

        case 4:
            cout<<"Area - "<<(*localShape)->getArea()<<"\n";
            break;

        case 5:
            cout<<"Radius - "<<(*localShape)->getOutRadius()<<"\n";
            break;

        case 6:
            double x,y;
            cout<<"X>";
            cin>>x;
            cout<<"\nY>";
            cin>>y;
            (*localShape)->move(x,y);
            break;

        case 7:
            double alpha;
            cout<<"Rad>";
            cin>>alpha;
            (*localShape)->rotate(alpha);
            break;
        case 8: {
            if (shape1 == nullptr || shape2 == nullptr) {
                throw MyException("Shapes are not initialized!");
            }
            double dif = Shapes::compare(shape1, shape2);
            if (dif == 0) {
                cout << "Shapes are equals\n";
            } else {
                if (dif < 0) {
                    cout << "Shape 2 is " << -dif << " more then Shape 1";
                } else {
                    cout << "Shape 1 is " << dif << " more then Shape 2";
                }
            }
            break;
        }
        case 9:
            cout<<"Center of mass - X = "<<(*localShape)->getMassCenter()->getX()<<"   Y = "<<(*localShape)->getMassCenter()->getY()<<"\n";
            break;
        case 0:
            delete localShape;
            running = false;
        default: return;
    }
}

void Interactor::loop() {
    while(running) {
        try {
            showMenu();
            execute(getMenuNum());
            cout<<"\n";
        } catch (MyException &e) {
            cout << "\n" << e.what() << "\n\n";
        }
    }
}

bool Interactor::boolChoice(const char *text, const char *v1, const char *v2) {
    int x;
    cout<<text<<"\n"<<"1 - "<<v1<<"\n"<<"2 - "<<v2<<"\n";
    cin >> x;
    if (x==1){
        return true;
    }
    if (x == 2){
        return false;
    }
    throw MyException("Incorrect choice!");
}
