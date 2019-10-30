
#include <stdio.h>
// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Funcoes.h"
#include "Struct.h"

Objeto* mapa, * notaOnca, * notaTatu, * notaJacare, * notaMico;
Objeto* marcaOnca, * marcaTatu, * marcaJacare, * marcaMico;
Objeto* saidaDireita, * saidaBaixo;// * saidaCima;
Objeto* postIt3 = NULL;

int JogarFase5Brasil(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, Progresso* prog) {

	notaOnca = (Objeto*)malloc(sizeof(Objeto));
	notaOnca->bitmap = NULL;
	notaOnca->x = 120;
	notaOnca->y = 100;
	notaOnca->largura = 230;
	notaOnca->altura = 200;

	mapa = (Objeto*)malloc(sizeof(Objeto));
	mapa->bitmap = NULL;
	mapa->largura = 650;
	mapa->altura = 650;
	mapa->x = notaOnca->largura + notaOnca->x + 20;
	mapa->y = ALTURA_TELA / 2 - 330;

	notaTatu = (Objeto*)malloc(sizeof(Objeto));
	notaTatu->bitmap = NULL;
	notaTatu->x = 120;
	notaTatu->y = ALTURA_TELA - 220;
	notaTatu->largura = 230;
	notaTatu->altura = 200;

	notaJacare = (Objeto*)malloc(sizeof(Objeto));
	notaJacare->bitmap = NULL;
	notaJacare->x = LARGURA_TELA - 240;
	notaJacare->y = 100;
	notaJacare->largura = 230;
	notaJacare->altura = 200;

	notaMico = (Objeto*)malloc(sizeof(Objeto));
	notaMico->bitmap = NULL;
	notaMico->x = LARGURA_TELA - 240;
	notaMico->y = ALTURA_TELA - 220;
	notaMico->largura = 230;
	notaMico->altura = 200;

	marcaOnca = (Objeto*)malloc(sizeof(Objeto));
	marcaOnca->bitmap = NULL;
	marcaOnca->x = notaOnca->x + notaOnca->largura - 55;
	marcaOnca->y = notaOnca->y + notaOnca->altura - 55;
	marcaOnca->largura = 50;
	marcaOnca->altura = 50;

	marcaTatu = (Objeto*)malloc(sizeof(Objeto));
	marcaTatu->bitmap = NULL;
	marcaTatu->x = notaTatu->x + notaTatu->largura - 55;
	marcaTatu->y = notaTatu->y + notaTatu->altura - 55;
	marcaTatu->largura = 50;
	marcaTatu->altura = 50;

	marcaJacare = (Objeto*)malloc(sizeof(Objeto));
	marcaJacare->bitmap = NULL;
	marcaJacare->x = notaJacare->x + notaJacare->largura - 55;
	marcaJacare->y = notaJacare->y + notaJacare->altura - 55;
	marcaJacare->largura = 50;
	marcaJacare->altura = 50;

	marcaMico = (Objeto*)malloc(sizeof(Objeto));
	marcaMico->bitmap = NULL;
	marcaMico->x = notaMico->x + notaMico->largura - 55;
	marcaMico->y = notaMico->y + notaMico->altura - 55;
	marcaMico->largura = 50;
	marcaMico->altura = 50;

	saidaDireita = (Objeto*)malloc(sizeof(Objeto));
	saidaDireita->bitmap = NULL;
	saidaDireita->x = LARGURA_TELA - 20;
	saidaDireita->y = ALTURA_TELA/2 - 10;
	saidaDireita->largura = 20;
	saidaDireita->altura = 20;

	postIt3 = (Objeto*)malloc(sizeof(Objeto));
	postIt3->altura = 183;
	postIt3->largura = 201;
	postIt3->x = -500;
	postIt3->y = -500;
	postIt3->bitmap = NULL;

	/*saidaCima = (Objeto*)malloc(sizeof(Objeto));
	saidaCima->bitmap = NULL;
	saidaCima->x = LARGURA_TELA / 2 - 10;
	saidaCima->y = 0;
	saidaCima->largura = 20;
	saidaCima->altura = 20;*/

	saidaBaixo = (Objeto*)malloc(sizeof(Objeto));
	saidaBaixo->bitmap = NULL;
	saidaBaixo->x = LARGURA_TELA / 2 - 10;
	saidaBaixo->y = ALTURA_TELA - 20;
	saidaBaixo->largura = 20;
	saidaBaixo->altura = 20;

	ALLEGRO_BITMAP* Background = al_load_bitmap("Imgs/fundo.png");

	mapa->bitmap = al_load_bitmap("Imgs/bioma.png");

	notaOnca->bitmap = al_load_bitmap("Imgs/nonca.png");
	notaTatu->bitmap = al_load_bitmap("Imgs/ntatu.png");
	notaJacare->bitmap = al_load_bitmap("Imgs/njacare.png");
	notaMico->bitmap = al_load_bitmap("Imgs/nmico.png");

	marcaOnca->bitmap = al_load_bitmap("Imgs/monca.png");
	marcaTatu->bitmap = al_load_bitmap("Imgs/mtatu.png");
	marcaJacare->bitmap = al_load_bitmap("Imgs/mjacare.png");
	marcaMico->bitmap = al_load_bitmap("Imgs/mmico.png");
	postIt3->bitmap = al_load_bitmap("Imgs/postitHomem.png");
	
	saidaDireita->bitmap = al_load_bitmap("Imgs/direita.png");

	Background = al_load_bitmap("Imgs/fundo.png");

	int gameOver = 0;
	int arrastando = 0;
	while (!gameOver)
	{
		while (!al_is_event_queue_empty(fila_eventos))
		{
			//Cria um evento
			ALLEGRO_EVENT evento;
			//espero por um evento da fila, e guarda em evento
			al_wait_for_event(fila_eventos, &evento);

			//se teve eventos e foi um evento de fechar janela, encerra repeti��o			
			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				prog->Gameover = 1;
				gameOver = 1;
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				printf("(%d,%d)", evento.mouse.x, evento.mouse.y);
				
				if (IsInside(evento.mouse.x, evento.mouse.y, saidaDireita))
				{
					prog->proximaSala = 6;////////////////////////////////
					gameOver = 1;
				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, saidaBaixo))
				{
					prog->proximaSala = 6;////////////////////////////////
					gameOver = 1;

				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, marcaOnca))
				{
					arrastando = 1;
					marcaOnca->cliqueX = MapearDistancia(evento.mouse.x, marcaOnca->x);
					marcaOnca->cliqueY = MapearDistancia(evento.mouse.y, marcaOnca->y);
				}
				else if(IsInside(evento.mouse.x, evento.mouse.y, marcaTatu) && !prog->Salas[5])
				{
					arrastando = 2;
					marcaTatu->cliqueX = MapearDistancia(evento.mouse.x, marcaTatu->x);
					marcaTatu->cliqueY = MapearDistancia(evento.mouse.y, marcaTatu->y);
				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, marcaJacare) && !prog->Salas[5])
				{
					arrastando = 3;
					marcaJacare->cliqueX = MapearDistancia(evento.mouse.x, marcaJacare->x);
					marcaJacare->cliqueY = MapearDistancia(evento.mouse.y, marcaJacare->y);
				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, marcaMico) && !prog->Salas[5])
				{
					arrastando = 4;
					marcaMico->cliqueX = MapearDistancia(evento.mouse.x, marcaMico->x);
					marcaMico->cliqueY = MapearDistancia(evento.mouse.y, marcaMico->y);
				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, postIt3) && !prog->Inventario[1])
				{
					prog->Itens[prog->inventCount] = postIt3;
					prog->Inventario[prog->inventCount] = 1;
					prog->inventCount++;
				}
				else {
					arrastando = 0;
				}
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				arrastando = 0;
			}

			ALLEGRO_MOUSE_STATE state;

			al_get_mouse_state(&state);
			if (state.buttons & 1 && arrastando)
			{
				switch (arrastando)
				{
				case 1:
					if (!VerificarBordas(evento.mouse.x, evento.mouse.y, marcaOnca)) {
						marcaOnca->x = evento.mouse.x - marcaOnca->cliqueX;
						marcaOnca->y = evento.mouse.y - marcaOnca->cliqueY;
					}
					break;
				case 2:
					if (!VerificarBordas(evento.mouse.x, evento.mouse.y, marcaTatu)) {
						marcaTatu->x = evento.mouse.x - marcaTatu->cliqueX;
						marcaTatu->y = evento.mouse.y - marcaTatu->cliqueY;
					}
					break;
				case 3:
					if (!VerificarBordas(evento.mouse.x, evento.mouse.y, marcaJacare)) {
						marcaJacare->x = evento.mouse.x - marcaJacare->cliqueX;
						marcaJacare->y = evento.mouse.y - marcaJacare->cliqueY;
					}
					break;
				case 4:
					if (!VerificarBordas(evento.mouse.x, evento.mouse.y, marcaMico)) {
						marcaMico->x = evento.mouse.x - marcaMico->cliqueX;
						marcaMico->y = evento.mouse.y - marcaMico->cliqueY;
					}
					break;
				default:
					break;
				}
			}

			if (InCaatinga() && InAmazonia() && InPantanal() && InMata())
			{
				prog->Salas[5] = 1;
				postIt3->x = (LARGURA_TELA / 2) - (postIt3->largura / 2);
				postIt3->y = ALTURA_TELA - postIt3->altura;
			}
		}

		al_draw_bitmap(Background, 0, 0, 0);
		al_draw_bitmap(mapa->bitmap,mapa->x,mapa->y,0);

		al_draw_bitmap(saidaDireita->bitmap, saidaDireita->x, saidaDireita->y, 0);
		//al_draw_bitmap(saidaBaixo->bitmap, saidaBaixo->x, saidaBaixo->y, 0);

		al_draw_bitmap(notaOnca->bitmap, notaOnca->x, notaOnca->y, 0);
		al_draw_bitmap(notaTatu->bitmap, notaTatu->x, notaTatu->y, 0);
		al_draw_bitmap(notaJacare->bitmap, notaJacare->x, notaJacare->y, 0);
		al_draw_bitmap(notaMico->bitmap, notaMico->x, notaMico->y, 0);

		if (prog->Salas[5]) {
			al_draw_bitmap(marcaOnca->bitmap, 555, 185, 0);
			al_draw_bitmap(marcaTatu->bitmap, 928, 235, 0);
			al_draw_bitmap(marcaJacare->bitmap, 641, 426, 0);
			al_draw_bitmap(marcaMico->bitmap, 902, 427, 0);
		}
		else {
			al_draw_bitmap(marcaOnca->bitmap, marcaOnca->x, marcaOnca->y, 0);
			al_draw_bitmap(marcaTatu->bitmap, marcaTatu->x, marcaTatu->y, 0);
			al_draw_bitmap(marcaJacare->bitmap, marcaJacare->x, marcaJacare->y, 0);
			al_draw_bitmap(marcaMico->bitmap, marcaMico->x, marcaMico->y, 0);
		}

		if (prog->Salas[5] && !prog->Inventario[1])//arrumar
		{
			al_draw_bitmap(postIt3->bitmap, postIt3->x, postIt3->y, 0);
		}

		caregaInventario(prog);
		al_flip_display();
	}

	al_destroy_bitmap(Background);
	al_destroy_bitmap(mapa->bitmap);
	free(mapa);

	al_destroy_bitmap(notaOnca->bitmap);
	al_destroy_bitmap(notaJacare->bitmap);
	al_destroy_bitmap(notaMico->bitmap);
	al_destroy_bitmap(notaTatu->bitmap);
	free(notaJacare);
	free(notaMico);
	free(notaTatu);
	free(notaOnca);

	al_destroy_bitmap(marcaJacare->bitmap);
	al_destroy_bitmap(marcaMico->bitmap);
	al_destroy_bitmap(marcaOnca->bitmap);
	al_destroy_bitmap(marcaTatu->bitmap);
	free(marcaJacare);
	free(marcaMico);
	free(marcaOnca);
	free(marcaTatu);
	al_destroy_bitmap(saidaDireita->bitmap);

	free(saidaDireita);

	return;
}

int InCaatinga() {
	if (marcaTatu->x+10 >= 887 && marcaTatu->x+10 <= 953 && marcaTatu->y+10 >= 146 && marcaTatu->y+10 <= 348 || marcaTatu->x + 10 >= 946 && marcaTatu->x + 10 <= 1003 && marcaTatu->y + 10 >= 165 && marcaTatu->y + 10 <= 334)
	{
		return 1;
	}
	return 0;
}

int InPantanal() {
	if (marcaJacare->x + 10 >= 611 && marcaJacare->x + 10 <= 703 && marcaJacare->y + 10 >= 393 && marcaJacare->y + 10 <= 490)
	{
		return 1;
	}
	return 0;
}

int InMata() {
	if (marcaMico->x + 10 >= 685 && marcaMico->x + 10 <= 782 && marcaMico->y + 10 >= 508 && marcaMico->y + 10 <= 579 || marcaMico->x + 10 >= 742 && marcaMico->x + 10 <= 779 && marcaMico->y + 10 >= 435 && marcaMico->y + 10 <= 530 || marcaMico->x + 10 >= 780 && marcaMico->x + 10 <= 913 && marcaMico->y + 10 >= 470 && marcaMico->y + 10 <= 515 || marcaMico->x + 10 >= 890 && marcaMico->x + 10 <= 952 && marcaMico->y + 10 >= 352 && marcaMico->y + 10 <= 505 || marcaMico->x + 10 >= 780 && marcaMico->x + 10 <= 913 && marcaMico->y + 10 >= 470 && marcaMico->y + 10 <= 515 || marcaMico->x + 10 >= 865 && marcaMico->x + 10 <= 906 && marcaMico->y + 10 >= 445 && marcaMico->y + 10 <= 490)
	{
		return 1;
	}
	return 0;
}

int InAmazonia() {
	if (marcaOnca->x + 10 >= 419 && marcaOnca->x + 10 <= 733 && marcaOnca->y + 10 >= 88 && marcaOnca->y + 10 <= 310 || marcaOnca->x + 10 >= 375 && marcaOnca->x + 10 <= 605 && marcaOnca->y + 10 >= 252 && marcaOnca->y + 10 <= 341 || marcaOnca->x + 10 >= 531 && marcaOnca->x + 10 <= 603 && marcaOnca->y + 10 >= 32 && marcaOnca->y + 10 <= 120 || marcaOnca->x + 10 >= 709 && marcaOnca->x + 10 <= 762 && marcaOnca->y + 10 >= 34 && marcaOnca->y + 10 <= 125 || marcaOnca->x + 10 >= 637 && marcaOnca->x + 10 <= 847 && marcaOnca->y + 10 >= 124 && marcaOnca->y + 10 <= 225)
	{
		return 1;
	}
	return 0;
}
