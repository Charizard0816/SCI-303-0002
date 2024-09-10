#include <fstream>
#include <iomanip>
#include <string>
#include <array>
#include <iostream>
#include <algorithm>
#include <stdexcept>

int searchArrayForInt(int value, int values[], int lastIndex){ //Searches Array for the value inputed by user
    for (int i = 0; i < lastIndex + 1; i++)
    {
        if (values[i] == value)
        {
            std::cout << i << std::endl;
        }
        
    }
    return -1; //If the value is not in the array return -1
}

void editArrayWithIndex(int index, int value, int values[], int lastIndex){ //Edits the value of an int at the given index
       
       if (index < 0 || index > lastIndex)//Checks if index is in array and throws an exeption if true
       {
            throw std::out_of_range(
                "The Index is Out of Range of the Array"
            );  
       }
    std::cout << "The Old Value Was: " << values[index] << " The New Value Is: " << value << std::endl;
    
}

int addAtEnd(int value, int values[], int lastIndex){ //Adds a new value at the end of the array
    if (lastIndex == 100)
    {
        throw std::runtime_error(
            "Array is full"
        );
    }
    
    values[lastIndex + 1] = value;
    lastIndex++;
    std::cout << values[lastIndex] << " Added to End at Index "<< lastIndex << std::endl;
    return lastIndex;
}

void removeIndex(int index, int values[], int lastIndex){ //Removes the value at a given index
    for (int i = index; i < lastIndex + 1; i++) //Moves the values down the array
    {
        values[i] = values[i+1];
    }
    std::cout << "Value at " << index << " Has Been Deleted" << std::endl;
}

int display(int values[], int lastIndex){//Diplays the user interface
    int choice = 0;
    int index;
    int value;
    while(choice != 5){
    std::cout << "Please Choose an Operation:\n1: Check For an Integer\n2: Modify a Value at an Index\n3: Add an Integer to the End of Array\n4: Remove a Value at an Index\n5: End" << std::endl;
    std::cin >> choice;
        switch (choice)//The choices the user can choose from
        {
        case 1:
            std::cout << "Please Enter an Integer to Search for:\n";
            std::cin >> value;
            std::cout << "The Value "<< value << " is at Index(s):\n";
            searchArrayForInt(value, values, lastIndex);
            break;
        case 2:
            std::cout << "Please Enter an Index to Edit:\n";
            std::cin >> index;
            std::cout << "Please Enter an Integer:\n";
            std::cin >> value;
            try //Catches user input errors
            {
                editArrayWithIndex(index, value, values, lastIndex);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 3:
            std::cout << "Please Enter an Integer to Add:\n";
            std::cin >> value;
            try
            {
                lastIndex = addAtEnd(value, values, lastIndex);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 4:
            std::cout << "Please Enter an Index to Remove:\n";
            std::cin >> index;
            removeIndex(index, values, lastIndex);
            break;
        
        default:
            break;
        }
    }
    return 0;
}

void fillArray(){ //Reads the input file and fills the array
    int count = 0;
    std::string text;
    int num = 0;
    int values[101];
    size_t pos;
    std::string s;
    std::ifstream file("D:/SCI 303/SCI-303-0002/Assignment_1/A1input.txt");//Reads the file

    while (getline(file, text, ' ')) { //Stores the values into the array
       text.erase(std::remove(text.begin(), text.end(), '\n'), text.end());
        if (text.size() > 3)
        {
            s=text.substr(0,2);
            num = stoi(s);
            values[count] = num;
            count++;
            text=text.substr(2,2);
            num = stoi(text);
            values[count] = num;
            count++;
            
        }
        else{
            num = stoi(text);
            values[count] = num;
            count++;
        }
    }
    file.close();
    display(values, count - 1);
}