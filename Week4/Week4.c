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
#define MAX_BUFFER_SIZE 256
#define SQR(A) (A*A)


///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////



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
int main(int argc, char *argv[])
{

	int intValue = 5;

	int *pIntValue = &intValue;

	unsigned long valuePIntValue = (unsigned long)pIntValue;

	*pIntValue = 10;

	return 0;
}

