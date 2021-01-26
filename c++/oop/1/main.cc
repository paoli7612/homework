#include <iostream>
#include <cstring>

using namespace std;

#include "persona.hpp"

int main(int argc, char** argv)
{
    Persona p("Tommaso", "Paoli");


    cout << p.get_nome() << " " << p.get_cognome() << endl;

    


    return 0;
}