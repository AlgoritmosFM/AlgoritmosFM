#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Structs.h"

void readTeamInfo(char *teams)
{
	FILE *teamFile;
	char teamPath[60] = "../Equipas/";
	int playerCounter = 0;
	Club clubs[18];
	char remover[255];

	for (int i = 0; i < 18; i++)
	{
		clubs[i].stadiumName[0] = '\0';

		strcat(teamPath, teams + i * 30);
		strcat(teamPath, ".txt");

		teamFile = fopen(teamPath, "r");

		fgets(clubs[i].teamName, 30, teamFile);

		printf("Nome: %s\n", clubs[i].teamName);

		fgets(clubs[i].stadiumName, 30, teamFile);

		printf("Estádio: %s\n", clubs[i].stadiumName);

		fscanf(teamFile, "%lf", &clubs[i].stadiumPlaces);
		fscanf(teamFile, "%lf", &clubs[i].partnersNumber);
		fscanf(teamFile, "%lf" , &clubs[i].clubFunds);
		fscanf(teamFile, "%lf" , &clubs[i].mensalSpents);

		printf("Estádio lugares: %lf", clubs[i].stadiumPlaces);
		printf("Estádio lugares: %lf", clubs[i].partnersNumber);

		fscanf(teamFile, "%s, %s, %d", clubs[i].team.coach.coachName,
			clubs[i].team.coach.startContractDate,
			&clubs[i].team.coach.monthsLeft);

		// Read all the player info
		while (fscanf(teamFile, "%s, %s, %d, %f, %s, %d, %s, %d, %d, %d, %d",
			clubs[i].team.players[playerCounter].firstName,
			clubs[i].team.players[playerCounter].lastName,
			&clubs[i].team.players[playerCounter].number,
			&clubs[i].team.players[playerCounter].salary,
			clubs[i].team.players[playerCounter].startContractDate,
			&clubs[i].team.players[playerCounter].monthsLeftUntilEnd,
			clubs[i].team.players[playerCounter].position,
			&clubs[i].team.players[playerCounter].gkStrength,
			&clubs[i].team.players[playerCounter].cbStrength,
			&clubs[i].team.players[playerCounter].cmStrength,
			&clubs[i].team.players[playerCounter].stStrength) != EOF)
		{
			playerCounter++;
		}

		strcpy(teamPath, "../Equipas/");

		fclose(teamFile);
	}
}

void addCalendar(char *calendar)
{
	// Write in the schedule file the schedule of the season
	FILE *calendarFile;
	calendarFile = fopen("Season.txt", "w");
	for (int i = 0; i < 306; i++)
	{
		fprintf(calendarFile, "%s\n", calendar + i * 60);
	}
	fclose(calendarFile);
}

//TODO: not done yet
void readCalendar()
{
	int game;
	int i = 0;
	FILE *calendarFile;
	calendarFile = fopen("Season.txt", "r");
	while (((game = fgetc(calendarFile)) != EOF) && i < 18)
	{
		printf("%c", game);
		if (game == '\n')
			i++;
	}
}
