#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "Sorting_Algorithms.h"
#define TAM 50000

int* gerador(int tam){
	
	int *vetor = (int *)malloc(sizeof(int)*tam);
	
	if (vetor != NULL) {
		srand(time(NULL));
		for (int i = 0; i < tam; i++){
			vetor[i] = rand() % 1000;
		}
		return vetor;
	}
	else {
		printf("Problema de memoria");
		exit(1);
	}

}

int main(){
	
	int *vetor = gerador(TAM);
	
	clock_t Ticks[2];
	Ticks[0] = clock();
	
	printf("Vetor: \n[");
	for(int i=0; i<TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("]");

	bubbleSort(TAM, vetor);
	quickSort(TAM, vetor, 0, TAM);
	mergeSort(TAM, vetor);
	selectionSort(TAM, vetor);
	
	
	printf("\n\nVetor Ordenado: \n[");
	for(int i=0; i<TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("]");
	
	printf("\n\n");
	Ticks[1] = clock();
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\n  Tempo gasto: %g ms.\n", Tempo);
	
	return 0;
	
}

