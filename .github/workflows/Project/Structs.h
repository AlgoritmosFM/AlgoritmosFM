#pragma once
typedef struct {
	char firstName[30];
	char lastName[30];
	int number;
	float salary;
	char startContractDate[10];
	int monthsLeftUntilEnd;
	char position[20];
	int gkStrength;
	int cbStrength;
	int cmStrength;
	int stStrength;
} Player;

typedef struct {
	char coachName[60];
	char startContractDate[10];
	int monthsLeft;
} Coach;

typedef struct {
	Player players[30];
	Coach coach;
} Team;

typedef struct {
	float salaries;
	float stadium;
} Expenses;

typedef struct {
	int id;
	Team team;
	char teamName[30];
	char stadiumName[50];
	float stadiumPlaces;
	float partnersNumber;
	float clubFunds;
	float mensalSpents;
} Club;

typedef struct {
	char teamName[30];
	int points;
	int goalsScored;
	int goalsTaken;
	int gamesDisputed;
	int gamesWon;
	int gamesLost;
	int gamesTied;
} ResultTable;

typedef struct {
	char homeTeam[30];
	char visitorTeam[30];
} Calendar;

typedef struct {
	char homeTeam[30];
	int homeTeamGoals;
	char visitorTeam[30];
	int visitorTeamGoals;
} Results;

typedef struct {
	int day;
	int month;
	int year;
} ContractDate;
