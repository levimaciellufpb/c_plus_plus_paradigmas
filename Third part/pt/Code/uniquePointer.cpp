#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

int main(){
    
    unique_ptr<string> p1(new string("Estegossauro"));

    unique_ptr<string> p2(p1.release()); //método release deixa p1 null e p2 passa a apontar para p1

    cout << *p2 << endl; //Imprime estegossauro

    unique_ptr<string> p3(new string("T-rex"));

    //Reset apaga a memória de p2 e transfere o que p3 aponta
    p2.reset(p3.release());
    cout << *p2 << endl; //imprime T-rex

    //p1 e p3 são nulos, p2 tem t-rex
    if(p1)
        cout << "p1 não nulo? " << endl;
    if(p3)
        cout << "p3 não nulo? " << endl;

    cout << *p2 << endl;

}






