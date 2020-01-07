#define _CRT_SECURE_NO_WARNINGS  
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void MenuNewSeson();
void menuContrata();
void mNewSeson();
void menuCompra();
void menuMain();
void menuConfirma();
void menuPreJogo();
void menuStarter();

#pragma region mStarter
int main(void) {
	system("color A");
	setlocale(LC_ALL, "Portuguese");


	int menuStarter;
	int menuSaida;
	char equipa;
	
	do
	{
		printf("Menu Inicial\n\n");
		printf("\t[1] -> Start new season. \n");
		printf("\t[2] -> View previous season history. \n");
		printf("\t[3] -> Exit.\n\n");
		printf("Caminho->");
		scanf("%d", &menuStarter);
		switch (menuStarter)
		{
		case 1:
			//MenuNewSeson();
			//StartNewSeason();
								//Exemplo
								system("cls");
								printf("Escolha a equipa.");
								system("cls");
								menuConfirma();
			break;
		case 2:
			system("cls");
			//Historico();
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
#pragma region menuConfirma
void menuConfirma()
{
	int menuConfira;
	char playerfirstName[30];
	char playerlastName[30];

	do
	{
		printf("Identidade jogador:\n\n");
		printf("\tPrimeiro Nome->");
		scanf("%s", &playerfirstName);
		printf("\tUltim Nome->");
		scanf("%s", &playerlastName);
		printf("\nQuer ser tratado por?\n\n");
		printf("\t%s %s\n", playerfirstName, playerlastName);
		printf("\n\t[1]Sim\n\t[2]Nao");
		printf("\n\nCaminho->");
		scanf("%d", &menuConfira);
		switch (menuConfira)
		{
		case 1:
			mNewSeson();
			break;
		case 2:
			//retorna ao meno novamente
			system("cls");
			mNewSeson();
			break;
		default:
			printf("Nao exeiste essa opecao.\n");
			printf("Prima [ENTER] para recomecar.\n\n");
			system("pause");
			system("cls");
			menuConfirma();
			break;
		}
	} while (menuConfira == 2);
}
#pragma endregion
#pragma region mNewSeson0.1
void mNewSeson()
{
	char playerfirstName[30];
	char playerlastName[30];
	int menuNewSeson;

	do
	{
		system("cls");
		//printf("\t%s %s\n\n", playerfirstName, playerlastName);
		//printf("equipa")
		printf("Menu Start:\n\n");
		printf("\t[1] -> Contratar jogadores.\n");
		printf("\t[2] -> Comecar temporada.\n");
		printf("\n\nCaminho->");
		scanf("%d", &menuNewSeson);

		switch (menuNewSeson)
		{
		case 1:
			system("cls");
			menuContrata();
			break;

		case 2:
			system("cls");
			menuMain();
			break;

		default:
			menuMain();
			break;
		}
	} while (menuNewSeson == 2);
}
#pragma endregion
#pragma endregion


//Ver melhor os menus de Contratos
#pragma region menuContrata
	void menuContrata()
	{
		int mContrata;
		//Fundo inicial da equipa
		//Equipas existentes
		//Jogadores existentes na equipa
		do
		{
			printf("Identifique o nome do jogadr.->\n\n");
			system("pause");
			//Fzer um validador se o jogador existe ou nao
			printf("[1] -> Caracteristicas do jogador.\n");
			printf("[2] -> Comprar.\n");
			printf("[3] -> Voltar.\n");
			printf("[4] -> Confirmar alteracao.\n");

			scanf("%d", &mContrata);

			switch (mContrata)
			{
			case 1:
				//pega no jogador e ve as especificacoes dele 
				system("pause");
				break;
			case 2:
				//funcao que confirme a compra
				break;
			case 3:
				system("cls");
				menuContrata();
				break;
			case 4:
				system("cls");
				// manda para meno anterior
				mNewSeson();
				break;

			default:
				break;
			}
		} while (mContrata == 3);
		return 0;
	}
#pragma endregion

//Ver melhor a Compra
#pragma region mCompra
	void menuCompra()
	{
		int mCompra;
		//Fundo inicial da equipa
		//Equipas existentes
		//Jogadores existentes na equipa
		do
		{
			printf("Identifique o nome do jogadr.->\n\n");
			system("pause");
			//Fzer um validador se o jogador existe ou nao
			printf("[1] -> Caracteristicas do jogador.\n");
			printf("[2] -> Comprar.\n");
			printf("[3] -> Voltar.\n");
			scanf("%d", &mCompra);

			switch (mCompra)
			{
			case 1:
				//pega no jogador e ve as especificacoes dele 
				system("pause");
				break;
			case 2:
				//funcao que confirme a compra
				break;
			case 3:
				menuMain();
				break;
			default:
				break;
			}
		} while (mCompra == 3);
		return 0;
	}
#pragma endregion

#pragma region menuMain
	void menuMain()
	{
		int menuMain;
		//Apresenta o nome do jogador
		//Apresenta os fundos da equipa
		//nome da equipa
		//Apresenta o numero de vitorias e de derrotas
		//Apresenta o numero da jornada.
		do
		{
			printf("Meu Principal");
			printf("\t Nome: Vima\n");
			printf("\t\t Nome equipa:\n");
			printf("\t\t Vitorias Derrotas:\n");
			printf("\t\t Jornada:\n\n");

			printf("[1] -> Caracteristicas da equipa.\n");
			printf("[2] -> Ver jornada.\n");
			printf("[3] -> Sobre proximo jogo.\n");
			printf("[4] -> Ver a jornada ate ao momento.\n");
			printf("[5] -> Plantel.\n");
			printf("[6] -> Da inicio ao jogo.\n");
			printf("[7] -> Abandonar equipa.\n\n");

			printf("Caminho->");
			scanf("%d", &menuMain);

			switch (menuMain)
			{
			case 1:
				//identivica como esta a situacao do club na struct
				break;
			case 2:
				//Apresenta 9 jogos funcao de menu de avancar a jornada recuar a jornada e sair
				break;
			case 3:
				//vai boscar o plantel da outra equipa e ve os pontos fortes e pontos fracos
				break;
			case 4:
				//da o historico de todos os jogos com os respetivos planeis os resultados 
				break;
			case 5:
				//mostra o nosso planel com as opecoes de selecionar os jogadores que vaos er convocados apra o jogo
				break;
			case 6:
				//ao iniciar o jogo ele nao tem como voltar
				system("cls");
				menuPreJogo();
				break;
			case 7:
				//Volta as equipas
				break;
			default:
				break;
			}
		} while (menuMain == 1);
		return 0;
	}
#pragma endregion

#pragma region menuPreJogo
	void menuPreJogo()
	{
		int menuPreJogo;
		do
		{
			printf("Menu primeira partida:\n\n");
			printf("\t[1] -> alterar tatica.\n");
			printf("\t[2] -> Confirmar.\n\n");
			printf("Caminho->");
			scanf("%d", &menuPreJogo);

			switch (menuPreJogo)
			{
			case 1:
				system("cls");
				//funcao para a alteracao da tatica
				break;
			case 2:
				system("cls");
				menuStarter();
				break;
			default:
				break;
			}
		} while (menuPreJogo == 2);
		return 0;
	}
#pragma endregion
#pragma region MenuDurantJogo
	void menuStarter()
	{
		do
		{
			//todos os alertas

			int menuStarter;
			printf("Menu segunda da Partida:\n\n");
			printf("\t[1] -> Alterar tatica.\n");
			printf("\t[2] -> Alterar jogadores.\n");
			printf("\t[3] -> Confirmar.\n\n");
			printf("Caminho->");
			scanf("%d", &menuStarter);

			switch (menuStarter)
			{
			case 1:
				system("cls");
				//funcao que faz a alteracao da tatica.
				break;
			case 2:
				system("cls");
				//Funcao que altera os jogadores maximo 3 por jogo
				break;
			case 3:
				system("cls");
				//Confirma as alteracoes e prossegue a 2 parte do jogo
				break;
			default:
				break;
			}
		} while (menuStarter == 3);
		return 0;
	}
#pragma endregion
