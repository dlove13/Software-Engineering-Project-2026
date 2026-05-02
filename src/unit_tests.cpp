#include "function.h"

/*  Parser Test
 *  
 *  Valid Expression
 *  Test Expression: (14 + 16 - 12) * 3 / -4 % 6 ** 2
 *
 *  Expected: 14 16 + 12 - 3 * -4 / 6 2 ** %
 *  
 *  Invalid Expression
 *  Test Expression : (14 + 16 - 12) * 3 / -4 % 6 ** 2 
 *
 *  Expected: ERROR - Unmatched parenthesis
 *
 */

//Init Expected value
vector<string> EXPECTED = {"14", "16", "+", "12", "-", "3", "*", "-4", "/", "6", "2","**", "%"};

//Create test expression
vector<Token> INIT_PARSER_TEST()
{

//Init Expression vector
vector<Token> EXPRESSION;

//Init tokens without tokenizer
Token lparen("(", TokenType::LPAREN);
Token rparen(")", TokenType::RPAREN);

Token plus("+", 1, 'L', TokenType::OP); 
Token minus("-", 1, 'L', TokenType::OP);
Token mult("*", 2, 'L', TokenType::OP);
Token divide("/", 2, 'L', TokenType::OP);
Token mod("%", 2, 'L', TokenType::OP);
Token exponent("**", 3, 'R', TokenType::OP);

Token num_14("14");
Token num_16("16");
Token num_12("12");
Token num_3("3");
Token num_neg4 ("-4");
Token num_6("6");
Token num_2("2");
Token num_4("4");
Token num_1("1");

//Add Tokens to vector
EXPRESSION.push_back(lparen);
EXPRESSION.push_back(num_14);
EXPRESSION.push_back(plus);
EXPRESSION.push_back(num_16);
EXPRESSION.push_back(minus);
EXPRESSION.push_back(num_12);
EXPRESSION.push_back(rparen);
EXPRESSION.push_back(mult);
EXPRESSION.push_back(num_3);
EXPRESSION.push_back(divide);
EXPRESSION.push_back(num_neg4);
EXPRESSION.push_back(mod);
EXPRESSION.push_back(num_6);
EXPRESSION.push_back(exponent);
EXPRESSION.push_back(num_2);

return EXPRESSION;
}

//Helper function to create a vector list of valid tokens
void PrintTokens(vector<Token> tokenlist)
{
    //Test Print vector
    for (size_t i = 0; i < tokenlist.size(); i++)
    {
        cout << tokenlist.at(i).token << " ";
    }

    cout << endl;
}

//Helper function to print the RPN vector
void PrintRPN(vector<string> parsedExpression)
{

    for (size_t i = 0; i < parsedExpression.size(); i++)
    {
        cout << parsedExpression.at(i) << " ";
    
    }

    cout << endl;
}

//Helper function to show if the actual output matches the expected
void Result(ParserResult output, vector<string> expected)
{
   if (output.output == expected)
   {
        cout << "PASSED" << endl;
   }

   else
   {
        cout << "Expected: " << endl;
        PrintRPN(expected);

        cout << "Actual: " << endl;
        PrintRPN(output.output);

        ErrorHandler(output.error);
   }
}

void Result_Error(ParserResult invalid)
{
    if (invalid.error != ErrorCode::NONE)
    { 
        ErrorHandler(invalid.error);
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "no error caught" << endl;
    }    
}

void RUN_PARSER_TEST()
{
    cout << "RUNNING PARSER UNIT TEST" << endl;
    cout << "------------------------\n" << endl;
    
    //Valid Expression
    cout << "Valid Expression: " << endl;
    vector<Token> VALID_EXPRESSION = INIT_PARSER_TEST();
    PrintTokens(VALID_EXPRESSION);
    cout << endl;
        
    ParserResult OUTPUT = Parser(VALID_EXPRESSION);
    Result(OUTPUT, EXPECTED);
    
    //Invalid Expression with left parenthesis removed
    cout << "\nTest Invalid Expression: No matching left parenthesis" << endl;
    vector<Token> INVALID_EXPRESSION = INIT_PARSER_TEST();
    INVALID_EXPRESSION.erase(INVALID_EXPRESSION.begin());
    ParserResult INVALID_OUTPUT = Parser(INVALID_EXPRESSION);
    
    Result_Error(INVALID_OUTPUT);

    //Invalid Expression with right parenthesis removed
    cout << "\nTest Invalid Expression: No matching right parenthesis" << endl;
    vector<Token> INVALID_EXPRESSION_RIGHT = INIT_PARSER_TEST();
    INVALID_EXPRESSION_RIGHT.erase(INVALID_EXPRESSION_RIGHT.begin() + 6);
    ParserResult INVALID_OUTPUT_RIGHT = Parser(INVALID_EXPRESSION_RIGHT);

    Result_Error(INVALID_OUTPUT_RIGHT);
}

//Put all Unit tests here
void Unit_Tests()
{
   RUN_PARSER_TEST();
}

