#include <stdio.h>
#include <stdlib.h>

void cria_fase_2(char **mapa);
char** desenha_mapa(int dimensao);
void imprime_mapa(int dim,char **mapa);
void libera_espaco(char **mapa,int dim);

int main(void){
	
	int Pontos = 0;
	int dimensao = 20;
	char **m;
	m = desenha_mapa(dimensao);
	cria_fase_2(m);
	imprime_mapa(dimensao,m);
	libera_espaco(m,dimensao);

	return 0;
}

//FUN��O QUE CONSTROI O MAPA
//essa fun��o precisa de parametro uma variavel fixa int dimensao = 20;
char** desenha_mapa(int dim){
	
	int i,x;
	char **mapa;
	
	mapa = (char**)malloc(dim*sizeof(char*));//alocando uma dimensao do mapa
		for(x=0;x<dim;x++){
			mapa[x] = (char*)malloc(dim*sizeof(char));//fazendo a segunda aloca��o do mapa
			for(i=0;i<dim;i++){
				//condi��o que verifica e faz a constru��o do mapa
				if(i==0 || i==(dim-1) || x==0 || x==(dim-1)){
					mapa[x][i] = 254;
				}else{
					mapa[x][i] = '.';
				}
		   } 
		}
	return mapa;	
}
//FIM DA FUN��O QUE CRIA O MAPA
//fun��o que imprime o mapa na tela
void imprime_mapa(int dim,char **mapa){
	int i,j;
	for(i=0;i<dim;i++){
		printf("\n");
		for(j=0;j<dim;j++){
			printf("%c ",mapa[i][j]);
		}
	}
}	

//==============================
//FUN��O QUE DESENHA AS PAREDES NO MAPA
void cria_fase_2(char **mapa){
	system("color 4f");
	//criando as paredes bloco superior esquerdo
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
	//bolocos unit�rios
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
	mapa[14][14] = 254;
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
}
void cria_fase_1(char **mapa){
		
}
void cria_fase_boss(char **mapa){
	
}
void libera_espaco(char **mapa,int dim){
		for(int x=0;x<dim;x++)free(mapa[x]);
		free(mapa);
}

