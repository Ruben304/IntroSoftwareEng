#include <iostream>
using namespace std;

int main (){
    int x1, y1, len1, hei1;
    int x2, y2, len2, hei2;
    
    cout << "Enter the information for the first rectangle" << endl;
    cout << "x-coordinate: ";
    cin >> x1;

    cout << "y-coordinate: ";
    cin >> y1;

    cout << "length: ";
    cin >> len1;

    cout << "height: ";
    cin >> hei1;

    cout << "Enter the information for the second rectangle" << endl;
    cout << "x-coordinate: ";
    cin >> x2;

    cout << "y-coordinate: ";
    cin >> y2;

    cout << "length: ";
    cin >> len2;

    cout << "height: ";
    cin >> hei2;

    int nx1cord = x1 + len1;
    int ny1cord = y1 + hei1;
    int nx2cord = x2 + len2;
    int ny2cord = y2 + hei2;


        if((((x2 >= x1) || (nx2cord >= x1)) && ((x2 <= nx1cord) || (nx2cord <= nx1cord))) && (((y2 >= y1) || (ny2cord >= y1)) && ((y2 <= ny1cord) || (ny2cord <= ny1cord)))){
            cout << "THE RECTANGLES INTERSECT" << endl;
        }
        else{
            cout << "THE RECTANGLES DO NOT INTERSECT" << endl;
        }
    return 0;
    
}