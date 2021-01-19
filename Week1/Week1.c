/*****************************************************
 * Demonstration for week 1
 * Author:  Michael J Duren
 * This program reads a table of aquarium fishes from
 * a file and displays the information to the user.
******************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME                128
#define MAX_SCIENTIFIC_NAME     128
#define MAX_DESCRIPTION         1024

// structure that is used to hold table information in memory
typedef struct {
	char name[MAX_NAME];
	char scientificName[MAX_SCIENTIFIC_NAME];
	char description[MAX_DESCRIPTION];
}  IchthyThing;

// global table of IchthyThings in Mr. Duren's reef tank
IchthyThing tankSpecies[64];
int tankSpeciesCount = 0;

void ReadTable(char* filename);
char* TrimRight(char* str, const char* trimChars);

int main(int argc, char* argv[])
{
	int selection;

	/* Did the user specific arguments? */
	if (argc == 2)
	{
		ReadTable(argv[1]);

		while (1)
		{
			printf("\nMr. Duren has %d different species in his reef tank.\n\n", tankSpeciesCount);
			for (int i = 0; i < tankSpeciesCount; ++i)
			{
				printf("%d. %s\n\n", i + 1, tankSpecies[i].name);

			}

			printf("Enter a number to learn more about one of the species (enter 0 to quit): ");
			scanf_s("%d", &selection);
			printf("\n");

			if (selection == 0)
			{
				break;
			}
			else
			{
				printf("Name:            %s\n", tankSpecies[selection - 1].name);
				printf("Scientific Name: %s\n", tankSpecies[selection - 1].scientificName);
				printf("Description:     %s\n", tankSpecies[selection - 1].description);
			}
			printf("\nPress enter to return to the menu.");
			fflush(stdin);
			getchar();
			printf("\n\n");

		}


	}
	else
	{

	}
	return 0;
}


int ParseLine(IchthyThing *pThing, char* line)
{
	int i = 0;
	int result = 0;
	int num_quotes = 0;
	char* token;

	token = strtok(line, ",");
	if (strlen(token) > 0)
	{
		strncpy(pThing->name, token, MAX_NAME);
		token = strtok(NULL, ",");
		if (strlen(token) > 0)
		{
			strncpy(pThing->scientificName, token, MAX_SCIENTIFIC_NAME);
		}
		token = strtok(NULL, ",");
		if (strlen(token) > 0)
		{
			strncpy(pThing->description, token, MAX_DESCRIPTION);
		}
	}
	return result;
}

/******************************************************************************
 *
 * ReadTable()
 *
 * Reads table if fishes from a file and populate an array of IchthyThing types
 *
 *****************************************************************************/
void ReadTable(char* filename)
{
	// pointer to the opened file
	FILE* pTableFile = NULL;

	// used to index the array of table entries
	int index = 0;

	// declare a buffer that is large enough to hold a complete entry plus any delimiters
	char dataBuffer[MAX_NAME + MAX_SCIENTIFIC_NAME + MAX_DESCRIPTION + 4];

	// Open the file
	fopen_s(&pTableFile, filename, "r");

	/* Make sure the file is open. */
	if (pTableFile == NULL)
	{
		printf("Input file not found or could not be accessed.");
	}
	else
	{
		while (fgets(dataBuffer, sizeof(dataBuffer), pTableFile) != NULL)
		{
			TrimRight(dataBuffer, NULL);
			ParseLine(&tankSpecies[index], dataBuffer);
			++index;
		}
		// save this value to the global count variable
		tankSpeciesCount = index;
	}
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

