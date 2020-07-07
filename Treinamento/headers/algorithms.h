#include <time.h>

/*
 *	Header de dos algoritmos
 *
 * */

void swap (long int *a, long int *b) {
	long int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort (long int *array, long int tamanho_array) {

	for (long int i = 0; i < tamanho_array; i++) {
		for (long int j = 0; j < tamanho_array - i; j++) {
			if (array[i] > array[i+1]) {
				swap(&array[i], &array[i+1]);
			}
		}
	}
}

void insertion_sort (long int *array, long int tamanho_array) {

	long int ultimo; 
	long int j;

	for (long int i = 0; i < tamanho_array; i++) {
		ultimo = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > ultimo) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = ultimo;
	}
}

int particionar (long int *array, long int menor, long int maior) {
	int pivo = array[maior];
	int i = menor - 1;

	for (int j = menor; j <= maior - 1; j++) {
		if (array[j] < pivo) {
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[maior]);
	return (i + 1);
}

void quick_sort (long int *array, long int menor, long int maior) {
	/*
	 *	Quick Sort
	 *	
	 *	O quick sort eh um metodo de dividir e conquistar, onde
	 *	o algoritmo pega um elemento como pivo e particiona a array
	 *	perto do elemento. Possiveis maneiras de selecionar o pivo:
	 *
	 *		- Sempre o primeiro elemento
	 *		- Sempre o ultimo elemento
	 *		- Pegar um elemento aleatorio
	 *		- Pegar um elemento mediano	
	 * */

	if (menor < maior) {
		int aux = particionar(array, menor, maior);

		quick_sort(array, menor, aux - 1);
		quick_sort(array, aux + 1, maior);
	}
}

void merge (long int *array, long int comeco, long int meio, long int fim) {
	
	long int index_esquerdo = comeco;
	long int index_direito = meio + 1;
	long int index_auxiliar = 0;
	long int tamanho = fim - comeco + 1;
	long int *array_auxiliar = (long int*) malloc(tamanho * sizeof(tamanho));

	while (index_esquerdo <= meio && index_direito <= fim) {
		if (array[index_esquerdo] < array[index_direito]) {
			array_auxiliar[index_auxiliar] = array[index_esquerdo];
			index_esquerdo++;
		} else {
			array_auxiliar[index_auxiliar] = array[index_direito];
			index_direito++;
		}
		index_auxiliar++;
	}

	while (index_esquerdo <= meio) {
		array_auxiliar[index_auxiliar] = array[index_esquerdo];
		index_auxiliar++;
		index_esquerdo++;
	}

	while (index_direito <= fim) {
		array_auxiliar[index_auxiliar] = array[index_direito];
		index_auxiliar++;
		index_direito++;
	}

	for (long int i = comeco; i <= fim; i++) {
		array[i] = array_auxiliar[i - comeco];
	}

	free(array_auxiliar);
}

void merge_sort (long int *array, long int comeco, long int fim) {
	
	if (comeco < fim) {

		long int meio = (fim + comeco) / 2;

		merge_sort(array, comeco, meio);
		merge_sort(array, meio + 1, fim);
		merge(array, comeco, meio, fim);
	}
}

void seleciona_ordenacao (long int *array, long int tamanho_array, int opcao) {
	clock_t time;
	time = clock();
	
	if (opcao == 1) {
		printf("\nOrdenacao com Bubble Sort!");
		bubble_sort(array, tamanho_array - 1);
	} else if (opcao == 2) {
		printf("\nOrdenacao com Insertion Sort!");
		insertion_sort(array, tamanho_array);
	} else if (opcao == 3) {
		printf("\nOrdenacao com Quick Sort!");
		quick_sort(array, 0, tamanho_array - 1);
	} else if (opcao == 4) {
		printf("\nOrdenacao com Merge Sort!");
		merge_sort(array, 0, tamanho_array - 1);
	}

	time = clock() - time;
	printf("\nArray ordenado!!");
	double tempo_tomado = ((double) time) / CLOCKS_PER_SEC;
	printf("\nO algoritmo levou %f segundos para ordenar o array.", tempo_tomado);
}
