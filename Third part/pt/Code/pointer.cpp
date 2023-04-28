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

    //cout << 








    return 0;
}