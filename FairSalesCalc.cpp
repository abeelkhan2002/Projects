// Abeel Khan
// Programming Fundementals 
// CS 1136.001
// This program displays the dollar amount of the taxable items sold, taxes, non-taxable items sold, and the total of the three values: taxable amount, taxes, and non-taxable amount.
#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{

    int chilliDogs, cornDogs, chips, softDrinks, waterBottles; // Data type  for amount of items sold
    double chilliPrice, cornPrice, chipsPrice, softPrice, waterPrice, taxable, taxAmount, nonTaxable, total; // Data type for cost of every item, taxable, nontaxable, and total cost
    const double tax = 0.065; //constant amount of tax

    cout << "How many chili dogs were sold? ";
    cin >> chilliDogs; // Asks user input for amount of Chilli Dogs sold

    cout << "How many corn dogs were sold? ";
    cin >> cornDogs; // Asks user input for amount of Corn Dogs sold

    cout << "How many bags of chips were sold? ";
    cin >> chips; // Asks user input for amount of Bags of Chips sold 

    cout << "How many soft drinks were sold? ";
    cin >> softDrinks; // Asks user input for amount of Soft Drinks sold

    cout << "How many bottles of water were sold? ";
    cin >> waterBottles; // Asks user input for amount of Water Bottles sold

    cout << setprecision(2) << fixed; // Sets each value below to 2 decimal places to the right

    chilliPrice = (chilliDogs * 8.5); // Formula for price of all Chilli Dogs
    cornPrice = (cornDogs * 7); // Formula for price of all Corn Dogs
    chipsPrice = (chips * 2.5); // Formula for price of all Bags of Chips
    softPrice = (softDrinks * 4.5); // Formula for price of all Soft Drinks
    waterPrice = (waterBottles * 4); // Formula for price of all Water Bottles

    taxable = chilliPrice + cornPrice + chipsPrice + softPrice; // Formula for taxable amount via adding all the total cost of all taxable food items
    taxAmount = taxable * tax; // Formula for dollar amount of taxes
    nonTaxable = waterPrice; // Nontaxable is the same as waterPrice due to it being the only nonTaxable item 
    total = taxable + nonTaxable + taxAmount; // Formula for sum of all 3 types of 

    cout << "\nTaxable: " << setw(7) << "$" << setw(10) << taxable << endl; // String statement for the Taxable amount
    cout << "Tax amount: " << setw(4) << "$" << setw(10) << taxAmount << endl; // String statement for Tax amount
    cout << "Non-taxable: " << setw(3) << "$" << setw(10) << nonTaxable << endl; // String statement for Nontaxable amount
    cout << "Total: " << setw(9) << "$" << setw(10) << total << endl; // String Statement for Total amount


   

}