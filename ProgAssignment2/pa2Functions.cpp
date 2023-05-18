#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pa2Functions.h"

using namespace std;

//Global Variables
const int ENTRIES = 10;
ofstream *offile = NULL;
ifstream *infile = NULL;

void initialize()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2022" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
    return;
}

bool checkCode(char option)
{
    //If the option is one of the testcases then it returns true 
    switch(option){
        case 'F':
        case 'f':
        case 'B':
		case 'b':
		case 'R':
		case 'r':
		case 'U':
		case 'u':
		case 'C':
		case 'c':
		case 'E':
		case 'e':
		case 'K':
		case 'k':
		case 'S':
		case 's':
		case 'N':
		case 'n':
		case 'X':
		case 'x':
		case 'L':
		case 'l':
		case 'Y':
		case 'y':
		case 'D':
		case 'd':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'Q':
		case 'q':
            return true;
            break;
        default:  //if not a test case then return false 
            return false;
    }
}

void writeDataToFile(const char *filename)
{
    offile = new ofstream(); //  inititlize offile in the heap 
    offile -> open(filename); // arrow derefrences and directs the offile to the open file
    return; 
}

void readDataFromFile(const char *filename)
{
    infile = new ifstream(); //initlize ifflie in the heap
    infile -> open(filename); //arrow defrences and directs the infile to the open file
    return;
}
  
int factorial(int input)
{
    int num = 1; // initialize the output

    for (int i = 1; i <= input; i++)
    {
        num = num * i; // multiplies all the number before num to itself with i 
    }

    return num;
}

int fibonacci(int input)
{
    //initialize the variables term we need 
    int first = 0; 
    int second = 1;
    int next = 0;

    if (input == 1)
    {
        return first; //if first input is wanted return first(0)
    }
    else if (input == 2)
    {
        return second; //if second input is wanted return second(1)
    }
    else  //if another input is wanted, calculate it first
    {
        for (int i = 2; i < input; i++)
        {
            next = first + second; //collects the ext term by adding the previous two
            first = second; //stores the second previous term to the new first term
            second = next; //stores the calculate next term and the nenw second term
        }

        return next;
    }
}

double findSqrtValue(double input)
{
    //declare where we store the output to return
    double output; 
    output = sqrt(input); //use operation to calculate sqrt
    return output;
}

double naturalLog(double input)
{
    //declare where we store the output to return
    double output; 
    output = log(input); //use operation to calculate natural log
    return output;  
}

double areaCircle(double radius)
{
    // declare where we store the output to return
    double areaC; 
    areaC = 3.14159 * radius * radius; // pi*(r^2) finds area of a circle 
    return areaC;
}

double areaSquare(double length)
{
    // declare where we store the output to return
    double areaS; 
    areaS = length * length; // length^2 is area of square
    return areaS;
}

int findNextOddValue(int input)
{
    int oddv; // initialize the output
    if (input % 2 == 1) //if odd
    {
        oddv = input + 2; // makes next odd value
        return oddv;
    }
    else //if even
    {
        oddv = input + 1; // turn to odd
        return oddv;
    }
}

int findNextEvenValue(int input)
{
    int evenv; // initialize the output
    if (input % 2 == 0) //if even
    {
        evenv = input + 2; // makes next odd value
        return evenv;
    }
    else //if odd
    {
        evenv = input + 1; // turn to even
        return evenv;
    }
}

double findNyanCatValue(double input)
{
    double ncatv; 
    ncatv = pow((4 * input),input) + input + 10;
    return ncatv;
}

double doMath(double num, char wave)
{
    double result;// declare where to store and return the output

    switch(wave){ //created a switch statement for 
        case 'S':
        case 's':
            result = sin(num); // sin value of number 
            break;
        case 'C':
        case 'c':
            result = cos(num); //cos value of number
            break;
        case 'X':
        case 'x':
            result = exp(num); //exponenetial value of number
            break;
    }

    return result;
}

double lucky(double rando)
{
    srand(time(NULL) + rando); //creates the seed with ssytem time and argument
    double out; 
    out = (double) rand(); //generates that random number
    return out;
}
