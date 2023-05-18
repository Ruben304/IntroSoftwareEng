#include <iostream>
#include <iomanip>
using namespace std;

double series (double num)
{
    if (num == 1) //base case
    {
        return 2.0 /5; //breaks out of loop by returning first value
    }

    double value = (double) (2.0 * num)/(3.0 * num + 2.0) + series(num - 1); //forms the last series values and continues till it works itself to the first term(base case)

    return value; //returns the total sum
}
int main(){
    double num; //double for all since were dealing with decimals

    cout << "Enter n: "; //gets user input
    cin >> num;

    double result = series(num);
    cout << "Series (" << num << ") is : " << result << endl; 

    return 0;
}