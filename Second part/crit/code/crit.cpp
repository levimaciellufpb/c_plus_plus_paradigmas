#include <iostream>

using namespace std;

class Critter{

    public:
        Critter(int fome = 0, int tedio = 0);
        void Falar();
        void Comer(int food = 4);
        void Brincar(int fun = 4);
    
    private:
        int fome;
        int tedio;
        
        //const evita que variáveis sejam alteradas
        int GetHumor() const;
        //int time é um parâmetro padrão da função, caso não seja passado nada
        void PassarTempo(int time = 1);

};

Critter::Critter(int fome, int tedio):
    fome(this->fome),
    tedio(this->tedio)
    {}

inline int Critter::GetHumor() const{
    return (fome + tedio);
}

void Critter::PassarTempo(int tempo){
    fome += tempo;
    tedio += tempo;
}

void Critter::Falar(){
    cout << "Sou um bichinho e me sinto ";

    int humor = GetHumor();

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

    fome -= comida;

    if(fome < 0){
        fome = 0;
    }
    PassarTempo();
}

void Critter::Brincar(int diversao){
    cout << "wheeeee" << endl;

    tedio -= diversao;

    if(tedio < 0){
        tedio = 0;
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




