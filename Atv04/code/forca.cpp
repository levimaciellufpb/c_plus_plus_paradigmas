#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int main(){

    const int MAX_TENTATIVAS = 8;
    vector<string> palavras;

    palavras.push_back("ADVINHE");
    palavras.push_back("FORCA");
    palavras.push_back("DIFICIL");
    palavras.push_back("POESIA");
    palavras.push_back("HISTORIA");
    palavras.push_back("BATMAN");
    palavras.push_back("MACACO");
    palavras.push_back("CANADA");

    unsigned seed = time(0);
    srand(seed);

    random_shuffle(palavras.begin(), palavras.end());
    const string PALAVRA = palavras[0];

    int tentativas = 0;
    string ateAgora(PALAVRA.size(), '-');
    string usados = "";

    cout << "Bem vindo ao jogo da forca! Boa sorte!" << endl;

    while((tentativas < MAX_TENTATIVAS) && (ateAgora != PALAVRA)){

        cout << "Ainda existem " << (MAX_TENTATIVAS - tentativas) << " tentativas restantes.\n" << endl;
        cout << "Letras utilizadas: " << usados << "\n" << endl;
        cout << "A palavra revelada: \n" << ateAgora << "\n" << endl;

        char tentativa;
        cout << "\n\nDigite sua tentativa: " << "\n" << endl;
        cin >> tentativa;

        tentativa = toupper(tentativa);

        while(usados.find(tentativa) != string::npos){
            cout << "\nVocê já tentou a letra " << tentativa << "!" << endl;
            cout << "\n\nDigite sua tentativa: " << "\n" << endl;
            cin >> tentativa;
        }

        usados = usados + tentativa;

        if(PALAVRA.find(tentativa) != string::npos){
            cout << "\nCorreto! " << tentativa << " está na palavra!" << endl;

            //Mudando a palavra escondida
            for(int i = 0; i < PALAVRA.length(); i++){
                if(PALAVRA[i] == tentativa){
                    ateAgora[i] = tentativa;
                }
            }

        }
        else{
            cout << "\nDesculpe, " << tentativa << " não está na palavra!" << endl;
            tentativas++;
        }

    }

    if(MAX_TENTATIVAS == tentativas){
        cout << "\nVocê foi enforcado!" << endl;
    }
    else{
        cout << "\nVocê venceu!" << endl;
    }

    cout << "A palavra era: " << PALAVRA << endl;
    cout << "Muito obrigado por jogar!" << endl;

}