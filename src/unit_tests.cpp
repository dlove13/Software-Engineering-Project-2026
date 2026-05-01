#include "function.h"

/*Define unit tests for each individual t*/

//Infix Expression
vector<char> test_expression_1 = {'3', '+', '4'};
vector<char> test_expression_2 = {'8' , '-', '(', '5', '-', '2', ')'};
vector<char> test_expression_3 = {'-','8', '+', '(', '2', '*', '3', ')'};
vector<char> test_expression_4 = {'4', '*', '(', '3', '+', '2', ')', '%', '7', '-', '1'};

//Crude Tokenizer
vector<Token> parser_test_1;
vector<Token> parser_test_2;
vector<Token> parser_test_3;
vector<Token> parser_test_4;

//Expected Output
vector<char> expected_1 = {'3','4','+'};
vector<char> expected_2 = {'8','5','2', '-', '-'};
vector<char> expected_3 = {'-','8', '2', '3', '*', '+'};
vector<char> expected_4 = {'4','3','2','+','*','7','%', '1', '-'};


//Actual output
vector<char> test_rpn_1;
vector<char> test_rpn_2;
vector<char> test_rpn_3;
vector<char> test_rpn_4;



vector<Token> CreateTokenList(vector<char> expr)
{
    vector<Token> tokens;

    for (size_t i = 0; i < expr.size(); i++){
        Token newToken;
        newToken.token = expr.at(i);

        tokens.push_back(newToken);
    }
    
    return tokens;
}

void PrintTokens(vector<Token> tokenlist)
{
    //Test Print vector
    for (size_t i = 0; i < tokenlist.size(); i++)
    {
        cout << tokenlist.at(i).token;
    }

    cout << endl;
}

void PrintRPN(vector<char> parsedExpression)
{

    for (size_t i = 0; i < parsedExpression.size(); i++)
    {
        cout << parsedExpression.at(i);
    
    }

    cout << endl;
}

void Result (vector<char> );

void UnitTests ()
{
    //Init list of tokens
    parser_test_1 = CreateTokenList(test_expression_1);
    parser_test_2 = CreateTokenList(test_expression_2);
    parser_test_3 = CreateTokenList(test_expression_3);
    parser_test_4 = CreateTokenList(test_expression_4);
    

    //Print Infix expressions
    cout << "Infix Expressions" << endl;
    cout << "-----------------" << endl;
    PrintTokens(parser_test_1);
    PrintTokens(parser_test_2);
    PrintTokens(parser_test_3);
    PrintTokens(parser_test_4);
    
    //Parse expressions
    test_rpn_1 = Parser(parser_test_1);
    test_rpn_2 = Parser(parser_test_2);
    test_rpn_3 = Parser(parser_test_3);
    test_rpn_4 = Parser(parser_test_4);


    //Print RPN expressions
    cout << "\nRPN Expression" << endl;
    cout << "--------------" << endl;
    PrintRPN(test_rpn_1);
    PrintRPN(test_rpn_2);
    PrintRPN(test_rpn_3);
    PrintRPN(test_rpn_4);
}

