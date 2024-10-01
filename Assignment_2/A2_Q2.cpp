#include "A2_Q2.h"

using namespace std;

int main(){
    Stack stack;

    cout << "Is the Stack Empty?: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << "Is the Stack Empty?: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.display();
    cout << "The Top of the Stack is: " << stack.top() << endl;
    stack.pop();
    cout << "The Top of the Stack is: " << stack.top() << endl;
    cout << "Average: " << stack.average() << endl;
    stack.pop();
    stack.display();
    cout << "Average: " << stack.average() << endl;
    return 0;
}
