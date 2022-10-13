/**
 * @ Author: Heloisa Alves
 * @ Create Time: 2022-02-11 09:00:38
 * @ Modified time: 2022-02-27 21:04:20
*/
#include <stdbool.h>
#include <time.h>

typedef struct{
    float preco;
    char modelo[50];
    char nome[50];
    char telefone[50];
    time_t data;
}cadastro;

typedef struct{
    cadastro *dado;
    int *proximo;
}no;

typedef struct{
    no *head;
    no *end;
    int tam;
}fila;

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

fila *criar(void);
bool vazia(fila *f);
int inserir(fila *f, cadastro cliente);
cadastro *remover(fila *f);
void limpa(fila *f);
void imprime(fila *f);
cadastro cadastrar(void);
void limpa_buffer(void);
void limpa_tela(void);