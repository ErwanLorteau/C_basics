/** Minimal subset of code to run a program **/
#include <stdio.h>
#include <string.h> 

int main(void) {
  //Alternative  -- int main(int argc, char *argv[])
  printf("Hello World\n"); // /n = Line return, /t = tab
  return 0;
}

/**Basics (declare, input, operators, shortcut, loops, cases ) **/ 
void declareVariable () {
  int anInt ; 
  unsigned int aPositiveInteger ; 
  float aFloatingPointNum ; 
  double aDoubleSizedFloatingPointNumber ; 
  char aChar ; 
}



void declareArray() {
  //Decalre
  int array[4] ; 

  //Iinitialize
  int secondArray    = { 1, 2 , 3 , 4 } ; 
  int thirdArray[4]  = { 1, 2 } ;        // = [ 1, 2 , 0, 0 ] USEFULL FOR INIT
  int fourthArray[4] = { 0 } ;           // { 0, 0, 0, 0} ; 
  int fifthArray[4]  = { 1 } ;           // {1, 0, 0, 0} 
  int sixthArray[]   = { 2, 3 ,9 ,10 } ; //Compiler deduce the size of the array
  
  //int array[someVar (even const one)] are not supported by every compiler so avoid it

  /**Explanation
  array is a pointer to the first case in the array
  An array is contingous in memory
  *array = array[0]
  *(array +1 ) = array[1]
**/
}

void useArray(int* array, int arraySize) {
  //...Do something
  //The point is, array are pointer, so the parameter is int*
  //Also possible to use int array[] as parameter
}

void useChar() {
  //Declare
  
  //Remember that the variable are always int in th end, the type just give an interpretation
  char aChar = 'a' ; 
  char aSecondeOne = -25 ; //Interpreted with the ASCII table   
  char aString[3] = {'H', 'I', '\0'} ;  //A STRING ALWAYS END WITH \0, so there is no need to know the size of the array
  char anotherString[] = "HI" ; 
  char *ThirdWay = "HI" ; //The compiler automaticly understand that we want an array of size "HI" (2)
  printf("%d", aString) ; //Print 'HI'

  /**Ask an input**/
  char name[100];
  printf("Name ? ");
  scanf("%s", name);
  printf("Erwan", name);
}


#include <string.h> 
void useStringLibrary () {
  char* s  = "Hello" ; 
  char* s2 = "Goodbye" ; 
  strlen(s)     ; //length of the string
  strcpy(s, s2) ; //copy s in s2, beware of the /0 char and the size of the arr
  strcat(s, s2) ; //concat s1 and s2
  strcmp(s,s2) ;  // compare
  //A bunch of other function are available 
  //more details : https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/7672681-manipulez-du-texte-avec-les-chaines-de-caracteres
}



void displayVariable() {
  int aInteger = 15 ; 
  printf("You have %d point", aInteger) ;
  //For each type, change the %d to the corresponding letter for the given type
  //If you want to display several variable, just follow the order
}

void AskInput () {
  int input ; 
  scanf("%d", &input) ; 
  //Also depend on the type of the variable
}

void divide() {
  int result = 5/2 ;  // = 5 ! 
  int result2 = 5.0/2.0 ;  //= 2.5
  int result3 = 0 ; 
  result3 += 2 ; //shortcut, work with every basic operator  
}

#include <math.h>
void mathLibrary() {
 //Need the include !  
  int result = pow(5,2) ; 
  //A bunch of other stuff exist in the standart library
}

#include <stdbool.h>
void logicOperator () {
  bool a, b, c ; 
  bool result = a && b ; 
  result = a || b ; 
  result = ! c ; 
  //Bunch of other operator exist
}

//Case exemple (for and if alse not shown here)
void caseSyntax () {
  int a ; 
  switch(a) {
    case 1 :  
    //do something
    break ; 
  
    case 15 : 
    // 
    break ;
    }
  //Don't use break if you want to cover several cases
}

#include <time.h> 
void generateRandom() {   
  int randomNumber = rand() %20 ;  // (0-19) 
  //Don't use this for secure key generation
  //Rand() generate a number between 0 and RAND_MAX, either use modulo or setup the seed
}


/***Includes and scope of the functions****/

//To use a function anywhere in the file, without having to put the function code before the function call, add this following pre-declaration (modular programming)
void conditionalShortcut() ; 


void conditionalShortcut() {
  //No need for {} if there is only one intruction after
  int age = 0 ; 
  bool majeur = true ; 
  if (majeur) 
    age = 18 ; 

  //Ternair condition
  age = (majeur) ? 18 /**true**/ : /**false**/ 17 ;
}

//Call a function from an header (see the attached files for explanation)
#include "header_explanation.h" ; 

void callOutsideFunction() {
  firstFunction() ; 
}

/****Global / statics variable and function***/ 

int global ; //Accessible from every file
static int fileGlobal ; //Accesible from this file only

//Static varaible inside a function
int staticExemple() {
  int static staticExempleVar = 0 ; 
  staticExempleVar++ ;   
}

/**
  *Next call of staticExemple(), staticExemple will still exist (and have the same value)
  *The variable isn't deleted after the function call
  *Next call will "jump" the declaration line
  *First call : var = 1, second call, var = 2 and so on
**/


//static function
//If not precised, a function can be called in every file
//if static, can only be called in the file. Don't forget to update the prototype too

static int afunction (int a) {
  //
}

/**Explanation for pointer, heap and stack**/

/**
  **Reminder**

  *Pointer is the adress of a var.
  *Heap contain dynamic variable, stack locals one

 **The problem**

 *When a fct is called, it copy the arguments inside the frame of the function (alloted memory)
 *The parameter your are using inside the fct ARE JUST COPYS
 *If you have only one value, you can return the value
 *If you need to return several value, you have two choice : use pointers as parameter and moddify the value inside the function using the adress of the parameter, or allocate memory (almost the same)

 **How it work behind the scene**
 *WHen a function is called, it create a frame in the memory that is destroyed after the call
 *If you declare a local variable inside the function, it will be inside the frame, and the frame will be     destroyed after the call, so the var too.
 
/**General advices**
 *If you use dynamic allocation, the var still remain after the call inside the heap
 *So don't forget to FREE the memory
 *Good practice is to RETURN the value, and free the value INSIDE the function to avoid memory leaks*
 *The return value of a function is destroyed at the same time than the frame but can be copy before (savedreturnValue = functionCall(...) )
*/

void pointerSyntax() {
  //Display an adress
  int anInteger ; 
  printf( "The adress is %p" , &anInteger) ; 
  

  //Declaration : 
  int* integerPointer ;  //Btw you have to precise the type of the pointed variable
  //Initlizaion (good practice) 
  integerPointer = NULL ; 
  
  //Exemple : 
  int anInt =  1 ; 
  int* anIntPointer = NULL ;
  anIntPointer = &anInt ; //Adress of the variable = &var 
  *(anIntPointer) = 5 ;  //Access memory at the adress of the *(var)

  printf(" The value pointed by the pointer is : %d" , *anIntPointer ) ; 

  //Reminder : int* p declare a local variable in the frame of the function pointerSyntax inside the stack
  //The memory allocated is made to stock an pointer (hexadecimal adress)
}

//Typycal case : 

//Here, the value passed is a pointer, the parameter is still a copy but it's an adress so at the end 
void modify( int* a, int* b) {
  *(a) = 5 ; 
  *(b) = 10 ; 
}

void referenceParameter () {
  int a = 0, b  = 0 ; 
  int* pa = NULL , pb = NULL ; 
  modify(pa,pb) ; 
  //Here, a / b have been modified
}

/**MACROS**/
//Macros are keyword which the compiler gonna replace by what you've defined 
//It's used to change quickly a parameter in severals function
#define SIZE_ARRAY 10 

#define height 1080
#define width 1920 
#define nbPixel (height * width)  
//See that as a string replcement for the compiler, it can be anything
//Defaults "preprocessing" instruction are __PATH__ __FILE__ __DATE__ __LINE__

//It's also possible to define function with macro
#define HI() printf("Hi"); \
             printf("My name is Erwan")

//Macro with parameter
#define legalAge(age) if (age >= 18) printf ("LegalAge") ;

//Additionnal stuff
#define LINUX
//Here no replacement value is assigned, yet we can now use that to compile only the code needed
#ifdef LINUX
//code to compile
#endif


void processor_directive() {
  int* array[SIZE_ARRAY] ; 
  int* arrayPixel[nbPixel] ; 
  legalAge(18) ; 
}

//Most of the time, returns are used to send an error code (1) or a success code (0), not a value 


/****CUSTOM TYPES***/
//Creation --> see in datastructure.H
#include "datastructure.h" 



void changeCoordinate(Coordinate* ptr) {
  ptr->x = 999 ;
  ptr->y = 998 ; // ptr->x = *(ptr).x
  (*ptr).x = 999; // and not *ptr.x = 999 
}

void useStructure() {
  Coordinate c ; 
  c.x = 10 ;
  c.y = 20 ; 
  //Other way to initilize : 
  Coordinate c2 = {10, 20} ; 
  //if used in any function, use a pointer on the struct, otherwise just the copy wil be modified
  Coordinate *c_ptr = &c ;
  changeCoordinate(c_ptr) ;
  
}

//Same thing, decalration in headers
//Enum can take one value in the given set. it's in one memory case, and cannot contain object
void useEnumeration() {

  typedef enum Volume Volume ; 
  enum Volume {
  LOW, MEDIUM, HIGH
  } ; 

  Volume v = LOW ; 
  if (v == LOW) {
    //
  }
  //Usefull to make you'r code easy to maintain/read
}

/**File input / output***/

void useFile() {
  //Open a file And get the result (pointer on the new file)
  
  // FILE* FILENAME = FILE* fopen(const char* ../text.txt, const char* openMod );*
    /**
  open mod : read : r
             write : w
             add : a
             add at the end : a+
             read/write : r+
             read/write over the previous : w+
    **/

  //The file must be in the same directory than the .exe, otherwise wrtie the path
  //then use the pointer to manipulate the file
  }
