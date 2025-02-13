#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "moverpeca.h"
#include "index.h"

//prototipo de funcao
void perguntaInicial();
int verificarPeca(char peca[20]);
void minusculaConverter(char peca[]);
void selecionarNovaPeca();

void perguntaInicial() {
    char peca[20];
    printf("Entre essas opcoes, digite a peca que voce deseja movimentar:\n");
    printf("Bispo, Torre ou Rainha ?\n");
    if (fgets(peca, 20, stdin)) {
        peca[strcspn(peca, "\n")] = '\0';  
    } else {
        clearerr(stdin);
        perguntaInicial();
    }
    
    verificarPeca(peca);  
}
int verificarPeca(char peca[20]) {
    minusculaConverter(peca);
    if (strcmp(peca, "bispo") == 0 ||
        strcmp(peca, "torre") == 0 ||
        strcmp(peca, "rainha") == 0) {
moverPeca(peca);
        return 1;
    }
    printf("Peca '%s' invalida.\n", peca);
    perguntaInicial();
    return 0;  
}
void minusculaConverter(char peca[]) {
    for (int i = 0; peca[i]; i++) {
        peca[i] = tolower(peca[i]);
    }
}

void selecionarNovaPeca(){
char resposta[5];
    while (1) {
printf("Digite se deseja selecionar outra peca sim ou nao ?\n");
    if (fgets(resposta, sizeof(resposta), stdin)) {
            resposta[strcspn(resposta, "\n")] = '\0';
        }
        if (strcmp(resposta, "sim") == 0 ) {
perguntaInicial();            
            break;
        } else if (strcmp(resposta, "nao") == 0) {
            printf("Fim de jogo.\n");
            break;
        } else {
            printf("Resposta invalida.\n");
        }
    }
}

int main() {
perguntaInicial();

return 0;
}