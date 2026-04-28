#include "function.h"


void Display() {


    Display_Menu();

}


void Display_Menu () {

    cout << "Display is running..." << endl;

    cout << "\n0) Exit Program " << endl;
    cout << "1) Execute Arithmetic Expression Evaluator (Not Implemented)" << endl;
    cout << "2) Run Unit Tests" << endl;
    cout << "\nEnter 0, 1, or 2: ";

}

char userMenuChoice() {
    char inputBuf;

    cin >> inputBuf; 

    return inputBuf;
}


//vector<char> Tokenizer () {}
vector<char> Parser (vector<Token> tokenizedInput) {
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
    vector<char> postFixExpr;

    for (size_t i = 0; i < tokenizedInput.size(); i++)

    {
        //Check if number, then push to output
        if (isdigit(tokenizedInput.at(i).token)) 
        {
            postFixExpr.push_back(tokenizedInput.at(i).token);
        }
        //Push left parenthesis onto operator stack
        else if (tokenizedInput.at(i).token == '(')
        {
            operatorStack.push(tokenizedInput.at(i));
        }
        //Pop operators from stack and add to output until next left parenthesis
        else if (tokenizedInput.at(i).token == ')')
        {
            while (!operatorStack.empty() && operatorStack.top().token != '(')
            {
                postFixExpr.push_back(operatorStack.top().token);
                operatorStack.pop();
            }

            if (!operatorStack.empty()) 
            {
                operatorStack.pop();
            } 
            else 
            {
                //Error-Handling: Mismatched Parenthesis
            }

            //Pop remaining parenthesis
        }

        else if (tokenizedInput.at(i).token == '+' ||
                tokenizedInput.at(i).token == '-' ||      
                tokenizedInput.at(i).token == '/' ||
                tokenizedInput.at(i).token == '*' 
                )
        {
            while (!operatorStack.empty() &&
                    operatorStack.top().token != '(' &&
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
        try {

            if (operatorStack.top().token == '(')
            {
                //Error_Handler: Mismatched Parenthesis
                throw runtime_error("Mismatched parenthesis.");
            }
        }

        catch (const runtime_error& e)
        {
            cerr << "Error: " << e.what() << endl;
        }


        postFixExpr.push_back(operatorStack.top().token);
        operatorStack.pop();
    }

    return postFixExpr;
}

//   vector<char> Evaluator () {}

// int Error_Handler () {}


