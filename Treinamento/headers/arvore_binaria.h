typedef struct arvore_no {
	int elemento;
	int altura;
	struct arvore_no *direita;
	struct arvore_no *esquerda;
}arvore_no;

typedef struct arvore {
	struct arvore_no *raiz;
} arvore;

arvore* newTree() {
	arvore *tree = (struct arvore*) malloc(sizeof(arvore));
	tree->raiz = NULL;

	return tree;
}

arvore_no* newTreeNode(int n_elemento) {
	arvore_no *new_arvore_node = (struct arvore_no*) malloc(sizeof(arvore_no));
	new_arvore_node->elemento = n_elemento;
	new_arvore_node->altura = 1;
	new_arvore_node->direita = NULL;
	new_arvore_node->esquerda = NULL;

	return new_arvore_node;
}

int getMax(int a, int b) {
	return (a > b) ? a : b;
}

arvore_no *insertTreeElement(arvore_no *raiz, int nelemento) {
	
	if(raiz == NULL) {
		raiz = newTreeNode(nelemento);
		printf("\n%d - elemento adicionado a arvore!\n", raiz->elemento);
	} else {
		if(nelemento < raiz->elemento) {
			raiz->esquerda = insertTreeElement(raiz->esquerda, nelemento);
		} else if(nelemento > raiz->elemento) {
			raiz->direita = insertTreeElement(raiz->direita, nelemento);
		} else {
			return raiz;
		}

	}

	raiz->altura = 1 + getMax(getTreeHeight(raiz->esquerda), getTreeHeight(raiz->direita));

	int temp_balance = getBalance(raiz);

	if(temp_balance > 1 && nelemento < raiz->esquerda->elemento) {
		//esquerda -> esquerda = rotacao direita
		//rotacao simples
		return rotacaoDireita(raiz);
	} else if(temp_balance < -1 && nelemento > raiz->direita->elemento) {
		//direita -> direita = rotacao esquerda
		//rotacao simples
		return rotacaoEsquerda(raiz);
	} else if(balance > 1 && nelemento > raiz->esquerda->elemento) {
		//rotacao dupla
		//esquerda -> direita = rotacao esquerda + rotacao direita
		raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
		return rotacaoDireita(raiz);
	} else if(balance < -1 && nelemento < raiz->direita->elemento) {
		//rotacao dupla
		//direita -> esquerda = rotacao direita + rotacao esquerda
		raiz->direita = rotacaoDireita(raiz->direita);
		return rotacaoEsquerda(raiz);
	}

	return raiz;
}

void insertTreeNode(arvore *tree, int n_element) {
	tree->raiz = insertTreeElement(tree->raiz, n_element);
}

int getTreeHeight(arvore *tree) {
	if(tree->raiz == NULL) {
		return 0;
	}

	return tree->raiz->altura;
}

int getBalance(arvore_no *raiz) {
	if(raiz == NULL) {
		return 0;
	}
	return getTreeHeight(raiz->esquerda) - getTreeHeight(raiz->direita);
}

arvore_no *noMenorValor(arvore_no *raiz) {
	arvore_no *temp_atual = raiz;

	while(temp_atual->esquerda != NULL) {
		temp_atual = temp_atual->esquerda;
	}

	return temp_atual;
}

arvore_no *removeTreeNode(arvore_no *raiz, int r_elemento) {
	if(raiz == NULL) {
		return raiz;	
	} else {
		if(r_elemento < raiz->elemento) {
			raiz->esquerda = removeTreeNode(raiz->esquerda, r_elemento);
		} else if(r_elemento > raiz->elemento) {
			raiz->direita = removeTreeNode(raiz->direita, r_elemento);
		} else {
			if((raiz->esquerda == NULL) || raiz->direita == NULL) {
				arvore_no *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
				if(temp == NULL) {
					temp = raiz;
					raiz = NULL;
				} else {
					*raiz = *temp;
					free(temp);
				}
			} else {
				arvore_no temp = noMenorvalor(raiz->direita);
				raiz->elemento = temp->elemento;
				raiz->direita = removeTreeNode(raiz->direita, temp->elemento);

			}
		}

		if(raiz == NULL) {
			return raiz;
		}

		raiz->altura = 1 + getMax(getHeight(raiz->esquerda), getHeight(raiz->direita));
		int balance = getBalance(raiz);

		if(balance > 1 && getBalance(raiz->esquerda) >= 0) {
			//rotacao simples
			//esquerda -> esquerda = rotacao direita
			return rotacaoDireita(raiz);
		} else if(balance > 1 && getBalance(raiz->esquerda) < 0) {
			//rotacao dupla
			//esquerda -> direita = rotacao dupla direita
			raiz->esquerda = rotacaoDireita(raiz->esquerda);
			return rotacaoDireita(raiz);
		} else if(balance < -1 && getBalance(raiz->direita) <= 0) {
			//rotacao simples
			//direita -> direita = rotacao simples esquerda
			return rotacaoEsquerda(raiz);
		} else if(balance < -1 && getBalance(raiz->direita) > 0) {
			//rotacao dupla
			//direita -> esquerda = rotacao dupla esquerda
			raiz->direita = rotacaoDireita(raiz->direita);
			return rotacaoEsquerda(raiz);
		}
	}

	return raiz;
}

void *removeTreeElement(arvore *tree, int r_elemento) {
	arvore_no *no_removido = removeTreeNode(tree->raiz, r_elemento);	
	printf("\n%d - Elemento removido!\n", no_removido->elemento);
}

arvore_no *searchTreeNode(arvore_no *raiz, int s_element) {
	
	arvore_no *temp;

	if(raiz == NULL) {
		temp = NULL;
	} else if(raiz->elemento == s_element) {
		temp = raiz;
	} else if(raiz->elemento > s_element) {
		temp = searchTreeNode(raiz->esquerda, s_element);
	} else if(raiz->elemento < s_element) {
		temp = searchTreeNode(raiz->direita, s_element);
	}
	return temp;
}

void showNodeInOrder(arvore_no *raiz) {
	if(raiz == NULL) {
		//printf("\nA arvore esta vazia!\n");
		return;
	} else {
		showInOrder(raiz->esquerda);
		printf("\n%d\n", raiz->elemento);
		showInOrder(raiz->direita);
	}
}

void showNodeInPostOrder(arvore_no *raiz) {
	if(raiz == NULL) {
		//printf("\nA arvore esta vazia!\n");
		return;
	} else {
		showInPostOrder(raiz->esquerda);
		showInPostOrder(raiz->direita);
		printf("\n%d\n",raiz->elemento);
	}
}

void showNodeInPreOrder(arvore_no *raiz) {
	if(raiz == NULL) {
		//printf("\nA arvore esta vazia!\n");
		return;
	} else {
		printf("\n%d\n", raiz->elemento);
		showInPreOrder(raiz->esquerda);
		showInPreOrder(raiz->direita);
	}
}

void *searchTreeElement(arvore *tree, int s_element) {
	
	arvore_no *busca_no = searchTreeNode(tree->raiz, s_element);

	if(busca_no == NULL) {
		printf("\nElemento nao encontrado!\n");
		break;
	} else {
		printf("\nElemento no endereco %p eh %d\n", busca_no, busca_no->elemento);
		break;
	}
	free(busca_no);

}

void getTreeEmpty(arvore *tree) {
	tree->raiz = NULL;
}

void showTreeinOrder(arvore *tree) {
	showNodeInOrder(tree->raiz);
}

void showTreeInPostOrder(arvore *tree) {
	showNodeInPostOrder(tree->raiz);
}

void showTreeInPreOrder(arvore *tree) {
	showNodeInPreOrder(tree->raiz);
}

arvore_no *rotacao_direita(arvore_no *raiz) {
	arvore_no *sub_arvore = raiz->esquerda;
	arvore_no *folha = sub_arvore->direita;

	sub_arvore->direita = folha;
	raiz->esquerda = folha;

	raiz->altura = getMax(getTreeHeight(folha->esquerda), getTreeHeight(folha->direita)) + 1;
	sub_arvore->altura = getMax(getTreeHeight(sub_arvore->esquerda), getThreeHeight(sub_arvore->direita)) + 1;

	return raiz;
}

arvore_no *rotacao_esquerda(arvore_no *raiz) {
	arvore_no *sub_arvore = raiz->direita;
	arvore_no *folha = sub_arvore->esquerda;

	sub_arvore->esquerda = folha;
	raiz->direita = folha;

	raiz->altura = getMax(getTreeHeight(raiz->esquerda), getTreeHeight(raiz->direita)) + 1;
	sub_arvore->altura = getMax(getThreeHeight(sub_arvore->esquerda), getTreeHeight(sub_arvore->direita)) + 1;

	return raiz;
}

