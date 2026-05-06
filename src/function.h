#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <stdexcept>
using namespace std;

//Display Functions
void Display();
void Display_Menu();
char userMenuChoice();   //TODO: Check for valid input
void clear();

//Define token types: number, operatorm left parenthesis, right parenthesis
enum class TokenType { NUM, OP, LPAREN, RPAREN };

//TODO Add more error codes
enum class ErrorCode
{
   NONE,
   MISMATCHED_PARENTHESIS,
   DIVIDE_BY_ZERO,
   INVALID_SYNTAX,
   ADJACENT_OPERATORS,
   INVALID_EXPRESSION

};

void ErrorHandler(ErrorCode error);


//Define token class
class Token {
        
    public:
        string token;
        int precedence;
        char associativity;
        TokenType type;
        
        //== overload to check if two tokens are equal
        bool operator==(const Token& other) const
        {
           return token == other.token &&
                  precedence == other.precedence &&
                  associativity == other.associativity &&
                  type == other.type;
        }
        //default constructor for numbers
        Token(string n) 
        {
           token =  n;
           precedence = 0;
           associativity = ' ';
           type = TokenType::NUM;
        }

        //constructor for operators
        Token(string o, int p, char a, TokenType t)
        {
           token = o;
           precedence = p;
           associativity = a;
           type = t;
        }

        //Constructor for parenthesis
        Token(string paren, TokenType t)
        {
           token = paren;
           precedence = 0;
           associativity = ' ';
           type = t;
        }
};

//vector<char> Tokenizer();   //TODO

//Store result of parser and potential error code
struct ParserResult
{
    vector<Token> output;
    ErrorCode error = ErrorCode::NONE;
};

ParserResult Parser( vector<Token> tokenizedInput); 


/*  Could probably mirror the ParserResult struct and create an
 *  Evaluator struct to hold the result and error code
 *
 * */

//int Evalutor();             //TODO

//Store result of evaluator and potential error code
struct EvaluatorResult
{
   double output = 0.0;
   ErrorCode error = ErrorCode::NONE;
};

EvaluatorResult Evaluator(ParserResult parserOutput);

void Unit_Tests();            //TODO

#endif
