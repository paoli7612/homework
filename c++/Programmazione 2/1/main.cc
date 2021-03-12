#include <iostream>

using namespace std;

const int T = -1; // Terminatore

   /*
    * Stampa array fino al terminatore
    */
void stampa(int *p)
{
    for (int i=0; p[i]!=T; p++)
        cout << p[i] << " ";
    cout << endl;
}

   /*
    * Stampa array fino al terminatore ( senza variabile locale )
    */
void stampa2(int *p)
{
    while (*p != T)
    {
        cout << *p << " "; // Stampa il contenuto della variabile a cui punta p
        p++; // Sposta il puntatore sulla cella sucessiva
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int array[] = {1, 5, 4, 2, 3, 5, T};
    
    stampa(array);
    stampa2(array);


    return 0;
}
