/*****************************************************
 * Demonstration for week 2
 * Author:  Michael J Duren
 * Demonstrating the use of strings
******************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




void PrintDN()
{
	char *commonName = "CN=Michael";
	char *organization = "O=UA";
	char *country = "C=US";
	char *distinguishedName;

	distinguishedName = malloc(strlen(commonName) + strlen(organization) + strlen(country) + 1);
	sprintf(distinguishedName, "%s, %s, %s", commonName, organization, country);
	free(distinguishedName);

	printf("%s", distinguishedName);

}
