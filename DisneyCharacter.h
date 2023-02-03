/*
* File name: DisneyCharacter.h
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: 
* Description: 
*/

#include <stdio.h>
#include <string.h>

#pragma once

#define kName 51
#define kDate 11

class DisneyCharacter
{
private:
	char name[kName]; //name of the character
	char creationDate[kDate]; // date of the character's creation
	int numMovies; // the number of movies the character has been in
	char whichPark; // the Disney establishment where the character can be found 
	
	DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark); // constructor - 4 parameters
	DisneyCharacter(char* name, char* creationDate);  // constructor - 2 parameters
	~DisneyCharacter(void); //destructor

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
};

//const array to store all parks
const char parks[] = { 'M', 'S', 'A', 'E', 'C', 'N' };