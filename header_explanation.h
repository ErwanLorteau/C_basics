//Declare you'r function as prototype here

void firstFunction() ; 
void secondFunction(int a) ; 

//Then, decalre the body inside the header_explanation.c

/***
Explanation : 
 Case 1 : You don't mind and you just put everything in the same file
  Case 2 : You have a lot of function, then ; 
    -Create couple of header/.c files
    -Write the prototype inside the header, the body inside the c file
    -Include the h file, or a specific function where you want to use thios function (in any file)

---TO CALL A FUNCTION, YOU NEED TO INCLUDE THE PROTYPE IN A HEADER, ITS A GENERAL RULE
#include "myHeaderFile.h" in main.c for exemple

Info : standat library are already compiled inside you'r ide, but you can still look at the body of the function in the lib folder
**/


/**
  Doing and include mean that in order to compile the current file you need to compile the other one
if you need to include an header A inside a file B and also B in A, it's gonna loop. To avoid that ALWAYS use this syntax 

#define DEF_FILENAME.h
  #ifndef DEF_FILENAME.h
  all the .h code
#endif

so it's only compiled once
**/


