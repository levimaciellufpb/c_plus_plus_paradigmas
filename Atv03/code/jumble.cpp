#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    
    enum campos{PALAVRA, DICA, NUM_CAMPOS};

    const int NUM_PALAVRAS = 5;

    //Gerando número aleatório entre 0 e 4;
    unsigned seed = time(0);
    srand(seed);
    int numEscolhido = rand() % NUM_PALAVRAS;

    const string PALAVRAS[NUM_PALAVRAS][NUM_CAMPOS] = {
        {"parede", "Você sente vontade de bater sua cabeça nela"},
        {"oculos","Talvez lhe ajude a ver a resposta"},
        {"touro","Não mostre nada vermelho para ele"},
        {"pikachu","choque do trovão agora!"},
        {"batman","órfão e bilionário"}
    };

    string palavraEscolhida = PALAVRAS[numEscolhido][PALAVRA];
    string dicaEscolhida = PALAVRAS[numEscolhido][DICA];

    string palavraDistorcida = palavraEscolhida;
    const int tamanhoPalavra = palavraEscolhida.size();

    for(int i = 0; i < tamanhoPalavra; i++){
        int primeiroIndex = rand() % tamanhoPalavra;
        int segundoIndex = rand() % tamanhoPalavra;

        char swap = palavraDistorcida[primeiroIndex];

        palavraDistorcida[primeiroIndex] = palavraDistorcida[segundoIndex];
        palavraDistorcida[segundoIndex] = swap;

    }

    cout << "Bem vindo ao word jumble!" << endl;
    cout << "Desembaralhe as letras e forme uma palavra!" << endl;
    cout << "Digite 'Dica' para receber uma dica" << endl;
    cout << "Digite 'Sair' para sair do jogo \n" << endl;

    cout << "A palavra embaralhada é: " << palavraDistorcida << endl;

    string tentativa;
    cout << "Digite a sua tentativa: " << endl;
    cin >> tentativa;

    while((tentativa != palavraEscolhida) && tentativa != "Sair"){

        if(tentativa == "Dica"){
            cout << dicaEscolhida << endl;
        }
        else{
            cout << "Palavra incorreta!" << endl;
        }    

        cout << "Digite a sua tentativa: " << endl;
        cin >> tentativa;

    }

    if(tentativa == palavraEscolhida){
        cout << "Parabéns! Você ganhou!" << endl;
    }

    cout << "Muito obrigado por jogar!" << endl;

    return 0;
}