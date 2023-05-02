#include <iostream>
using std::cout; using std::endl;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;


int main(){
    
    //make_shared() retorna um shared_ptr<string>
    shared_ptr<string> pointer1 = std::make_shared<string>("Estegossauro");
    //segundo ponteiro que vai apontar para p1
    shared_ptr<string> pointer2(pointer1);

    cout << *pointer2 << endl; //Imprime estegossauro

    shared_ptr<string> pointer3 = std::make_shared<string>("T-Rex");

    pointer2 = pointer3;

    cout << *pointer2 << endl; //Imprime T-Rex


    if(pointer1)
        cout << "Pointer1 não null? " << pointer1.use_count() << endl;
        
    if(pointer3)
        cout << "Pointer3 não null? " << pointer3.use_count() << endl;

    cout << *pointer2 << endl;

    return 0;
}