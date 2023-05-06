#include <vector>
#include <cassert>

template<typename T>
class Stack{
    private:
        std::vector<T> elements;

    public:
    void push(T const& elem);
    void pop();
    T const& top() const;
    bool empty() const{
        return elements.empty();
    }
};

template<typename T>
void Stack<T>::push(T const& element){
    elements.push_back(element);
}

template<typename T>
void Stack<T> :: pop(){
    assert(!elements.empty());
    elements.pop_back();
}

template<typename T>
T const& Stack<T> :: top() const{
    assert(!elements.empty());
    return elements.back();
}