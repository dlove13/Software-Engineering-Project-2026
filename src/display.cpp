#include "function.h"
//Display Functions
void Display() {

    //Lambda function to pause the program and wait until user
    //presses enter - Source Claude
    auto pauseAndContinue = [&]()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore();
    };
    
    //init user menu choice
    char choice;

    do {
        clear();              //clear screen
        Display_Menu();       //show menu
        choice = userMenuChoice();
        cin.ignore();

        if (choice == '0') {
            cout << "\nExiting program...\n";
        }
        else if (choice == '1') {

            clear();

            //init containers
            string expression;
            TokenizerResult tokens;
            ParserResult rpn;
            EvaluatorResult result;

            //display arithemetic evaluator menu    
            Display_AEE();

            cin.clear();

            //get user expression
            getline(cin, expression);

            if (expression.empty())
            {
                cout << "No expression entered." << endl;
                pauseAndContinue();
                continue;
            }
            //Put input through the tokenizer
            tokens = Tokenizer(expression);
            if (tokens.error != ErrorCode::NONE)
            {
                ErrorHandler(tokens.error);
                pauseAndContinue();
                continue;
            }

            //Put expression through the parser
            rpn = Parser(tokens.tokens);
            //Check if there was an error
            if (rpn.error != ErrorCode::NONE)
            {
                ErrorHandler(rpn.error);
                pauseAndContinue();
                continue;
            }

            //Put expression through the evaluator
            result = Evaluator(rpn);
            //Check if there was an error
            if (result.error != ErrorCode::NONE)
            {
                ErrorHandler(result.error);
                pauseAndContinue();
                continue;
            }

            cout << "Result: " << result.result << endl;

        }
        else if (choice == '2') {
            clear();
            cout << "\nRunning unit tests...\n";
            Unit_Tests();   // make sure this exists
        }
        else {
            cout << "\nInvalid input.\n";
        }

        if (choice != '0') {
            cout << "\nPress Enter to continue...";
            cin.ignore();
        }

    } while (choice != '0');
}

//Main display menu
void Display_Menu () {

    cout << "Welcome to the Arithmetic Expression Evaluator 1.0!" << endl;

    cout << "\n0) Exit Program " << endl;
    cout << "1) Execute Arithmetic Expression Evaluator" << endl;
    cout << "2) Run Unit Tests" << endl;
    cout << "\nEnter 0, 1, or 2: ";
}

//Program interface
void Display_AEE ()
{   
    cout << "\nValid input is any numeric value, operators such as + - / % and ** for exponents." << endl;

    cout << "\nEnter an expression to be evaluated: ";

}

//Store User Input
char userMenuChoice() 
{
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


