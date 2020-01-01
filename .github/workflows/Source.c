#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


//Contador de quem começa com a bola (3 - Se escolher campo da esquerda ou se escolher bola e 4 se escolher da direita
int bola;
int i;

//Golos da Equipa A e Equipa B
int golosA = 0;
int golosB = 0;

//Ler o planter e fazer a média de força de gk ao gk, força de defesa aos defesas, força de médio aos medios e força de avançado aos avançados
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
	printf("PARABÉNS!\n");
	printf("Você ganhou o jogo por: ", golosA, " - ", golosB);
	printf("Continue no bom caminho");
}

void menu_derrota(int golosA, int golosB) 
{
	printf("Acabou o jogo\n\n");
	printf("Você perdeu o jogo por: ", golosA, " - ", golosB);
	printf("Não desista! Você consegue para a próxima!");
}

void menu_empate(int golosA, int golosB) 
{
	printf("Acabou o jogo\n\n");
	printf("Você empatou o jogo por: ", golosA, " - ", golosB);
	printf("Poderia ter corrido melhor! Mas você consegue!");
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
		printf("Por qual lado quer começar?\n\n");
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
		printf("Escolha não existe... Tente outra vez\n");
		break;
	}

	//Atribuir a força maior para as probabilidades
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

	//Ler o plantel e fazer a média de forças a todas as posições


	
	//[JOGO] Probabilidades de avançar ou perder a bola em 90 minutos
	for (bola = 4, i = 0; bola = 4, i < 90; bola = 4, i++)
	{
	    

		//Avança ou perde a bola para o adversário
		int x = RandInRange(0, 100);
		if (x < forcaMaior)
		{
			bola++;
			printf("Avança\n");
		}

		else if (x > forcaMaior)
		{
			bola--;
			printf("Perdeu a bola\n");
		}



		//Atribuiçao da media de posição de equipa A e B (0-GKA, 1-DEFA, 2-MEDA, 3-ATACA, 4- ATACB, 5-MEDB, 6- DEFB, 7- GKB) e golos
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

	//Atribuição dos pontos: 3 Vitoria, 1 Empate, 0 Derrota

	return 0;
}