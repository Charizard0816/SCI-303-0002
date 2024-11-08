#include "A3_Q3.h"

using namespace std;

int main(){
     Queue<int> queue;
    
    queue.push(9);
    queue.push(7);
    queue.push(5);
    queue.push(6);
    queue.push(3);
    queue.push(4);
    queue.push(2);
    queue.push(8);
    queue.push(1);
    queue.push(10);

    cout << "Current queue: ";
    queue.display();

    insertion_sort(queue);

    cout << "Current queue: ";
    queue.display();
    return 0;
}
