#include "function.h"

/*Define unit tests for each individual t*/

//Parser Test
vector<char> test_expression_1 = {'3', '+', '4'};
vector<char> test_expression_2 = {}
vector<char> test_expression_3 = {}
vector<char> test_expression_4 = {}
vector<char> test_expression_5 = {}


vector<Token> parser_test_1;

void UnitTests ()
{
    for (size_t i = 0; i < test_expression_1.size(); i++){
        Token newToken;
        newToken.token = test_expression_1.at(i);

        parser_test_1.push_back(newToken);
    }

    //Test Print vector
    for (size_t i = 0; i < parser_test_1.size(); i++)
    {
        cout << parser_test_1.at(i).token << endl;
    }

}

