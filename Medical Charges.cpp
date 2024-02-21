//Abeel Khan, CS1336. 001, due 03/31/2023. 
//Completed on 03/29/2023

#include <iostream>

using namespace std;

double inPatient (int days, double rate, double medCharges, double serviceCharges) 
{

    return days * rate + medCharges + serviceCharges;
}

double outPatient (double medCharges, double serviceCharges) 
{

    return medCharges + serviceCharges;
}

int main()
{

    int choice, days;
    double rate, medCharges, serviceCharges, totalCharges;

    cout << "Enter 1 for in-patient, 2 for out-patient: ";
    cin >> choice;


    if (choice == 1) {
        cout << "Enter number of days spent in the hospital: ";
        cin >> days;
        cout << "Enter daily rate: ";
        cin >> rate;
        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        cout << "Enter charges for hospital services: ";
        cin >> serviceCharges;


        totalCharges = inPatient (days, rate, medCharges, serviceCharges);
    }


    else if (choice == 2)
    {

        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        cout << "Enter charges for hospital services: ";
        cin >> serviceCharges;

        totalCharges = outPatient (medCharges, serviceCharges);
    }
    
    else 
    
    {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Total charges: $" << totalCharges << endl;

    return 0;
}