/*
 * 	Header das funcoes de utilidade
 *
 *
 * */



void menu(long int opcao) {
	if (opcao == 1) {
		printf("\nTreinamento");
		printf("\n1 - Testar Algoritmos de ordenacao");
		printf("\n2 - Testar Estruturas de dados");
		printf("\n3 - Testar Arvores e algoritmos de percurso"); 
		printf("\n0 - Sair do programa");
		printf("\nEscolha: ");
	} else if (opcao == 2) {	
		printf("\n1 - preencher array manualmente");
		printf("\n2 - preencher array de forma aleatoria automaticamente");
		printf("\n3 - visulizar array");
		printf("\n4 - ordenar array");
		printf("\n5 - esvaziar array");
		printf("\n6 - voltar ao menu inicial");
		printf("\nEscolha: ");		
	} else if (opcao == 3) {
		printf("\n1 - Ordenar array com bubble sort");
		printf("\n2 - Ordenar array com insertion sort");
		printf("\n3 - Ordenar array com quick sort");
		printf("\n4 - Ordenar array com merge sort");
		printf("\nEscolha: ");
	} else if (opcao == 4) {
		printf("\nEstruturas de Dados");
		printf("\n1 - Testar pilha");
		printf("\n2 - Testar fila");
		printf("\n3 - Testar lista ligada");
		printf("\n0 - Voltar");
		printf("\nEscolha: ");
	} else if (opcao == 5) {
		printf("\nOpcoes para a pilha");
		printf("\n1 - Empilhar elemento");
		printf("\n2 - Desempilhar elemento");
		printf("\n3 - Topo da pilha");
		printf("\n4 - Esvaziar pilha");
		printf("\n5 - Exibir toda a pilha");
		printf("\n0 - Sair");
		printf("\nEscolha: ");
	} else if (opcao == 6) {
		printf("\nOpcoes para a fila");
		printf("\n1 - Enfileirar elemento");
		printf("\n2 - Desenfileirar elemento");
		printf("\n3 - Mostrar extremidades");
		printf("\n4 - Esvaziar fila");
		printf("\n5 - Exibir toda a fila");
		printf("\n0 - Sair");
		printf("\nEscolha: ");
	} else if (opcao == 7) {
		printf("\nOpcoes para a lista");
		printf("\n1 - Adicionar elemento no comeco da lista");
		printf("\n2 - Adicionar elemento no final da lista");
		printf("\n3 - Remover elemento do comeco da lista");
		printf("\n4 - Remover elemento do final da lista");
		printf("\n5 - Adicionar elemento ordenado");
		printf("\n6 - Remover elemento especifico");
		printf("\n7 - Esvaziar lista");
		printf("\n8 - Exibir toda a lista");
		printf("\n0 - Sair");
		printf("\nEscolha: ");
	} else if (opcao == 8) {
		printf("\nOpcoes para a arvore binaria");
		printf("\n1 - Adicionar elemento na arvore");
		printf("\n2 - Buscar elemento na arvore");
		printf("\n3 - Remover elemento da arvore");
		printf("\n4 - Percorrer arvore em ordem");
		printf("\n5 - Percorrer arvore em pos ordem");
		printf("\n6 - Percorrer arvore em pre ordem");
		printf("\n7 - Esvaziar toda a arvore");
		printf("\n0 - Sair");
		printf("\nEscolha: ");
	}
}

void empty_stdin() {

	long int c = getchar();

	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}

long int verifica_entrada(long int retorno_entrada) {

	/*
	 * Retornos: 
	 *
	 * 	1 - Saida manual do usuario
	 * 	2 - Se for um caracter
	 * 	0 - Se for valida
	 * */

	if (retorno_entrada == EOF) {
		//Saida manual do usuario
		printf("\nSaida manual do usuario...");	
		return 1;
	} else if (retorno_entrada == 0) {
		//Caracter inserido em vez de long inteiro
		return 2;
	} else {
		//Entrada valida
		return 0;
	}
}

void mostrar_vetor(long int *vetor, long int tamanho_vetor) {
	printf("\n");
	printf("\nArray: ");
	for (long int i = 0; i < tamanho_vetor; i++) {
		printf(" %li", vetor[i]);
	}
	printf("\n");
}

void preencher_vetor(long int *vetor, long int tamanho_vetor) {
	
	srand(time(NULL));

	for (long int i = 0; i < tamanho_vetor; i++) {
		vetor[i] = rand() % tamanho_vetor + 1;
	}
}
