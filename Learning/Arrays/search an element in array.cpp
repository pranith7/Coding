#include <iostream>
using namespace std;

int main()
{
    int input[50], count ,i, num;

    cout << "enter number of elements in array\n";
    cin >> count;
    
    cout << "enter " << count  << " number \n";
    
    for (i=0; i<count; i++)
    {
        cin >> input[i];
    }

    cout << " enter a number to search in array\n";
    cin >> num;

    for (i=0; i<num; i++)
    {
        if (input[i] == num)
        {
            cout << "element found at index " << i ;
            break;
        
        }
    } 

    if (i == count)
    {
        cout << "element not found in array\n";
    
    }

    return 0;
}













}