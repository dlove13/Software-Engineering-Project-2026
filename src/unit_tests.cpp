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
Token num_0("0");

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

// Evaluator Test Inputs
vector<Token> SIMPLE_DIV = {num_6, num_3, opDivide}; //Division 6 / 3 = 2
vector<Token> DIV_BY_ZERO = {num_6, num_0, opDivide}; //Divide by zero 6 / 0


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

//Helper function to show if the actual result matches the expected
void Result_Evaluator(EvaluatorResult result, double expected)
{
    if (result.error != ErrorCode::NONE)
    {
        ErrorHandler(result.error);
        cout << "FAILED" << endl;
    }

    else if (result.result == expected)
    {
        cout << "PASSED" << endl;
    }

    else 
    {
        cout << "Expected: " << expected << endl;
        cout << "Actual: " << result.result << endl;
        cout << "FAILED" << endl;
        
    }
}

//Helper function to ensure the correct error was caught
void Result_Evaluator_Error(EvaluatorResult result, ErrorCode expected)
{
    if (result.error == expected)
    {
        ErrorHandler(result.error);
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "No error caught" << endl;
        cout << "FAILED" << endl;
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

void RUN_EVALUATOR_TEST()
{
    cout << "RUNNING EVALUATOR UNIT TEST" << endl;
    cout << "------------------------\n" << endl;
    
    cout << "Valid Expression Test" << endl;
    EvaluatorResult VALID_EVAL = Evaluator(Parser(VALID_EXPRESSION));
    Result_Evaluator(VALID_EVAL, -13.5);

    cout << "\nSimple Division Test: 6 / 3 = 2." << endl;
    EvaluatorResult EVAL_DIV = Evaluator({SIMPLE_DIV, ErrorCode::NONE});
    Result_Evaluator(EVAL_DIV, 2.0);

    cout << "\nError Test: Divide by zero." << endl;
    EvaluatorResult EVAL_ZERO = Evaluator({DIV_BY_ZERO, ErrorCode::NONE});
    Result_Evaluator_Error(EVAL_ZERO, ErrorCode::DIVIDE_BY_ZERO);

    cout << "-----END EVALUATOR TEST-----\n" << endl;
}

void RUN_TOKENIZER_TEST()
{
    cout << "RUNNING TOKENIZER UNIT TEST" << endl;
    cout << "---------------------------\n" << endl;
 
    Token t_num("42");
    cout << "Numeric token -> token: " << t_num.token << ", prec: " << t_num.precedence << ", assoc: " << t_num.associativity << endl;
    cout << (t_num.token == "42" && t_num.precedence == 0 && t_num.associativity == ' ' && t_num.type == TokenType::NUM ? "PASSED" : "FAILED") << endl;
 

    
    cout << "\nNegative number token -> token: " << endl;
    Token t_neg("-7");
    cout << (t_neg.token == "-7" && t_neg.type == TokenType::NUM ? "PASSED" : "FAILED") << endl;
 
    cout << "\nOperator token -> token: " << endl;
    Token t_op("**", 3, 'R', TokenType::OP);
    cout << (t_op.token == "**" && t_op.precedence == 3 && t_op.associativity == 'R' && t_op.type == TokenType::OP ? "PASSED" : "FAILED") << endl;
 
    cout << "\nLeft parenthesis token -> token: " << endl;
    Token t_lp("(", TokenType::LPAREN);
    cout << (t_lp.token == "(" && t_lp.type == TokenType::LPAREN ? "PASSED" : "FAILED") << endl;
 

    cout << "\nRight parenthesis token -> token: " << endl;
    Token t_rp(")", TokenType::RPAREN);
    cout << (t_rp.token == ")" && t_rp.type == TokenType::RPAREN ? "PASSED" : "FAILED") << endl;
 


    cout << "\nToken equality -> same tokens: " << endl;
    Token t_a("+", 1, 'L', TokenType::OP);
    Token t_b("+", 1, 'L', TokenType::OP);
    cout << (t_a == t_b ? "PASSED" : "FAILED") << endl;
 

    cout << "\nToken equality -> different tokens: " << endl;
    Token t_c("-", 1, 'L', TokenType::OP);
    cout << (!(t_a == t_c) ? "PASSED" : "FAILED") << endl;
 
    cout << "\n-----END TOKENIZER TEST-----\n" << endl;
}

//Put all Unit tests here
void Unit_Tests()
{
   RUN_TOKENIZER_TEST();
   RUN_PARSER_TEST();
   RUN_EVALUATOR_TEST();


}

