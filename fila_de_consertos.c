/**
 * @ Author: Heloisa Alves
 * @ Create Time: 2022-02-11 09:00:38
 * @ Modified time: 2022-02-27 21:04:32
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<locale.h>
#include "fila_encadeada.h"

fila *f;

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil"); //comando para acentuação no terminal
    system("chcp 65001> nul"); //comando para acentuação no terminal

    int op;
    cadastro leitus_temp;
    f = criar();

    do{
        printf("\n\n---------------AssistHAL Consertos-------------");
        printf("\n\n1. Cadastrar computador");
        printf("\n2. Remover cadastro");
        printf("\n3. Limpar fila");
        printf("\n4. Imprimir fila");
        printf("\n5. Sair");
        printf("\n\nInforme a sua opcao:\n");
        scanf("%d", &op);
        limpa_tela();
        switch(op){
            case(1):
                leitus_temp = cadastrar();
                inserir(f, leitus_temp);
                break;  
            case(2): 
                remover(f);
                break; 
            case(3): 
                limpa(f);
                break;
            case(4):
                limpa_tela();
                printf("\n"); 
                imprime(f);
                break;
            case(5): 
                printf("\nFim de Programa!\n");
                break;
            default: 
                printf("\nERRO! Digite novamente:\n");
                break;
        }
    } while(op != 5);
    return EXIT_SUCCESS;
}