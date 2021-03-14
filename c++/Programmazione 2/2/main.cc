#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

    int *a[10];

    for (int i=0; i<10; i++)
    {
        int r = rand()%10;
        a[i] = new int[r+1];
        a[i][0] = r;
        for (int j=0; j<r; j++)
            a[i][j+1] = rand()%20-10;
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<a[i][0]; j++)
            cout << a[i][j+1] << " ";
        cout << endl;
    }
        

    return 0;
}