/*
* File name: DisneyCharacter.cpp
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: Feb 5th 2023
* Description: This file contains all of the methods definition for the class 'DisneyCharacter'.  It contains 2 constructors, 
*				4 accessors, 2 mutators, and 2 public methods: one displaying all details of a character, and another placing 
*				the character at a particular park location, given an abbreviation of a location as input.
*/

#include "DisneyCharacter.h"

//4 paratermeter constructor 
DisneyCharacter::DisneyCharacter(char* newName, char* newCreationDate, int newNumMovies, char newWhichPark)
{
	//validate name 
	strncpy(name, newName, kName);
	clearN(name);
	int len = (int)strlen(name);
	// if name is longer than 50, truncate to 46, append "..."
	if (len > kName - 1)
	{
		char* pModify = name;
		pModify += kTrunc;
		strcpy(pModify, "...\0");
	}
	
	//validate creationDate 
	clearN(newCreationDate);
	bool valid = true;
	len = (int)strlen(newCreationDate);
	//check length and content 
	if (len == kDate - 1)
	{
		for (int i = 0; i < kDate - 1; i++)
		{
			char check = newCreationDate[i];
			if ((i == kDash || i == kDash2) && check != '-')
			{
				valid = false;
				break;
			}
			else if ((i != kDash && i != kDash2) && (isdigit(check) == 0))
			{
				valid = false;
				break;
			}
		}
	}
	else
	{
		valid = false;
	}

	// if valid, copy input to creationDate, if not, set it as blank (null) 
	if (valid)
	{
		strcpy(creationDate, newCreationDate);
	}
	else
	{
		strcpy(creationDate, kNul);
	}
	
	//validate numMovies input
	if (newNumMovies >= 0)
	{
		numMovies = newNumMovies;
	}
	else
	{
		numMovies = 0;
	}

	//validate whichPark input
	valid = false;
	for (int i = 0; i < kPark; i++)
	{
		if (parks[i].capital == newWhichPark)
		{
			valid = true;
			break;
		}
	}
	if (valid)
	{
		whichPark = newWhichPark;
	}
	else
	{
		whichPark = 'N';
	}

	//initalize nameCopy and creationDate copy 
	strcpy(nameCopy, kNul);
	strcpy(creationDateCopy, kNul);
}



//2 parameter constructor 
DisneyCharacter::DisneyCharacter(char* newName, char* newCreationDate)
{
	//validate name 
	strncpy(name, newName, kName);
	clearN(name);
	int len = (int)strlen(name);
	// if name is longer than 50, truncate to 46, append "..."
	if (len > kName - 1)
	{
		char* pModify = name;
		pModify += kTrunc;
		strcpy(pModify, "...\0");
	}

	//validate creationDate 
	clearN(newCreationDate);
	bool valid = true;
	len = (int)strlen(newCreationDate);
	//check length and content 
	if (len == kDate - 1)
	{
		for (int i = 0; i < kDate - 1; i++)
		{
			char check = newCreationDate[i];
			if ((i == kDash || i == kDash2) && check != '-')
			{
				valid = false;
				break;
			}
			else if ((i != kDash && i != kDash2) && (isdigit(check) == 0))
			{
				valid = false;
				break;
			}
		}
	}
	else
	{
		valid = false;
	}

	// if valid, copy input to creationDate, if not, set it as blank (null) 
	if (valid)
	{
		strcpy(creationDate, newCreationDate);
	}
	else
	{
		strcpy(creationDate, kNul);
	}

	//default numMovies, default whichPark, also the string copies 
	numMovies = 0; 
	whichPark = 'N';
	strcpy(nameCopy, kNul); 
	strcpy(creationDateCopy, kNul);
}



//destructor
DisneyCharacter::~DisneyCharacter(void)
{
	printf("%s is destroyed.\n", name);
}



//name getter
char* DisneyCharacter::getName(void)
{
	memcpy(nameCopy, name, kName);
	return nameCopy;
}



//creation date getter
char* DisneyCharacter::getDate(void)
{
	memcpy(creationDateCopy, creationDate, kDate);
	return creationDateCopy;
}



//movie number getter
int DisneyCharacter::getMovieNum(void)
{
	return numMovies;
}



//movie number setter
bool DisneyCharacter::setMovieNum(int newNum)
{
	bool valid = false; 
	if (newNum >= 0)
	{
		numMovies = newNum;
		valid = true;
	}
	return valid;
}



//park getter
char DisneyCharacter::getPark(void)
{
	return whichPark; 
}



//park setter
bool DisneyCharacter::setPark(char newPark)
{
	//search for newPark in the park list, if match, set return to true, newPark to whichPark
	bool valid = false; 
	for (int i = 0; i < kPark; i++)
	{
		if (parks[i].capital == newPark)
		{
			valid = true;
			whichPark = newPark;
			printf("%s's location has been set to \"%s.\"\n\n", name, parks[i].parkName);
			return valid;
		}
	}
	printf("Error: %c is not a valid input for park location.\n\n", whichPark);
	return valid;
}



//print out all info for the character 
void DisneyCharacter::ShowInfo(void)
{
	printf("Character's name: %s\n", name); 
	printf("%s's creation date: %s\n", name, creationDate); 
	printf("%s has been in %d movies.\n", name, numMovies); 
	int i = 0;
	for (; i < kPark; i++)
	{
		if (whichPark == parks[i].capital)
		{
			break;
		}
	}
	if (whichPark == 'N')
	{
		printf("%s is currently not placed at any park.\n\n", name);
	}
	else
	{
		printf("%s can be found at %s.\n\n", name, parks[i].parkName);
	}
}


//place character
bool DisneyCharacter::PlaceCharacter(char whichPark)
{
	bool valid = false;
	for (int i = 0; i < kPark; i++)
	{
		if (parks[i].capital == whichPark)
		{
			valid = true;
			this->whichPark = whichPark;
			printf("%s has been placed in %s.\n\n", name, parks[i].parkName);
			return valid;
		}
	}
	printf("Error: %c is not a valid input for park location.\n\n", whichPark);
	return valid;
}


//copy numMovies from one character to another 
void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
	numMovies = anotherCharacter.getMovieNum();
}

//clear newline
void clearN(char* input)
{
	char* newline = strchr(input, '\n'); 
	if (newline != NULL)
	{
		strcpy(newline, kNul);
	}
}