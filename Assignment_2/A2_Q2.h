#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Stack{
    private:
    
        vector<int> stack;
    public:
    
        void push(int value){//Adds value to top of stack
            
            stack.push_back(value);
            cout << "Pushed to the Top of the Stack" << endl;
        }
        void pop(){//Removes value from top of stack
            
            if(stack.empty()){ 
                cout << "Stack is empty" << endl;
            }
            else{
                stack.pop_back();
                cout << "Popped the Top of the Stack" << endl;
            }
        }
        bool isEmpty(){//Returns a bool value for if the stack is empty
            
            return stack.empty();
        }
        int top(){//Returns the value on the top of the stack
            
            if(stack.empty()){
                cout << "Stack is empty" << endl; 
                return -1;
            }

            return stack.back();
        }
        double average(){//Returns the average of all the ints in the stack
            
            if (stack.empty()){
                cout << "Stack is empty" << endl;
                return 0.0;
            }

            int sum = 0;
            int size = stack.size();
            vector<int> temp = stack;
            
            for (size_t i = 0; i < size; i++){//Moves through stack
                sum += stack.back();
                stack.pop_back();
            }

            stack = temp;
           
            return static_cast<double>(sum) / stack.size();
        }
        void display(){//Displays the values in the stack
            
            if(stack.empty()) cout << "Stack is Empty" << endl;

            cout << "Stack: ";
            
            for (int i = stack.size() - 1; i >= 0; --i){//Moves through stack
                cout << stack[i] << " ";
            }
            
            cout << endl;
        }
};