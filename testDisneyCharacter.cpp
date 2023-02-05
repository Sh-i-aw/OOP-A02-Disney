/*
* File name: testDisneyCharacter.cpp
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: 
* Description: 
*/

#include "DisneyCharacter.h"


int main(void)
{
	//instantiate mickey 
	DisneyCharacter Mickey((char*)"Mickey", (char*)"1929-01-01", 100, 'M');
	//instantiate minnie 
	DisneyCharacter Minnie((char*)"Minnie", (char*)"1930-01-01");

	DisneyCharacter Ariel((char*)"ArielArielArielArielArielArielArielArielArielArielAr", (char*)"wef", 2, 'T');

	//set minnie's movies same as mickey's 
	Minnie.SameMovies(Mickey);

	//show information of both characers 
	Mickey.ShowInfo();
	Minnie.ShowInfo();
	Ariel.ShowInfo();

	//place minnie in Epcot Park 
	Minnie.PlaceCharacter('E');
}