#include<stdio.h>
#include<stdlib.h>

//declaracao de funcões

void encheJarra(int *jarra, int x);
void esvaziaJarra(int *jarra, int x);
void imprimeJarra(int *jarra, int x);
void menu(int *jarra1, int x, int *jarra2, int y);
int verificaJarra(int *jarra, int x);
int contaLitros(int *jarra, int x);
void contentSwap(int *jarra1, int x, int *jarra2,  int y);

/*
 * O exercicio consiste em fazer uma representação do exercício das Jarras proposto pelo professor Giuliano 
 * na matéria de Inteligência Artificial
 * 
 * Terá um menu principal que rodará enquanto a jarra 1, ou seja a jarra de 4 litros não tiver exatamente 2 litros
 * se a jarra 1 estiver com 2 litros de água, então o programa termina
 * 
 * As funções do menu serão:
 * 
 * Encher jarra
 *  Jarra1 ou Jarra2
 *  Imprime Jarra
 * 
 * Esvaziar jarra
 *  jarra1 ou jarra2
 *  imprime jarra
 * 
 * Trocar o conteudo das jarras
 *  jarra 1 para a jarra 2 ou jarra 2 para a jarra 1
 *  imprime jarra
 */

void encheJarra(int *jarra, int x){
    int i;
    for(i = 0; i < x; i++){
        jarra[i] = 1;
    }
    printf("\nJarra de %d litros cheia!", x);
}

void esvaziaJarra(int *jarra, int x){
    int i;
    for(i = 0; i < x; i++){
        jarra[i] = 0;/* condition */
    }
    printf("\nJarra de %d litros esvaziada!", x);
}

void imprimeJarra(int *jarra, int x){
    int i;
    for(i = 0; i < x; i++){
        printf("\n%d",jarra[i]);
    }
    printf("\nJarra de %d litros",x);
}

void menu(int *jarra1, int x, int *jarra2, int y){
    //menu para manipulação das jarras
    //jarra 1 no caso é a jarra de 4 litros
    /*
    - Encher jarras
        Jarra 1 (4 litros) ou jarra 2 (3 litros)
        Imprimir jarras

    - Esvaziar jarras
        Jarra 1 ou Jarra 2
        imprimir jarras
    
    - Trocar o conteudo das jarras
        Jarra 1 para Jarra 2 ou Jarra 2 para Jarra 1
        Imprimir Jarras
    */
    
    printf("\nMenu para manipulacao do exercício");

    int opt = 0;
    int subOpt = 0;

    while(contaLitros(jarra1, x) != 2){
        
        printf("\n\n1) Encher a jarra.");
        printf("\n2) Esvaziar a jarra.");
        printf("\n3) Trocar o conteudo das jarras.");
        printf("\n4) Imprimir as jarras.");
        scanf("%d", &opt);

        //switch (opt){

            //case 1:
        if(opt == 1){
            printf("\nEscolha a jarra que voce quer encher");
            printf("\n1) Jarra de 4 litros.");
            printf("\n2) Jarra de 3 litros.");
            scanf("%d", &subOpt);
            if(subOpt == 1){
                encheJarra(jarra1, x);
                imprimeJarra(jarra1, x);
            }else if(subOpt == 2){
                encheJarra(jarra2, y);
                imprimeJarra(jarra2, y);
            }else{
                printf("\nDigite uma opcao válida!!");
            }
        }else if(opt == 2){
            //break;
            //case 2:
            printf("\nEscolha a jarra que voce quer esvaziar");
            printf("\n1) Jarra de 4 litros.");
            printf("\n2) Jarra de 3 litros.\n");
            scanf("%d", &subOpt);
            if(subOpt == 1){
                esvaziaJarra(jarra1, x);
                imprimeJarra(jarra1, x);
            }else if(subOpt == 2){
                esvaziaJarra(jarra2, y);
                imprimeJarra(jarra2, y);
            }else{
                printf("\nDigite uma opcao valida!!");
            }
        }else if(opt == 3){
            //break;

            //case 3:
            printf("\n\nEscolha a jarra para trocar o conteudo");
            printf("\n1) Jarra de 4 litros para jarra de 3 litros.");
            printf("\n2) Jarra de 3 litros para jarra de 4 litros.");
            scanf("%d", &subOpt);
            if(subOpt == 1){
                contentSwap(jarra1, x, jarra2, y);
                imprimeJarra(jarra1, x);
                imprimeJarra(jarra2, y);
            }else if(subOpt == 2){
                contentSwap(jarra2, y, jarra1, x);
                imprimeJarra(jarra1, x);
                imprimeJarra(jarra2, y);
            }else{
                printf("\nDigite uma opcao valida!!");
            }
        }else if(opt == 4){
            imprimeJarra(jarra1, x);
            imprimeJarra(jarra2, y);
        }else{
            printf("\nDigite uma opcao valida!!");
        }

    }

    printf("\nYou did it!");

}



int verificaJarra(int *jarra, int x){
    //verifica se as jarras estão cheias, com conteudo, ou vazias
    int i;
    int count = 0;
    for(i = 0; i < x; i++){
        if(jarra[i] == 1){
            count++;
        }

    }

    if(count == x){
        //se a jarra estiver cheia retorna 1
        return 1;
    }else if(count == 0){
        //se a jarra estiver vazia retorna 0
        return 0;
    }else{
        //se a jarra estiver com conteudo
        return 2;
    }

}

int contaLitros(int *jarra, int x){

    int i;
    int count = 0;

    for(i = 0; i < x; i++){
        if(jarra[i] == 1){
            count ++;
        }
    }
    return count;
}

void contentSwap(int *jarra1, int x, int *jarra2,  int y){
    //trocar o conteude de um vetor para o outro
    //A jarra 1 sempre enchera a jarra 2
    //jarra1 --- x
    //jarra2 --- y
    int i, j, temp = 0;

    if(verificaJarra(jarra1, x) == 1 && verificaJarra(jarra2, y) == 1){
        printf("\nAs duas jarras estão cheias!");
    }else if(verificaJarra(jarra1, x) == 0 && verificaJarra(jarra2, y) == 0){
        printf("\nAs duas jarras estão vazias!");
    }else if(verificaJarra(jarra2, y) == 1){
        printf("\nA jarra que voce está tentando encher já está cheia");
    }else if(verificaJarra(jarra1, x) == 0){
        printf("\nA jarra que voce esta tentando trocar o conteudo está vazia!");
    }else{
        if(y > x){
            for(i = 0; i <= x; i++){
                for(j = y; j >= 0; j--){
                    if(jarra1[i] == 1 && jarra2[j] == 0){
                        temp = jarra1[i];
                        jarra1[i] = 0;
                        jarra2[j] = temp;
                        temp = 0;
                    }
                }
            }
        }else if(x > y){
            for(j = y; j >= 0; j--){
                for(i = 0; i <= x; i++){
                    if(jarra1[i] == 1 && jarra2[j] == 0){    
                        temp = jarra1[i];
                        jarra1[i] = 0;
                        jarra2[j] = temp;
                        temp = 0;
                    }
                }
            }
        }
    }
}

/*
 * - Se as duas jarras estiverem cheias;
 * - Se as duas jarras estiverem vazias;
 * - Se a jarra que vai encher estiver vazia;
 * - Se a jarra que vai ser enchida já estiver cheia;
 * 
 * - Recebe jarra 1 e coloca na jarra 2;
 * - Recebe jarra 2 e coloca na jarra 1;
 * 
 */



int main(){

    int jarra3[3];
    int jarra4[4];
    
    esvaziaJarra(jarra3, 3);
    esvaziaJarra(jarra4, 4);

    menu(jarra4, 4, jarra3, 3);
    return 0;
}
