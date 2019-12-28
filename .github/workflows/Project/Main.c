#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Structs.h"
#include "FuncsHeader.h"

int main(void) {

	setlocale(LC_ALL, "Portuguese");

	int menuOption;

	do
	{
		// Initial menu
		printf("1 - Start new season");
		printf("2 - Sair");
		scanf("%d", &menuOption);

		switch (menuOption)
		{
		case 1:
			StartNewSeason();
			break;
		default:
			break;
		}
	} while (menuOption == 2);

	return 0;
}
