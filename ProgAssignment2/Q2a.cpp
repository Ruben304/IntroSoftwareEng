#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    if (m == 0 || n == 0)//base case
    {
        return 0; //break out of recrusion
    }
    if (m % n == 0) //special caseof one being zero
    {
        return n; //returns gcd for case
    }

    return gcd(n, m % n); //calls itself till there is no remainder

}

int main(){
    // This will find the greatest common denominator 
    int m,n;
    cout << "Enter m: ";//user input
    cin >> m;
    cout << "Enter n: ";//user input
    cin >> n;

    int ans = gcd(m,n); // this calls tehe recursive function 
    cout << "GCD is: " << ans << endl; 
    return 0;
}