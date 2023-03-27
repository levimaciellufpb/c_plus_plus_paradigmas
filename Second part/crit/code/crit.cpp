#include <iostream>

using namespace std;

class Critter{

    public:
        Critter(int fome = 0, int tedio = 0);
        void Falar();
        void Comer(int comida = 4);
        void Brincar(int diversao = 4);
    
    private:
        int m_fome;
        int m_tedio;
        
        //const evita que variáveis sejam alteradas
        int GetHumor() const;
        //int time é um parâmetro padrão da função, caso não seja passado nada
        void PassarTempo(int time = 1);

};

Critter::Critter(int fome, int tedio):
    m_fome(fome),
    m_tedio(tedio)
    {}

inline int Critter::GetHumor() const{
    return (m_fome + m_tedio);
}

void Critter::PassarTempo(int tempo){
    m_fome += tempo;
    m_tedio += tempo;
}

void Critter::Falar(){
    cout << "Sou um bichinho e me sinto ";

    int humor = GetHumor();
    cout << GetHumor();

    if(humor > 15){
        cout << "com raiva.\n";
    }
    else if(humor > 10){
        cout << "frustrado.\n";
    }
    else if(humor > 5){
        cout << "okay.\n";
    }
    else{
        cout << "feliz :)\n";
    }
    PassarTempo();
}

void Critter::Comer(int comida){
    cout << "Brruuuppp.\n" << endl;

    m_fome = m_fome - comida;

    if(m_fome < 0){
        m_fome = 0;
    }
    PassarTempo();
}

void Critter::Brincar(int diversao){
    cout << "wheeeee" << endl;

    m_tedio = m_tedio - diversao;

    if(m_tedio < 0){
        m_tedio = 0;
    }

    PassarTempo();

}

int main(){
    Critter geraldo;
    geraldo.Falar();
    int escolha;

    do{
        cout << "\n Cuidador de Bichinho\n\n" << endl;
        cout << "[1] - Sair" << endl;
        cout << "[2] - Ouvir seu bichinho" << endl;
        cout << "[3] - Alimentar seu bichinho" << endl;
        cout << "[4] - Brincar com seu bichinho\n" << endl;

        cout << "Digite sua escolha\n>>" << endl;
        
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "Até breve!\n";
            break;

        case 2:
            geraldo.Falar();
            break;

        case 3:
            geraldo.Comer();
            break;

        case 4: 
            geraldo.Brincar();
            break;
        
        default:
            cout << "A opção digitada não existe! Por favor, tente novamente!" << endl;
            break;
        }


    }while(escolha != 1);
}




