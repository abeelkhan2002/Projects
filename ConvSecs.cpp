#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const long long int SecondsDay = 86400;
    const long long int SecondsHour = 3600;
    const long long int SecondsMin = 60;
    long long int totalSeconds;

    cout << "Enter a number of seconds: ";
    cin >> totalSeconds;

    if (totalSeconds <= 0)
    {
        cout << endl << "Error! The seconds must be greater than zero." << endl;
    }
    else
    {
        long long int days = totalSeconds / SecondsDay;
        long long int remainingSeconds = totalSeconds % SecondsDay;
        long long int hours = remainingSeconds / SecondsHour;
        remainingSeconds %= SecondsHour;
        long long int minutes = remainingSeconds / SecondsMin;
        remainingSeconds %= SecondsMin;

        cout << endl << totalSeconds << " seconds is:" << endl;

        if (days > 0)
        {
            cout << setw(4) << days << " days, " << "\t" << endl;
        }
        if (hours > 0)
        {
            cout << setw(4) << hours << " hours, " << "\t" << endl;
        }
        if (minutes > 0)
        {
            cout << setw(4) << minutes << " minutes, " << "\t" << endl;
        }
        cout << setw(4) << remainingSeconds << " seconds." << "\t" << endl;
    }

    return 0;
}