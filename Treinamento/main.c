#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./headers/utility.h"
#include "./headers/algorithms.h"
#include "./headers/pilha.h"
#include "./headers/fila.h"
#include "./headers/lista_ligada.h"
#include "./headers/arvore_binaria.h"

int main(int argc, char *argv[]) {

	long int opcao;
	long int retorno_entrada_user;
	long int tamanho_vetor = 0;
	long int *vetor;
	long int temp;
	pilha *stack = newStack();
	fila *queue = newQueue();
	lista *list = newList();
	arvore *tree = newTree();

	for (;;) {
		//loop ate o break
		menu(1);
		retorno_entrada_user = scanf("%li", &opcao);

		if (verifica_entrada(retorno_entrada_user) == 0 && opcao == 1) {
			empty_stdin();
			opcao = 0;
			
			for(;;){
				menu(2);
				retorno_entrada_user = scanf("%li", &opcao);

				if(verifica_entrada(retorno_entrada_user) == 2) {
					printf("\nCaracteres nao sao entradas validas!");
					empty_stdin();
				} else if(opcao == 1) {
					//preencher o vetor manualmente
					for(;;) {
						printf("\nDigite o tamanho da array: ");
						retorno_entrada_user = scanf("%li", &tamanho_vetor);

						if(verifica_entrada(retorno_entrada_user) == 2){
							printf("\nCaracteres nao sao entradas validas!");
							empty_stdin();
						} else if(tamanho_vetor < 0) {
							printf("\nArray nao pode ter um tamanho negativo!");
						} else if(tamanho_vetor > 0) {
							vetor = (long int*) malloc(tamanho_vetor * sizeof(long int));

							if (vetor == NULL) {
								printf("\nErro ao alocar memoria!!");
								exit (EXIT_FAILURE);
							}
							break;
						}
					}

					for (long int i = 0; i < tamanho_vetor; i++) {
						for(;;) {
							printf("\nValor a ser inserido no array: ");
							retorno_entrada_user = scanf("%li", &temp);
							if(verifica_entrada(retorno_entrada_user) == 2){
								printf("\nCaracteres nao sao entradas validas!");
								empty_stdin();
							} else if(temp < 0) {
								printf("\nA array nao aceita numeros negativos!");
							} else if (temp >= 0) {
								vetor[i] = temp;
								break;
							}
						}
					}
				} else if (opcao == 2) {
					for(;;) {
						printf("\nDigite o tamanho do array: ");
						retorno_entrada_user = scanf("%li", &tamanho_vetor);
						
						if(verifica_entrada(retorno_entrada_user) == 2){
							printf("\nCaracteres nao sao entradas validas!");
							empty_stdin();
						} else if(tamanho_vetor < 0) {
							printf("\nO array nao pode ter um tamanho negativo!");
						} else if(tamanho_vetor > 0) {
							vetor = (long int*) malloc(tamanho_vetor * sizeof(long int));

							if (vetor == NULL) {
								printf("\nErro ao alocar memoria!!");
								exit (EXIT_FAILURE);
							}

							break;
						}
					}
					//preencher o vetor automaticamente e aleatoriamente
					preencher_vetor(vetor, tamanho_vetor);
				} else if (opcao == 3) {
					//mostrar o array
					if(tamanho_vetor == 0) {
						printf("\nArray vazio!\n");
					} else {
						mostrar_vetor(vetor, tamanho_vetor);	
					}
				} else if (opcao == 4) {
					//ordenar usando bubble sort
					if(tamanho_vetor == 0) {
						printf("\nO array se encontra vazio!");
					} else {
						for (;;) {
							menu(3);
							retorno_entrada_user = scanf("%d", &opcao);
							
							if (verifica_entrada(retorno_entrada_user) == 2) {
								printf("\nCaracteres nao sao entradas validas!");
								empty_stdin();
							} else {
								seleciona_ordenacao(vetor, tamanho_vetor, opcao);	
								break;
							}
						}
					}
				} else if (opcao == 5) {
					//limpar o array
					if(tamanho_vetor == 0) {
						printf("\nArray ja esta vazio!\n");
					} else {
						printf("\nEsvaziando array...\n");
						tamanho_vetor = 0;
					}
				} else if (opcao == 6) {
					//voltar ao menu inicial
					printf("\nVoltando ao menu inicial...");
					break;
				}
			}

		} else if (verifica_entrada(retorno_entrada_user) == 0 && opcao == 2) {	
			//Estruturas de Dados..
			for(;;) {
				menu(4);
				retorno_entrada_user = scanf("%d", &opcao);
				
				if(verifica_entrada(retorno_entrada_user) == 2) {
					printf("\nCaracteres nao sao entradas validas!\n");
					empty_stdin();
				} else if(opcao == 1) {
					//Pilha

					int elemento;

					for(;;) {
						menu(5);
						retorno_entrada_user = scanf("%d", &opcao);

						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!\n");
							empty_stdin();
						} else if(opcao == 1) {
							for(;;) {
								printf("\nDigite o elemento a ser empilhado: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validas!\n");
									empty_stdin();
								} else {
									printf("\nInserindo elemento na pilha...\n");
									pilha_no *new_node = newStackNode(elemento);
									push(stack, new_node);	
									break;
								}
							}
						} else if(opcao == 2) {
							int temp = pop(stack);
							if(temp == INT_MIN) {
								printf("\nA pilha ja esta vazia!\n");
							} else {
								printf("\n%d - Elemento desempilhado.\n", temp);	
							}
						} else if(opcao == 3) {
							if(isStackEmpty(stack)) {
								printf("\nPilha vazia!\n");
							} else {
								printf("\n%d - Elemento no topo da pilha\n", *stack->topo);
							}
						} else if(opcao == 4) {
							getStackEmpty(stack);
							stack->topo = NULL;
						} else if(opcao == 5) {
//							printf("\nExibindo pilha completa...\n");
							showStack(stack);
					 	} else if(opcao == 0) {
							free(stack);
							printf("\nVoltando...\n");
							break;
						}
					}
				} else if(opcao == 2) {
				//Fila
				/*
				printf("\nOpcoes para a fila");
				printf("\n1 - Enfileirar elemento");
				printf("\n2 - Desenfileirar elemento");
				printf("\n3 - Mostrar extremidades");
				printf("\n4 - Esvaziar fila");
				printf("\n5 - Exibir toda a fila");
				printf("\n0 - Exibir toda a fila");
				printf("\nEscolha: ");
				*/
					int elemento;

					for(;;) {
						menu(6);
						retorno_entrada_user = scanf("%d", &opcao);

						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!\n");
							empty_stdin();
						} else if(opcao == 1) {
							for(;;) {
								printf("\nDigite o elemento a ser enfileirado: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validas!\n");
									empty_stdin();
								} else {
									printf("\nInserindo elemento na fila...\n");
									fila_no *new_node = newQueueNode(elemento);
									enfileirar(queue, new_node);	
									break;
								}
							}
						} else if(opcao == 2) {
							int temp = desenfileirar(queue);
							if(temp == INT_MIN) {
								printf("\nA fila ja esta vazia!\n");
							} else {
								printf("\n%d - Elemento desenfileirado.\n", temp);	
							}
						} else if(opcao == 3) {
							//Mostrar extremidades	
							mostrarExtremidades(queue);
						} else if(opcao == 4) {
							getQueueEmpty(queue);
						} else if(opcao == 5) {
//							printf("\nExibindo fila completa...\n");
							showQueue(queue);
					 	} else if(opcao == 0) {
							free(queue);
							printf("\nVoltando...\n");
							break;
						}
					}

				} else if(opcao == 3) {
					//Lista ligada
					/*
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
					*/

					int elemento;

					for(;;) {
						menu(7);
						retorno_entrada_user = scanf("%d", &opcao);

						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!\n");
							empty_stdin();
						} else if(opcao == 1) {
							for(;;) {
								printf("\nDigite o elemento a ser adicionado no comeco da lista: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validas!\n");
									empty_stdin();
								} else {
									printf("\nInserindo elemento na lista...\n");
									no *new_node = newListNode(elemento);
									insertOnBegin(list, new_node);
									break;
								}
							}
						} else if(opcao == 2) {
							for(;;) {
								printf("\nDigite o elemento a ser adicionado no final da lista: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validas!\n");
									empty_stdin();
								} else {
									printf("\nInserindo elemento na lista...\n");
									no *new_node = newListNode(elemento);
									insertOnEnd(list, new_node);	
									break;
								}
							}

						} else if(opcao == 3) {
							int temp = removeFromBegin(list);
							if(temp == INT_MIN) {
								printf("\nLista vazia!\n");
							} else {
								printf("\n%d - elemento removido do comeco da lista!\n", temp);
							}
						} else if(opcao == 4) {
							int temp = removeFromEnd(list);
							if(temp == INT_MIN) {
								printf("\nLista vazia!\n");
							} else {
								printf("\n%d - elemento removido do final da lista!\n", temp);
							}
						} else if(opcao == 5) {
							for(;;) {
								printf("\nDigite o elemento a ser adicionado em sua posicao ordenada: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validas!\n");
									empty_stdin();
								} else {
									printf("\nInserindo elemento na lista...\n");
									no *new_node = newListNode(elemento);
									insertOrderedElement(list, new_node);
									break;
								}
							}
					 	} else if(opcao == 6) {
							for(;;) {
								printf("\nDigite o elemento a ser removido da lista: ");
								retorno_entrada_user = scanf("%d", &elemento);

								if(verifica_entrada(retorno_entrada_user) == 2) {
									printf("\nCaracteres nao sao entradas validaS!\n");
									empty_stdin();
								} else {
									no *rm_node = newListNode(elemento);

									if(removeSpecificElement(list, rm_node) == SHRT_MIN) {
										printf("\nElemento nao encontrado!\n");
										break;
									} else {
										printf("\nRemovendo elemento...\n");
										removeSpecificElement(list, rm_node);
										break;
									}
								}
							}
						} else if(opcao == 7) {
							getListEmpty(list);
						} else if(opcao == 8) {
							showList(list);
						} else if(opcao == 0) {
							free(list);
							printf("\nVoltando...\n");
							break;
						}
					}
				} else if(opcao == 0) {
					break;
				}
			}
		} else if (verifica_entrada(retorno_entrada_user) == 0 && opcao == 3) {	
			//Arvores e algoritmos de percurso..
			int elemento;

			for(;;) {

				menu(8);
				retorno_entrada_user = scanf("%d", &opcao);

				if(verifica_entrada(retorno_entrada_user) == 2) {
					printf("\nCaracteres nao sao entradas validas!");
					empty_stdin();
				} else if(opcao == 1) {
					for(;;) {
						printf("\nDigite o elemento a ser adicionado a arvore: ");
						retorno_entrada_user = scanf("%d", &elemento);
						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!");
							empty_stdin();
						} else {
							printf("\nInserindo elemento na arvore...\n");
							arvore_no *new_node = newTreeNode(elemento);
							insertTreeElement(tree, new_node);
							break;
						}
					}
				} else if(opcao == 2) {
					for(;;) {
						printf("\nDigite o elemento a ser buscado na arvore: ");
						retorno_entrada_user = scanf("%d", &elemento);
						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!");
							empty_stdin();
						} else {
							printf("\nBuscando elemento na arvore...\n");
							arvore_no *b_no = newTreeNode(elemento);
							arvore_no *founded_element = searchTreeNode(tree, b_no);
							
							if(founded_element == NULL) {
								printf("\nElemento nao encontrado!");
								free(b_no);
								free(founded_element);
								break;
							} else {
								printf("\nElemento no endereco %p eh %d", founded_element, founded_element->elemento);
								free(b_no);
								free(founded_element);
								break;
							}
						}
					}
				} else if(opcao == 3) {
					for(;;) {
						printf("\nDigite o elemento a ser removido da arvore: ");
						retorno_entrada_user = scanf("%d", &elemento);
						if(verifica_entrada(retorno_entrada_user) == 2) {
							printf("\nCaracteres nao sao entradas validas!");
							empty_stdin();
						} else {
							printf("\nBuscando elemento para ser removido da arvore!\n");
							arvore_no *rm_no = newTreeNode(elemento);
							arvore_no *removed_element = removeTreeElement(tree, rm_no);
							printf("\n%d elemento removido da arvore!", rm_no->elemento);
						}
					}
				} else if(opcao == 4) {
					printf("\nPercorrendo arvore em ordem!\n");
					showInOrder(tree);
				} else if(opcao == 5) {
					printf("\nPercorrendo arvore em pos ordem!\n");
					showInPostOrder(tree);
				} else if(opcao == 6) {
					printf("\nPercorrenco arvore em pre ordem!\n");
					showInPreOrder(tree);
				} else if(opcao == 0) {
					free(tree);
					printf("\nVoltando...\n");
					break;
				}
			}
		}else if (verifica_entrada(retorno_entrada_user) == 0 && opcao == 0) {
			printf("\nOk, Saindo do programa...");
			break;
		} else if (verifica_entrada(retorno_entrada_user) == 2) {
			printf("\nCaracteres nao sao entradas validas");
			empty_stdin();
		} else if (verifica_entrada(retorno_entrada_user) == 0 && (opcao != 1 || opcao != 0 || opcao != 2 || opcao != 3)) {
			printf("\nDigite um long inteiro valido!");
			empty_stdin();
		}
	}

	free(vetor);

	return 0;
}
