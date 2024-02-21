// HotDogStands 
// 2023/9/28
// Abeel Khan 
// Devloping a program that handles buisness transactions and tracks activities of all the hotdogstands

#include <iostream>
#include <string>

using namespace std;

class HotDogStand

{
private: //Declaring private member variables 

    string standId;
    string address;
    double price;
    int inventory;
    int storeSold;
    static int globalSold;

public:
    HotDogStand(const string& id, const string& addr, double p) : standId(id), address(addr), price(p), inventory(0), storeSold(0) {}

    void stockInventory(int quantity)

    {
        inventory += quantity;
    }

    bool buy(int quantity)

    {
        if (inventory >= quantity) // checking if their is enough inventory so that the purchase can go through 

        {
            inventory -= quantity;
            storeSold += quantity;
            globalSold += quantity;

            return true;
        }

        return false;
    }

    void displayStatus() const //displays the status of HotDogStand object 
    {
        cout << "\nStand Id : " << standId << endl;
        cout << "Address : " << address << endl;
        cout << "Price : " << price << endl;
        cout << "Inventory : " << inventory << endl;
        cout << "Store Sold : " << storeSold << " at $" << price << " ea." << endl;
    }

    void displayTransaction(const string& transactionId, int transactionArgument)
    {
        cout << "Process Transactions:" << endl;
        cout << "=====================" << endl;
        cout << "\n-----------------------------" << endl;
        cout << "\nHotDog Stand Current Status :" << endl;
        displayStatus();
        cout << "\nTransaction:" << endl;
        cout << "\nTransaction Stand Id : " << standId << endl;
        cout << "Transaction Id : " << transactionId << endl;
        cout << "Transaction Argument : " << transactionArgument << endl;

        if (transactionId == "stock inventory") //if statement with multiple blocks that checks transaction ID

        {
            stockInventory(transactionArgument);
        }
        else if (transactionId == "buy")

        {
            if (!buy(transactionArgument))

            {
                if (inventory == 0) {
                    cout << "\n*There are not any more hotdogs left to be sold*" << endl;
                }
                else {
                    cout << "\n*We only have " << inventory << " hotdogs left.*" << endl;
                }
            }
        }

        cout << "\nHotDog Stand Status After Transaction :" << endl;
        displayStatus();
        cout << "\nGlobal Sold : " << globalSold << endl;
        cout << "\nPlease press enter key once or twice to continue..." << endl;
        cin.ignore();
    }

    static int getGlobalSold()

    {
        return globalSold;
    }

};

int HotDogStand::globalSold = 0;

int main()
{
    HotDogStand stand1("HotDogStand1", "17817 Coit Rd", 10.27);
    HotDogStand stand2("HotDogStand2", "800 West Campbell Rd", 13.20);
    HotDogStand stand3("HotDogStand3", "7421 Frankford Rd", 18.23);

    cout << "Initial states of stands:" << endl;
    cout << "=========================" << endl;

    stand1.displayStatus();
    cout << endl;
    stand2.displayStatus();
    cout << endl;
    stand3.displayStatus();
    cout << endl;
    cout << "\nGlobal Sold : " << HotDogStand::getGlobalSold() << endl;
    cout << "\nPlease press the enter key once or twice to continue..." << endl;
    cin.ignore();

    stand1.displayTransaction("stock inventory", 20);
    stand2.displayTransaction("stock inventory", 20);
    stand3.displayTransaction("stock inventory", 20);
    stand1.displayTransaction("buy", 10);
    stand2.displayTransaction("buy", 3);
    stand3.displayTransaction("buy", 1);
    stand1.displayTransaction("buy", 30);
    stand2.displayTransaction("buy", 17);
    stand2.displayTransaction("buy", 1); // calling display function to display the information for all the transactions 

    cout << "Final states of stands:" << endl;
    cout << "=======================" << endl;
    stand1.displayStatus();
    cout << endl;
    stand2.displayStatus();
    cout << endl;
    stand3.displayStatus();
    cout << endl;
    cout << "\nGlobal Sold : " << HotDogStand::getGlobalSold() << endl;
    cout << "\nPlease press the enter key once or twice to end..." << endl;
    cin.ignore();

    return 0;

}

