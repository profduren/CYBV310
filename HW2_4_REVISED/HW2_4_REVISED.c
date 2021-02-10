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
	RDN_MAX // number of rdn types
} RDN_TYPE;

char* rdnAttributes[RDN_MAX] = { "CN", "O", "OU", "C", "L", "S" };
char* rdnDescriptions[RDN_MAX] = { "Common Name",
							"Organization",
							"Organizational Unit",
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
	int count;
	RelativeDistinguishedName *rdnTypeValues[RDN_MAX];
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
void PrintDistinguishedName(DistinguishedName* pDN);
RelativeDistinguishedName* GetRelativeDistinguishedName(RDN_TYPE rdnType);


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
	DistinguishedName distinguishedName;
	RelativeDistinguishedName* pRdn;
	int i;

	// initialize the disinguishedName structure
	memset(&distinguishedName, 0, sizeof(distinguishedName));

	for (i = 0; i < RDN_MAX; ++i)
	{
		if ((pRdn = GetRelativeDistinguishedName(i)) != NULL)
		{
			distinguishedName.rdnTypeValues[distinguishedName.count++] = pRdn;
		}
	}

	// Call PrintDistinguishedName() to print the DN
	PrintDistinguishedName(&distinguishedName);

	// free the memory allocated by GetRelativeDistinguishedName
	for (i = 0; i < distinguishedName.count; ++i)
	{
		free(distinguishedName.rdnTypeValues[i]);
	}

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
RelativeDistinguishedName *GetRelativeDistinguishedName(RDN_TYPE rdnType)
{
	RelativeDistinguishedName* pName = NULL;
	char value[MAX_RDN_LENGTH];

	printf("Please enter the value for %s (%s): ", rdnDescriptions[rdnType], rdnAttributes[rdnType]);
	if (fgets(value, MAX_RDN_LENGTH, stdin) != NULL)
	{
		TrimRight(value, NULL);

		if (strlen(value) > 0)
		{
			/* We have a value, allocate an RDN and return it. */
			pName = malloc(sizeof(RelativeDistinguishedName));
			pName->type = rdnType;
			strcpy_s(pName->value, MAX_RDN_LENGTH, value);
		}
	}
	return pName;
}

/******************************************************************************
 *
 * PrintRelativeDistringuishedName()
 *
 * Prints a DN
 *
 *****************************************************************************/
void PrintDistinguishedName(DistinguishedName *pDN)
{
	char* separator = "";

	printf("\r\nThe Distinguished Name (DN) is: ");

	for (int i = 0; i < pDN->count; ++i)
	{
		printf("%s%s=%s", separator, rdnAttributes[pDN->rdnTypeValues[i]->type], pDN->rdnTypeValues[i]->value);
		separator = ", ";
	}
	printf("\n\n");
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
