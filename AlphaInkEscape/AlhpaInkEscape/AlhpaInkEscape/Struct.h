#include <stdio.h>
// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#ifndef Struct_H
#define Struct_H

// Tamanho da tela
#define LARGURA_TELA 1280
#define ALTURA_TELA 720
// Tamanho do Invent�rio
#define TAMANHO_INVENTARIO 7

// Struct para imagens
typedef struct Obj
{
	ALLEGRO_BITMAP* bitmap;
	int x;
	int y;
	int largura;
	int altura;
	int cliqueX;
	int cliqueY;
} Objeto;

// Struct de progresso
typedef struct prog
{
	int proximaSala;
	int Gameover;
	int Salas[16];// Progresso de cada sala
	int Invent�rio[TAMANHO_INVENTARIO];// Ter ou n�o o item
	Objeto Itens[TAMANHO_INVENTARIO];// Item propriamente dito
} Progresso;

#endif
