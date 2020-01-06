#define _CRT_SECURE_NO_WARNINGS  
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Structs.h"
#include "Funcs.h"

void MenuNewSeson();
//void menuCompra();

int main(void) {

	setlocale(LC_ALL, "Portuguese");

#pragma region mStarter
	int menuStarter;
	int menuSaida;
	do
	{
		printf("[1] -> Start new season. \n");
		printf("[2] -> View previous season history. \n");
		printf("[3] -> Exit. \n");
		scanf("%d", &menuStarter);

		switch (menuStarter)
		{
		case 1:
			system("cls");
			MenuNewSeson();
			StartNewSeason();
			break;
		case 2:
			system("cls");
			Historico();
			menuStarter = 3;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			printf("Quer msmo sair ?\n[1]Sim    [2]Nao\n");
			scanf("%d", &menuSaida);
			switch (menuSaida)
			{
			case 1:
				return 0;
				break;
			case 2:
				system("cls");
			default:
				break;
			}
			break;
		}
	} while (menuStarter == 3);
}
#pragma endregion
#pragma region mNewSeson
void mNewSeson()
{
	MainPlayer mainplayr;
	int menuNewSeson;
	do
	{
		printf("Primeiro Nome->\n");
		scanf("%c ", mainplayr.playerfirstName);
		printf("Ultim Nome->\n");
		scanf("%c ", mainplayr.playerlastName);
		printf("[1] -> Contratar jogadores.");
		printf("[2] -> Comecar temporada.");
		scanf("%d", &menuNewSeson);

		switch (menuNewSeson)
		{
		case 1:
			menuCompra();
			break;

		case 2:
			break;


		default:
			break;
		}
	} while (menuNewSeson == 2);
}
#pragma endregion
#pragma region menuCompra
	//void menuCompra()
	//{
	//	int menuCompra;
	//	//Fundo inicial da equipa
	//	//Equipas existentes
	//	//Jogadores existentes na equipa
	//	do
	//	{
	//		printf("[1] -> Comprar.");
	//		printf("[2] -> Caracteristicas do jogador.");
	//		printf("[3] -> Confirmar alteracao.");
	//		scanf("%d", &menuCompra);

	//		switch (menuCompra)
	//		{
	//		case 1:
	//			//funcao que confirme a compra
	//			break;
	//		case 2:
	//			//pega no jogador e ve as especificacoes dele 
	//			//le uma key e volta
	//			break;
	//		case 3:
	//			//funcao que confirme as alteracoes e rediciona para o menoMain.
	//			break;
	//		default:
	//			break;
	//		}
	//	} while (menuCompra == 3);
	//	return 0;
	//}
#pragma endregion
//#pragma region menuMain
//	void menuMain()
//	{
//		int menuMain;
//		//Apresenta o nome do jogador
//		//Apresenta os fundos da equipa
//		//Apresenta o numero de vitorias e de derrotas
//		//Apresenta o numero da jornada.
//		do
//		{
//			printf("[1] -> Caracteristicas da equipa.");
//			printf("[2] -> Ver jornada.");
//			printf("[3] -> Sobre proximo jogo.");
//			printf("[4] -> Ver a jornada ate ao momento.");
//			printf("[5] -> Plantel.");
//			printf("[6] -> Da inicio ao jogo.");
//			printf("[7] -> Abandonar equipa.");
//			scanf("%d", &menuMain);
//
//			switch (menuMain)
//			{
//			case 1:
//				//identivica como esta a situacao do club na struct
//				break;
//			case 2:
//				//Apresenta 9 jogos funcao de menu de avancar a jornada recuar a jornada e sair
//				break;
//			case 3:
//				//vai boscar o plantel da outra equipa e ve os pontos fortes e pontos fracos
//				break;
//			case 4:
//				//da o historico de todos os jogos com os respetivos planeis os resultados 
//				break;
//			case 5:
//				//mostra o nosso planel com as opecoes de selecionar os jogadores que vaos er convocados apra o jogo
//				break;
//			case 6:
//				//da inicio ao jogo
//				break;
//			case 7:
//				//chama a funcao de confirmacao se o jogador quere abandonar a equipa com o alerta que a temporada ira ser apagada
//				break;
//			default:
//				break;
//			}
//		} while (menuMain == 1);
//		return 0;
//	}
//#pragma endregion
//#pragma region menuPreJogo
//	void menuPreJogo()
//	{
//		int menuPreJogo;
//		do
//		{
//			printf("[1] -> alterar tatica.");
//			printf("[2] -> Confirmar.");
//			scanf("%d", &menuPreJogo);
//
//			switch (menuPreJogo)
//			{
//			case 1:
//				//funcao para a alteracao da tatica
//				break;
//			case 2:
//				//confirirma a alteracao e procege a 1 parte do jogo
//				break;
//			default:
//				break;
//			}
//		} while (menuPreJogo == 2);
//		return 0;
//	}
//#pragma endregion
//#pragma region MenuDurantJogo
//	void menuStarter()
//	{
//		do
//		{
//			int menuStarter;
//
//			printf("[1] -> Alterar tatica.");
//			printf("[2] -> Alterar jogadores.");
//			printf("[3] -> Confirmar.");
//			scanf("%d", &menuStarter);
//
//			switch (menuStarter)
//			{
//			case 1:
//				//funcao que faz a alteracao da tatica.
//				break;
//			case 2:
//				//Funcao que altera os jogadores maximo 3 por jogo
//				break;
//			case 3:
//				//Confirma as alteracoes e prossegue a 2 parte do jogo
//				break;
//			default:
//				break;
//			}
//		} while (menuStarter == 3);
//		return 0;
//	}
//
//#pragma endregion
