#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string input_filename; // string for the input file name
    cout << "Enter the input file name: ";
    getline(cin, input_filename); // getline for the file name

    ifstream input_file(input_filename);
    if (!input_file)  // if statement if the file isn't found
    {
        cout << "The file \"" << input_filename << "\" could not be opened." << endl; 
        return 1;
    }

    ofstream output_file("badvalues.txt"); // output file badvalues.txt

    double sum = 0.0, value; // double type sum
    int num_values = 0, num_valid_values = 0, num_invalid_values = 0; // variables for the valid invalid and num values

    while (input_file >> value) // while loop that runs while every line is read from the file
    {
        num_values++; //increments the variable

        if (input_file.fail()) // if statement for if the input file fails
        {
            input_file.clear();
            string line;
            getline(input_file, line);
            output_file << fixed << setprecision(3) << value << endl;
            num_invalid_values++;
        }
        else // else statement that runs if the code above doesn't proc
        {
            sum += value;
            num_valid_values++;
        }
    }

    if (num_valid_values > 0) // if statement if the values are below 0
    {
        double average = sum / num_valid_values;
        cout << "Total number of values read: " << num_values << endl;
        cout << "Valid values read: " << num_valid_values << endl;
        cout << "Invalid values read: " << num_invalid_values << endl;
        cout << "The average of the valid numbers read = " << fixed << setprecision(2) << average << endl;
    }
    else // else statement if the code above doesnt work
    {
        cout << "Total number of values read: " << num_values << endl;
        cout << "Valid values read: " << num_valid_values << endl;
        cout << "Invalid values read: " << num_invalid_values << endl;
        cout << "The file did not contain any valid values." << endl;
    }

    return 0;
}
