#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

/**
 * @brief Insere uma nova música no arquivo de acervo geral.
 * @pre O arquivo binário do acervo deve estar aberto no modo "rb+" (leitura e atualização). 
 * Se for a primeira execução, o arquivo já deve ter sido criado com o cabeçalho inicializado.
 * @post A música é gravada no final do arquivo (posição 'topo'). O encadeamento da lista 
 * é atualizado e o 'topo' no cabeçalho é incrementado.
 * @authors @matthewMSL, 
 *
 */
void cadastrar_musica(FILE *arquivo, int codigo, const char *titulo, const char *artista, int ano) {
    CabecalhoPadrao cabecalho;
    Musica nova_musica, atual;
    long posicao_atual, posicao_anterior;

    nova_musica.codigo = codigo;
    nova_musica.ano = ano;
    nova_musica.proxima_musica = -1; 
    strncpy(nova_musica.titulo, titulo, sizeof(nova_musica.titulo) - 1);
    nova_musica.titulo[sizeof(nova_musica.titulo) - 1] = '\0';
    
    strncpy(nova_musica.artista, artista, sizeof(nova_musica.artista) - 1);
    nova_musica.artista[sizeof(nova_musica.artista) - 1] = '\0';

    rewind(arquivo); 
    fread(&cabecalho, sizeof(CabecalhoPadrao), 1, arquivo);

    fseek(arquivo, cabecalho.topo, SEEK_SET);
    fwrite(&nova_musica, sizeof(Musica), 1, arquivo);

    
    if (cabecalho.cabeca_lista == -1) {
        cabecalho.cabeca_lista = cabecalho.topo;
    } else {
    
        posicao_atual = cabecalho.cabeca_lista;
        
       
        while (posicao_atual != -1) {
            fseek(arquivo, posicao_atual, SEEK_SET);
            fread(&atual, sizeof(Musica), 1, arquivo);
            posicao_anterior = posicao_atual;
            posicao_atual = atual.proxima_musica;
        }
        
        
        atual.proxima_musica = cabecalho.topo;
        fseek(arquivo, posicao_anterior, SEEK_SET);
        fwrite(&atual, sizeof(Musica), 1, arquivo);
    }

   
    cabecalho.topo += sizeof(Musica);
    

    rewind(arquivo);
    fwrite(&cabecalho, sizeof(CabecalhoPadrao), 1, arquivo);

    printf("Sucesso: Musica '%s' cadastrada com codigo %d!\n", nova_musica.titulo, nova_musica.codigo);
}