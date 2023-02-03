/*
* File name: DisneyCharacter.cpp
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date:
* Description:
*/

#include "DisneyCharacter.h"

//4 paratermeter constructor 
DisneyCharacter::DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark)
{
	DisneyCharacter(name, creationDate);

}


//2 parameter constructor 
DisneyCharacter::DisneyCharacter(char* name, char* creationDate)
{
	//default numMovies, default whichPark 
	numMovies = 0; 
	whichPark = 'N';
}



//destructor
DisneyCharacter::~DisneyCharacter(void)
{
	printf("%s is destroyed.", name);
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
		if (parks[i] == newPark)
		{
			valid = true;
			whichPark = newPark;
			break;
		}
	}
	return valid;
}

//print out all info for the character 
void DisneyCharacter::ShowInfo(void)
{

}


//place character
bool DisneyCharacter::PlaceCharacter(char whichPark)
{
	bool valid = false;
	for (int i = 0; i < kPark; i++)
	{
		if (parks[i] == whichPark)
		{
			valid = true;
			whichPark = whichPark;
			break;
		}
	}
	return valid;
}


//copy numMovies from one character to another 
void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
	numMovies = anotherCharacter.getMovieNum();
}