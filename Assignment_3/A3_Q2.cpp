#include "A3_Q2.h"

using namespace std;

int main(){
    vector<int> items = {4,6,7,9,8,6,2,4,2,3,9,5,2,2,5};
    int target = 6;
    cout << "The last instance of the value "<< target << " is at index number: " << linear_last_search(items, target, items.size()-1) << endl;
    
    target = 3;
    cout << "The last instance of the value "<< target << " is at index number: " << linear_last_search(items, target, items.size()-1) << endl;
    
    target = 2;
    cout << "The last instance of the value "<< target << " is at index number: " << linear_last_search(items, target, items.size()-1) << endl;

    return 0;
}
