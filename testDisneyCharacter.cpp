/*
* File name: testDisneyCharacter.cpp
* Project name: PROG 1385 - A02 Disney Character
* By: Xiao Xue
* First version date: Feb 4th 2023
* Description: This program contains the test harness for the class DisneyCharacter. 2 characters named Mickey and Minnie are 
*				instantiated then altered. The program then prints out each characters details, and what actions have been done
*				to them. Program will end with message displayed about both objects being destroyed. 
*/

#include "DisneyCharacter.h"

int main(void)
{
	//instantiate mickey 
	DisneyCharacter Mickey((char*)"Mickey", (char*)"1929-01-01", 100, 'M');
	//instantiate minnie 
	DisneyCharacter Minnie((char*)"Minnie", (char*)"1930-01-01");

	//set minnie's movies same as mickey's 
	Minnie.SameMovies(Mickey);

	//show information of both characters 
	Mickey.ShowInfo();
	Minnie.ShowInfo();

	//place minnie in Epcot Park 
	Minnie.PlaceCharacter('E');

}