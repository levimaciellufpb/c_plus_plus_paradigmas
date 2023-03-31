#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char ESPACO = ' ';
const char X = 'X';
const char O = 'O';

//protótipos de funções
void instrucoes();
char pecaHumano();
char perguntarSimOuNao(string pergunta);
char oponente(char peca);
void mostrarTabuleiro(const vector<char>* const pTabuleiro);
char vencedor(const vector<char>* const pTabuleiro);


int main(){

    int movimento;
    const int NUM_QUADRADOS = 9;

    vector<char> tabuleiro(NUM_QUADRADOS, ESPACO);

    instrucoes();
    char humano = pecaHumano();
    char computador = oponente(humano);
    char turno = X;
    mostrarTabuleiro(&tabuleiro);

}

//funções

void instrucoes(){

    cout << "Bem vindo ao confronto final entre homem e máquina: Jogo da velha!\n";
    cout << "--Onde o cérebro humano é colocado contra um processador de silício\n\n";

    cout << "Faça um movimento conhecido ao digitar um número de 0 a 8, o número\n";
    cout << "corresponde a posição desejada no tabuleiro, como será ilustrado:\n\n";

    cout << "   0 | 1 | 2\n";
    cout << "  -----------\n";
    cout << "   3 | 4 | 5\n";
    cout << "  -----------\n";
    cout << "   6 | 7 | 8\n";

    cout << "Se prepare, humano. A batalha está prestes a começar...\n\n";

}

char pecaHumano(){
    char irPrimeiro = perguntarSimOuNao("Você quer fazer a primeira jogada?");

    if(irPrimeiro == 's'){
        cout << "\nEntão faça a primeira jogada. Você vai precisar disso...\n";
        return X;
    }
    else{
        cout << "\nVocê ainda vai desejar não ter escolhido isso... Irei primeiro!\n";
        return O;
    }
}

char perguntarSimOuNao(string pergunta){
    char resposta;

    do{
        cout << pergunta << " (s/n): ";
        cin >> resposta;
    }while(resposta != 's' && resposta != 'n');

    return resposta;
}

char oponente(char peca){
    if(peca == X){
        return O;
    }
    else{
        return X;
    }
}

void mostrarTabuleiro(const vector<char>* const pTabuleiro){
    cout << "\n\t" << (*pTabuleiro)[0] << " | " << (*pTabuleiro)[1] << " | " << (*pTabuleiro)[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pTabuleiro)[3] << " | " << (*pTabuleiro)[4] << " | " << (*pTabuleiro)[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pTabuleiro)[6] << " | " << (*pTabuleiro)[7] << " | " << (*pTabuleiro)[8];
    cout << "\n\n";
}

char vencedor(const vector<char>* const pTabuleiro){
    const int POSSIVEIS_VITORIAS[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    const int TOTAL_COLUNAS = 8;

    for(int linha = 0; linha <= TOTAL_COLUNAS; ++linha){

        
    }


}
