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
class SingleList{

    private://Private variables
        
        Node<Item_Type>* head;
        Node<Item_Type>* tail;
        int num_items;
    public:
        
        SingleList() : head(nullptr), tail(nullptr), num_items(0) {}//Constructor

        void push_front(const Item_Type& item){//Adds the value to the front
            
            Node<Item_Type>* newNode = new Node<Item_Type>(item, head);    
            head = newNode;
            
            if (tail == nullptr){ //Checks for empty list
                tail = head;
            }

            ++num_items;
        }
        void push_back(const Item_Type& item){//Adds the value to the back
            
            Node<Item_Type>* newNode = new Node<Item_Type>(item, NULL);
            
            if (tail){//Checks for empty list
                tail->next = newNode;
            }
            else{
                head = newNode;
            }
            
            tail = newNode;
            ++num_items;//Increments num_items 
        }
        void pop_front(){//Removes front value
            
            if (!head) return;//Checks for empty list

            Node<Item_Type>* temp = head;
            head = head->next;
            
            if (head == nullptr){
                tail = nullptr;
            }
            delete temp;
            --num_items;//Decrements num_items
        }
        void pop_back(){
            
            if (!head) return;//Checks for empty list
            
            if (head == tail){
                delete head;
                head = tail = nullptr;
                num_items = 0;
                return;
            }

            Node<Item_Type>* temp = head;
            
            while (temp->next != tail){//Travels through list
                temp = temp->next;
            }
            
            delete tail;
            tail = temp;
            temp->next = nullptr;
            --num_items;//Decrements num_items
        }
        Item_Type front(){//Gives the value at the head of list
            
            if(head) return head->data;
        }
        Item_Type back(){//Gives the value at the tail of list
            
            if(tail) return tail->data;
        }
        bool empty(){//Gives a bool value for if the list is empty
            
            return head == nullptr;
        }
        void insert(size_t index, const Item_Type& item){//Inserts a value at a given index
            
            if(index >= num_items){//Uses push_back if the index is bigger or equal to num_items
                push_back(item);
                return;
            }

            if (index == 0){//Uses push_front if index is 0
                push_front(item);
                return;
            }
        
            Node<Item_Type>* current = head;

            for (size_t i = 0; i < index - 1; i++){//Moves through list
                current = current->next;
            }
            
            Node<Item_Type>* newNode = new Node<Item_Type>(item, current->next);
            current->next = newNode;
            ++num_items;//Increments num_items
        }
        bool remove(size_t index){//Removes an item at a given index and returns a bool value
            
            if(index >= num_items) return false;//Returns false if index is greater than or equal to num_items
            
            if(index == 0){//Uses pop_front if index is 0
                pop_front();
                return true;
            }
            
            if(index == num_items - 1){//Uses pop_back if index is equal to num_items - 1
                pop_back();
                return true;
            }

            Node<Item_Type>* current = head;

            for (size_t i = 0; i < index - 1; i++){//Moves through list
                current = current->next;
            }
            
            Node<Item_Type>* temp = current->next;
            current->next = temp->next;
            delete temp;
            --num_items;//Decrements num_items

            return true;
        }
        size_t find(const Item_Type& item){//Returns the index of a given value if the value is found within the list
            
            size_t i = 0;
            Node<Item_Type>* current = head;

            for (size_t i = 0; i < num_items; i++){//Moves though list
                if(current->data == item) return i;
                current = current->next;
            }
            return num_items;//Returns num_items if value is not found in list
        }
        void display(){
            
            Node<Item_Type>* current = head;
            while (current){
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl << "Num Items: " << num_items << endl;
        }
        ~SingleList(){//Deconstructor
            
            while (head){
                pop_front();
            }
            
        }
};
