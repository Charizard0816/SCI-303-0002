#include "A3_Q1.h"

int main(){
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);

    cout << "Current queue: ";
    queue.display();

    cout << "Current front of the queue: " << queue.front() << endl;
    
    queue.pop();
    cout << "After pop: ";
    queue.display();

    queue.pop();
    cout << "After pop: ";
    queue.display();

    queue.move_to_rear();
    cout << "After move_to_rear: ";
    queue.display();

    cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;
    cout << "Current queue size: " << queue.size() << endl;
    return 0;
}
