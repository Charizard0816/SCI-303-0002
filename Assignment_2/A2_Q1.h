#include <iomanip>
#include <string>
#include <iostream>
#include <string>

using namespace std;



template <typename Item_Type>
struct Node{
    Item_Type data;
    Node* next;

    Node(const Item_Type& data_item, Node* next_ptr = NULL):
    data(data_item), next(next_ptr){}
};

template <typename Item_Type>
class List{

private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
public:
    List() : head(NULL) {}
    List() : tail(NULL) {}

    void push_front(const Item_Type& item);
        Node<Item_Type>* newNode = new Node<Item_Type>();    
        head = newNode;
    void push_back();
    void pop_front();
    void pop_back();
    void front();
    void back();
    void empty();
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
    ~List();
};
