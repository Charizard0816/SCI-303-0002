#include "A2_Q1.h"

int main(){
    SingleList<string> list;
    int choice = 0;
    while (choice != 5)
    {
        choice = list.menu();
        switch (choice){
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;

        default:
            break;
        }    
    }
    
    list.push_front("Alice");
    list.push_back("Bob");
    list.push_back("Charlie");

    cout << "Current List: ";
    list.display();

    cout << "Front item: " << list.front() << endl;
    cout << "Back item: " << list.back() << endl;

    list.insert(1,"Tom");
    cout << "After inserting at index 1: ";
    list.display();

    cout << "What index is \"Kobe\" at?: " << list.find("Kobe") << endl;

    cout << "Did the value at index 4 get removed? "<< (list.remove(4) ? "Yes" : "No") << endl;
    
    list.pop_front();
    cout << "After popping front: ";
    list.display();

    list.pop_back();
    cout << "After popping back: ";
    list.display();

    list.pop_back();
    cout << "After popping back: ";
    list.display();


    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl;
    return 0;
}
