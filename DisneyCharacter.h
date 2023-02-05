/*
* File name: DisneyCharacter.h
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: Feb 4th 2023
* Description: This file contains the class definition of 'DisneyCharacter', the constants and librarys for the class methods, 
*				and a const struct array storing all parks' abbreviations and names. 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning (disable:4996)
#pragma once

#define kName 51
#define kDash 4
#define kDash2 7
#define kDate 11
#define kPark 6
#define kTrunc 46
#define kNul "\0"


/*
* Class Name: DisneyCharacter 
* Class Purpose: This class aim to model the disney characters who are present in Disney amusement parks. The class contains
*				members indicating the character's name, date of creation, numbers of movies they've been in, and their current
*				location. All characters of the class can be retrieved, though only the park location and numbers of movies can be
*				updated/mutated. One may also set one characters' movie count the same as anothers. All details of a character 
*				can be displayed by calling ShowInfo(). 
*/
class DisneyCharacter
{
private:
	char name[kName + 1]; //name of the character + 1 for null 
	char nameCopy[kName + 1]; // name copy to pass back to main (mask the address) + 1 for null 
	char creationDate[kDate]; // date of the character's creation
	char creationDateCopy[kDate]; // copy of creation date (mask the address)
	int numMovies; // the number of movies the character has been in
	char whichPark; // the Disney establishment where the character can be found 

public:
	char* getName(void); //name getter
	char* getDate(void); //creation date getter
	int getMovieNum(void); //movie count getter
	bool setMovieNum(int newNum); //movie count setter
	char getPark(void); //park location getter
	bool setPark(char newPark); //park location setter

	void ShowInfo(void); //display all info
	bool PlaceCharacter(char whichPark); //place character at another location
	void SameMovies(DisneyCharacter& anotherCharacter); // duplicate one character's movie count to another character 

	DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark); // constructor - 4 parameters
	DisneyCharacter(char* name, char* creationDate);  // constructor - 2 parameters
	~DisneyCharacter(void); //destructor
};

//const struct array to store all park abbreviation and names
typedef struct park
{
	const char capital; 
	const char* parkName; 
}park;

const struct park parks[kPark]
{
	{'M', "Magic Kingdom"},
	{'S', "Disney Studios"},
	{'A', "Animal Kingdom"},
	{'E', "Epcot"},
	{'C', "California Adventure"},
	{'N', "Not Placed"}
};

void clearN(char* input);