#include "function.h"

int main() {
    bool Running = true;

    while (Running) {
        
        Display();
        
        char choice = userMenuChoice();

        if (!isdigit(choice)) {
            Running = false;
        }
        
        else {
            cout << choice << endl;
        }
    }
    
    cout << "Exiting program..." << endl;

    return 0;
}
