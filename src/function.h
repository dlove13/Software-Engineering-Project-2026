#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <stdexcept>
using namespace std;

void Display();
void Display_Menu();
char userMenuChoice();   //TODO: Check for valid input


class Token {

    public:
        char token;
        int precedence;
        char associativity;
};

//vector<char> Tokenizer();   //TODO
vector<char> Parser( vector<Token> tokenizedInput);      //TODO
//int Evalutor();             //TODO

//int Error_Handler();        //TODO

void UnitTests();
