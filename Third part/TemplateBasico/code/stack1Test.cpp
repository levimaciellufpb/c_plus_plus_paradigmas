#include "stack1.hpp"
#include <iostream>
#include <string>

int main(){

    Stack<int> intStack;
    Stack<std::string> stStack;

    intStack.push(7);
    std::cout << intStack.top() << std::endl;

    stStack.push("hello");
    stStack.push("World");
    std::cout << stStack.top() << std::endl;
    stStack.pop();
    std::cout << stStack.top() << std::endl;

}