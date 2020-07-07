#include <limits.h>

typedef struct no {
	int elemento;
	struct no *proximo;
	struct no *anterior;
}no;

typedef struct lista {
	struct no *inicio;
	struct no *fim;
}lista;

lista* newList() {
	lista *list = (struct lista*) malloc(sizeof(lista));
	list->inicio = NULL;
	list->fim = NULL;

	return list;
}

no* newListNode(int n_elemento) {
	no *new_node = (struct no*) malloc(sizeof(no));
	new_node->elemento = n_elemento;
	new_node->proximo = NULL;
	new_node->anterior = NULL;

	return new_node;
}

int isListEmpty(lista *list) {
	return !list->inicio;
}

void getListEmpty(lista *list) {
	if(!isListEmpty(list)) {
		no *temp_inicio = list->inicio;
		no *temp_fim = list->fim;
		free(temp_inicio);
		free(temp_fim);
		printf("\nEsvaziando lista...\n");
		list->inicio = NULL;
		list->fim = NULL;
	} else {
		printf("\nLista ja esta vazia!\n");
	}
}

void insertOnBegin(lista *list, no *novo_no) {
	if(isListEmpty(list)) {
		list->inicio = novo_no;
		list->inicio->proximo = NULL;
		list->inicio->anterior = NULL;
		list->fim = novo_no;
		list->fim->proximo = NULL;
		list->fim->anterior = NULL;
		printf("\n%d elemento adicionado ao comeco da lista.\n", novo_no->elemento);
	} else {
		novo_no->anterior = NULL;
		novo_no->proximo = list->inicio;
		list->inicio->anterior = novo_no;
		list->inicio = novo_no;
		printf("\n%d elemento adicionado ao comeco da lista.\n", novo_no->elemento);
	}
}

void insertOnEnd(lista *list, no *novo_no) {
	if(isListEmpty(list)) {
		list->inicio = novo_no;
		list->inicio->proximo = NULL;
		list->inicio->anterior = NULL;
		list->fim = novo_no;
		list->fim->proximo = NULL;
		list->fim->anterior = NULL;
		printf("\n%d elemento adicionado ao final da lista.\n", novo_no->elemento);
	} else {
		novo_no->proximo = NULL;
		novo_no->anterior = list->fim;
		list->fim->proximo = novo_no;
		list->fim = novo_no;
		printf("\n%d elemento adicionado ao final da lista.\n", novo_no->elemento);
	}
}

void insertOrderedElement(lista *list, no *novo_no) {
	if(isListEmpty(list)) {		
		novo_no->proximo = NULL;
		novo_no->anterior = NULL;
		list->inicio = novo_no;
		list->fim = novo_no;
		printf("\n%d elemento adicionado a sua posicao ordenada na lista.\n", novo_no->elemento);
	} else {
		no *temp = list->inicio;

		while(temp->proximo != NULL && temp->elemento < novo_no->elemento) {
			temp = temp->proximo;
		}

		if(temp->anterior == NULL) {
			insertOnBegin(list, novo_no);
		} else if(temp->proximo == NULL) {
			insertOnEnd(list, novo_no);
		} else {

			no *temp_anterior = temp->anterior;
			temp->anterior = novo_no;
			novo_no->proximo = temp;
			novo_no->anterior = temp_anterior;
			temp_anterior->proximo = novo_no;
			
			printf("\n%d elemento adicionado a sua posicao ordenada na lista.\n", novo_no->elemento);
		}
	}
}

int removeFromBegin(lista *list) {
	if(isListEmpty(list)) {
		return INT_MIN;
	} else {
		
		int elemento_removido = list->inicio->elemento;
		no *temp = list->inicio;

		if(temp->anterior == NULL && temp->proximo == NULL) {
			list->inicio = NULL;
			list->fim = NULL;
			free(temp);
			return elemento_removido;
		} else {
				
			list->inicio = list->inicio->proximo;
			list->inicio->anterior = NULL;
			free(temp);
			if(list->inicio == NULL) {
				list->fim = NULL;
			}
			return elemento_removido;

		}
	}
}

int removeFromEnd(lista *list) {
	if(isListEmpty(list)) {
		return INT_MIN;
	} else {
		int elemento_removido = list->fim->elemento;
		no *temp = list->fim;

		if(temp->anterior == NULL && temp->proximo == NULL) {
			list->inicio = NULL;
			list->fim = NULL;
			free(temp);
			return elemento_removido;
		} else {

			list->fim = list->fim->anterior;
			list->fim->proximo = NULL;
			free(temp);
			if(list->fim == NULL) {
				list->inicio = NULL;
			}
			return elemento_removido;

		}
	}
}

int removeSpecificElement(lista *list, no *no_rm) {
	if(isListEmpty(list)) {
		return INT_MIN;
	} else {
		no *temp = list->inicio;
		int elemento_removido;

		while(temp->proximo != NULL && temp->elemento != no_rm->elemento) {
			temp = temp->proximo;
		}

		if(temp == NULL) {
			return SHRT_MIN;
		} else if(temp->elemento == no_rm->elemento) {
			if (temp->proximo == NULL && temp->anterior == NULL && temp->elemento != no_rm->elemento) {
				return SHRT_MIN;
			} else if (temp->elemento == no_rm->elemento && temp->anterior == NULL) {
				elemento_removido = removeFromBegin(list);
				return elemento_removido;
			} else if (temp->elemento == no_rm->elemento && temp->proximo == NULL) {
				elemento_removido = removeFromEnd(list);
				return elemento_removido;
			} else if (temp->elemento == no_rm->elemento && temp->proximo == NULL && temp->anterior == NULL) {
				elemento_removido = temp->elemento;
				getListEmpty(list);
				return elemento_removido;
			} else {

				elemento_removido = temp->elemento;
				no *temp_anterior = temp->anterior;
				no *temp_proximo = temp->proximo;

				temp_anterior->proximo = temp_proximo;
				temp_proximo->anterior = temp_anterior;
				free(temp);
				return elemento_removido;
			
			}
		} else {
			return SHRT_MIN;
		}
	}
}

void showList(lista *list) {
	if(isListEmpty(list)) {
		printf("\nLista vazia!\n");
	} else {
		no *temp = list->inicio;
		printf("\nLista: ");
		while(temp != NULL) {
			printf(" %d ", temp->elemento);
			temp = temp->proximo;
		}
	}
}
