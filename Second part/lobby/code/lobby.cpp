#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        Player(const string& nome);
        string GetNome() const;
        Player* GetProximo() const;
        void SetProximo(Player* proximo);

    private:
        string m_Nome;
        Player* m_pProximo; //Ponteiro para próximo jogador na lista;
};

Player::Player(const string& nome):
    m_Nome(nome),
    m_pProximo(0)
    {}

string Player::GetNome() const{
    return m_Nome;
}

Player* Player::GetProximo() const{
    return m_pProximo;
}

void Player::SetProximo(Player* proximo){
    m_pProximo = proximo;
}

class Lobby{

    //sobrecarga do operador '<<' para que possa imprimir 
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);

    public:
        Lobby();
        ~Lobby();

        void AddJogador();
        void RemoverJogador();
        void Limpar();

    private:
        Player* m_pCabeca;
        
};

Lobby::Lobby():
    m_pCabeca(0)
    {};

Lobby::~Lobby(){
    Limpar();
}

void Lobby::AddJogador(){
    cout << "Por favor, digite o nome do novo jogador: \n>>";

    string nome;
    cin >> nome;

    Player* pNovoJogador = new Player(nome);

    //Caso não tenham jogadores no lobby
    if(m_pCabeca == 0){
        m_pCabeca = pNovoJogador;
    }
    //Se não, já temos uma cabeça para lista. Procurar jogador até que não haja nada mais
    //Funcionamento semelhante de uma linked list
    else{
        Player* pIter = m_pCabeca;

        while (pIter->GetProximo() != 0)
        {
            pIter = pIter->GetProximo();
        }

        pIter->SetProximo(pNovoJogador);
        
    }
}

void Lobby::RemoverJogador(){
    if(m_pCabeca == 0){
        cout << "O lobby está vazio! Não há jogadores!" << endl;
    }
    else{
        //Com a linha abaixo, terão 2 variaveis apontando para pCabeca
        Player* pTemp = m_pCabeca;
        //pCabeca irá apontar para o próximo, deixando somente pTemp
        m_pCabeca = m_pCabeca->GetProximo();
        //é deletado e desalocado pTemp
        delete pTemp;
    }
}

void Lobby::Limpar(){
    while(m_pCabeca != 0){
        RemoverJogador();
    }
}

//Quando ocorrer cout de um lobby, como se fosse um toString()
ostream& operator<<(ostream& os, const Lobby& aLobby){
    Player* pIter = aLobby.m_pCabeca;

    os << "\nEstes são os que estão no lobby de jogo:" << endl;

    if(pIter == 0){
        os << "Não há jogadores no lobby!" << endl;
    }
    else{
        while (pIter != 0)
        {
            os << pIter->GetNome() << "\n";
            pIter = pIter->GetProximo();
        }
    }
    return os;
}

int main(){
    Lobby meuLobby;
    int escolha;

    do{
        cout << meuLobby;
        cout << "\nLobby de Jogo\n";
        cout << "[1] Sair do programa" << endl;
        cout << "[2] Adicionar jogador ao Lobby" << endl;
        cout << "[3] Remover jogador do Lobby" << endl;
        cout << "[4] Limpar Lobby completamente\n" << endl;

        cout << "Digite sua opção:\n>>";
        cin >> escolha;

        switch(escolha){
            
            case 1: cout << "Adeus!\n"; break;
            case 2: meuLobby.AddJogador(); break;
            case 3: meuLobby.RemoverJogador(); break;
            case 4: meuLobby.Limpar(); break;
            default: cout << "Essa escolha não é válida! Por favor, tente novamente!" << endl;

        }
    }while(escolha != 1);
}




