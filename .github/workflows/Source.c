#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


//Contador de quem come�a com a bola (3 - Se escolher campo da esquerda ou se escolher bola e 4 se escolher da direita
int bola;
int i;

//Golos da Equipa A e Equipa B
int golosA = 0;
int golosB = 0;

//Ler o planter e fazer a m�dia de for�a de gk ao gk, for�a de defesa aos defesas, for�a de m�dio aos medios e for�a de avan�ado aos avan�ados
//Exemplo:
int forcaGKA = 70;
int forcaGKB = 69;
int forcaDefesaA = 73;
int forcaDefesaB = 75;
int forcaMedioA = 70;
int forcaMedioB = 68;
int forcaAvancadoA = 81;
int forcaAvancadoB = 82;
int mediaPosicao;
int forcaMaior;





//Numero random
int RandInRange(int min, int max)
{
	return rand() % (max - min + 1) + min;
	
}

void menu_vitoria(int golosA, int golosB) 
{
	printf("Acabou o jogo\n\n");
	printf("PARAB�NS!\n");
	printf("Voc� ganhou o jogo por: ", golosA, " - ", golosB);
	printf("Continue no bom caminho");
}

void menu_derrota(int golosA, int golosB) 
{
	printf("Acabou o jogo\n\n");
	printf("Voc� perdeu o jogo por: ", golosA, " - ", golosB);
	printf("N�o desista! Voc� consegue para a pr�xima!");
}

void menu_empate(int golosA, int golosB) 
{
	printf("Acabou o jogo\n\n");
	printf("Voc� empatou o jogo por: ", golosA, " - ", golosB);
	printf("Poderia ter corrido melhor! Mas voc� consegue!");
}


int main(void)
{


	setlocale(LC_ALL, "Portuguese");

	//Escolher campo ou bola
	int escolha;
	int escolhacampo;

	printf("Escolher campo ou bola?\n\n");
	printf("[1] - Campo\n");
	printf("[2] - Bola\n\n");
	scanf_s("%d", &escolha);
	
	switch (escolha)
	{
	case 1:
		printf("Por qual lado quer come�ar?\n\n");
		printf("[1] - Esquerdo\n");
		printf("[2] - Direito\n\n");
		scanf_s("%d", &escolhacampo);


		if (escolhacampo == 1)
		{
			bola = 3;	
		}

		else if (escolhacampo == 2)
		{
			bola = 4;
		}

		break;
	case 2:
		bola = 4;
		break;

	default:
		printf("Escolha n�o existe... Tente outra vez\n");
		break;
	}

	//Atribuir a for�a maior para as probabilidades
	if (forcaAvancadoA > mediaPosicao)
	{
		forcaMaior = forcaAvancadoA;
	}
	else if (forcaAvancadoA < mediaPosicao)
	{
		forcaMaior = forcaAvancadoB;
	}
	else
	{
		if (RandInRange(0, 100) < 49)
		{
			forcaMaior = forcaAvancadoA;
		}
		else
		{
			forcaMaior = forcaAvancadoB;
		}
	}



    srand(time(NULL));

	//Ler o plantel e fazer a m�dia de for�as a todas as posi��es


	
	//[JOGO] Probabilidades de avan�ar ou perder a bola em 90 minutos
	for (bola = 4, i = 0; bola = 4, i < 90; bola = 4, i++)
	{
	    

		//Avan�a ou perde a bola para o advers�rio
		int x = RandInRange(0, 100);
		if (x < forcaMaior)
		{
			bola++;
			printf("Avan�a\n");
		}

		else if (x > forcaMaior)
		{
			bola--;
			printf("Perdeu a bola\n");
		}



		//Atribui�ao da media de posi��o de equipa A e B (0-GKA, 1-DEFA, 2-MEDA, 3-ATACA, 4- ATACB, 5-MEDB, 6- DEFB, 7- GKB) e golos
		switch (bola)
		{
		case 0:
			mediaPosicao = forcaGKA;
			break;

		case 1:
			mediaPosicao = forcaDefesaA;
			break;

		case 2:
			mediaPosicao = forcaMedioA;
			break;

		case 3:
			mediaPosicao = forcaAvancadoA;
			break;

		case 4:
			mediaPosicao = forcaAvancadoB;
			break;

		case 5:
			mediaPosicao = forcaMedioB;
			break;

		case 6:
			mediaPosicao = forcaDefesaB;
			break;

		case 7:
			mediaPosicao = forcaGKB;
			break;
		}

		//Golos
		if (bola == -1)
		{
			printf("GOLO!!! da Equipa B");
			golosB++;
			bola = 4;
		}
		else if (bola == 8)
		{
			printf("GOLO!!! da Equipa A");
			golosA++;
			bola = 3;
		}

	}

	//Resultado
	if (escolhacampo == 1 && golosA > golosB)
	{
		menu_vitoria(golosA, golosB);
	}

	else if (escolhacampo == 2 && golosA < golosB)
	{
		menu_vitoria(golosA, golosB);
	}

	else if (escolhacampo == 1 && golosA < golosB)
	{
		menu_derrota(golosA, golosB);
	}

	else if (escolhacampo == 2 && golosA > golosB)
	{
		menu_derrota(golosA, golosB);
	}

	else if (golosA = golosB)
	{
		menu_empate(golosA, golosB);
	}

	//Atribui��o dos pontos: 3 Vitoria, 1 Empate, 0 Derrota

	return 0;
}