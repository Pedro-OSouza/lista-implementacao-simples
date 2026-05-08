#include <stdio.h>
#include <stdlib.h>

int main(){

    //implementação de uma estrutura de lista com inserção no inicio e no final e listagem dos elementos


    int lista[5];

    lista[0] = -1; //setar este valor no primeiro indice da lista nos ajuda a validar se está vazia ou não

    //definir váriaveis de inicio e fim ajudam a controlar onde começa e onde termina a lista
    int inicio = -1;
    int fim = 0;


    // o loop permite a aplicação rodar em loop para permitir a inserção
    // de vários itens na nossa lista sem fechar o programa automaticamente
    int run = 1;
    int op; // para ler as escolhas do usuário
    int novoNumero;

    while(run){
        printf("\nEscolha uma das seguintes opcoes:\n 1. Inserir no inicio\n 2. Inserir no fim\n 3. Ler lista\n 4. Encerrar programa\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nInforme o numero que deseja inserir: \n");
                scanf("%d", &novoNumero);

                if(fim == (sizeof(lista) / sizeof(lista[0]))){
                    printf("\nA lista atingiu seu limite!\n");
                } else {
                    //se o inicio for igual -1 então a lsita está vazia
                    if(inicio == -1){
                        printf("Lista vazia, item inserido no inicio da lista\n");
                        printf("Item %d inserido no indice 0\n", novoNumero);
                        lista[0] = novoNumero;
                        // após inserir o elemento no primeiro indice da lista, nos incrementamos a variavel inicio
                        // isso já indica que a lista já não esta mais vazia e já indica onde é o inicio, no caso, o indice 0.
                        inicio += 1; //o novo valor da variável é 0.

                    } else if (inicio == fim){ // se o inicio for igual ao fim (inicio = 0 e fim = 0) então significa que há apenas um elemento na lista
                        printf("\nSo ha um elmeento na lista.\nNovo valor sendo inserido.\n");

                        lista[fim+1] = lista[fim]; // o item que está no fim da lista (indice 0) é copiado para o indice seguinte (indice 1)
                        lista[inicio] = novoNumero; // o novo item é sobrescrito no indice 0.

                        fim += 1; // a variavel fim é incrementada em 1 (novo valor se torna 1) indicando o novo fim da lista.

                        printf("Item %d movido para o indice %d\nNovo item %d inserido no indice 0\n", lista[fim], fim, lista[inicio]);
                    } else { //há dois elementos ou mais na lista
                        printf("Percorrendo lista e movendo items\n");

                        //a lista é percorrida de trás pra frente movendo os items do fim para o indice a frente
                        for(int i = fim; i >= inicio; i--){
                            lista[i+1] = lista[i];
                            printf("Item %d movido para o indice %d\n", lista[i], i+1);
                        }
                        //novamente a variavel fim deve ser incrementada.
                        fim += 1;
                        lista[inicio] = novoNumero;
                        printf("Item %d inserido no indice 0\n", novoNumero);
                    }
                }
            break;

            case 2:
                //inserir no final da lista é bem mais simples
                printf("Informe o numero que deseja inserir: \n");
                scanf("%d", &novoNumero);

                //nós apenas incrementamos a variável fim e inserimos o novo valor no indice fim
                fim+=1;
                lista[fim] = novoNumero;
                printf("\nItem %d inserido no indice %d\n", novoNumero, fim);
            break;

            case 3:
                //aqui um simples loop percorre cada item da lista e os exibe na tela.
                printf("A lista atual é: \n");
                for(int i = 0; i <= fim; i++){
                    printf("Indice %d: %d\n", i, lista[i]);
                }
            break;

            case 4:
                printf("Saindo do programa...");
                run = 0;
            break;

            default:
                printf("Opcao invalida!\n");

        }

    }

    return 0;
}
