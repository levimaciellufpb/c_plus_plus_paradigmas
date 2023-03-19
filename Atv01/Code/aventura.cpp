#include <iostream>
#include <string>

using namespace std;


int main(){

    const int OURO = 900;
    unsigned int pessoas, mortos, sobreviventes;

    cout << "Me diga um número: " << endl;
    cin >> pessoas;
    cout << "Me diga um número menor igual a este:" << endl;
    cin >> mortos;

    while(mortos >= pessoas){
        cout << "Você digitou um número maior que " << pessoas << "! Por favor, me diga um número menor:" << endl;
        cin >> mortos;
    }

    sobreviventes = pessoas - mortos;

    cout << "O Naufrágio \n" << endl;

    cout << "Era uma noite fria em Vancouver, quando " << pessoas << " embarcaram em um navio que iria até Liverpool. " << endl;

    cout << "No caminho para Liverpool, uma grande baleia atingiu o casco do navio. " << endl;

    cout << "O acidente causou um naufrágio que matou " << mortos << " pessoas das " << pessoas << " que embarcaram originalmente." << endl;

    cout << "Os " << sobreviventes << " restantes acabaram chegando em uma pequena ilha, onde seriam apenas resgatadas após dois meses do naufrágio.\n" << endl;

    cout << "Fim :)" << endl;

}