#include <iostream>
#include <cstring>

#include "persona.hpp"

class Utente: public Persona {
    private:
    public:
        Utente(const char n[M], const char c[M]) : Persona(n, c){}
        char* to_string();
};

char* Utente::to_string()
{
    char* ret = Persona::to_string();
    ret[0] = 'G';
    return ret;
}

