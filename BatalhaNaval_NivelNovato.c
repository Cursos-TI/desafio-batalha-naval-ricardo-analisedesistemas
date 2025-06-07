#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void criatbuleiro(int tabuleiro[10][10],int linhas){//esse argumento assume que nao se sabe quantas linhas terá a matriz apenas o numero de elementos[10]
    for(int i =0;i < linhas;i++){
        for(int j =0;j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }


}

int inserenavio(int tabuleiro[10][10], int tamanho, int linha, int coluna, int oritentacao);

void imprimetabuleiro(int tabuleiro[10][10],char letras[10]){ //ou tabuleiro[][10]
//imprime,posiciona e alinha os caracteres de 'A' a 'J' sobre as colunas do tabuleiro
printf(" /-------BATALHA NAVAL--------/\n");
for(int i = 0; i < 10;i++){ 
    printf("  %c",letras[i]);
}
    printf("\n");
//imprime o número identificador e correspondente para cada linha de 0 a 9
for(int i = 0 ; i < 10;i++){
    printf("%2d  ", i - 0);
    for(int j = 0; j < 10;j++){
        tabuleiro[i][j];
        printf("%d  ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }
//imprime ass cooordenadas em que estão os navios
printf("\nCoordenadas dos Navios:\n");
for(int i = 0; i < 10; i++){
    for(int j = 0;j < 10; j++){
        if(tabuleiro[i][j] == 1){
            printf("(Linha:%d, Coluna:%c) ", i, letras[j]);
        }
    }
}


}



int main(int argc, char const *argv[]){

int  tabuleiro[10][10];//(*tabuleiro)[10] se declarar como ponteiro de arrays o compilador exige alocação dinamica de memoria
char letras[11] = {'A','B','C','D','E','F','G','H','I','J'};
int tamanhonavio = 3;

criatbuleiro(tabuleiro,10);

inserenavio(tabuleiro,tamanhonavio,2,2,1);//tamanho, linha,coluna, orientação
inserenavio(tabuleiro,tamanhonavio,9,0,0);

imprimetabuleiro(tabuleiro,letras);


return 0;
}



int inserenavio(int tabuleiro[10][10], int tamanho, int linha, int coluna, int orientacao){
    // Orientacao: 0 para horizontal, 1 para vertical
    
    
    // Verifica se a posição inicial é válida
    if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
        printf("Posição invalida!!");
        getchar();
        return 0; // Posição inválida
    }
    
    // Verifica se o navio cabe na orientação escolhida
    if(orientacao == 0 && (coluna + tamanho) > 10) {
        printf("Não cabe na horizontal, está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0; // Não cabe na horizontal
    }
    if(orientacao == 1 && (linha + tamanho) > 10) {
        printf("Não cabe na vertical, está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0; // Não cabe na vertical
    }
    
    // Verifica se já não há navio nessas posições
    for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0) { // Horizontal
            if(tabuleiro[linha][coluna + i] != 0) {
                printf("Já tem navio aqui!!");
                getchar();
                return 0; // Já tem navio aqui
            }
        } else { // Vertical
            if(tabuleiro[linha + i][coluna] != 0) {
                printf("Já tem navio aqui!!");
                getchar();
                return 0; // Já tem navio aqui
            }
        }
    }
    
// Insere o navio
    for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = 1;//se posição for horizontal = na mesma linha  preenche colunas
        } else { // Vertical
            tabuleiro[linha + i][coluna] = 1;//se posição for vertical = na mesma coluna  preenche linhas
        }
    }
    
    return 1; // Sucesso

}    