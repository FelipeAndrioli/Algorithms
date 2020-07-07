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
		return rotacaoDireita(raiz);
	} else if(temp_balance < -1 && nelemento > raiz->direita->elemento) {
		//direita -> direita = rotacao esquerda
		return rotacaoEsquerda(raiz);
	} else if(balance > 1 && nelemento > raiz->esquerda->elemento) {
		//esquerda -> direita = rotacao esquerda + rotacao direita
		raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
		return rotacaoDireita(raiz);
	} else if(balance < -1 && nelemento < raiz->direita->elemento) {
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

void *removeTreeElement(arvore *tree, arvore_no *arvore_novo_no) {
	
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

