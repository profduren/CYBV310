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
#define MAX_RDN_LENGTH     256
#define RDN_CN   "CN"
#define RDN_C    "C"
#define RDN_O    "O"
#define RDN_OU   "OU"
#define RDN_L    "L"
#define RDN_ST   "ST"

///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

/* Zero-based offset, used as an index into the
   descriptive text array. */
typedef enum
{
	RDN_COMMON_NAME = 0,
	RDN_ORGANIZATION,
	RDN_ORGANIZATION_UNIT,
	RDN_COUNTY,
	RDN_LOCALITY,
	RDN_STATE,
	RDN_COUNT // number of rdn types
} RDN_TYPE;

char* rdnAttributes[RDN_COUNT] = { "CN", "O", "OU", "C", "L", "S" };
char* rdnDescriptions[RDN_COUNT] = { "Common Name",
							"Organization",
							"Organization Unit",
							"County",
							"Locality",
							"State" };

/* Attribute type and value for the RDN. */
typedef struct
{
	RDN_TYPE type;
	char value[MAX_RDN_LENGTH];
} RelativeDistinguishedName;

/* DistinguishedName is a structure of RDN values. */
typedef struct
{
	char commonName[MAX_RDN_LENGTH];
	char organization[MAX_RDN_LENGTH];
	char country[MAX_RDN_LENGTH];
	char organizationUnit[MAX_RDN_LENGTH];
	char locality[MAX_RDN_LENGTH];
	char state[MAX_RDN_LENGTH];
} DistinguishedName;

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
	DistinguishedName distinguishedName;

	GetRelativeDistinguishedName(RDN_CN, "Common Name", distinguishedName.commonName);

	// TODO: Collect the remaining RDN values


	// Call PrintDistinguishedName() to print the DN

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char* rdnDescription, char *rdnValue)
{
	int result = -1;

	rdnValue[0] = '\0';

	printf("Please enter the value for %s (%s): ", rdnDescription, rdnAttribute);
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
