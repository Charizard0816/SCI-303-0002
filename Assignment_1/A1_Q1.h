#include <fstream>
#include <iomanip>
#include <string>
#include <array>
#include <iostream>

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

void editArrayWithIndex(int index, int value, int values[]){ //Edits the value of an int at the given index
    std::cout << "The Old Value Was: " << values[index] << " The New Value Is: " << value << std::endl;
    values[index] = value;
}

int addAtEnd(int value, int values[], int lastIndex){ //Adds a new value at the end of the array
    values[lastIndex + 1] = value;
    lastIndex++;
    std::cout << values[lastIndex] << " Added to End at Index "<< lastIndex << std::endl;
    return lastIndex;
}

void removeIndex(int index, int values[], int lastIndex){ //Removes the value at a given index
    std::cout << values[index] << std::endl;
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
            editArrayWithIndex(index, value, values);
            break;
        case 3:
            std::cout << "Please Enter an Integer to Add:\n";
            std::cin >> value;
            lastIndex = addAtEnd(value, values, lastIndex);
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
    int values[200];
    size_t pos;
    std::ifstream file("D:/SCI 303/SCI-303-0002/Assignment_1/A1input.txt");//Reads the file

    while (getline(file, text, ' ')) { //Stores the values into the array
        while ((pos = text.find('\n')) != std::string::npos)
            text.erase(pos, 1);
        num = stoi(text);
        values[count] = num;
        count++;
    }
    file.close();
    display(values, count - 1);
}