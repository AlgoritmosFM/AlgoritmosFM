#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

void readTeamInfo(char *teams)
{
	FILE *teamFile;
	char teamPath[60] = "../Equipas/";
	Club clubs[18];
	char *info;
	char buffer[255];
	int count = 0;
	int playerCount = 0;
	char clubInfo[4][255];
	char trainerInfo[3][255];
	char playerInfo[11][355];

	for (int i = 0; i < 18; i++)
	{
		strcat(teamPath, teams + i * 30);
		strcat(teamPath, ".txt");

		teamFile = fopen(teamPath, "r");
		
		fgets(clubs[i].teamName, 30, teamFile);

		printf("\nNome: %s", clubs[i].teamName);

		fgets(clubs[i].stadiumName, 50, teamFile);

		printf("Estádio: %s", clubs[i].stadiumName);

		// Read club info (stadium places, partners numbers, funds and spents
		info = strtok(fgets(buffer, sizeof(buffer), teamFile), ",");

		while (info != NULL)
		{
			strcpy(clubInfo[count], info);
			count++;
			info = strtok(NULL, ",");
		}

		count = 0;

		clubs[i].stadiumPlaces = atof(clubInfo[0]);
		clubs[i].partnersNumber = atof(clubInfo[1]);
		clubs[i].clubFunds = atof(clubInfo[2]);
		clubs[i].mensalSpents = atof(clubInfo[3]);

		printf("Estádio lugares: %.0f\n", clubs[i].stadiumPlaces);
		printf("Número sócios: %.0f\n", clubs[i].partnersNumber);
		printf("Fundos: %.0f\n", clubs[i].clubFunds);
		printf("Despesas: %.0f\n", clubs[i].mensalSpents);

		// Read Trainer info (name, start contract date, months until the end)
		info = strtok(fgets(buffer, sizeof(buffer), teamFile), ",");
		
		while (info != NULL)
		{
			strcpy(trainerInfo[count], info);
			count++;
			info = strtok(NULL, ",");
		}

		count = 0;

		strcpy(clubs[i].team.coach.coachName, trainerInfo[0]);
		strcpy(clubs[i].team.coach.startContractDate, trainerInfo[1]);
		clubs[i].team.coach.monthsLeft = atoi(trainerInfo[2]);

		printf("Nome treinador: %s\n", clubs[i].team.coach.coachName);
		printf("Data Inicio: %s\n", clubs[i].team.coach.startContractDate);
		printf("Meses restantes: %d\n", clubs[i].team.coach.monthsLeft);
		
		// Read PlayerInfo
		info = strtok(fgets(buffer, sizeof(buffer), teamFile), ",");
		while (info != NULL)
		{
			while (info != NULL)
			{
				strcpy(playerInfo[count], info);
				count++;
				info = strtok(NULL, ",");
			}
			strcpy(clubs[i].team.players[playerCount].firstName, playerInfo[0]);
			strcpy(clubs[i].team.players[playerCount].lastName, playerInfo[1]);
			clubs[i].team.players[playerCount].number = atoi(playerInfo[2]);
			clubs[i].team.players[playerCount].salary = atof(playerInfo[3]);
			strcpy(clubs[i].team.players[playerCount].startContractDate, playerInfo[4]);
			clubs[i].team.players[playerCount].monthsLeftUntilEnd = atoi(playerInfo[5]);
			strcpy(clubs[i].team.players[playerCount].position, playerInfo[6]);
			clubs[i].team.players[playerCount].gkStrength = atoi(playerInfo[7]);
			clubs[i].team.players[playerCount].cbStrength = atoi(playerInfo[8]);
			clubs[i].team.players[playerCount].cmStrength = atoi(playerInfo[9]);
			clubs[i].team.players[playerCount].stStrength = atoi(playerInfo[10]);

			count = 0;
			playerCount++;
			info = strtok(fgets(buffer, sizeof(buffer), teamFile), ",");
		}

		playerCount = 0;
		count = 0;

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
