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
	char commonName[MAX_RDN_LENGTH];
	char organization[MAX_RDN_LENGTH];
	char organizationalUnit[MAX_RDN_LENGTH];
	char country[MAX_RDN_LENGTH];
	char locality[MAX_RDN_LENGTH];
	char state[MAX_RDN_LENGTH];
	char distinguishedName[MAX_RDN_LENGTH * 6];
	char *pNamePos;
	char *separator="";

	GetRelativeDistinguishedName(RDN_CN, "Common Name", commonName);
	GetRelativeDistinguishedName(RDN_O,"Organization",  organization);
	GetRelativeDistinguishedName(RDN_OU, "Organizational Unit", organizationalUnit);
	GetRelativeDistinguishedName(RDN_C, "Country", country);
	GetRelativeDistinguishedName(RDN_L, "Locality", locality);
	GetRelativeDistinguishedName(RDN_ST, "State", state);

	// Initialize the DN to zero length
	distinguishedName[0] = '\0';

	// print each attribute that has a value
	printf("\r\nThe Distinguished Name (DN) is: ");
	if (strlen(commonName) > 0)
	{
		printf("%s=%s", RDN_CN, commonName);
		separator = ", ";
	}
	if (strlen(organization) > 0)
	{
		printf("%s%s=%s", separator, RDN_O, organization);
		separator = ", ";
	}
	if (strlen(organizationalUnit) > 0)
	{
		printf("%s%s=%s", separator, RDN_OU, organizationalUnit);
		separator = ", ";
	}
	if (strlen(country) > 0)
	{
		printf("%s%s=%s", separator, RDN_C, country);
		separator = ", ";
	}
	if (strlen(locality) > 0)
	{
		printf("%s%s=%s", separator, RDN_L, locality);
		separator = ", ";
	}
	if (strlen(state) > 0)
	{
		printf("%s%s=%s", separator, RDN_ST, state);
	}

	printf("\n\n");

	return 0;
}

/*****************************************************
 *
 * AddRelativeDistinguishedName
 *
******************************************************/
void AddRelativeDistinguishedName(char* rdnAttribute, char* rdnValue)
{

}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char* rdnDescription, char *rdnValue)
{
	int result = -1;

	printf("Please enter the value for %s (%s): ", rdnDescription, rdnAttribute);
	fgets(rdnValue, MAX_RDN_LENGTH, stdin);
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
