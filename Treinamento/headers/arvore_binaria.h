typedef struct arvore_no {
	int elemento;
	struct arvore_no *direita;
	struct arvore_no *esquerda;
}arvore_no;

typedef struct arvore {
	struct arvore_no *raiz;
} arvore;

arvore* newTree() {
	arvore *tree = malloc(sizeof(tree));
	tree->raiz = NULL;

	return tree;
}

arvore_no* newTreeNode(int n_elemento) {
	arvore_no *new_arvore_node = malloc(sizeof(new_arvore_node));
	new_arvore_node->elemento = n_elemento;
	new_arvore_node->direita = NULL;
	new_arvore_node->esquerda = NULL;

	return new_arvore_node;
}

void *insertTreeElement(arvore *tree, arvore_no *novo_arvore_no) {
	if(tree->raiz == NULL) {
		tree->raiz = novo_arvore_no;
		tree->raiz->esquerda = NULL;
		tree->raiz->direita = NULL;
		printf("\n%d - elemento adicionado a arvore!\n", novo_arvore_no->elemento);
	} else {
		if(novo_arvore_no->elemento < tree->raiz->elemento) {
			//valor mearvore_nor que o da raiz, vai pra esquerda
			arvore *temp_tree = newTree();
			temp_tree->raiz = tree->raiz->esquerda;
			tree->raiz->esquerda = insertTreeElement(temp_tree, novo_arvore_no);
			printf("\nPercorrendo esquerda!\n");
			//tree->raiz->esquerda = insertTreeElement(tree->raiz->esquerda, novo_arvore_no);
		} else if(novo_arvore_no->elemento > tree->raiz->elemento) {
			arvore *temp_tree = newTree();
			temp_tree->raiz = tree->raiz->direita;
			tree->raiz->direita = insertTreeElement(temp_tree, novo_arvore_no);
			printf("\nPercorrendo direita!\n");
			//tree->raiz->direita = insertTreeElement(tree->raiz->direita, novo_arvore_no);
		}
	}	
}

void *removeTreeElement(arvore *tree, arvore_no *arvore_novo_no) {
	if(tree->raiz != NULL) {
		if(arvore_novo_no->elemento < tree->raiz->elemento) {
			arvore *temp_tree = newTree();
			temp_tree->raiz = tree->raiz->esquerda;
			tree->raiz->esquerda = removeTreeElement(temp_tree, arvore_novo_no);
//			tree->raiz->esquerda = removeTreeElement(arvore->raiz->esquerda);
		} else if(arvore_novo_no->elemento > tree->raiz->elemento) {
			arvore *temp_tree = newTree();
			temp_tree->raiz = tree->raiz->direita;
			tree->raiz->direita = removeTreeElement(temp_tree, arvore_novo_no);
//			tree->raiz->direita = removeTreeElement(arvore->raiz->direita);
		}

	} else {
		if(tree->raiz->esquerda == NULL && tree->raiz->direita == NULL) {
			free(tree->raiz);
			tree->raiz == NULL;
		} else if(tree->raiz->esquerda = NULL) {
			arvore_no *temp = tree->raiz;
			tree->raiz = tree->raiz->direita;
			free(temp);
		} else if(tree->raiz->direita = NULL) {
			arvore_no *temp = tree->raiz;
			tree->raiz = tree->raiz->esquerda;
			free(temp);
		} else {
			//arvore_nos filhos dos dois lados
			arvore_no *maior = tree->raiz->esquerda;
			while(maior->direita != NULL) {
				maior = maior->direita;
			}
			tree->raiz->elemento = maior->elemento;
			maior->elemento = arvore_novo_no->elemento;
			arvore *temp_tree = newTree();
			temp_tree->raiz = tree->raiz->esquerda;
			tree->raiz->esquerda = removeTreeElement(temp_tree, arvore_novo_no);
//			tree->raiz->esquerda = removeTreeElement(tree->raiz->esquerda, arvore_novo_no);
		}
	}
}

arvore_no *searchTreeNode(arvore *tree, arvore_no *b_arvore_no) {
	arvore_no *temp;
	if(tree->raiz == NULL) {
		temp = NULL;
	} else if(b_arvore_no->elemento == tree->raiz->elemento) {
		temp = tree->raiz;
	} else if(b_arvore_no->elemento < tree->raiz->elemento) {
		arvore *temp_tree = newTree();
		temp_tree->raiz = tree->raiz->esquerda;
		temp = searchTreeNode(temp_tree, b_arvore_no);
	}
	return temp;
}

void showInOrder(arvore *tree) {
	if(tree->raiz == NULL) {
		printf("\nA arvore esta vazia!\n");
		return;
	} else {
		arvore *temp_tree = newTree();
		temp_tree->raiz = tree->raiz->esquerda;
		showInOrder(temp_tree);
		printf("\n%d\n", temp_tree->raiz->elemento);
		arvore *temp_tree_sec = newTree();
		temp_tree_sec->raiz = tree->raiz->direita;
		showInOrder(temp_tree_sec);
	}
}

void showInPostOrder(arvore *tree) {
	if(tree->raiz == NULL) {
		printf("\nA arvore esta vazia!\n");
		return;
	} else {
		arvore *temp_tree_esq = newTree();
		arvore *temp_tree_dir = newTree();
		temp_tree_esq->raiz = tree->raiz->esquerda;
		temp_tree_dir->raiz = tree->raiz->direita;
		showInPostOrder(temp_tree_esq);
		showInPostOrder(temp_tree_dir);
		printf("\n%d\n",tree->raiz->elemento);
	}
}

void showInPreOrder(arvore *tree) {
	if(tree->raiz == NULL) {
		printf("\nA arvore esta vazia!\n");
		return;
	} else {
		arvore *temp_tree_esq = newTree();
		arvore *temp_tree_dir = newTree();
		temp_tree_esq->raiz = tree->raiz->esquerda;
		temp_tree_dir->raiz = tree->raiz->direita;
		printf("\n%d\n", tree->raiz->elemento);
		showInPreOrder(temp_tree_esq);
		showInPreOrder(temp_tree_dir);
	}
}
