#include <iostream>

using namespace std;

int somma(int a, int b) { return a + b; }
int sottrazione(int a, int b) { return a - b; }
int prodotto(int a, int b) { return a * b; }
int divisione(int a, int b) { return a / b; }

int main(int argc, char **argv)
{
    int (*operazioni[])(int, int) = { somma, sottrazione, prodotto, divisione };

    cout << "Operazione? (0: somma, 1: sottrazione, 2: moltiplicazione, 3: divisione): ";
    int op;
    cin >> op;

    cout << "Interi?: ";
    int a, b;
    cin >> a >> b;

    cout << operazioni[op](a, b) << endl;

    return 0;
}