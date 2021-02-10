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
//////////////////////////////////////////////////////

/* DistinguishedName is a structure of RDN values. */
typedef struct
{
	char commonName[MAX_RDN_LENGTH];
	char organization[MAX_RDN_LENGTH];
	char country[MAX_RDN_LENGTH];
	char organizationalUnit[MAX_RDN_LENGTH];
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
void PrintDistinguishedName(DistinguishedName* pDN);
int GetRelativeDistinguishedName(char* rdnAttribute, char* rdnDescription, char* rdnValue);


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

	GetRelativeDistinguishedName(RDN_CN, "Common Name", distinguishedName.commonName);
	GetRelativeDistinguishedName(RDN_O, "Organization", distinguishedName.organization);
	GetRelativeDistinguishedName(RDN_OU, "Organizational Unit", distinguishedName.organizationalUnit);
	GetRelativeDistinguishedName(RDN_C, "Country", distinguishedName.country);
	GetRelativeDistinguishedName(RDN_L, "Locality", distinguishedName.locality);
	GetRelativeDistinguishedName(RDN_ST, "State", distinguishedName.state);

	// Call PrintDistinguishedName() to print the DN
	PrintDistinguishedName(&distinguishedName);

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char* rdnAttribute, char* rdnDescription, char* rdnValue)
{
	int result = -1;

	rdnValue[0] = '\0';

	printf("Please enter the value for %s (%s): ", rdnDescription, rdnAttribute);
	fgets(rdnValue, 256, stdin);
	if (strlen(rdnValue) > 0)
	{
		TrimRight(rdnValue, NULL);
		result = 0;
	}

	return result;
}

/******************************************************************************
 *
 * PrintRelativeDistringuishedName()
 *
 * Prints a DN
 *
 *****************************************************************************/
void PrintDistinguishedName(DistinguishedName* pDN) 
{
	char *separator = "";

	// print each attribute that has a value
	printf("\r\nThe Distinguished Name (DN) is: ");
	if (strlen(pDN->commonName) > 0)
	{
		printf("%s=%s", RDN_CN, pDN->commonName);
		separator = ", ";
	}
	if (strlen(pDN->organization) > 0)
	{
		printf("%s%s=%s", separator, RDN_O, pDN->organization);
		separator = ", ";
	}
	if (strlen(pDN->organizationalUnit) > 0)
	{
		printf("%s%s=%s", separator, RDN_OU, pDN->organizationalUnit);
		separator = ", ";
	}
	if (strlen(pDN->country) > 0)
	{
		printf("%s%s=%s", separator, RDN_C, pDN->country);
		separator = ", ";
	}
	if (strlen(pDN->locality) > 0)
	{
		printf("%s%s=%s", separator, RDN_L, pDN->locality);
		separator = ", ";
	}
	if (strlen(pDN->state) > 0)
	{
		printf("%s%s=%s", separator, RDN_ST, pDN->state);
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
