#include "function.h"

//vector<char> Evaluator () {}

EvaluatorResult Evaluator(ParserResult parserOutput) {

    //check if error, if so, return immediately
    if (parserOutput.error != ErrorCode::NONE) {
        return {{}, parserOutput.error};
    }

    //init container
    stack<double> evalStack;

    for () //placeholder
    
    {
        if (something == TokenType::NUM)
        {
            evalStack.push(stod(something));
        }
        else if (something == TokenType::OP) 
        {
            
        }
    }

}
