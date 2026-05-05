#include "function.h"

//TODO add more error messages
void ErrorHandler(ErrorCode error)
{
   switch(error)
   {
        case ErrorCode::MISMATCHED_PARENTHESIS:
            cout << "Error: Mismatched parenthesis. " << endl;
            break;
        
        case ErrorCode::DIVIDE_BY_ZERO:
            cout << "Error: Divide by 0" << endl;
            break;

        case ErrorCode::INVALID_SYNTAX:
            cout << "Error: Invalid syntax." << endl;
            break;      
        case ErrorCode::ADJACENT_OPERATORS:
            cout << "Error: Adjacent operators detected." << endl;
            break;
        case ErrorCode::INVALID_EXPRESSION:
            cout << "Error: Invalid Expression." << endl;
            break;
        //No error
        default:
            break;
   }
}
