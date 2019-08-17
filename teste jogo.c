#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<conio.h>

void cria_fase_2(char **mapa, int x,int y,int xz,int yz, int xc, int yc);
void cria_fase_1(char **mapa, int x,int y,int xz,int yz, int xc, int yc);
void libera_espaco(char **mapa,int dimensao);
void tela_carregamento();
char** desenha_mapa(int dimensao);
void imprime_mapa(int dim,int x,int y,int xz,int yz,int xc,int yc,char **mapa);
void jogador();
//int inteliencia(int x, int y, int xz, int yz, char **mapa);

int main(void){

    srand(time(NULL));
    char tecla;

    int x;
    int y;
    int xz;
    int yz;
    int xc;
    int yc;
    int o=0;

    x = rand() % 20;
    y = rand() % 20;
    xz = rand() % 20;
    yz = rand() % 20;
    xc = rand() % 20;
    yc = rand() % 20;

	int dimensao = 20;
	int Pontos = 0;
	int pontos_max = 0;
    char **m;
    tela_carregamento();
    system("PAUSE");
    m = desenha_mapa(dimensao);
	cria_fase_2(m, x, y, xz, yz, xc, yc);
	//cria_fase_1(m, x, y, xz, yz, xc, yc);

	while(o==0){
	imprime_mapa(dimensao,x,y,xz,yz,xc,yc,m);

	/*TRECHO D OCÓDIGO QUE EXIBE A PONTUAÇÃO DO JOGADOR
	AINDA FALTA IMPLEMETAR COMO VAI FAZER A PONTUAÇÃO.
	*/
	printf("\n");
	printf("|--------------------------------------|\n");
	printf("|             PONTOS: [%d]              |\n",Pontos);
	printf("|--------------------------------------|\n");
	// FIM DO TRECHO QUE EXIBE A PONTUAÇÃO
	Sleep(200);

	//aqui

	if(kbhit()){
        tecla = getch();
	}

	if(tecla == 'w'|| tecla == 'W'){
        if(m[x-1][y]==(char)254){
            //continue;
            //não faz nada
        }else{
            if(m[x-1][y] == '.'){
                Pontos++;
                m[x][y] = ' ';
                x--;
                m[x-1][y] = 'C';
            }
        }
	}
	if(tecla == 's'|| tecla == 'S'){
        if(m[x+1][y]==(char)254){
            //não faz nada
        }else{
            if(m[x+1][y] == '.'){
                Pontos++;
                m[x][y] = ' ';
                x++;
                m[x+1][y] = 'C';
            }
        }
	}
	if(tecla == 'a'|| tecla == 'A'){
        if(m[x][y-1]==(char)254){
            //não faz nada
        }else{
            if(m[x][y-1] == '.'){
                Pontos++;
                m[x][y] = ' ';
                x--;
                m[x][y-1] = 'C';
            }
        }
	}
	if(tecla == 'd'|| tecla == 'D'){
        if(m[x][y+1]==(char)254){
            //não faz nada
        }else{
            if(m[x][y+1] == '.'){
                Pontos++;
                m[x][y] = ' ';
                x++;
                m[x][y+1] = 'C';
            }
        }
	}

	if(xz==xc&&yz==yc){
        if(m[xz+1][yz]!=(char)254){
            xz++;}else{
                    if(m[xc-1][yc]!=(char)254){
            xc--;}else{
                    if(m[xc][yc+1]!=(char)254){
            yc++;}else{
                    if(m[xz][yz-1]!=(char)254){

            yz--;}
                    }
                    }
                    }

	}
	if(x>xz){
        if(m[xz+1][yz]==(char)254){
            if(m[xz][yz+1]==' '||m[xz][yz+1]=='.'){
                 yz++;

            }else{
                if(m[xz][yz-1]==' '||m[xz][yz-1]=='.'){
                  yz--;

                }
            }

        }else{
            xz++;}

        }else{
            if(y>yz){
                if(m[xz][yz+1]==(char)254){
                    if(m[xz+1][yz]==' '||m[xz+1][yz]=='.'){
                        xz++;
                }else{
                    if(m[xz-1][yz]==' '||m[xz-1][yz]=='.'){
                        xz--;
                }}
            }else{
            yz++;}



            }else{
                if(x<xz){
                    if(m[xz-1][yz]==(char)254){
                        if(m[xz][yz+1]==' '||m[xz][yz+1]=='.'){
                            yz++;
                }else{
                    if(m[xz][yz-1]==' '||m[xz][yz-1]=='.'){
                    yz--;
                }}
            }else{
                xz--;}

            }else{
                if(y<yz){
                    if(m[xz][yz-1]==(char)254){
                        if(m[xz+1][yz]==' '||m[xz+1][yz]=='.'){
                            xz++;

                }else{
                    if(m[xz-1][yz]==' '||m[xz-1][yz]=='.'){
                        xz--;
                }}



            }else{
                yz--;}

                }

if(x==xz && y==yz){
    libera_espaco(m,dimensao);
    return(0);

}

}

}

}



if(x>xc){

            if(m[xc+1][yc]==(char)254){

                if(m[xc][yc+1]==' '||m[xc][yc+1]=='.'){

                 yc++;

                }else{

                if(m[xc][yc-1]==' '||m[xc][yc-1]=='.'){

                  yc--;

                }}

            }else{

    xc++;}



}else{

if(y>yc){

            if(m[xc][yc+1]==(char)254){

                if(m[xc+1][yc]==' '||m[xc+1][yc]=='.'){

                    xc++;

                }else{

                if(m[xc-1][yc]==' '||m[xc-1][yc]=='.'){

                    xc--;

                }}



            }else{

    yc++;}



}else{

if(x<xc){

                    if(m[xc-1][yc]==(char)254){

                if(m[xc][yc+1]==' '||m[xc][yc+1]=='.'){

                    yc++;

                }else{

                if(m[xc][yc-1]==' '||m[xc][yc-1]=='.'){

                    yc--;

                }}



            }else{

    xc--;}



}else{

if(y<yc){

                        if(m[xc][yc-1]==(char)254){

                if(m[xc+1][yc]==' '||m[xc+1][yc]=='.'){

                    xc++;

                }else{

                if(m[xc-1][yc]==' '||m[xc-1][yc]=='.'){

                    xc--;

                }}



            }else{

    yc--;}

}

if(x==xc && y==yc){
    libera_espaco(m,dimensao);
    return(0);

}

}

}

}


	system("cls");
	imprime_mapa(dimensao,x,y,xz,yz,xc,yc,m);
	system("cls");
	}

	return 0;

}

//FUNÇÃO QUE CONSTROI O MAPA
//essa função precisa de parametro uma variavel fixa int dimensao = 20;

char** desenha_mapa(int dim){
	int i,x;
	char **mapa;
	mapa = (char**)malloc(dim*sizeof(char*));//alocando uma dimensao do mapa
		for(x=0;x<dim;x++){
			mapa[x] = (char*)malloc(dim*sizeof(char));//fazendo a segunda alocação do mapa
			for(i=0;i<dim;i++){
				//condição que verifica e faz a construção do mapa
				if(i==0 || i==(dim-1) || x==0 || x==(dim-1)){
					mapa[x][i] = 254;
				}else{
					mapa[x][i] = '.';

				}
		   }
		}

	return mapa;
}

//FIM DA FUNÇÃO QUE CRIA O MAPA

void imprime_mapa(int dim,int x,int y,int xz,int yz,int xc,int yc,char **mapa){

	int i,j;

	mapa[x][y] = 'C';
	mapa[xz][yz] = '#';
	mapa[xc][yc] = '&';
	system("CLS");

	for(i=0;i<dim;i++){
		printf("\n");
		for(j=0;j<dim;j++){
			printf("%c ",mapa[i][j]);

		}
	}
}

//==============================

//FUNÇÃO QUE DESENHA AS PAREDES NO MAPA

void cria_fase_2(char **mapa, int x, int y, int xz, int yz, int xc, int yc){

	//criando as paredes bloco superior esquerdo
	system("color 4f");
	mapa[10][9] = 254;
    mapa[10][10] = 254;
    mapa[11][9] =  254;
    mapa[11][10] = 254;
    mapa[12][9] = 254;
	//criando as paredes bloco superior esquerdo
	mapa[2][6] = 254;
	mapa[2][7] = 254;
	mapa[3][6] = 254;
	mapa[3][7] = 254;
	mapa[4][6] = 254;
	mapa[4][7] = 254;
	mapa[5][6] = 254;
	mapa[5][7] = 254;
    mapa[2][2] = 254;
    mapa[2][3] = 254;
	mapa[2][4] = 254;
	mapa[3][2] = 254;
	mapa[3][3] = ' ';
	mapa[3][4] = 254;
	mapa[4][2] = 254;
	mapa[4][3] = ' ';
	mapa[4][4] = 254;
	mapa[5][2] = 254;
	mapa[5][3] = 254;
	mapa[5][4] = 254;
	//==============fim
	//criando parede na parte superior direita
	mapa[2][12] = 254;
	mapa[3][12] = 254;
	mapa[4][12] = 254;
	mapa[5][12] = 254;
	mapa[2][13] = 254;
	mapa[3][13] = 254;
	mapa[4][13] = 254;
	mapa[5][13] = 254;
	//==============fim
	//superior direito 2
	mapa[2][15] = 254;
	mapa[2][16] = 254;
	mapa[2][17] = 254;
	mapa[3][15] = 254;
	mapa[3][16] = ' ';
	mapa[3][17] = 254;
	mapa[4][15] = 254;
	mapa[4][16] = ' ';
	mapa[4][17] = 254;
	mapa[5][15] = 254;
	mapa[5][16] = 254;
	mapa[5][17] = 254;
	//==============fim
	//superior central beira
	mapa[1][9] = 254;
	mapa[2][9] = 254;
	mapa[3][9] = 254;
	mapa[4][9] = 254;
	mapa[5][9] = 254;
	mapa[1][10] = 254;
	mapa[2][10] = 254;
	mapa[3][10] = 254;
	mapa[4][10] = 254;
	mapa[5][10] = 254;
	//==============fim
	//direita central
	mapa[7][1] = 254;
	mapa[7][2] = 254;
	mapa[7][3] = 254;
	mapa[8][1] = 254;
	mapa[9][3] = 254;
	mapa[10][2] = 254;
	mapa[10][3] = 254;
	mapa[11][3] = 254;
	mapa[12][1] = 254;
	mapa[13][1] = 254;
	mapa[13][2] = 254;
	mapa[13][3] = 254;
	//==============fim
	//bolocos unitários
	mapa[12][7] = 254;
	mapa[12][12] = 254;
	//==============fim
	//esquerdo central
	mapa[7][16] = 254;
	mapa[7][17] = 254;
	mapa[7][18] = 254;
	mapa[8][18] = 254;
	mapa[9][16] = 254;
	mapa[10][16] = 254;
	mapa[10][17] = 254;
	mapa[11][16] = 254;
	mapa[12][18] = 254;
	mapa[13][18] = 254;
	mapa[13][17] = 254;
	mapa[13][16] = 254;
	//===============fim
	//central esquerdo
	mapa[7][5] = 254;
	mapa[8][5] = 254;
	mapa[9][5] = 254;
	mapa[10][5] = 254;
	mapa[11][5] = 254;
	mapa[12][5] = 254;
	mapa[9][6] = 254;
	mapa[9][7] = 254;
	mapa[10][6] = 254;
	mapa[10][7] = 254;
	//===============fim
	//central direito
	mapa[7][14] = 254;
	mapa[8][14] = 254;
	mapa[9][14] = 254;
	mapa[10][14] = 254;
	mapa[11][14] = 254;
	mapa[12][14] = 254;
	mapa[9][13] = 254;
	mapa[9][12] = 254;
	mapa[10][13] = 254;
	mapa[10][12] = 254;
	//===============fim
	//superior central
	mapa[7][7] = 254;
	mapa[7][8] = 254;
	mapa[7][9] = 254;
	mapa[7][10] = 254;
	mapa[7][11] = 254;
	mapa[7][12] = 254;
	mapa[8][9] = 254;
	mapa[8][10] = 254;
	mapa[9][9] = 254;
	mapa[9][10] = 254;
	//==============fim
	//inferior esquerdo
	mapa[15][2] = 254;
	mapa[15][3] = 254;
	mapa[15][4] = 254;
	mapa[16][2] = 254;
	mapa[16][3] = ' ';
	mapa[16][4] = ' ';
	mapa[17][2] = 254;
	mapa[17][3] = 254;
	mapa[17][4] = 254;
	mapa[14][5] = 254;
	mapa[15][5] = 254;
	mapa[16][5] = 254;
	mapa[17][5] = 254;
	//==============fim
	//inferior direito
	mapa[15][15] = 254;
	mapa[15][16] = 254;
	mapa[15][17] = 254;
	mapa[16][15] = ' ';
	mapa[16][16] = ' ';
	mapa[16][17] = 254;
	mapa[17][15] = 254;
	mapa[17][16] = 254;
	mapa[17][17] = 254;
	mapa[14][19] = 254;
	mapa[14][10] = 254;
	mapa[14][14] = 254;
	mapa[15][9] = 254;
	mapa[15][10] = 254;
	mapa[15][14] = 254;
	mapa[16][14] = 254;
	mapa[17][14] = 254;
	//===============fim
	//superior esquerdo 3
	mapa[16][7] = 254;
	mapa[17][7] = 254;
	//===============fim
	//superior direito 3
	mapa[16][12] = 254;
	mapa[17][12] = 254;
	//===============fim
	//inferior central beira
	mapa[16][9] = 254;
	mapa[17][9] = 254;
	mapa[18][9] = 254;
	mapa[16][10] = 254;
	mapa[17][10] = 254;
	mapa[18][10] = 254;
	//================fim
    // trecho do código que insere os personagens
    //mapa[x][y] = 'k';
	//mapa[xz][yz] = 'j';
	//mapa[xc][yc] = 'v';

}


void cria_fase_1(char **mapa, int x, int y, int xz, int yz, int xc, int yc){

    //MAPA VERDE E BRANCO

    system("color 2f");

    mapa[2][2] = 254;

    mapa[2][3] = 254;

    mapa[3][2] = 254;

    mapa[3][3] = 254;

    mapa[4][2] = 254;

    mapa[4][3] = 254;

    mapa[5][2] = 254;

    mapa[5][3] = 254;

    //===============

    mapa[2][5] = 254;

    mapa[2][6] = 254;

    mapa[3][5] = 254;

    mapa[3][6] = 254;

    mapa[4][5] = 254;

    mapa[4][6] = 254;

    mapa[5][5] = 254;

    mapa[5][6] = 254;

    //===============

    mapa[2][8] = 254;

    mapa[2][9] = 254;

    mapa[3][8] = 254;

    mapa[3][9] = 254;

    mapa[4][8] = 254;

    mapa[4][9] = 254;

    mapa[5][8] = 254;

    mapa[5][9] = 254;

    //===============

    mapa[2][11] = 254;

    mapa[2][12] = 254;

    mapa[3][11] = 254;

    mapa[3][12] = 254;

    mapa[4][11] = 254;

    mapa[4][12] = 254;

    mapa[5][11] = 254;

    mapa[5][12] = 254;

    //================

    mapa[2][14] = 254;

    mapa[2][15] = 254;

    mapa[3][14] = 254;

    mapa[3][15] = 254;

    mapa[4][14] = 254;

    mapa[4][15] = 254;

    mapa[5][14] = 254;

    mapa[5][15] = 254;

    //================

    mapa[2][17] = 254;

    mapa[2][17] = 254;

    mapa[3][17] = 254;

    mapa[3][17] = 254;

    mapa[4][17] = 254;

    mapa[4][17] = 254;

    mapa[5][17] = 254;

    mapa[5][17] = 254;

    //================

    mapa[7][17] = 254;

    mapa[7][16] = 254;

    mapa[7][15] = 254;

    mapa[7][14] = 254;

    mapa[7][13] = 254;

    mapa[7][12] = 254;

    mapa[7][11] = 254;

    //mapa[7][10] = 254;

    mapa[7][9] = 254;

    mapa[7][8] = 254;

    mapa[7][7] = 254;

    mapa[7][6] = 254;

    mapa[7][5] = 254;

    mapa[7][4] = 254;

    mapa[7][3] = 254;

    mapa[7][2] = 254;

    //===============

    //mapa[9][10] = 254;

    mapa[9][11] = 254;

    mapa[9][12] = 254;

    mapa[9][13] = 254;

    mapa[9][14] = 254;

    mapa[9][15] = 254;

    mapa[9][16] = 254;

    mapa[9][17] = 254;

    //================

    //mapa[10][10] = 254;

    mapa[10][11] = 254;

    mapa[10][12] = 254;

    mapa[10][13] = 254;

    mapa[10][14] = 254;

    mapa[10][15] = 254;

    mapa[10][16] = 254;

    mapa[10][17] = 254;

    //=================

    mapa[9][2] = 254;

    mapa[9][3] = 254;

    mapa[9][4] = 254;

    mapa[9][5] = 254;

    mapa[9][6] = 254;

    mapa[9][7] = 254;

    mapa[9][8] = 254;

    mapa[9][9] = 254;

    //===============

    mapa[10][2] = 254;

    mapa[10][3] = 254;

    mapa[10][4] = 254;

    mapa[10][5] = 254;

    mapa[10][6] = 254;

    mapa[10][7] = 254;

    mapa[10][8] = 254;

    mapa[10][9] = 254;

    //================

    mapa[12][2] = 254;

    mapa[13][2] = 254;

    mapa[14][2] = 254;

    mapa[15][2] = 254;

    mapa[12][3] = 254;

    mapa[13][3] = 254;

    mapa[14][3] = 254;

    mapa[15][3] = 254;

    //================

    mapa[12][5] = 254;

    mapa[13][5] = 254;

    mapa[14][5] = 254;

    mapa[15][5] = 254;

    mapa[12][6] = 254;

    mapa[13][6] = 254;

    mapa[14][6] = 254;

    mapa[15][6] = 254;

    //================

    mapa[12][8] = 254;

    mapa[13][8] = 254;

    mapa[14][8] = 254;

    mapa[15][8] = 254;

    mapa[12][9] = 254;

    mapa[13][9] = 254;

    mapa[14][9] = 254;

    mapa[15][9] = 254;

    //================

    mapa[12][11] = 254;

    mapa[13][11] = 254;

    mapa[14][11] = 254;

    mapa[15][11] = 254;

    mapa[12][12] = 254;

    mapa[13][12] = 254;

    mapa[14][12] = 254;

    mapa[15][12] = 254;

    //=================

    mapa[12][14] = 254;

    mapa[13][14] = 254;

    mapa[14][14] = 254;

    mapa[15][14] = 254;

    mapa[12][15] = 254;

    mapa[13][15] = 254;

    mapa[14][15] = 254;

    mapa[15][15] = 254;

    //=================

    mapa[12][17] = 254;

    mapa[13][17] = 254;

    mapa[14][17] = 254;

    mapa[15][17] = 254;

    mapa[12][17] = 254;

    mapa[13][17] = 254;

    mapa[14][17] = 254;

    mapa[15][17] = 254;

    //=================

    mapa[17][2] = 254;

    mapa[17][3] = 254;

    mapa[17][4] = 254;

    mapa[17][5] = 254;

    mapa[17][6] = 254;

    mapa[17][7] = 254;

    mapa[17][8] = 254;

    mapa[17][9] = 254;

    mapa[17][10] = 254;

    mapa[17][11] = 254;

    mapa[17][12] = 254;

    mapa[17][13] = 254;

    mapa[17][14] = 254;

    mapa[17][15] = 254;

    mapa[17][16] = 254;

    mapa[17][17] = 254;

    //=================
    //trecho que insere os personagens no jogo
    //mapa[x][y] = 'k';
	//mapa[xz][yz] = 'v';
	//mapa[xc][yc] = 'j';


}

void libera_espaco(char **mapa,int dim){
		for(int x=0;x<dim;x++){
			free(mapa[x]);
		}
		free(mapa);

}
void tela_carregamento(){
    //TRECHO DE CÓDIGO QUE SIMULA UMA TELA DE CARREGAMENTO.
	printf("Carregando mapa: ");
	for(int x=0;x<100;x++){
	    Sleep(20);
            printf("|*|*");
	}
	// FIM DO CÓDIGO DE CARREGAMENTO
}

