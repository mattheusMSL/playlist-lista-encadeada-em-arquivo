#ifndef ACERVO_H
#define ACERVO_H
#define NOME_ARTISTA 50
#define TITULO_MUSICA 50
#define TITULO_PLAYLIST 50

typedef struct {
   int codigo;
   char titulo[TITULO_MUSICA];
   char artista[NOME_ARTISTA];
   int ano; 
} Musica;

typedef struct {
    int codigo;
    char titulo[TITULO_PLAYLIST];
    Musica pos_cabeça;
    Musica pos_fim;
    Musica pos_livre;
} Playlist;

typedef struct {
    
};

#endif // ACERVO_H