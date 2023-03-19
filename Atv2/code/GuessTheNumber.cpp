#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    unsigned seed = time(0);
    srand(seed);

    int numeroEscolhido = rand() % 100 +1;

    int tentativas = 5;
    int chute;

    cout << "Bem vindo Ao guess the number! \n" << endl;
    cout << "Um número aleatório foi escolhido! Tente descobrir que número é esse" << endl;
    cout << "As tentativas vão de 0 até 100. Boa sorte!\n" << endl;

    system("pause");

    do{

        cout << "Tentativas : " << tentativas << endl;
        cout << "Digite um número: \n" << endl;
        cin >> chute; 

        if(chute > numeroEscolhido){
            cout << "Seu chute foi muito alto! O número que você procura é menor. \n" << endl;
            tentativas -= 1;
        }
        else if(chute < numeroEscolhido){
            cout << "Seu chute foi muito baixo! O número que você procura é maior. \n" << endl;
            tentativas -= 1;
        }
        else{
            cout << "Você acertou! O número secreto era " << numeroEscolhido << "! Bom trabalho!" << endl;
        }

        if(tentativas == 0){
            cout << "Lamento, mas suas tentativas acabaram! O número secreto era " << numeroEscolhido << endl;
        }

    }while (chute != numeroEscolhido && tentativas > 0);
    
    cout << "Muito obrigado por jogar!" << endl;

    return 0;
}