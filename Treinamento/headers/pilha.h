#include <limits.h>

typedef struct pilha_no {
	int elemento;
	struct pilha_no *proximo;
} pilha_no;


typedef struct Pilha {
	struct pilha_no *inicio;
	struct pilha_no *topo;
} pilha;

pilha* newStack() {
	pilha *stack = malloc(sizeof(stack));
	stack->inicio = NULL;
	stack->topo = NULL;

	return stack;
}

pilha_no* newStackNode(int n_elemento) {
	pilha_no *novo_no = malloc(sizeof(novo_no));
	novo_no->elemento = n_elemento;
	novo_no->proximo = NULL;

	return novo_no;
}

int isStackEmpty(pilha *stack) {
	return !stack->topo;
}

void getStackEmpty(pilha *stack) {
	if(isStackEmpty(stack)) {
		free(stack->topo);
		printf("\nEsvaziando pilha.\n");
		stack->topo = NULL;
	} else {
		printf("\nPilha ja esta vazia!\n");
	}
}

void push(pilha *stack, pilha_no *novo_no) {
	if(isStackEmpty(stack)) {
		stack->inicio = novo_no;
		stack->topo = novo_no;
		printf("\n%d elemento adicionado.\n", novo_no->elemento);
	} else {
		stack->topo->proximo = novo_no;
		stack->topo = novo_no;
		printf("\n%d elemento adicionado.\n", novo_no->elemento);
	}
}

int pop(pilha *stack) {
	if(isStackEmpty(stack)) {
		return INT_MIN;
	} else {
		int popped = stack->topo->elemento;
	    	if(stack->topo == stack->inicio) {
	      		free(stack->topo);
	      		stack->topo = NULL;
	      		stack->inicio = NULL;
	    	} else {
	      		pilha_no *temp = stack->inicio;
	      		
			while(temp->proximo != stack->topo) {
				temp = temp->proximo;
			}

			temp->proximo = NULL;
	      		free(stack->topo);
	      		stack->topo = temp;
	    	}
	    	
		return popped;
	}
}

void showStack(pilha *stack) {
	if(isStackEmpty(stack)) {
		printf("\nPilha vazia!\n");
		return;
	} else {
		pilha_no *temp = stack->inicio;
		printf("\nPilha: ");
		while(temp != NULL) {
			printf(" %d", temp->elemento);
			temp = temp->proximo;
		}
	}
}

