#include "function.h"

//vector<char> Evaluator () {}

EvaluatorResult Evaluator(ParserResult parserOutput) {

    //check if error, if so, return immediately
    if (parserOutput.error != ErrorCode::NONE) {
        return {{}, parserOutput.error};
    }

    //init container
    stack<double> evalStack;

    for (size_t i = 0; i < parserOutput.output.size(); i++) 
    
    {
        //Check if number, then push to evalStack, stod converts from string to double
        if (parserOutput.output.at(i).type == TokenType::NUM)
        {
            evalStack.push(stod(parserOutput.output.at(i).token));
        }

        //Check if operator
        else if (parserOutput.output.at(i).type == TokenType::OP) 
        {
            //pop right and left operands
            double right = evalStack.top();
            evalStack.pop();
            double left = evalStack.top();
            evalStack.pop();

            if (parserOutput.output.at(i).token == "+")
            {
                evalStack.push(left + right);
            }

            else if (parserOutput.output.at(i).token == "-")
            {
                evalStack.push(left - right);
            }
            
            else if (parserOutput.output.at(i).token == "*")
            {
                evalStack.push(left * right);
            }
            
            else if (parserOutput.output.at(i).token == "/")
            {
                if (right == 0.0)
                {
                    return{{}, ErrorCode::DIVIDE_BY_ZERO};
                }
                evalStack.push(left / right);
            }
            
            else if (parserOutput.output.at(i).token == "%")
            {
                if (right == 0.0)
                {
                    return{{}, ErrorCode::DIVIDE_BY_ZERO};
                }
                //fmod required for mod operations on doubles
                evalStack.push(fmod(left, right)); 
            }
            
            else if (parserOutput.output.at(i).token == "**")
            {
                //pow takes two doubles, executes exponentiation
                evalStack.push(pow(left, right));
            }
        }
    }

    return {evalStack.top(), ErrorCode::NONE};
}
