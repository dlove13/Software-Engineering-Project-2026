# 04-20 Meeting Notes

###### Time : 4pm - 4:30pm

###### Location: Discord Call

###### Purpose: Talk about Shunting Yard Algorithm implementation

###### Attendance : Liam, Connor, Landrie, Christian, Davina



Implement using Shunting Yard Algorithm

Pros: Already implemented in most compilers, don't need to worry about parenthesis when evaluating

Cons: New concept, personally I've never heard of it before so understanding it will probably be the biggest challenge. Implementing error handling might be difficult as well.

Main point is to convert a user input infix expression into a post fix expression that can be evaluated using stacks. Below is the table showing operator precedence.



u- (\~), u+    4    R

^    3    R

,/,%    2    L

+,-    1    L

(,)    0    NA



Associativity tells the algorithm which way to read the expression.



Tokenizer: Map the operator precedence and associativity. Parse Strings into vector of chars. Distinguish char as Int, Whitespace, Operator, Left parenthesis, right parenthesis, or unary.

&#x20;   Idea: Create a Token class with members: token: char, type: string, associativity: char

&#x20;   Output: Vector of chars

Possible Errors: Invalid Characters



Parser: Implement Shunting Yard Algorithm ( Refer to this video for context: https://www.youtube.com/watch?v=Jd71l0cHZL0 )

&#x20;   Output: Vector of char in post-fix notation

&#x20;       Example: Infix expression 8 - 2 + (3 \* 4) / 2 ^ 2

&#x20;           Postfix expression 8 2 - 3 4 \* 2 2 ^ / +

Possible Errors: No matching parenthesis



Evaluator: Evaluate post fix expression using operator stack

&#x20;       -Scan vector left to right using a stack to store operands

&#x20;       -When operator is encountered, pop operands from stack and perform operation

&#x20;       \*Unary pops only one operand and performs operation



&#x20;   Output: Result as an Int

Possible Errors: Not enough Operands, Not enough Operators, Division by 0, etc. 





This will probably be the most collaborative part of the project so far, since it will be difficult to assign specific parts to people.



When implementing something, be sure to work on the correct branch and update the remote. Then create a pull request to push it up to main once there are no errors. 



All the branches are already setup on github, do the 'git switch <branchname>' command to get the branch and the local will automatically connect with the remote.



