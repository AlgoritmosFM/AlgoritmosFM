#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Files.h"
#include "Season.h"

long CalcTransferValue(int salary, int monthsLeft)
{
	return salary * 5 * monthsLeft;
}

long NewSalary(int salary)
{
	return (long)salary * 1.5f;
}

float RandInRange(float min, float max)
{
	return ((((float)rand()) / ((float)RAND_MAX)) * (max - min)) + min;
}

float TicketsProfit(int maxCapacity)
{
	float profit, ticketPrice = 3.5f, usedCapacity;
	srand((unsigned int)time(NULL));

	usedCapacity = RandInRange(0, 100);

	profit = ((float)maxCapacity * (usedCapacity / 100)) * ticketPrice;

	return profit;
}

void CreateCalendar(char *team)
{
	// Variables
	char calendar[306][60];
	char equipaCasa[30];
	char equipaFora[30];
	char primeiroJogo[60];
	int counter = 0;
	
	// Populate the calendar array with all of the games possible
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (i != j)
			{
				printf("\n***** %s *****\n", team + i * 30);
				strcpy(equipaCasa, team + i * 30);
				strcpy(equipaFora, team + j * 30);

				strcpy(primeiroJogo, equipaCasa);
				strcat(primeiroJogo, " X ");
				strcat(primeiroJogo, equipaFora);

				strcpy(calendar[counter], primeiroJogo);

				counter++;
			}
		}
	}

	// Randomize the games
	for (int i = 0; i < 306; i++)
	{
		int j = RandInRange(0, 305);
		char temp[60];
		strcpy(temp, calendar[j]);
		strcpy(calendar[j], calendar[i]);
		strcpy(calendar[i], temp);
	}

	addCalendar((char *) calendar);
}

void ShowTeamsList(char *teams)
{

	printf("Teams List:\n");

	// Show list of the teams
	for (int i = 0; i < 18; i++)
	{
		printf("%s\n", teams + i * 30);
	}
}

void OpenTeamFile(char **teams, char chosedTeam[30])
{
	readTeamInfo(teams);

	// Change this to read into a struct
	FILE *chosenTeam;
	char filePath[60] = "../Equipas/";
	int x;

	// ..\Equipas\chosenTeam
	strcat(filePath, chosedTeam);
	strcat(filePath, ".txt");

	chosenTeam = fopen(filePath, "r");

	while ((x = fgetc(chosenTeam)) != EOF)
	{
		printf("%c", x);
	}
}

void StartNewSeason()
{
	// Here is the code to start a new season
	Season();
}

void NewJourney()
{
	readCalendar();
}
