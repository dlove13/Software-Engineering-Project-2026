#include "function.h"

//Display Functions
void Display() {
    char choice;

    do {
        clear();              //clear screen
        Display_Menu();       //show menu
        choice = userMenuChoice();

        if (choice == '0') {
            cout << "\nExiting program...\n";
        }
        else if (choice == '1') {
            cout << "\nArithmetic Expression Evaluator not implemented yet.\n";
            //later: call evaluator here
        }
        else if (choice == '2') {
            cout << "\nRunning unit tests...\n";
            runUnitTests();   // make sure this exists
        }
        else {
            cout << "\nInvalid input.\n";
        }

        if (choice != '0') {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != '0');
}

//Main display menu
void Display_Menu () {

    cout << "Display is running..." << endl;

    cout << "\n0) Exit Program " << endl;
    cout << "1) Execute Arithmetic Expression Evaluator (Not Implemented)" << endl;
    cout << "2) Run Unit Tests" << endl;
    cout << "\nEnter 0, 1, or 2: ";
}

//Store User Input
char userMenuChoice() {
    char inputBuf;

    cin >> inputBuf; 

    return inputBuf;
}

//Clear terminal helper function
void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
