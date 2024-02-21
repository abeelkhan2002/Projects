
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

int main()
{

	double object, earth, moon, mercury, venus;
	double const earthGravity = 9.807, moonGravity = 1.62, mercuryGravity = 3.7, venusGravity = 8.87;

	cout << setprecision(2) << fixed;

	cout << "Please enter the mass of an object in kilograms: ";
	cin >> object;
	cout << endl;
	cout << endl;

	earth = object * earthGravity;
	moon = object * moonGravity;
	mercury = object * mercuryGravity;
	venus = object * venusGravity;

	if (object < 0)
	{
		cout << "Error, invalid mass entered." << endl;
		cout << "The entered mass must be greater than 0.";
	}

	else if (earth > 1250)
	{
		cout << endl << endl << left << setw(16) << "Planet/Satellite" << "\t" << right << setw(14) << " Weight (N) " << endl;
		cout << left << setw(16) << "Earth " << "\t" << right << setw(14) << earth << " The object is heavy " << endl;
		cout << left << setw(16) << "Moon " << "\t" << right << setw(14) << moon << endl;
		cout << left << setw(16) << "Mercury " << "\t" << right << setw(14) << mercury << endl;
		cout << left << setw(16) << "Venus " << "\t" << right << setw(14) << venus << endl;
	}

	else if (earth < 20)
	{
		cout << endl << endl << left << setw(16) << "Planet/Satellite" << "\t" << right << setw(14) << " Weight (N) " << endl;
		cout << left << setw(16) << "Earth " << "\t" << right << setw(14) << earth << "\tThe object is light." << endl;
		cout << left << setw(16) << "Moon " << "\t" << right << setw(14) << moon << endl;
		cout << left << setw(16) << "Mercury " << "\t" << right << setw(14) << mercury << endl;
		cout << left << setw(16) << "Venus " << "\t" << right << setw(14) << venus << endl;
	}

	else
	{
		cout << endl << endl << left << setw(16) << "Planet/Satellite" << "\t" << right << setw(14) << " Weight (N) " << endl;
		cout << left << setw(16) << "Earth " << "\t" << right << setw(14) << earth << endl;
		cout << left << setw(16) << "Moon " << "\t" << right << setw(14) << moon << endl;
		cout << left << setw(16) << "Mercury " << "\t" << right << setw(14) << mercury << endl;
		cout << left << setw(16) << "Venus " << "\t" << right << setw(14) << venus << endl;

	}









}