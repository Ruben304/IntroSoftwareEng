#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int conversion;
    double inpt, outpt;

    while(true){
        cout << "Celsius to Farenhiet (enter 0)" << endl;
        cout << "Celsius to Kelvin (enter 1)" << endl;
        cout << "Farenhiet to Celsius (enter 2)" << endl;
        cout << "Farenhiet to Kelvin (enter 3)" << endl;
        cout << "Kelvin to Celsius (enter 4)" << endl;
        cout << "Kelvin to Farenhiet (enter 5)" << endl;

        cout << "Conversion type: ";
        cin >> conversion;

        if (conversion == 0){
            cout << "Enter amount in Celsius: ";
            cin >> inpt;
            outpt = (inpt * (9.0 /5)) + 32.0;
            cout << inpt << " Celsius is " << fixed << setprecision(3) << outpt << " Farenhiet." << endl;
            break;
        }
        else if (conversion == 1){
            cout << "Enter amount in Celsius: ";
            cin >> inpt;
            outpt = (inpt + 273.15);
            cout << inpt << " Celsius is " << fixed << setprecision(3) << outpt << " Farenhiet." << endl;
            break;
        }
        else if (conversion == 2){
            cout << "Enter amount in Farenhiet: ";
            cin >> inpt;
            outpt = (inpt - 32.0) * (5.0 /9);
            cout << inpt << " Farenhiet is " << fixed << setprecision(3) << outpt << " Celcius." << endl;
            break;
        }
        else if (conversion ==3){
            cout << "Enter amount in Farenhiet: ";
            cin >> inpt;
            outpt = ((inpt - 32.0) * (5.0 /9)) + 273.15;
            cout << inpt << " Farenhiet is " << fixed << setprecision(3) << outpt << " Kelvin." << endl;
            break;
        }
        else if (conversion == 4){
            cout << "Enter amount in Kelvin: ";
            cin >> inpt; 
            outpt = (inpt - 273.15);
            cout << inpt << " Kelin is " << fixed << setprecision(3) << outpt << " Celsius." << endl;
            break;
        }
        else if (conversion == 5){
            cout << "Enter amount in Kelvin: ";
            cin >> inpt;
            outpt = ((inpt - 273.15) * (9.0 /5)) + 32.0;
            cout << inpt << " Kelin is " << fixed << setprecision(3) << outpt << " Farenhiet." << endl;
            break;
        }
        else
            cout << "Not valid input" << endl;

    }

    return 0;
}