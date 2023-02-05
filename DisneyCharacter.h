/*
* File name: DisneyCharacter.h
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: 
* Description: 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning (disable:4996)
#pragma once

#define kName 51
#define kDash 4
#define kDashTwo 7
#define kDate 11
#define kPark 6
#define kTrunc 46
#define kNul "\0"

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
	char* getName(void);
	char* getDate(void);
	int getMovieNum(void);
	bool setMovieNum(int newNum);
	char getPark(void);
	bool setPark(char newPark);

	void ShowInfo(void); 
	bool PlaceCharacter(char whichPark); 
	void SameMovies(DisneyCharacter& anotherCharacter);

	DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark); // constructor - 4 parameters
	DisneyCharacter(char* name, char* creationDate);  // constructor - 2 parameters
	~DisneyCharacter(void); //destructor

};

//const array to store all parks
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