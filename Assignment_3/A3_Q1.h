#include <iomanip>
#include <string>
#include <iostream>

using namespace std;


template <typename Item_Type>
struct Node{//Node struct class
    Item_Type data;
    Node* next;

    Node(const Item_Type& data_item, Node* next_ptr = NULL):
    data(data_item), next(next_ptr){}
};

template <typename Item_Type>
class Queue{

    private://Private variables
        
        Node<Item_Type>* head;
        Node<Item_Type>* tail;
        int num_items;
    public:
        
        Queue() : head(nullptr), tail(nullptr), num_items(0) {}//Constructor

        void push(const Item_Type& item){//Adds the value to the queue
            
            Node<Item_Type>* newNode = new Node<Item_Type>(item, NULL);
            
            if (tail){//Checks for empty queue
                tail->next = newNode;
            }
            else{
                head = newNode;
            }
            
            tail = newNode;
            ++num_items;//Increments num_items 
        }
        void pop(){//Removes the next value in the queue
            
            if (!head) return;//Checks for empty queue

            Node<Item_Type>* temp = head;
            head = head->next;
            
            if (head == nullptr){
                tail = nullptr;
            }
            delete temp;
            --num_items;//Decrements num_items
        }
        Item_Type front(){//Gives the next value in the queue
            return head->data;
        }
        int size(){//Gives the size of the queue
            return num_items;
        }
        bool empty(){//Gives a bool value for if the queue is empty
            
            return head == nullptr;
        }
        void move_to_rear(){//Pushes the front value to the queue then pops the queue
            push(front());
            pop();
        }
        void display(){
            for (int i = 0; i < size()-1; i++)
            {  
                cout<<front()<<"->";
                push(front());
                pop();
            }
                cout<<front()<<endl;
                push(front());
                pop();
        }
        ~Queue(){//Deconstructor
            
            while (head){
                pop();
            }
            
        }
};
