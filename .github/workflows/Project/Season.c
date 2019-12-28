#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Structs.h"
#include "Arrays.h"
#include "FuncsHeader.h"

void Season()
{
	char chosenTeam[30];

	// Find the team the player wants to play with
	// Show the team list
	ShowTeamsList(teamsNames);

	// Asking what team the player wants
	printf("Select a team: ");
	scanf("%s", chosenTeam);

	// Reading the struct with the right team
	OpenTeamFile(chosenTeam);

	// Create the schedule of the games
	CreateCalendar(teamsNames);
	
	// Show message about a new coach
	

	// First menu for the coach


	// Use this every journey
	NewJourney();
}
