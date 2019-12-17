#pragma once
typedef struct {
	char firstName[30];
	char lastName[30];
	int number;
	float salary;
	char startContractDate[10];
	int monthsLeft;
	int gkStrength;
	int cbStrength;
	int cmStrength;
	int stStrength;
} Player;

typedef struct {
	Player players[20];
	char trainerName[60];
} Team;

typedef struct {
	float salaries;
	float stadium;
} Expenses;

typedef struct {
	int id;
	Team team;
	Expenses expense;
	char teamName[30];
	char stadiumName[30];
	int stadiumPlaces;
	int partnersNumber;
	double clubFunds;
	double mensalSpents;
	ResultTable resultTable;
} Club;

typedef struct {
	char homeTeam[30];
	char awayTeam[30];
	char matchResult[7]; //00 - 00
	int goalsScored;
	int goalsTaken;
	int gamesDisputed;
	int gamesWon;
	int gamesLost;
	int gamesTied;
} ResultTable;
Boa tarde
