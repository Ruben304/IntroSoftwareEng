#include <iostream>
using namespace std;


int * ReverseMultiply (int *list, int size)
{
    int product = 1;
    int nsize = (2 * size);
    int *multptr = new int[nsize + 1]; //initialize new array from heap to pointer

    for (int i = 0; i < size; i++)
    {
        *(multptr  + i) = *(list + i);
        product = product * *(list + i);
    }
    for (int i = size - 1, j = size; i >= 0; i--, j++)
    {
        *(multptr + j) = *(list + i); 
        product = product * *(list + i);
    }

    *(multptr + nsize) = product;

    return multptr;
}

int * ReverseAdd(int *list, int size)
{
    int sum = 0;
    int nsize = (2 * size);
    int *addptr = new int[nsize -1]; // initlize the new array from heap to pointer
    for (int i = 0; i < size; i++)
    {
        *(addptr  + i) = *(list + i);
    }
    for (int i = size -1, j = size; i >= 1; i--, j++)
    {
        *(addptr + j) = *(list + i) + *(list + i - 1); 
    }
    return addptr;
}

int main(){
    //declare all of the variables and pointers
    int size;
    const int MAX = 300;
    int list[MAX];
    int *listptr;
    int *multptr;
    int *addptr;
    listptr = list;

    cout << "Enter the number of entries: "; //user input for entries
    cin >> size;

    for (int i = 0; i < size ; i++)
    {
        cout << "Entry " << i << " is: ";
        cin >> list[i];
        cout << endl;
    }
    cout << "*****" << endl;//star divider

    //print out the original array and address
    cout << "Original array is: ";
    for (int i = 0; i < size ; i++)
    {
        cout << list[i] << " ";
    }
    cout << "and the address of the zero element is: " << &list[0] << endl;

    //make and print out the reverse mulitply array

    multptr = ReverseMultiply(listptr, size);  
    cout << "One array is: ";
    for (int i = 0; i < (size * 2) + 1; i++)
    {
        cout << *(multptr + i) << " ";
    }
    cout << "and the address of the zero element is: " << multptr << endl;

    //make and print out the reverse add array
    
    addptr = ReverseAdd(listptr, size);
    cout << "Two array is: ";
    for (int i = 0; i < (size *2 - 1); i++)
    {
        cout << *(addptr + i) << " ";
    }
    cout << "and the address of the zero element is: " << addptr << endl;
    
    return 0;
}