#include "function.h"

//Display Functions
void Display() { 

    Display_Menu();


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


