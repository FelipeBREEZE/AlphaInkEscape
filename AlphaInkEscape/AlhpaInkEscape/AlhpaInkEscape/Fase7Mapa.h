#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include "Funcoes.h"
#include "Struct.h"
#include <string.h>



int JogarFase7Mapa(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, Progresso* prog) {
	Objeto* SaidaBaixo;
	SaidaBaixo = (Objeto*)malloc(sizeof(Objeto));
	SaidaBaixo->altura = 20;
	SaidaBaixo->largura = 20;
	SaidaBaixo->x = 110 + (LARGURA_TELA / 2) - (SaidaBaixo->largura / 2) - 100;
	SaidaBaixo->y = ALTURA_TELA - (SaidaBaixo->altura * 2);
	SaidaBaixo->bitmap = al_load_bitmap("Imgs/baixoV.png");

	Objeto* SaidaEsquerda;
	SaidaEsquerda = (Objeto*)malloc(sizeof(Objeto));
	SaidaEsquerda->altura = 20;
	SaidaEsquerda->largura = 20;
	SaidaEsquerda->x = 110;
	SaidaEsquerda->y = (ALTURA_TELA / 2) - (SaidaBaixo->altura / 2);
	SaidaEsquerda->bitmap = al_load_bitmap("Imgs/campo.png");

	Objeto* SaidaCima;
	SaidaCima = (Objeto*)malloc(sizeof(Objeto));
	SaidaCima->altura = 20;
	SaidaCima->largura = 20;
	SaidaCima->x = 110 + (LARGURA_TELA / 2) - (SaidaCima->largura / 2);
	SaidaCima->y = 1;
	SaidaCima->bitmap = al_load_bitmap("Imgs/cima.png");

	Objeto* campo1;
	campo1 = (Objeto*)malloc(sizeof(Objeto));
	campo1->bitmap = al_load_bitmap("Imgs/slide4.png");
	campo1->altura = 250;
	campo1->largura = 500;
	campo1->x = 0;
	campo1->y = ALTURA_TELA - campo1->altura;

	Objeto* campoesquerda;
	campoesquerda = (Objeto*)malloc(sizeof(Objeto));
	campoesquerda->bitmap = NULL;
	campoesquerda->altura = 250;
	campoesquerda->largura = 500;
	campoesquerda->x = 110;
	campoesquerda->y = 350;

	ALLEGRO_BITMAP* btn = al_load_bitmap("Imgs/botao.png");
	ALLEGRO_BITMAP* btnPressionado = al_load_bitmap("Imgs/botaopressed.png");

	Objeto* campodireita;
	campodireita = (Objeto*)malloc(sizeof(Objeto));
	campodireita->bitmap = NULL;
	campodireita->altura = 250;
	campodireita->largura = 500;
	campodireita->x = 1100;
	campodireita->y = 350;

	//======================================IMAGENS=======================================================================
	Objeto* brasil;
	brasil = (Objeto*)malloc(sizeof(Objeto));
	brasil->bitmap = al_load_bitmap("Imgs/Brasil.png");
	brasil->altura = 250;
	brasil->largura = 500;
	brasil->x = 250;
	brasil->y = 50;

	Objeto* toronto;
	toronto = (Objeto*)malloc(sizeof(Objeto));
	toronto->bitmap = al_load_bitmap("Imgs/toronto.png");
	toronto->altura = 250;
	toronto->largura = 500;
	toronto->x = 750;
	toronto->y = 50;

	Objeto* londres;
	londres = (Objeto*)malloc(sizeof(Objeto));
	londres->bitmap = al_load_bitmap("Imgs/londres.png");
	londres->altura = 250;
	londres->largura = 500;
	londres->x = 750;
	londres->y = 300;

	Objeto* china;
	china = (Objeto*)malloc(sizeof(Objeto));
	china->bitmap = al_load_bitmap("Imgs/china.png");
	china->altura = 250;
	china->largura = 500;
	china->x = 250;
	china->y = 300;

	//==============================================CAMPOS===================================================

	Objeto* caixa1;
	caixa1 = (Objeto*)malloc(sizeof(Objeto));
	caixa1->bitmap = al_load_bitmap("Imgs/campo2.png");
	caixa1->altura = 100;
	caixa1->largura = 100;
	caixa1->x = 300;
	caixa1->y = 550;

	Objeto* caixa2;
	caixa2 = (Objeto*)malloc(sizeof(Objeto));
	caixa2->bitmap = al_load_bitmap("Imgs/campo2.png");
	caixa2->altura = 100;
	caixa2->largura = 100;
	caixa2->x = 500;
	caixa2->y = 550;

	Objeto* caixa3;
	caixa3 = (Objeto*)malloc(sizeof(Objeto));
	caixa3->bitmap = al_load_bitmap("Imgs/campo2.png");
	caixa3->altura = 100;
	caixa3->largura = 100;
	caixa3->x = 700;
	caixa3->y = 550;

	Objeto* caixa4;
	caixa4 = (Objeto*)malloc(sizeof(Objeto));
	caixa4->bitmap = al_load_bitmap("Imgs/campo2.png");
	caixa4->altura = 100;
	caixa4->largura = 100;
	caixa4->x = 900;
	caixa4->y = 550;

	//===========================================SETAS=================================================

	Objeto* setacima1;
	setacima1 = (Objeto*)malloc(sizeof(Objeto));
	setacima1->bitmap = al_load_bitmap("Imgs/cima.png");
	setacima1->altura = 100;
	setacima1->largura = 100;
	setacima1->x = 340;
	setacima1->y = 530;

	Objeto* setacima2;
	setacima2 = (Objeto*)malloc(sizeof(Objeto));
	setacima2->bitmap = al_load_bitmap("Imgs/cima.png");
	setacima2->altura = 100;
	setacima2->largura = 100;
	setacima2->x = 540;
	setacima2->y = 530;

	Objeto* setacima3;
	setacima3 = (Objeto*)malloc(sizeof(Objeto));
	setacima3->bitmap = al_load_bitmap("Imgs/cima.png");
	setacima3->altura = 100;
	setacima3->largura = 100;
	setacima3->x = 740;
	setacima3->y = 530;

	Objeto* setacima4;
	setacima4 = (Objeto*)malloc(sizeof(Objeto));
	setacima4->bitmap = al_load_bitmap("Imgs/cima.png");
	setacima4->altura = 100;
	setacima4->largura = 100;
	setacima4->x = 940;
	setacima4->y = 530;
	//-------------------------------------BAIXO----------------------------------------------
	Objeto* setabaixo1;
	setabaixo1 = (Objeto*)malloc(sizeof(Objeto));
	setabaixo1->bitmap = al_load_bitmap("Imgs/baixo.png");
	setabaixo1->altura = 100;
	setabaixo1->largura = 100;
	setabaixo1->x = 340;
	setabaixo1->y = 655;

	Objeto* setabaixo2;
	setabaixo2 = (Objeto*)malloc(sizeof(Objeto));
	setabaixo2->bitmap = al_load_bitmap("Imgs/baixo.png");
	setabaixo2->altura = 100;
	setabaixo2->largura = 100;
	setabaixo2->x = 540;
	setabaixo2->y = 655;

	Objeto* setabaixo3;
	setabaixo3 = (Objeto*)malloc(sizeof(Objeto));
	setabaixo3->bitmap = al_load_bitmap("Imgs/baixo.png");
	setabaixo3->altura = 100;
	setabaixo3->largura = 100;
	setabaixo3->x = 740;
	setabaixo3->y = 655;

	Objeto* setabaixo4;
	setabaixo4 = (Objeto*)malloc(sizeof(Objeto));
	setabaixo4->bitmap = al_load_bitmap("Imgs/baixo.png");
	setabaixo4->altura = 100;
	setabaixo4->largura = 100;
	setabaixo4->x = 940;
	setabaixo4->y = 655;

	//---------------------------------------------------SETAS-------------------------------------------------------
	Objeto* setaZ;
	setaZ = (Objeto*)malloc(sizeof(Objeto));
	setaZ->bitmap = al_load_bitmap("Imgs/setaZ.png");
	setaZ->altura = 100;
	setaZ->largura = 100;
	setaZ->x = 310;
	setaZ->y = 560;
	//a
	Objeto* setaN;
	setaN = (Objeto*)malloc(sizeof(Objeto));
	setaN->bitmap = al_load_bitmap("Imgs/setaN.png");
	setaN->altura = 100;
	setaN->largura = 100;
	setaN->x = 510;
	setaN->y = 560;

	Objeto* setaQ;
	setaQ = (Objeto*)malloc(sizeof(Objeto));
	setaQ->bitmap = al_load_bitmap("Imgs/setaQ.png");
	setaQ->altura = 100;
	setaQ->largura = 100;
	setaQ->x = 710;
	setaQ->y = 560;

	Objeto* setaT;
	setaT = (Objeto*)malloc(sizeof(Objeto));
	setaT->bitmap = al_load_bitmap("Imgs/setaT.png");
	setaT->altura = 100;
	setaT->largura = 100;
	setaT->x = 910;
	setaT->y = 560;
	//=========================================================================================================


	ALLEGRO_BITMAP* btn2 = al_load_bitmap("Imgs/botao.png");
	ALLEGRO_BITMAP* btnPressionado2 = al_load_bitmap("Imgs/botaopressed.png");


	Objeto* campo2;
	campo2 = (Objeto*)malloc(sizeof(Objeto));
	campo2->bitmap = al_load_bitmap("Imgs/slide4.png");
	campo2->altura = 250;
	campo2->largura = 500;
	campo2->x = LARGURA_TELA - campo2->largura;
	campo2->y = ALTURA_TELA - campo2->altura;

	Objeto* bola;
	bola = (Objeto*)malloc(sizeof(Objeto));
	bola->bitmap = al_load_bitmap("Imgs/monca.png");
	bola->altura = 50;
	bola->largura = 50;
	bola->x = (LARGURA_TELA / 2) - (bola->largura / 2);
	bola->y = (ALTURA_TELA / 4) - (bola->altura / 2);

	Objeto* conta;
	conta = (Objeto*)malloc(sizeof(Objeto));
	conta->bitmap = NULL;
	conta->altura = 500;
	conta->largura = 250;
	conta->x = (LARGURA_TELA / 2) - (conta->largura);
	conta->y = (ALTURA_TELA / 2) - (conta->altura / 2);

	//ALLEGRO_BITMAP* padrao = al_load_bitmap("");
	ALLEGRO_BITMAP* conta1 = al_load_bitmap("Imgs/esquerda.png");
	ALLEGRO_BITMAP* conta2 = al_load_bitmap("Imgs/direita.png");
	ALLEGRO_BITMAP* background = al_load_bitmap("Imgs/fundo.png");


	int vetorResposta[10] = { 1,1,2,1,1,2,2,1,2,2 }; //"EEDEEDDEDD";


	bool digitado = false;
	bool sair = false;
	bool drawNull = true;
	bool arrastando = false;
	bool pressionado = false;

	campoesquerda->bitmap = btn;
	campodireita->bitmap = btn2;

	int i = 0;

	Fila fila;
	Fila* f = &fila;
	CriarFila(f);
	while (!sair)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_eventos, &evento);

		ALLEGRO_MOUSE_STATE state;
		al_get_mouse_state(&state);

		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (IsInside(evento.mouse.x, evento.mouse.y, bola) && !arrastando) {
				arrastando = true;

				bola->cliqueX = MapearDistancia(evento.mouse.x, bola->x);
				bola->cliqueY = MapearDistancia(evento.mouse.y, bola->y);
			}

			else if (IsInside(evento.mouse.x, evento.mouse.y, campoesquerda)) {
				if (!pressionado && state.buttons & 1)
				{
					pressionado = false;
					campoesquerda->bitmap = btnPressionado;
				}

				if (FilaCheia(f)) {
					DeQueue(f);
				}
				EmQueue(f, 1);
				if (VerificaFila(f, vetorResposta))
					prog->Salas[0] = 1;
			}
			else if (IsInside(evento.mouse.x, evento.mouse.y, campodireita)) {
				if (!pressionado && state.buttons & 1)
				{
					pressionado = true;
					campodireita->bitmap = btnPressionado2;
				}
				if (FilaCheia(f)) {
					DeQueue(f, vetorResposta);
				}
				EmQueue(f, 2);
				if (VerificaFila(f, vetorResposta))
					prog->Salas[0] = 1;
			}


			else if (IsInside(evento.mouse.x, evento.mouse.y, SaidaCima))
			{
				prog->proximaSala = 1;
				sair = 1;
			}
			else if (IsInside(evento.mouse.x, evento.mouse.y, SaidaEsquerda))
			{
				prog->proximaSala = 3;
				sair = 1;
			}
			else if (IsInside(evento.mouse.x, evento.mouse.y, SaidaBaixo))
			{
				prog->proximaSala = 2;
				sair = 1;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			arrastando = false;
			pressionado = false;
			campoesquerda->bitmap = btn;
			campodireita->bitmap = btn2;


		}




		if (arrastando && state.buttons & 1)
		{
			if (!VerificarBordas(evento.mouse.x, evento.mouse.y, bola))
			{
				bola->x = evento.mouse.x - bola->cliqueX;
				bola->y = evento.mouse.y - bola->cliqueY;
			}

			if (IsInsideImagem(bola, campo1))
			{
				conta->bitmap = conta1;
				drawNull = false;
			}
			else if (IsInsideImagem(bola, campo2))
			{
				conta->bitmap = conta2;
				drawNull = false;
			}
			else
			{
				drawNull = true;

			}
		}

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			sair = true;
			prog->Gameover = true;
		}

		//===========================================DESENHAR========================================================================
		al_draw_bitmap(background, 0, 0, 0);
		if (prog->Salas[0])
			al_draw_bitmap(SaidaCima->bitmap, SaidaCima->x, SaidaCima->y, 0);


		al_draw_bitmap(SaidaEsquerda->bitmap, SaidaEsquerda->x, SaidaEsquerda->y, 0);
		al_draw_bitmap(SaidaBaixo->bitmap, SaidaBaixo->x, SaidaBaixo->y, 0);

		//if (!drawNull)
		//	al_draw_bitmap(conta->bitmap, conta->x, conta->y, 0);

		al_draw_bitmap(setaT->bitmap, setaT->x, setaT->y, 0);
		al_draw_bitmap(setaQ->bitmap, setaQ->x, setaQ->y, 0);
		al_draw_bitmap(setaN->bitmap, setaN->x, setaN->y, 0);
		al_draw_bitmap(setaZ->bitmap, setaZ->x, setaZ->y, 0);
		al_draw_bitmap(setabaixo4->bitmap, setabaixo4->x, setabaixo4->y, 0);
		al_draw_bitmap(setabaixo3->bitmap, setabaixo3->x, setabaixo3->y, 0);
		al_draw_bitmap(setabaixo2->bitmap, setabaixo2->x, setabaixo2->y, 0);
		al_draw_bitmap(setabaixo1->bitmap, setabaixo1->x, setabaixo1->y, 0);
		al_draw_bitmap(setacima4->bitmap, setacima4->x, setacima4->y, 0);
		al_draw_bitmap(setacima3->bitmap, setacima3->x, setacima3->y, 0);
		al_draw_bitmap(setacima2->bitmap, setacima2->x, setacima2->y, 0);
		al_draw_bitmap(setacima1->bitmap, setacima1->x, setacima1->y, 0);
		al_draw_bitmap(caixa4->bitmap, caixa4->x, caixa4->y, 0);
		al_draw_bitmap(caixa3->bitmap, caixa3->x, caixa3->y, 0);
		al_draw_bitmap(caixa2->bitmap, caixa2->x, caixa2->y, 0);
		al_draw_bitmap(caixa1->bitmap, caixa1->x, caixa1->y, 0);
		al_draw_bitmap(china->bitmap, china->x, china->y, 0);
		al_draw_bitmap(londres->bitmap, londres->x, londres->y, 0);
		al_draw_bitmap(toronto->bitmap, toronto->x, toronto->y, 0);
		al_draw_bitmap(brasil->bitmap, brasil->x, brasil->y, 0);
		//al_draw_bitmap(campo1->bitmap, campo1->x, campo1->y, 0);
		//al_draw_bitmap(campo2->bitmap, campo2->x, campo2->y, 0);
		//al_draw_bitmap(campoesquerda->bitmap, campoesquerda->x, campoesquerda->y, 0);
		//al_draw_bitmap(campodireita->bitmap, campodireita->x, campodireita->y, 0);
		//al_draw_bitmap(bola->bitmap, bola->x, bola->y, 0);


		caregaInventario(prog);
		al_flip_display();
	}

	al_destroy_bitmap(background);
	al_destroy_bitmap(SaidaCima->bitmap);
	al_destroy_bitmap(SaidaEsquerda->bitmap);
	al_destroy_bitmap(SaidaBaixo->bitmap);
	//al_destroy_bitmap(padrao);
	al_destroy_bitmap(conta1);
	al_destroy_bitmap(conta2);
	al_destroy_bitmap(campo1->bitmap);
	al_destroy_bitmap(campo2->bitmap);
	al_destroy_bitmap(campoesquerda->bitmap);
	al_destroy_bitmap(campodireita->bitmap);
	al_destroy_bitmap(bola->bitmap);

	free(SaidaBaixo);
	free(SaidaCima);
	free(SaidaEsquerda);
	free(campo1);
	free(campo2);
	free(campoesquerda);
	free(campodireita);
	free(bola);
	free(conta);


	system("pause");

	return 0;
}