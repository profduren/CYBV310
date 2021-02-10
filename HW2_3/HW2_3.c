
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
	/* sizeof gives us the number of bytes that each type takes up in memory */
	printf("sizeof(char) = %u\n", sizeof(char));
	printf("sizeof(unsigned char) = %u\n", sizeof(unsigned char));
	printf("sizeof(short) = %u\n", sizeof(short));
	printf("sizeof(unsigned short) = %u\n", sizeof(unsigned short));
	printf("sizeof(int) = %u\n", sizeof(int));
	printf("sizeof(unsigned int) = %u\n", sizeof(unsigned int));
	printf("sizeof(long) = %u\n", sizeof(long));
	printf("sizeof(unsigned long) = %u\n", sizeof(unsigned long));
	printf("sizeof(float) = %u\n", sizeof(float));
	printf("sizeof(double) = %u\n", sizeof(double));
	return 0;
}
