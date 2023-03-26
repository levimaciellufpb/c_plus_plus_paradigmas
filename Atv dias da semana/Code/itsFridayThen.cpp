#include <iostream>

using namespace std;

int getLastDigits(int year);
int somarCodigoMes(int valorSoma, int mesInt);
bool isBissexto(int ano);
int somaDosSeculos(int ano, int valorSoma);

int main(){

    cout << "Olá! Me diga uma data entre os anos 1700 e 2099 e eu lhe direi o dia da semana! " << endl;
    cout << "A data é no formato dia, mes e ano (dd mm aaaa)" << endl;

    int dia;
    int mes;
    int ano;

    cout << "Digite agora a data por favor: " << endl;
    cin >> dia >> mes >> ano;

    //tratamento de erro simples
    while((ano < 1700) || (ano > 2099)){
        cout << "Você escreveu um ano inválido: " << ano << endl;
        cout << "O ano deve estar entre 1700 e 2099!\n" << endl;

        cout << "Digite novamente a data por favor: " << endl;
        cin >> dia >> mes >> ano;
    }

    while((mes < 1) || (mes > 12)){
        cout << "Você escreveu um mes inválido: " << ano << endl;
        cout << "O mes deve estar entre 1 e 12!\n" << endl;

        cout << "Digite novamente a data por favor: " << endl;
        cin >> dia >> mes >> ano;
    }

    while((dia < 1) || (dia > 31)){
        cout << "Você escreveu um dia inválido: " << ano << endl;
        cout << "O dia deve estar entre 1 e 31!\n" << endl;

        cout << "Digite novamente a data por favor: " << endl;
        cin >> dia >> mes >> ano;
    }

    //Pegar os dois ultimos digitos do ano. 
    int doisDigitos = getLastDigits(ano);
    int resultado = doisDigitos;

    //Dividir por 4 e guardar a parte inteira
    resultado = doisDigitos / 4;

    //Somar com o dia do mês
    resultado = resultado + dia;

    //Somar com o código correspondente ao mês
    resultado = somarCodigoMes(resultado, mes);

    //Caso seja bissexto e tiver mês janeiro ou fevereiro, subtrair 1
    if((isBissexto(ano)) && (mes == 1) || (mes == 2)){
        resultado = resultado - 1;
    }
    
    //Somar certo valor dependendo da década
    resultado = somaDosSeculos(ano, resultado);

    //Somar dois ultimos digitos do ano
    resultado = resultado + doisDigitos;

    //Guardar o resto da divisão por 7
    resultado = resultado % 7;

    switch (resultado){
    case 1:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era um DOMINGO!" << endl;
        break;

    case 2:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era uma SEGUNDA!" << endl;
        break;

    case 3:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era uma TERÇA!" << endl;
        break;

    case 4:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era uma QUARTA!" << endl;
        break;

    case 5:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era uma QUINTA!" << endl;
        break;

    case 6:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era uma SEXTA!" << endl;
        break;

    case 0:
        cout << "O dia " << dia << "/" << mes << "/" << ano << " era um SABADO!" << endl;
        break;

    default:
        cout << "Ocorreu algo inesperado, o dia é: " << resultado << endl; 
        break;
    }

    return 0;
}


//Função para pegar os últimos dois dígitos de um ano
int getLastDigits(int year){
    return year % 100;
}

//Função para pegar somar certo valor a um código de mes
int somarCodigoMes(int valorSoma, int mesInt){

    enum Mes{JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};

    Mes mes = static_cast<Mes>(mesInt);
    int resultado = -1;

    switch (mes) {
    
    case JAN:
        resultado = valorSoma + 1;
        break;

    case FEV:
        resultado = valorSoma + 4;
        break;

    case MAR:
        resultado = valorSoma + 4;
        break;

    case ABR:
        resultado = valorSoma + 0;
        break;

    case MAI:
        resultado = valorSoma + 2;
        break;

    case JUN:
        resultado = valorSoma + 5;
        break;

    case JUL:
        resultado = valorSoma + 0;
        break;

    case AGO:
        resultado = valorSoma + 3;
        break;

    case SET:
        resultado = valorSoma + 6;
        break;

    case OUT:
        resultado = valorSoma + 1;
        break;

    case NOV:
        resultado = valorSoma + 4;
        break;

    case DEZ:
        resultado = valorSoma + 6;
        break;

    default:
        cout << "Número de mês inválido!" << endl;
        break;
    }

    return resultado;
}

//Função para descobrir se ano é bissexto
bool isBissexto(int ano){

    //verificar se é divisível por 4
    if(ano % 4 == 0){
        //se for, verificar se é divisível por 100
        if(ano % 100 == 0){
            return false;
        }
        return true;
    }
    else{
        //se for divisivel por 400, é bissexto
        if(ano % 400 == 0){
            return true;
        }
        return false;
    }
}

int somaDosSeculos(int ano, int valorSoma){
    int resultado = -1;

    if(ano < 1700){
        cout << "Ano não deveria ser menor que 1700!" << endl;
        return resultado;
    }

    //Caso o ano esteja no século 18
    if((ano >= 1701) && (ano <= 1800)){
        resultado = valorSoma + 4;
        return resultado;
    }
    //Caso o ano esteja no século 19
    else if((ano >= 1801) && (ano <= 1900)){
        resultado = valorSoma + 2;
        return resultado;
    }
    //Caso o ano esteja no século 20
    else if((ano >= 1901) && (ano <= 2000)){
        resultado = valorSoma + 0;
        return resultado;
    }
    //De 2002 para frente...
    else{
        resultado = valorSoma + 6;
        return resultado;
    }



}
