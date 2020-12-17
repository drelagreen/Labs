#include "Interactor.h"

void Interactor::loop() {
    vector <Elections>v;
    bool init = false;

    while (run) {
        int t;
        cout << "\nLoad file - \"1\"\nContinue - \"2\"\nExit - \"0\"\n";
        cin >> t;
        if (t == 0) {
            run = false;
        }
        else if (t == 1) {
            try {
                v = FileReader::read();
                cout << "Loading has been completed!\n";
                init = true;
            }
            catch (std::exception& e) {
                cout << e.what() << "\n";
                continue;
            }
        }
        else if (t == 2) {
            if (!init) {
                cout << "Vector has not been initialized!\n";
                continue;
            }
            double limiter;
            cout << "Enter the limiter (rating)\n";
            cin >> limiter;
            std::sort(v.begin(), v.end());
            init = true;

            auto i = v.begin();
            auto end = v.end();
            cout << "***BEGIN***\n";
            while (i != end && (*i).getRating() > t) {
                cout << (*i).toString() << "\n\n";
                i++;
            }
            cout << "***END***\n";
            v.clear();
        }
    }
}

