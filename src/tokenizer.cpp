#include "function.h" 
TokenizerResult Tokenizer (string input) {

    vector<Token> tokens; // stires tokens via vector

    for (size_t i = 0; i < input.size(); i++) { // iterate through input string
        char c = input[i];

        if (c != ' ') {

            if (isdigit(c) || c == '.') { // evaluate numbers in one token including decimal
                string numStr;

                bool doubledot = false;

                while (i < input.size() && (isdigit(input[i]) || input[i] == '.')) {

                    if (input[i] == '.') {
                        if (doubledot) {
                            return {{}, ErrorCode::INVALID_SYNTAX}; 
                        }

                        doubledot = true;
                    }

                    numStr += input[i];
                    i++;
                }

                i--; // Step back to re-evaluate the last character
                tokens.push_back(Token(numStr));
                continue;
            }  

            if (c == '*' && i + 1 < input.size() && input[i + 1] == '*') {// check for exponent operator
                tokens.push_back(Token("**", 3, 'R',TokenType::OP));
                i++;
                continue;
            } 

            if ( c == '*' || c == '/' || c == '%') { // check for multiplication, division, and modulus operators
                tokens.push_back(Token(string(1, c), 2, 'L',TokenType::OP));
                continue;
            } 

            if (c == '(') { // left parentheses
                tokens.push_back(Token(string(1, c),TokenType::LPAREN));
                continue;

            }
            if (c == ')') { // right parentheses
                tokens.push_back(Token(string(1, c),TokenType::RPAREN));
                continue;
            } 

            if (c == '-') {

                //check for the three valid unary - cases
                bool valid = tokens.empty() || 
                    tokens.back().type == TokenType::OP || 
                    tokens.back().type == TokenType::LPAREN;

                if (valid) {
                    string numStr = "-";
                    i++;

                    //skip whitespace
                    while (i < input.size() && input[i] == ' ') i++;

                    if (i < input.size() && (isdigit(input[i]) || input[i] == '.')) {
                        bool doubledot = false;
                        while (i < input.size() && (isdigit(input[i]) || input[i] == '.')) {
                            if (input[i] == '.') {
                                if (doubledot) {
                                   return {{}, ErrorCode::INVALID_SYNTAX}; 
                                }
                                doubledot = true;
                            }
                            numStr += input[i];
                            i++;
                        }
                        i--; // Step back to re-evaluate the last character
                        tokens.push_back(Token(numStr)); // e.g. "-3.14" as a NUM token
                    } else {
                        // '-' was not followed by a number — invalid
                        return {{}, ErrorCode::INVALID_SYNTAX};
                        
                    }
                } else {
                    tokens.push_back(Token(string(1, c), 1, 'L', TokenType::OP));
                }
                continue;
            } 

        if (c == '+') {
            tokens.push_back(Token(string(1, c), 1, 'L',TokenType::OP));
            continue;
        }
        return {{}, ErrorCode::INVALID_SYNTAX}; 
    }
}

return {tokens, ErrorCode::NONE};
}
