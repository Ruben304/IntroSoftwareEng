#include <iostream>
#include <fstream>
#include "pa2Functions.h"
using namespace std;

extern const int ENTRIES = 10;
extern ifstream * infile;
extern ofstream * offile;

bool checkdoubl(double first, double last, double delta)
{
    //checks to see of teh double parameters are albe to be computed
    if (delta <= 0 || first > last)
    {
        if (offile != NULL)
        {
            *offile << "No Computation needed." << endl;
        }
        cout << "No computation needed." << endl;
        return true;
    }
    else 
        return false;
}
int main(){

    char option; // the user option chosen
    char *fname = new char; //filename  declared
    int parnum, calcnum; // the parameter number and calculated number
    double first,last, delta, dout; //the parameters for the double options and its output
    bool checkout; // returns true or false based on valid parameters

    initialize();

    
    do{
        if (infile != NULL) // checks if the commands are from a file 
        {
            if(!infile -> eof())
            {
                *infile >> option; //if yes then read that input from file to option
            }
            else //at the end of the program by noting no more readable lines
            {
                if(offile != NULL)
                {
                    offile -> close();
                }
                if(infile != NULL)
                {
                    infile -> close();
                }
            }
        }
        else //if not from filie then we can take the user input
        {
            cout << "Please enter a command code: ";
            cin >> option;
        }


        //Checks the input of user to see if its valid
        if(checkCode(option) == false)
        {
            if (offile != NULL) //if the output stream is open
            {
                *offile << "Invalid command code." << endl; //write wrong input and close
                offile -> close();
            }
            if (infile != NULL) // if the input file stream is open
            {
                infile -> close(); //close it
            }
            cout << "Invalid command code" << endl;
            return 0;
        }

        switch(option){// reads which commans should be executued

            case 'F': // factorial option
            case 'f': // int return & one parameter
                
                if (infile != NULL) // if the input stream is open then get the input from file
                {
                    if(!infile ->eof())
                    {
                        *infile >> parnum;
                    }
                }
                else //otherwise get user input
                {
                    cout << "Please enter parameters: ";
                    cin >> parnum;
                }
                calcnum = factorial(parnum);
                if (offile != NULL) //if the outstream file is open
                {
                    *offile << "Factorial of " << parnum << " is: " << calcnum << endl; //put output to the file
                }
                else 
                {
                    cout << "Factorial is " << parnum << " is: " << calcnum << endl;//otherwise just print it
                }
                break;

            case 'B': // fibonacci function
            case 'b': // int return & one parameter
                
                if (infile != NULL) // if the input stream is open then get the input from file
                {
                    if(!infile ->eof())
                    {
                        *infile >> parnum;
                    }
                }
                else //otherwise get user input
                {
                    cout << "Please enter parameters: ";
                    cin >> parnum;
                }
                calcnum = fibonacci(parnum);
                if (offile != NULL) //if the outstream file is open
                {
                    *offile << "Fibonacci of " << parnum << " is: " << calcnum << endl; //put output to the file
                }
                else 
                {
                    cout << "Fibonacci of " << parnum << " is: " << calcnum << endl;//otherwise just print it
                }
                break;

            case 'R': // square root function
            case 'r': // double return & all parameters 
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = findSqrtValue(last); // then use that last value for computation
                            cout << "Square root of "<< last << " is: " << dout << endl;
                            if (offile != NULL) //if the output stream of the file is open 
                            {
                                *offile << "Square root of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else //if the last parameter is not met
                        {
                            dout = findSqrtValue(first + (delta * i)); //take the value of the other parameters
                            cout << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;

            case 'U': // area of a sqaure function
            case 'u': // double return & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = areaSquare(last); // then use that last value for computation
                            cout << "Area of a square with a side length of  "<< last << " is: " << dout << endl;
                            if (offile != NULL) //if the output stream of the file is open 
                            {
                                *offile << "Area of a square with a side length of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = areaSquare(first + (delta * i)); // take the value of the other parameters
                            cout << "Area of a square with a side length of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Area of a square with a side length of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;
            case 'C': // area of a circle function
            case 'c': // double return & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)//if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = areaCircle(last); // then use that last value for computation
                            cout << "Area of a circle with a radius of  "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Area of a circle with radius of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = areaSquare(first + (delta * i)); // take the value of the other parameters
                            cout << "Area of a square with a side length of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Area of a square with a side length of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }    
                break;

            case 'E': // next even number function
            case 'e': // return int & first/last parameter

                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, 1); // we can ignore delta for this one since we onlly use first and last parameters
                cout << "List of next even numbers from " << first << " to " << last << " : " << endl;
                if (offile != NULL)
                {
                    *offile << "List of next even numbers from " << first << " to " << last << " : " << endl;
                }
                if (checkout == false)// if the inputs are valid
                { // finding the next even value from first to an inclusie last 
                    for (int i = 0; i < ENTRIES *2; i += 2) // i needs to be increamented by 2 since an increamentation of 1 could still align it to the same even value
                    {                                       // this causes a double an increamentation so a double scale for ENTRIES
                        if (last <= (first + i)) 
                        {                       // once is becomes greater than the last we can stop looping
                            break;
                        }
                        calcnum = findNextEvenValue(first + i);
                        cout << "The closest/highest even number from parameters is " << calcnum << endl;
                        if (offile != NULL) // if output stream is open
                        {
                            *offile << "The closest/highest even number from parameters is " << calcnum << endl;
                        }
                    }
                }
                break;

            case 'K': // lucky function
            case 'k': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = lucky(last); //then use that last value for computation
                            cout << "The lucky of "<< last << " is: " << dout << endl;
                            if (offile != NULL) //if the output stream of the file is open 
                            {
                                *offile << "The lucky of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else //if the last parameter is not met
                        {
                            dout = lucky(first + (delta * i)); // take the value of the other parameters
                            cout << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }            
                break;

            case 'S': // sin function
            case 's': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = doMath(last, option); // then use that last value for computation & input the sin option
                            cout << "Sin of "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Sin of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = doMath(first + (delta * i), option); // take the value of the other parameters
                            cout << "Sin of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Sin of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }  
                break;

            case 'N': // cosine function
            case 'n': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        { 
                            dout = doMath(last, option); // then use that last value for computation & input the cosine option
                            cout << "Cosine of "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Cosine of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = doMath(first + (delta * i), option); // take the value of the other parameters
                            cout << "Cosine of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Cosine of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;

            case 'X': // exponential function
            case 'x': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)//if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = doMath(last, option); // then use that last value for computation & input the exponential option
                            cout << "Exponential of "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Exponential of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = doMath(first + (delta * i), option); // take the value of the other parameters
                            cout << "Exponential of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Exponential of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;

            case 'L': // natural log function
            case 'l': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = naturalLog(last); // then use that last value for computation
                            cout << "Natural Log of "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Natural Log of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = naturalLog(first + (delta * i)); // take the value of the other parameters
                            cout << "Natural Log  of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Natural Log of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;

            case 'Y': // nyancat function
            case 'y': // return double & all parameters
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, delta);

                if(checkout == false)// if the parameters are not a special case then 
                {
                    for (int i = 0; i < ENTRIES; i++) // loops Entries if it dosent meat least
                    {
                        if ((first + delta * i) >= last) // if the last value is meet or exceeded
                        {
                            dout = findNyanCatValue(last); //then use that last value for computation
                            cout << "Square root of "<< last << " is: " << dout << endl;
                            if (offile != NULL) // if the output stream of the file is open 
                            {
                                *offile << "Square root of "<< last << " is: " << dout << endl; 
                            }
                            break;
                        }
                        else // if the last parameter is not met
                        {
                            dout = findNyanCatValue(first + (delta * i)); // take the value of the other parameters
                            cout << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            if (offile != NULL)// if the output stream of the file is open 
                            {
                                *offile << "Square root of " << first << " + ( " << delta << " * " << i << " ) is: " << dout << endl;
                            }
                        }
                    }
                }
                break;
            case 'D': // next odd value function
            case 'd': // int return & first/last parameter
                if (infile != NULL) // if the input stream is open then use parametrs from there
                {
                    if (!infile -> eof())
                    {
                        *infile >> first >> last >> delta;
                    }
                }
                else // otherwise get user input parameters
                {
                    cout << "Please enter command parameters: ";
                    cin >> first >> last >> delta;
                }

                checkout = checkdoubl(first, last, 1); // we can ignore delta for this one since we onlly use first and last parameters
                cout << "List of next odd numbers from " << first << " to " << last << " : " << endl;
                if (offile != NULL)
                {
                    *offile << "List of next odd numbers from " << first << " to " << last << " : " << endl;
                }
                if (checkout == false)// if the inputs are valid
                { // finding the next odd value from first to an inclusie last 
                    for (int i = 0; i < ENTRIES *2; i += 2) // i needs to be increamented by 2 since an increamentation of 1 could still align it to the same odd value
                    {                                       // this causes a double an increamentation so a double scale for ENTRIES
                        if (last <= (first + i)) 
                        {                       // once is becomes greater than the last we can stop looping
                            break;
                        }
                        calcnum = findNextOddValue(first + i);
                        cout << "The closest/highest odd number from parameters is " << calcnum << endl;
                        if (offile != NULL) // if output stream is open
                        {
                            *offile << "The closest/highest odd number from parameters is " << calcnum << endl;
                        }
                    }
                }
                break;
            case 'I': // read data from file function
            case 'i': // no return
                cout << "Enter a file name: ";
                cin >> fname; // get the user input for file 
                readDataFromFile(fname); // initialize the output stream for file
                break;
            
            case 'O': // write data from file function
            case 'o': // no return
                cout << "Enter file name: ";
                cin >> fname; // get the user input for file
                writeDataToFile(fname); // initlialize the input stream for file
                break;

            case 'Q': // quit function
            case 'q': // returns nothing
                if (offile != NULL) // ensures the outstream of file is closed if open if being used
                {
                    offile -> close();
                }
                if (infile != NULL) // ensures the instream of file is closed if open if being used
                {
                    infile -> close();
                }
                return 0;
                break;
        }

    }while(true);
    return 0;
}