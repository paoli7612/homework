#include <iostream>
#include <cmath>

using namespace std;

const int n_bit = 8;
const int M = pow(2, n_bit)-1;

void cout_bin(int n)
{
    for (int i=n_bit-1; i>=0; i--)
        cout << (n/((int)pow(2, i)))%2;
    cout << " ";
}

int main()
{

    for (int i=0; i<200; i++)
    {
        int n = rand()%M;

        int b = 1<<rand()%n_bit;
        
        cout_bin(n);
        cout << " & ";

        cout_bin(b);
        int r = n&b;
        cout << "\t";
        cout_bin(r); 
        cout << n << " & " << b <<" = " << r;
        cout << endl;
    }
 

    return 0;
}
