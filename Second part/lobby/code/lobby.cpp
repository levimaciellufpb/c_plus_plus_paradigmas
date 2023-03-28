#include <iostream>
#include <string>

using namespace std;

class Player{
    public:

    private:
        string m_Nome;
        Player* m_pProximo; //Ponteiro para próximo jogador na lista;
};

class Lobby{
    public:
    private:
};


int main(){
    Lobby meuLobby;
    int escolha;

    do{
        //cout << meuLobby;
        cout << "\nLobby de Jogo\n";
        cout << "[1] Sair do programa" << endl;
        cout << "[2] Adicionar jogador ao Lobby" << endl;
        cout << "[3] Remover jogador do Lobby" << endl;
        cout << "[4] Limpar Lobby completamente\n" << endl;

        cout << "Digite sua opção:\n>>";
        cin >> escolha;

        switch(escolha){
            
            case 1: cout << "Adeus!\n"; break;
            case 2: //add player
            case 3: //remover player
            case 4: //limpar lobby
            default: cout << "Essa escolha não é válida! Por favor, tente novamente!" << endl;

        }





    }while(escolha != 1);



}




