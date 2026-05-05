#include "function.h"

/*  Parser Test
 *  
 *  Valid Expression
 *  Test Expression: (14 + 16 - 12) * 3 / -4 % 6 ** 2
 *
 *  Expected: 14 16 + 12 - 3 * -4 / 6 2 ** %
 *  
 *  Invalid Expression
 *  Test Expression : 14 + 16 - 12) * 3 / -4 % 6 ** 2 
 *
 *  Expected: ERROR - Unmatched parenthesis
 *
 *  Invalid Expression
 *  Test Expression : (14 + 16 - 12 * 3 / -4 % 6 ** 2 
 *
 *  Expected: ERROR - Unmatched parenthesis
 *
 *  Invalid Expression
 *  Test Expression : (14 ++ 3)
    
    Expected: ERROR - Operator Adjacent
 */

//Init tokens without tokenizer
Token lparen("(", TokenType::LPAREN);
Token rparen(")", TokenType::RPAREN);

Token opPlus("+", 1, 'L', TokenType::OP); 
Token opMinus("-", 1, 'L', TokenType::OP);
Token opMult("*", 2, 'L', TokenType::OP);
Token opDivide("/", 2, 'L', TokenType::OP);
Token opMod("%", 2, 'L', TokenType::OP);
Token opExponent("**", 3, 'R', TokenType::OP);

Token num_14("14");
Token num_16("16");
Token num_12("12");
Token num_3("3");
Token num_neg4 ("-4");
Token num_6("6");
Token num_2("2");
Token num_4("4");
Token num_1("1");

//Init Expected value
 vector<Token> EXPECTED = {num_14, num_16, opPlus, num_12,opMinus, num_3, opMult, num_neg4,
                           opDivide, num_6, num_2, opExponent, opMod}; 

 vector<Token> OPERATOR_TEST = {num_14, opPlus, opPlus, num_3};
//Create test expression
vector<Token> INIT_PARSER_TEST()
{
      
//Init Expression vector
vector<Token> EXPRESSION;
//Add Tokens to vector
EXPRESSION.push_back(lparen);
EXPRESSION.push_back(num_14);
EXPRESSION.push_back(opPlus);
EXPRESSION.push_back(num_16);
EXPRESSION.push_back(opMinus);
EXPRESSION.push_back(num_12);
EXPRESSION.push_back(rparen);
EXPRESSION.push_back(opMult);
EXPRESSION.push_back(num_3);
EXPRESSION.push_back(opDivide);
EXPRESSION.push_back(num_neg4);
EXPRESSION.push_back(opMod);
EXPRESSION.push_back(num_6);
EXPRESSION.push_back(opExponent);
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
void PrintRPN(vector<Token> parsedExpression)
{

    for (size_t i = 0; i < parsedExpression.size(); i++)
    {
        cout << parsedExpression.at(i).token << " ";
    
    }

    cout << endl;
}

//Helper function to show if the actual output matches the expected
void Result(ParserResult output, vector<Token> expected)
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
    PrintTokens(INVALID_EXPRESSION);
    ParserResult INVALID_OUTPUT = Parser(INVALID_EXPRESSION);
    
    Result_Error(INVALID_OUTPUT);

    //Invalid Expression with right parenthesis removed
    cout << "\nTest Invalid Expression: No matching right parenthesis" << endl;
    vector<Token> INVALID_EXPRESSION_RIGHT = INIT_PARSER_TEST();
    INVALID_EXPRESSION_RIGHT.erase(INVALID_EXPRESSION_RIGHT.begin() + 6);
    PrintTokens(INVALID_EXPRESSION_RIGHT);
    ParserResult INVALID_OUTPUT_RIGHT = Parser(INVALID_EXPRESSION_RIGHT);

    Result_Error(INVALID_OUTPUT_RIGHT);
    
    //Operators adjacent to each other
    cout << "\nTest Invalid Expression: Operators adjacent." << endl;
    PrintTokens(OPERATOR_TEST);
    ParserResult INVALID_OUTPUT_OP = Parser(OPERATOR_TEST);

    Result_Error(INVALID_OUTPUT_OP);


}

//Put all Unit tests here
void Unit_Tests()
{
   RUN_PARSER_TEST();
}

