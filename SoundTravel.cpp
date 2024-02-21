#include <iostream>
#include <iomanip>
using namespace std;

int main()

{

    unsigned int medium;
    const double Wood = 12631.23;
    const double Steel = 10614.81;
    const double Water = 4714.57;
    const double Air = 1125.33;
    double distance, sec;



    cout << "Time for Sound to Travel through a Medium given Distance " << endl;
    cout << "1 - Wood " << endl;
    cout << "2 - Steel " << endl;
    cout << "3 - Water " << endl;
    cout << "4 - Air " << endl << endl;
    cout << "Enter the number of the medium: ";
    cin >> medium;




    switch (medium)
    {

    case 1: cout << "Enter the distance to travel (in feet):" << endl;
        cin >> distance;

        if (distance > 0)

        {

            sec = distance / Wood;
            cout << "In wood it will take " << setprecision(4) << fixed << sec << " seconds to travel " << setprecision(2) << fixed << distance << " feet." << endl;


        }


        else
        {


            cout << "Error, the distance must be greater than zero.";

        }

        break;

    case 2: cout << "Enter the distance to travel (in feet):" << endl;

        cin >> distance;


        if (distance > 0)

        {

            sec = distance / Steel;
            cout << "In steel it will take " << setprecision(4) << fixed << sec << " seconds to travel " << setprecision(2) << fixed << distance << " feet." << endl;


        }


        else
        {


            cout << "Error, the distance must be greater than zero.";

        }

        break;

    case 3: cout << "Enter the distance to travel (in feet):" << endl;
        cin >> distance;


        if (distance > 0)

        {

            sec = distance / Water;
            cout << "In water it will take " << setprecision(4) << fixed << sec << " seconds to travel " << setprecision(2) << fixed << distance << " feet." << endl;


        }


        else
        {


            cout << "Error, the distance must be greater than zero.";

        }

        break;

    case 4: cout << "Enter the distance to travel (in feet):" << endl;
        cin >> distance;


        if (distance > 0)

        {

            sec = distance / Air;
            cout << "In water it will take " << setprecision(4) << fixed << sec << " seconds to travel " << setprecision(2) << fixed << distance << " feet." << endl;


        }


        else
        {


            cout << "Error, the distance must be greater than zero.";

        }

        break;

    }

































}