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

//Valid Test Case
vector<Token> VALID_EXPRESSION = {lparen, num_14, opPlus, num_16, opMinus, num_12, rparen, opMult, num_3, opDivide, num_neg4,
                                    opMod, num_6, opExponent, num_2};
//Expected RPN output value
 vector<Token> EXPECTED = {num_14, num_16, opPlus, num_12,opMinus, num_3, opMult, num_neg4,
                           opDivide, num_6, num_2, opExponent, opMod}; 

//Testing Error Cases
vector<Token> NO_OPENING_PAREN = {num_12, opPlus, num_neg4, rparen};//No matching parenthesis 12 + -4 )
vector<Token> NO_CLOSING_PAREN = {lparen, num_3, opMinus, num_2};   //No matching parenthesis ( 3 - 2
vector<Token> OPERATOR_TEST = {num_14, opPlus, opPlus, num_3};      //Adjacent operators 14 + + 3
vector<Token> OPERATOR_TEST_2 = {lparen, opDivide, num_1};          //Operator after opening parenthesis ( / 1
vector<Token> OPERATOR_TEST_3 = {lparen, num_12,opPlus,rparen};     //Operator before closing parenthesis ( 12 + )


//Helper function to print token list
void PrintTokens(vector<Token> tokenlist)
{
    //Test Print vector
    for (size_t i = 0; i < tokenlist.size(); i++)
    { 
        cout << tokenlist.at(i).token << " ";
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
        PrintTokens(expected);

        cout << "Actual: " << endl;
        PrintTokens(output.output);

        ErrorHandler(output.error);
   }
}

//Helper function to show error tests pass
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
    
    cout << "Valid Expression Test" << endl;
    ParserResult VALID_OUTPUT = Parser(VALID_EXPRESSION);
    Result(VALID_OUTPUT, EXPECTED);

    cout << "\nError Test: No matching parenthesis." << endl;
    ParserResult ERROR_1 = Parser(NO_OPENING_PAREN);
    Result_Error(ERROR_1);

    cout << "\nError Test: No matching parenthesis." << endl;
    ParserResult ERROR_2 = Parser(NO_CLOSING_PAREN);
    Result_Error(ERROR_2);

    cout << "\nError Test: Adjacent operators." << endl;
    ParserResult ERROR_3 = Parser(OPERATOR_TEST);
    Result_Error(ERROR_3);

    cout << "\nError Test: Operator after opening parenthesis." << endl;
    ParserResult ERROR_4 = Parser(OPERATOR_TEST_2);
    Result_Error(ERROR_4);

    cout << "\nError Test: Operator before closing parenthesis." << endl;
    ParserResult ERROR_5 = Parser(OPERATOR_TEST_3);
    Result_Error(ERROR_5);

    cout << "-----END PARSER TEST-----\n" << endl;
}

//Put all Unit tests here
void Unit_Tests()
{
   RUN_PARSER_TEST();
  
}

