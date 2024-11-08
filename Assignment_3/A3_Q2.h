#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename Item_Type>
int linear_last_search(vector<Item_Type>& items, Item_Type&target, size_t pos_last) {
    if (pos_last == -1)
        return -1;
    if (target == items[pos_last])
        return pos_last;
    else
        return linear_last_search(items, target, pos_last - 1);//Iterating through the vector in reverse order to find the last instance of a value
};
