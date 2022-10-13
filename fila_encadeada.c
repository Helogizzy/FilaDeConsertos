/**
 * @ Author: Heloisa Alves
 * @ Create Time: 2022-02-11 09:00:38
 * @ Modified time: 2022-10-11 19:45:09
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<locale.h>
#include <string.h>
#include "fila_encadeada.h"

#define ERROFILACHEIA -1

cadastro *remover(fila *f);

fila *criar(void){
    fila *f = malloc(sizeof(fila));
    if(f != NULL){
        f->tam=0;
        f->head=NULL;
        f->end=NULL;
    }
    return f;
}

bool vazia(fila *f){ //verifica caso a lista esteja vaiza por valores booleanos
    if (f->tam == 0)
        return true;
    else
        return false;
}

int inserir(fila *f, cadastro cliente){
    no *novo = malloc(sizeof(no));
    cadastro *dado;

    if(novo == NULL) return ERROFILACHEIA;

    else{
        dado = malloc(sizeof(cadastro));
        if(dado == NULL){
            free(novo);
            return ERROFILACHEIA;
        }else{
            if(vazia(f) == true) f->head = novo;
            else f->end->proximo = novo;

            *dado = cliente;
            novo->proximo = NULL;
            novo->dado = dado;
            f->end = novo;
            f->tam = f->tam+1;

            return f->tam;
        }
    }
}

cadastro *remover(fila *f){
    no *acabou;
    cadastro *ant;
    
    if(vazia(f)== true) return NULL;
    else{
        acabou = f->head;
        ant = acabou->dado;
        f->head = acabou->proximo;

        if(f->tam == 1) f->end = NULL;

        f->tam = f->tam - 1;
        free(acabou->dado);
        free(acabou);
        return ant;
    } 
}

void limpa(fila *f){
    while(f->tam != 0){
        remover(f);
    }  
    printf("\n=================================================\n");
    printf("\n\tLimpeza de fila feita com sucesso!\n");
    printf("\n=================================================");
}

void imprime(fila *f){
    no *temp = f->head;
    struct tm *data;
    int dia, mes, ano;

    if(vazia(f) == true){
        printf("\n=================================================\n");
        printf("\n\tFila vazia!\n");
    }
    for(int i=0; i<f->tam; i++){ //Define um for para printar todos os valores dentro da fila
        printf("\n=================================================\n");
        printf("\n    PEDIDOS!\n");
        printf("\nPedido: %d", i+1);
        printf("\nCliente: %s", temp->dado->nome);
        printf("\nTelefone: %s", temp->dado->telefone);
        printf("\nModelo do Computador: %s", temp->dado->modelo);  
        printf("\nPreço: %.2f", temp->dado->preco); 
        
        data = localtime(&temp->dado->data);
        dia = data->tm_mday;
        mes = data->tm_mon + 1;
        ano = data->tm_year + 1905;
        printf("\nData de entrega: %02d/%02d/%04d\n", dia,mes,ano);

        if(temp->proximo != NULL)
        temp = temp->proximo;
    }
    printf("\n=================================================\n");
}

cadastro cadastrar(void){ 
    cadastro cliente;
    time_t aux, aux2;

    printf("\n=================================================\n");
    printf("\n\tDigite os dados do cliente!\n");
    limpa_buffer();
    printf("\nNome: ");
    scanf("\n%[^\n]s", cliente.nome);
    printf("\nTelefone: ");
    limpa_buffer();
    scanf("\n%[^\n]s", cliente.telefone);
    printf("\nModelo do Computador: ");
    limpa_buffer();
    scanf("\n%[^\n]s", cliente.modelo);  
    printf("\nPreço: ");
    limpa_buffer();
    scanf("%f", &cliente.preco);
  
    time(&aux);    
    aux2 = aux+(60*60*24*14); 
    cliente.data = aux2;
    limpa_tela();
  
    printf("\n=================================================\n");
    printf("\n\tCadastro feito com sucesso!\n");
    printf("\n=================================================");
    
    return cliente;
}

void limpa_buffer(void){
    char aux[100];
    scanf("%c", aux);
    printf("\n");
}

void limpa_tela(void){
    //Comando para os dois sistemas operacionais limparem a tela
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif
}