#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Primo";
        break;
    case 2:
        cout << "Secondo";
        break;
    case 3:
        cout << "Terzo";
        break;
    case 4:
        cout << "Quarto";
        break;
    case 5:
        cout << "Quinto";
        break;
    case 6:
        cout << "Sesto";
        break;
    case 7:
        cout << "Settimo";
        break;
    default:
        cout << "Too big";
    }
    cout << endl;
}