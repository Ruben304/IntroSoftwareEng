#include <iostream>
#include <string>
using namespace std;

int main (){
    int num1, num2;
    int hamdist = 0;


    
    cout << "Enter two numbers between 0-100: ";
    cin >> num1 >> num2;
    int disp1 = num1;
    int disp2 = num2;

    if (num1 >= 81 || num2 >= 81)
    {
        int rem1 = num1 / 81;
        int rem2 = num2 / 81;
        if (rem1 != rem2)
        {
            hamdist += 1;
        }
        if (num1 >= 81)
        {
            num1 -= 81;
        }
        if (num2 >= 81)
        {
            num2 -= 81;
        }
    }
    if (num1 >= 27 || num2 >= 27)
    {
        int rem1 = num1 / 27;
        int rem2 = num2 / 27;
        if (rem1 != rem2)
        {
            hamdist += 1;
        }
        if (num1 >= 54)
        {
            num1 -= 54;
        }
        else if (num1 >= 27)
        {
            num1 -= 27;
        }
        if (num2 >= 54)
        {
            num2 -= 54;
        }
        else if (num2 >= 27)
        {
            num2 -= 27;
        }
    }
    if (num1 >= 9 || num2 >= 9)
    {
        int rem1 = num1 / 9;
        int rem2 = num2 / 9;
        if (rem1 != rem2)
        {
            hamdist += 1;
        }
        if (num1 >= 18)
        {
            num1 -= 18;
        }
        else if (num1 >= 9)
        {
            num1 -= 9;
        }
        if (num2 >= 18)
        {
            num2 -= 18;
        }
        else if (num2 >= 9)
        {
            num2 -= 9;
        }   
    }
    if (num1 >= 3 || num2 >= 3)
    {
        int rem1 = num1 / 3;
        int rem2 = num2 / 3;
        if (rem1 != rem2)
        {
            hamdist += 1;
        }
        if (num1 >= 6)
        {
            num1 -= 6;
        }
        else if (num1 >= 3)
        {
            num1 -= 3;
        }
        if (num2 >= 6)
        {
            num2 -= 6;
        }
        else if (num2 >= 3)
        {
            num2 -= 3;
        }
    }
    if (num1 >= 1 || num2 >= 1)
    {
        int rem1 = num1 / 1;
        int rem2 = num2 / 1;
        if (rem1 != rem2)
        {
            hamdist += 1;
        }
        if (num1 >= 2)
        {
            num1 -= 2;
        }
        else if (num1 >= 1)
        {
            num1 -= 1;
        }
        if (num2 >= 2)
        {
            num2 -= 2;
        }
        else if (num2 >= 1)
        {
            num2 -= 1;
        }
    }
    cout << "Hamming distance between " << disp1 << " and " << disp2 <<
    " when numbers are in ternary format is: " << hamdist << endl;
    return 0;
}