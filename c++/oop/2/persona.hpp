#include <iostream>
#include <cstring>

#define M 20

class Persona {
    private: 
        char nome[M];
        char cognome[M];
        char codice_fiscale[16];
    public:
        Persona(const char[M], const char[M]);

        char* get_nome();
        char* get_cognome();

        void set_nome(const char[M]);
        void set_cognome(const char[M]);

        void stampa();

        char* to_string();
};

Persona::Persona(const char nome[M], const char cognome[M]){
    set_cognome(cognome);
    set_nome(nome);
}


char* Persona::get_nome()
{
    return this->nome;
}

char* Persona::get_cognome()
{
    return this->cognome;
}

void Persona::set_nome(const char nome[M])
{
    strcpy(this->nome, nome);
}
void Persona::set_cognome(const char cognome[M])
{
    strcpy(this->cognome, cognome);
}

void Persona::stampa()
{
    cout << get_nome() << " " << get_cognome() << endl;
}

char* Persona::to_string()
{
    short int ln, lc;
    char* nome = get_nome();
    ln = strlen(nome);
    char* cognome = get_cognome();
    lc = strlen(cognome);

    char *ret = new char[ln + 1 + lc];

    strcpy(ret, nome);
    strcpy(ret+ln+1, cognome);
    ret[ln] = 3;

    return ret;
}