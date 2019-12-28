#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void CreateCalendar(char teams[18][30])
{
	// Variables
	char calendar[306][60];
	char equipaCasa[30];
	char equipaFora[30];
	char primeiroJogo[60], segundoJogo[60];
	int counter = 0;

	// Populate the calendar array with all of the games possible
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (i != j)
			{
				strcpy(equipaCasa, teams[i]);
				strcpy(equipaFora, teams[j]);

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

	addCalendar(calendar);
}

void ShowTeamsList(char teams[18][30])
{

	printf("Teams List:\n");

	// Show list of the teams
	for (int i = 0; i < 18; i++)
	{
		printf("%s\n", teams[i]);
	}
}

void OpenTeamFile(char teamName[30])
{
	readTeamInfo(teamName);

	// Change this to read into a struct
	FILE *chosenTeam;
	char filePath[60] = "../Equipas/";
	int x;

	// ..\Equipas\chosenTeam
	strcat(filePath, teamName);
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
