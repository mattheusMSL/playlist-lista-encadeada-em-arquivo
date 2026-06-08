#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>

/**
 * @brief Cabeçalho utilizado para os arquivos de Acervo (músicas) e Playlists[cite: 108, 109].
 */
typedef struct {
    long cabeca_lista; 
    long topo;       
} CabecalhoPadrao;

/**
 * @brief Cabeçalho exclusivo para o arquivo de faixas musicais[cite: 110].
 */
typedef struct {
    long topo;          
    long cabeca_livres; 
} CabecalhoFaixas;

/**
 * @brief Estrutura que representa uma música no acervo geral[cite: 12].
 */
typedef struct {
    int codigo;           
    char titulo[100];   
    char artista[50];     
    int ano;          
    long proxima_musica;  
} Musica;

/**
 * @brief Estrutura que representa uma playlist no sistema[cite: 15].
 */
typedef struct {
    int codigo;             
    char titulo[50];        
    long cabeca_faixas;    
    long fim_faixas;       
    long proxima_playlist; 
} Playlist;

/**
 * @brief Estrutura de um nó da lista encadeada de faixas musicais de uma playlist[cite: 21].
 */
typedef struct {
    int codigo_musica;  
    long proxima_faixa; 
} Faixa;


/* ========================================================================= */
/* PROTÓTIPOS DE FUNÇÕES (Exemplo de documentação)                           */
/* ========================================================================= */

/**
 * @brief Insere uma nova música no arquivo de acervo geral.
 * @pre O arquivo binário do acervo deve estar aberto no modo "rb+" (leitura e atualização). 
 * Se for a primeira execução, o arquivo já deve ter sido criado com o cabeçalho inicializado.
 * @post A música é gravada no final do arquivo (posição 'topo'). O encadeamento da lista 
 * é atualizado e o 'topo' no cabeçalho é incrementado.
 */
void cadastrar_musica(FILE *arquivo, int codigo, const char *titulo, const char *artista, int ano);

#endif // PLAYLIST_H