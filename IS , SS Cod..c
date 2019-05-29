#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

struct Fabricante{
	char nome[50];
	char nacionalidade[50];
	int ano;
};

void insertionSortAdaptado(struct Fabricante *vetor, int n, int f, int h)
{
	struct Fabricante valor;
	int i, j;
	for(i=f+h; i<n; i = i+h){
		valor = vetor[i];
		j = i-h;
		while( (j>=f) && (strcmp(vetor[j].nome, valor.nome) > 0) || (strcmp(vetor[j].nome, valor.nome) == 0 && strcmp(vetor[j].nacionalidade, valor.nacionalidade) > 0) || (strcmp(vetor[j].nacionalidade, valor.nacionalidade) == 0 && vetor[j].ano > valor.ano))
        {
        	vetor[j+h] = vetor[j];
        	j = j-h;
		}
		vetor[j + h] = valor;
	}
}

void shellSort(struct Fabricante *vetor, int n, int np)
{
	int h, p, j;
	
	for(p = np; p>0; p--){
		h = (int) pow(2, (int) p-1);
		for(j=0; j<h; j++)
			insertionSortAdaptado(vetor, n, j, h);
	}
}

void vetorfinal(struct Fabricante *vetor, int n){
	int i;
	for(i=0; i<n; i++){
		printf(" vetor [%d]: \n",i);
		printf(" nome: %s \n", vetor[i].nome);
		printf(" nacionalidade: %s \n", vetor[i].nacionalidade);
		printf(" ano: %d \n\n", vetor[i].ano);
	}
}

int main(int argc, char ** argv)
{
	
	setlocale(LC_ALL, "Portuguese");
	
	
	struct Fabricante fabricas[8];
	
	strcpy(fabricas[0].nome,"Zac");
	strcpy(fabricas[0].nacionalidade,"Russa");
	fabricas[0].ano = 1920;
	
	strcpy(fabricas[1].nome,"Bilphios");
	strcpy(fabricas[1].nacionalidade,"Sovietica");
	fabricas[1].ano = 1929;
	
	strcpy(fabricas[2].nome,"Malphite");
	strcpy(fabricas[2].nacionalidade,"Estados Unidos");
	fabricas[2].ano = 2005;
	
	strcpy(fabricas[3].nome,"Arnold");
	strcpy(fabricas[3].nacionalidade,"Chileno");
	fabricas[3].ano = 2099;
	
	strcpy(fabricas[4].nome,"Bilphios");
	strcpy(fabricas[4].nacionalidade,"Coreano");
	fabricas[4].ano = 1929;
	
	strcpy(fabricas[5].nome,"Cashe");
	strcpy(fabricas[5].nacionalidade,"Breta");
	fabricas[5].ano = 1540;
	
	strcpy(fabricas[6].nome,"Darius");
	strcpy(fabricas[6].nacionalidade,"Oceania");
	fabricas[6].ano = 1000;
	
	strcpy(fabricas[7].nome,"Darius");
	strcpy(fabricas[7].nacionalidade,"Oceania");
	fabricas[7].ano = 999;


	shellSort(fabricas, 8, 4);
	vetorfinal(fabricas, 8);
	
	return 0;
}