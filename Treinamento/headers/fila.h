#include <limits.h>

typedef struct fila_no {
	int elemento;
	struct fila_no *proximo;
} fila_no;

typedef struct Fila {
	struct fila_no *inicio;
	struct fila_no *fim;
} fila;

fila* newQueue() {
	fila *queue = malloc(sizeof(queue));
	queue->inicio = NULL;
	queue->fim = NULL;

	return queue;
}

fila_no* newQueueNode(int n_elemento) {
	fila_no *novo_no = malloc(sizeof(novo_no));
	novo_no->elemento = n_elemento;
	novo_no->proximo = NULL;

	return novo_no;
}

int isQueueEmpty(fila *queue) {
	return !queue->inicio;
}

void getQueueEmpty(fila *queue) {
	if(!isQueueEmpty(queue)) {
		free(queue->inicio);
		free(queue->fim);
		printf("\nEsvaziando fila.\n");
		queue->inicio = NULL;
		queue->fim = NULL;
	} else {
		printf("\nFila ja esta vazia!\n");
	}
}

void enfileirar(fila *queue, fila_no *novo_no) {
	novo_no->proximo = NULL;
	if(queue->inicio == NULL) {
		queue->inicio = novo_no;
		queue->fim = novo_no;
		printf("\n%d elemento enfileirado.\n", novo_no->elemento);
	} else {
		queue->fim->proximo = novo_no;
		queue->fim = novo_no;
		printf("\n%d elemento enfileirado.\n", novo_no->elemento);
	}
}

int desenfileirar(fila *queue) {
	if(isQueueEmpty(queue)) {
		return INT_MIN;
	} else {
		int desenfileirado = queue->inicio->elemento;
		fila_no *temp = queue->inicio;
		queue->inicio = queue->inicio->proximo;
		free(temp);
		if(queue->inicio == NULL) {
			queue->fim = NULL;
		}

		return desenfileirado;
	}
}

void showQueue(fila *queue) {
	if(isQueueEmpty(queue)) {
		printf("\nFila vazia!\n");
		return;
	} else {
		fila_no *temp = queue->inicio;
		printf("\nFila: ");
		while(temp != NULL) {
			printf("%d ", temp->elemento);
			temp = temp->proximo;
		}
	}
}

void mostrarExtremidades(fila *queue) {
	if(isQueueEmpty(queue)) {
		printf("\nFila vazia!\n");
		return;
	} else {
		printf("\nInicio da fila: %d\n", queue->inicio->elemento);
		printf("\nFinal da fila: %d\n", queue->fim->elemento);
	}
}
