#include "A2_Q2.h"

using namespace std;

int main(){
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Average: " << stack.average() << endl;

    stack.pop();
    stack.display();
    cout << "Average: " << stack.average() << endl;
    return 0;
}
