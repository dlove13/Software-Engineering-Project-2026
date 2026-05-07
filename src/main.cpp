#include "function.h"

int main() {
        bool Running = true;

        while (Running) {
                //Init display
                clear();
                Display();

                //Prompt user for input 
                char choice = userMenuChoice();

                //TODO: Closes if user input is not valid: implement input error_handling

                if (!isdigit(choice)) {
                        Running = false;
                }

                if (choice == '2')
                {   
                        clear();
                        Unit_Tests();
                        Running = false;
                }
        }

        cout << "Exiting program..." << endl;


        return 0;
}
