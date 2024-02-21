// Sort by Pointers 
// 2023/9/11
// Abeel Khan 
// Program uses pointers by sorting arrays, and creating overloaded functions

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function is created to swap pointers 
void SwapIntPtr(int** a, int** b)
{
    int* temp = *a;
    *a = *b;
    *b = temp;
}

// Overloaded function number 1 to display arrays for integers 
void DisplayArray(int dataArray[], unsigned maxElements, unsigned elementsPerLine) 
{
    for (unsigned i = 0; i < maxElements; i++) 
    {
        cout << dataArray[i] << ' ';
        if ((i + 1) % elementsPerLine == 0 || i == maxElements - 1)
        {
            cout << endl;
        }
    }
}

// Overloaded function number 2 to display integers for pointers
void DisplayArray(int* pointerArray[], unsigned maxElements, unsigned elementsPerLine)
{
    for (unsigned i = 0; i < maxElements; i++) 
    {
        cout << *pointerArray[i] << ' ';
        if ((i + 1) % elementsPerLine == 0 || i == maxElements - 1) 
        {
            cout << endl;
        }
    }
}

// Function that sorts the array for the integer pointers 
void BubbleSort(int* pointerArray[], int dataSize) 
{
    bool swapped;
    for (int i = 0; i < dataSize - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < dataSize - i - 1; j++)
        {
            if (*pointerArray[j] > *pointerArray[j + 1]) 
            {
                SwapIntPtr(&pointerArray[j], &pointerArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
// Start of main function 
int main()
{
    string inputFileName = "arrayData.txt";
    ifstream file(inputFileName);

    const unsigned maxElements = 100; 
    int dataArray[maxElements];
    int* pointerArray[maxElements];
    unsigned dataSize = 0;

    string line;
    while (getline(file, line))
    {
        // If statement that checks the line if it contains a digit 
        if (line.find_first_not_of("0123456789") == string::npos) 
        {
            continue;
        }
        cout << "Data Array elements are:\n";
        cout << line << endl;

        istringstream iss(line);
        vector<int> numbers;  // declate number vector, this will store intgers from line 
        int num;
        while (iss >> num)
        {
            numbers.push_back(num);
        }

        // Use vector numbers from array to set up pointer 
        for (int i = 0; i < numbers.size() && dataSize < maxElements; i++)
        {
            dataArray[dataSize] = numbers[i];
            pointerArray[dataSize] = &dataArray[dataSize];
            dataSize++;
        }

        cout << "The Pointer Array of sorted pointer elements:\n";
        BubbleSort(pointerArray, dataSize);
        DisplayArray(pointerArray, dataSize, 10);

        cout << "\nPress the enter key once or twice to continue..." << endl;
        cin.ignore();
        cin.get();
        dataSize = 0; 
    }

    file.close(); 

    cout << "Program Done" << endl;

    return 0;
}

