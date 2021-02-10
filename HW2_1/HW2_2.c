
/*****************************************************
 *
 * Author:  CYBV310 Students and Instructor
 *
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////
void OneThree();


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char** argv)
{
	printf("Starting: \n");
	OneThree();
	printf("Done");
	return 0;
}


/*****************************************************
*
*  Two()
*
*   Prints two
*
*****************************************************/
void Two()
{
	printf("two\n");
}


/*****************************************************
*
*  OneThree()
*
*   Prints one, calls two(), prints three
*
*****************************************************/
void OneThree()
{
	printf("One\n");
	Two();
	printf("three\n");

}
