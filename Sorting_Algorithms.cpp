#include <stdio.h>
#include <stdlib.h>
#include "Sorting_Algorithms.h"

void bubbleSort(int TAM, int *vetor){
	
	int i, segue, f = TAM, aux, troca = 0;
	
	do{
		
		segue = 0;
		
		for(i=0; i<f-1; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				segue = i;
				troca++;
			}
		}
		
		f--;
		
	}while(segue != 0);
	printf("\nTrocas efetuadas: %d", troca);
}


void quickSort(int TAM, int *vetor, int ini, int fim){
	
	int i, j, pivo, aux, troca = 0, trocaAux;
	
	i = ini;
	j = fim-1;
	pivo = vetor[(ini + fim)/2];
	if((j == TAM - 1)&&(i == 0)){
		trocaAux = 0;
	}
	
	while(i <= j){
		
		while((vetor[i] < pivo) && (i < fim)){
			i++;
		}
		while((vetor[j] > pivo) && (j > ini)){
			j--;
		}
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			troca++;
			i++;
			j--;
		}
	}
	
	trocaAux += troca;
	
	if(j > ini){
		quickSort(TAM, vetor, ini, j+1);
	}	
	if(i < fim){
		quickSort(TAM, vetor, i, fim);
	}
	if(i==TAM){
		printf("\nTrocas efetuadas: %d", trocaAux);
	}	
	
}

void mergeSort(int TAM, int *vetor){
  int *vetorAux = (int *)malloc(sizeof(int)*TAM);
  sort(vetor, vetorAux, 0, TAM-1);
  free(vetorAux);
}

void sort(int *vetor, int *vetorAux, int i, int f){
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(vetor, vetorAux, i, m);
  sort(vetor, vetorAux, m + 1, f);

  if (vetor[m] <= vetor[m + 1]) return;

  merge(vetor, vetorAux, i, m, f);
}

void merge(int *vetor, int *vetorAux, int i, int m, int f) {
  int z, ivetor = i, ivetorAux = m + 1;

  for (z = i; z <= f; z++) vetorAux[z] = vetor[z];

  z = i;

  while (ivetor <= m && ivetorAux <= f) {

    if (vetorAux[ivetor] <= vetorAux[ivetorAux]) vetor[z++] = vetorAux[ivetor++];
    else vetor[z++] = vetorAux[ivetorAux++];
  }

  while (ivetor <= m) vetor[z++] = vetorAux[ivetor++];

  while (ivetorAux <= f) vetor[z++] = vetorAux[ivetorAux++];
}

void selectionSort(int TAM, int *vetor){
	
	int i, j, min, aux, troca = 0;
	
	for(i=0; i<TAM-1; i++){
		
		min = i;
		
		for(j=i+1; j<TAM; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}
		
		if(i != min){
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
			troca++;
		}
		
	}
	printf("\nTrocas efetuadas: %d", troca);
	
}

