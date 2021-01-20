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
char* TrimRight(char* str, const char* trimChars);

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
int main(int argc, char **argv)
{
	char commonName[256];
	char organization[256];
	char country[256];

	GetRelativeDistinguishedName("CN", commonName);
	GetRelativeDistinguishedName("O", organization);
	GetRelativeDistinguishedName("C", country);

	printf("\r\nThe Distinguished Name (DN) is: CN=%s, O=%s, C=%s\r\n", commonName, organization, country);

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char *rdnValue)
{
	int result = -1;

	rdnValue[0] = '\0';

	printf("Please enter the value for %s: ", rdnAttribute);
	fgets(rdnValue, 256, stdin);
	if (strlen(rdnValue) > 0 )
	{
		TrimRight(rdnValue, NULL);
		result = 0;
	}


    return result;
}

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
	int i;

	if (trimChars == NULL)
	{
		trimChars = "\t\n\v\f\r ";
	}

	i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL)
	{
		str[i] = '\0';
		i--;
	}

	return str;
}
