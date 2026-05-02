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

//vector<char> Tokenizer () {}

//Parser Function
ParserResult Parser (vector<Token> tokenizedInput) {
    /*   Implement with Shunting Yard Algorithm
     *
     *   Numbers -> directly into output queue
     *   Left Parenthesis -> Push() onto operator stack
     *   Right parenthesis -> Pop() operators from stack and add to output
     *       until left parenthesis is reached
     *
     *       Discard both parenthesis
     *
     *   Operators -> Compare current operator precedence and associativity to
     *       operator at the top of the stack
     *
     *       if curr.precedence >= top.precendence and associativity == 'L':
     *           Pop() to output queue before pushing new operator
     *
     *   Once Input == Empty: Pop() remaining operators from stack and add to
     *       input
     *
     * */ 

    //Init containers
    stack<Token> operatorStack; 
    vector<string> postFixExpr;

    for (size_t i = 0; i < tokenizedInput.size(); i++)

    {
        //Check if number, then push to output
        if (tokenizedInput.at(i).type == TokenType::NUM) 
        {
            postFixExpr.push_back(tokenizedInput.at(i).token);
        }
        //Push left parenthesis onto operator stack
        else if (tokenizedInput.at(i).type == TokenType::LPAREN)
        {
            operatorStack.push(tokenizedInput.at(i));
        }
        //Pop operators from stack and add to output until next left parenthesis
        else if (tokenizedInput.at(i).type == TokenType::RPAREN)
        {
            while (!operatorStack.empty() && operatorStack.top().type != TokenType:: LPAREN)
            {
                postFixExpr.push_back(operatorStack.top().token);
                operatorStack.pop();
            }

            if (!operatorStack.empty() && operatorStack.top().type == TokenType::LPAREN)
            {
            
                operatorStack.pop();        //discard matching left parenthesis
            } 
            else 
            {
               //Error-Handling: Mismatched Parenthesis
                return {postFixExpr, ErrorCode::MISMATCHED_PARENTHESIS}; 
            }
        }
            //Pop remaining parenthesis

        else if (tokenizedInput.at(i).type == TokenType::OP)
        {
            while (!operatorStack.empty() &&
                    operatorStack.top().type != TokenType::LPAREN &&
                    operatorStack.top().precedence >= tokenizedInput.at(i).precedence &&
                    tokenizedInput.at(i).associativity == 'L')
            {
                postFixExpr.push_back(operatorStack.top().token);
                operatorStack.pop();
            }
            operatorStack.push(tokenizedInput.at(i));
        }
    }

    //Empty out remaining operators
    while (!operatorStack.empty())
    {
        //Error-Handling: Mismatched Parenthesis
        if (operatorStack.top().type == TokenType::LPAREN)
        {
            return {{}, ErrorCode::MISMATCHED_PARENTHESIS};
        }

        postFixExpr.push_back(operatorStack.top().token);
        operatorStack.pop();
    }

    return {postFixExpr, ErrorCode::NONE};
}

//   vector<char> Evaluator () {}

//TODO add more error messages
void ErrorHandler(ErrorCode error)
{
   switch(error)
   {
        case ErrorCode::MISMATCHED_PARENTHESIS:
            cout << "Error: Mismatched parenthesis. " << endl;
            break;
        //No error
        default:
            break;
   }
}

