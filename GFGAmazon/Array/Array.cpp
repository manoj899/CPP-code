#include<bits/stdc++.h>
using namespace std;

// Returns the number to be added to the
// input to replace all zeroes with five
int calculateAddedValue(int number)
{
    
    // Amount to be added
    int result = 0;

    // Unit decimal place
    int decimalPlace = 1;
    
    if (number == 0) 
    {
        result += (5 * decimalPlace);
    }

    while (number > 0)
    {
        if (number % 10 == 0)
        {
            
            // A number divisible by 10, then
            // this is a zero occurrence in 
            // the input
            result += (5 * decimalPlace);

        }
        
        // Move one decimal place
        number /= 10;
        decimalPlace *= 10;
    }
    return result;
}

int replace0with5(int number)
{
    return number += calculateAddedValue(number);
}

// Driver code
int main()
{
    int n ;
    cin>>n;
    cout << replace0with5(n);

    return 0;
}
