#include "function.h"


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
    vector<Token> postFixExpr;

    for (size_t i = 0; i < tokenizedInput.size(); i++)

    {
        //Check if number, then push to output
        if (tokenizedInput.at(i).type == TokenType::NUM) 
        {
            postFixExpr.push_back(tokenizedInput.at(i));
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
                postFixExpr.push_back(operatorStack.top());
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
                postFixExpr.push_back(operatorStack.top());
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

        postFixExpr.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return {postFixExpr, ErrorCode::NONE};
}


