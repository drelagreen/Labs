
#include "Interactor.h"

void Interactor::loop() {
    double t;
    vector <Elections>v;
    while (run){
        cout << "\nLoad file - \"1\"\nExit - \"0\"\n";
        cin>>t;
        if (t == 0){
            run = false;
        } else
        if (t == 1) {
            try {
                v = FileReader::read();
                cout << "\nLoading has been completed!\n\n";
            }
            catch (std::exception& e) {
                cout << e.what() << "\n";
                continue;
            }
            cout << "Enter the limiter (rating)\n";
            cin >> t;
            std::sort(v.begin(), v.end());


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
