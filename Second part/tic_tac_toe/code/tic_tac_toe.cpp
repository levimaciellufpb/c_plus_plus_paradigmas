#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char ESPACO = ' ';
const char EMPATE = 'T';
const char NENHUM = 'N';
const char X = 'X';
const char O = 'O';

//protótipos de funções
void instrucoes();
char pecaHumano();
char perguntarSimOuNao(string pergunta);
char oponente(char peca);
void mostrarTabuleiro(const vector<char>* const pTabuleiro);
char vencedor(const vector<char>* const pTabuleiro);
int movimentoHumano(const vector<char>* const pTabuleiro, char humano);
int perguntarNumero(string pergunta, int high, int low = 0);
bool isLegal(int movimento, const vector<char>* const pTabuleiro);
int movimentoCPU(vector<char> tabuleiro, char computador);
void anunciarVencedor(char vencedor, char computador, char humano);

int main(){
    int movimento;
    const int NUM_QUADRADOS = 9;

    vector<char> tabuleiro(NUM_QUADRADOS, ESPACO);

    instrucoes();
    char humano = pecaHumano();
    char computador = oponente(humano);
    char turno = X;
    mostrarTabuleiro(&tabuleiro);

    while(vencedor(&tabuleiro) == NENHUM){
        //Condição de verificar se é turno humano
        if(turno == humano){
            movimento = movimentoHumano(&tabuleiro, humano);
            tabuleiro[movimento] = humano;
        }
        //Se não for humano, é turno da máquina
        else{
            movimento = movimentoCPU(tabuleiro, humano);
            tabuleiro[movimento] = computador;
        }
        mostrarTabuleiro(&tabuleiro);
        turno = oponente(turno);
    }
    anunciarVencedor(vencedor(&tabuleiro), computador, humano);
    return 0;
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
    //Todas as possíveis vitorias
    const int VITORIAS[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    const int TOTAL_LINHAS = 8;

    for(int linha = 0; linha < TOTAL_LINHAS; ++linha){
        if(
            ((*pTabuleiro)[VITORIAS[linha][0]] != ESPACO) &&
            ((*pTabuleiro)[VITORIAS[linha][0]] == (*pTabuleiro)[VITORIAS[linha][1]]) &&
            ((*pTabuleiro)[VITORIAS[linha][1]] == (*pTabuleiro)[VITORIAS[linha][2]])
        ){
            return (*pTabuleiro)[VITORIAS[linha][0]];
        }
    }
    if(count(pTabuleiro->begin(), pTabuleiro->end(), ESPACO) == 0){
        return EMPATE;
    }
    return NENHUM;


}

int movimentoHumano(const vector<char>* const pTabuleiro, char humano){
    int movimento = perguntarNumero("Para onde você irá mover?", pTabuleiro->size()-1);

    while(!isLegal(movimento, pTabuleiro)){
        cout << "\nEsse espaço já está ocupado, humano bobinho! \n" << endl;
        movimento = perguntarNumero("Para onde você irá mover?", pTabuleiro->size()-1);
    }

    cout << "Certo...\n";
    return movimento;

}

int perguntarNumero(string pergunta, int high, int low){
    int numero;
    do{
        cout << pergunta << " (" << low << " - " << high << "): ";
        cin >> numero;
    }while((numero > high) || (numero < low));
    return numero;
}

//Verifica se existe um espaço no array original, ao invés de caractere
inline bool isLegal(int movimento, const vector<char>* const pTabuleiro){
    return ((*pTabuleiro)[movimento] == ESPACO);
}

int movimentoCPU(vector<char> tabuleiro, char computador){
    unsigned int movimento = 0;
    bool encontrado = false;

    //Se o computador conseguir vencer no próximo movimento, este é o movimento
    while(!encontrado && movimento < tabuleiro.size()){
        if(isLegal(movimento, &tabuleiro)){
            //Simular movimento
            tabuleiro[movimento] = computador;
            //Ver se o computador ganhou
            encontrado = vencedor(&tabuleiro) == computador;
            //Desfazer movimento
            tabuleiro[movimento] = ESPACO;
        }
        if(!encontrado){
            ++movimento;
        }
    }

    //Se não, se o oponente conseguir ganhar no próximo turno, esse é o movimento a se fazer
    if(!encontrado){

        movimento = 0;
        char humano = oponente(computador);

        while(!encontrado && movimento < tabuleiro.size()){
            if(isLegal(movimento, &tabuleiro)){
                //tentar movimento
                tabuleiro[movimento] = humano;
                //testar se humano venceu
                encontrado = vencedor(&tabuleiro) == humano;
                //desfazer movimento
                tabuleiro[movimento] = ESPACO;
            }
            if(!encontrado){
                ++movimento;
            }
        }
    }

    //Se nem humano nem máquina conseguem vencer, se mexer para o melhor quadrado vazio
    if(!encontrado){
        movimento = 0;
        unsigned int i = 0;

        const int MELHORES_MOVIMENTOS[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!encontrado && i < tabuleiro.size()){
            movimento = MELHORES_MOVIMENTOS[i];
            //pq tabuleiro tem que ser passado por referência?
            if(isLegal(movimento, &tabuleiro)){
                encontrado = true;
            }
            ++i;
        }
        
    }

    cout << "Eu devo me mover para o quadrado número " << movimento << endl;
    return movimento;
}

void anunciarVencedor(char vencedor, char computador, char humano){
    if(vencedor == computador){
        cout << "O vencedor foi: " << vencedor << endl;
        cout << "Não fique triste, humano. Era óbvio que iria ganhar\n";
        cout << "Isso só prova que computadores são superiores aos humanos em todos aspectos\n";
    
    }
    else if(vencedor == humano){
        cout << "O vencedor foi: " << vencedor << endl;
        cout << "Não, NÃO! Não pode ser! de alguma forma você me venceu, humano\n";
        cout << "Isso foi uma excessão, da próxima não será assim, humano!\n";
    }
    else{
        cout << "É um empate\n";
        cout << "Você é sortudo, humano. De alguma forma conseguiu empatar comigo\n";
        cout << "Celebre bastante... Pois isso é o melhor que você conseguirá.\n";
    }
}



