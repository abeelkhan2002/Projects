#include <iostream>
#include <iomanip>
using namespace std;


bool getOrder(int&, double&, char&, double&);//Setting up bool function with getting order 
double calculateSpoolCharges(int, double); //setting up spool charges function
int Shipping(int&, int);//function for calculating shiping 
void display(int, int, int, double, double, double);//void function for displaying message 

// main funtion
int main() {
    int totalChargesOrder = 0; //setting orders to 0
    int backValue = 0;//setting backval to 0
    int stocks = 0; // setting amount to 0 
    double discount = 0;// setting discount to 0//setting charges to 0//doubling the variable for totalAmount
    double charges = 0;//setting charges to 0//doubling the variable for totalAmount
    double totalCharges;//doubling the variable for totalAmount
    char choice = ' ';//setting choice for user to say Y or N 
    bool checking = getOrder(totalChargesOrder, discount, choice, charges);// if checking is equal to false then return back to 0

    if (checking == false) {// if checking is equal to false then return back to 0 
        return 0;
    }

    backValue = Shipping(stocks, totalChargesOrder);
    if (backValue == 10000000)//if shipping is equal to this amount then retunr to 0 
        return 0;
    if (backValue < 0) {// if statement for when back val is less then 0  // using assginemnt operater to assign the total variable to function 
        totalCharges = calculateSpoolCharges(stocks, discount); // using assginemnt operater to assign the total variable to function 
    }
    else {// else statement for if user inputs the rest of the possible values 
        totalCharges = calculateSpoolCharges(totalChargesOrder, discount);
    }

    cout << endl;
    display(backValue, stocks, totalChargesOrder, discount, totalCharges, charges);
}

bool getOrder(int& totalChargesOrder, double& discount, char& choice, double& charges) {//starting getOrder function, , here they will input there discount amount and choice for Y or N, and the results that will display are inside thi function

    cout << "Please enter the number of spools ordered: ";
    cin >> totalChargesOrder;
    if (totalChargesOrder < 1) { //if orders is less then 1 
        cout << "Spools must be at least one." << endl;
        cout << endl;
        cout << "Thank you, please shop again." << endl;
        return false;
    }
    else {//if orders are greater then 1 then they will move on to the next question 
        cout << "Enter the discount percentage for the customer: ";
        cin >> discount;
        if (discount < 0) { // if discount is less then 1 then this will appear //return back to false
            cout << "The percentage cannot be negative." << endl;
            cout << endl;
            cout << "Thank you, please shop again." << endl;
            return false;//return back to false
        }
        else {//if they input discount greater then 0 then the next set will appear
            cout << "Does the order include custom shipping and handling charges? [Enter Y for Yes or N for No]: "; //if user picks capital y or lowercase y after the last conditions have been met, then this set will appear 
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                cout << "Enter the shipping and handling charge: ";
                cin >> charges;
                if (charges < 0) { // if they enter charges less then 0 then this set will appear 
                    cout << "Shipping and handling cannot be negative." << endl;
                    cout << endl;
                    cout << "Thank you, please shop again." << endl;
                    return false;
                }
                else {
                    return true;
                }

            }
            else if (choice == 'N' || choice == 'n') {
                charges = 15; // if choice is no then charges will be 15 
                return true;
            }
            else {
                cout << "The response should be Y for Yes or N for No." << endl;
                cout << endl;
                cout << "Thank you, please shop again." << endl;
                return false;
            }
        }
    }

}
double calculateSpoolCharges(int totalChargesOrder, double discount) { //calculating spool charges function this will caluclate total charges
    double totalCharges;

    totalCharges = (totalChargesOrder * 134.95) * (100 - discount) / 100; //calc for total charges 

    return totalCharges;
}

int Shipping(int& stocks, int totalChargesOrder) { //creating intshipping function here they will enter stock amount 

    cout << "Enter the number of spools in stock: ";
    cin >> stocks;
    if (stocks < 0) { //if stock less then 0 then display this messsage 

        cout << "The number of spools cannot be negative." << endl;
        cout << endl;
        cout << "Thank you, please shop again." << endl;
        return 10000000;

    }
    return(stocks - totalChargesOrder);

}

void display(int backValue, int stocks, int totalChargesOrder, double discount, double totalCharges, double charges) { //creating display function that will appear for user after they input their values, these messages will appear 
    cout << "\t" << "\t" << "Order Summary" << endl;
    cout << "==============================" << endl;
    if (backValue < 0) { // if user inputs less then 0 then these sets will appear 
        cout << backValue * (-1) << " spools are on back order." << endl;
        cout << stocks << " spools are ready to ship." << endl;
    }
    else { // if value greater then 0 then these will appear 
        cout << totalChargesOrder << " spools are ready to ship." << endl;
    }

    if (backValue < 0) { //if back value less then 0 and discount greater then 0 then these will appear 
        if (discount > 0) {
            cout << "The charges for " << stocks << " spools (including a " << fixed << setprecision(1) << discount << "% discount): $" << fixed << setprecision(2) << totalCharges << endl;

        }
        else { 
            cout << "The charges for " << stocks << " spools : $" << fixed << setprecision(2) << totalCharges << endl; //message for when back value greater then 0 
        }

        cout << "Shipping and handling for " << stocks << " spools: $" << fixed << setprecision(2) << (stocks * charges) << endl;
        cout << "The totalCharges charges (incl. shipping & handling): $" << fixed << setprecision(2) << (totalCharges + (stocks * charges)) << endl;
    }
    else {
        if (discount > 0) { // if discount is greater then 0
            cout << "The charges for " << totalChargesOrder << " spools (including a " << fixed << setprecision(1) << discount << "% discount): $" << fixed << setprecision(2) << totalCharges << endl;

        }
        else {
            cout << "The charges for " << totalChargesOrder << " spools : $" << fixed << setprecision(2) << totalCharges << endl;
        }
        cout << "Shipping and handling for " << totalChargesOrder << " spools: $" << fixed << setprecision(2) << (totalChargesOrder * charges) << endl;
        cout << "The totalCharges charges (incl. shipping & handling): $" << fixed << setprecision(2) << (totalCharges + (totalChargesOrder * charges)) << endl;
    }

    cout << endl;
    cout << "Thank you, please shop again." << endl;

}