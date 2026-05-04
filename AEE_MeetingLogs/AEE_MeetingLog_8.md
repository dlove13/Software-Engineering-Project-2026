Date: 04 May 2026

Time: 04:00pm - 04:20pm

Location: Discord Call

Purpose: Delegate duties for implementation

Attendance: Caden, Liam, Connor, Christian, Davina, Landrie



###### Connor 

Continue working on your preprocessor and push your code into the tokenizer branch so that Liam will be able to use it in the tokenizer. If there is a way to optimize the error handling code, go ahead and make your changes in the error\_handling branch.



###### Landrie

Implement Display using the current display functions, feel free to add more. If there is invalid input, the display should basically 'refresh' 	  the page and prompt the user for input again. If an error is encountered at any part of the pipeline, the user should be brought to the very 		  beginning of the pipeline and prompted for a valid input. Each part of the pipeline should have a member variable *error* that if it doesn't equal NONE then an error is encountered, so you could probably use that as a flag to know to send the user back to the beginning.



###### Liam 

Utilize Connor's preprocessor for the tokenizer. Also for the token member variables, check the Software Architecture document (updated a few 	hours ago) for more guidance on how associativity and operator precedence is defined so the tokens will be properly utilized in the parser. Maybe add a another member variable to track if there is an error similar to the ParserResult and EvaluatorResult structs so that the UI will be able to tell if there is an error happening in the tokenizer?



###### Christian

Implement the evaluator using the ParserResult as the input. Use the struct EvaluatorResult as the output so that an error code can also be 	    stored as the output.



###### Caden

Complete the Deliverable 4 and 5 documents and write unit-tests for each component. Once the individual component's unit\_test is finished, implement a RUN\_TEST for each and put it in the Unit\_Tests() function at the bottom of the unit\_tests.cpp file. The main function will call this function to run all the unit tests. 

*Do not use previous components to write test cases*. Refer to the parser test case in the unit\_tests.cpp file for reference. 





If there are any issues, please reach out in the Discord group chat. 





##### TLDR;

**Duties :**

Landrie: Display, UI

Christian: Evaluator

Connor: Currently working on preprocessor, Error Handler

Liam: Tokenizer

Caden: Fill out documentation and write more unit tests for each component









