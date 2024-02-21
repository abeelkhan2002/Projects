// Abeel Khan
// CS 1336.001
// Due Date 2/28/2023 
// Completed on 2/28/2023 
// Submitted on 2/28/2023

#include <iostream>
#include <cmath>
using namespace std; 


int main()
{
	double circleArea, rectangleArea, triangleArea, rad, length, width, base, height; // labeling variables for each respective shape 
	int choice; // variable that user will input to choose their specific program 


	cout << "Enter your choice" << endl; // telling user to choose their option
	cout << " 1. Calculate the Area of a Circle " << endl; // if user wants to calculate area of a circle click 1 
	cout << " 2. Calculate the Area of a Rectangle " << endl; //if user wants to calculate area of a rectangle click 2
	cout << " 3. Calcultae the Area of a Triangle " << endl; //if user wants to calculate area of a triangle click 3
	cout << " 4. Quit " << endl << endl; //if they want to exit the program they can press 4 
	cin >> choice;

	



	if (choice == 1) // creating if statement for when they choose 1 
	{
		cout << "Enter radius of the circle " << endl; // user being told what to  input 
		cin >> rad; //user will enter the radius 
		double const pi = 3.14159; // pi is the constant used to calculate radius of circle 

		if (rad < 0) // if statment to make sure they do not unput value less then 0 
		{ 
			cout << "Error, make dimensions greater than 0. "; //telling user that they have to input a value greater then 0 
		}
		else // using else for the rest of the options if they choose a number greater than 0 
		{

			circleArea = pi * pow(rad, 2); // calculation to find the area of a circle 
			cout << "Area of circle is " << circleArea << endl; //the display that the user will see when they give the radius
		}

	}

	else if (choice == 2) // else if for when the user inputs option 2
	{
		cout << "Enter length and width of triangle" << endl; // telling user to input the length and width
		cin >> length >> width; // the user will input the length and width 

		if (length < 0 || width < 0) // if statement that will lead the prgram to an error if any of the values are negative. 
		{
			cout << "Error, make dimensions greater than 0. "; // output that user will see if they put in negative value
		}
		
		else // this is the option the user will see if they put a number that is greater then 0. 
		{
			rectangleArea = length * width; // calculations to find the area of a rectangle. 
			cout << "Area of rectangle is " << rectangleArea << endl; // Output the user will see after plugging in the length and width showing them what the area is 
		}
	}

	else if (choice == 3) // else if statement the user will see if they choose option 3. 
	{
		cout << "Enter base and height of triangle" << endl; //instructions for the user to input the base and height of the traingle. 
		cin >> base >> height; // User inputs the base and height of the triangle. 
		triangleArea = base * height * .5; // the calculations to find the area of the triangle. 
		cout << "Area of triangle is " << triangleArea << endl; // the display that the user will see showing them the area of the triangle after putting in their values. 

	}

	else if (choice == 4) // else if statement that the user will see if they choose the option 4 
	{
		cout << "Program ended" << endl; // The message they will see if they want the program to end. 
	}

	else // Final else statement that will only come up if the user puts in a int value that is not one of the options above. 
	{
		cout << "Error" << endl; // This message will pop up if they put in a value that is not listed above. 
	}




}


