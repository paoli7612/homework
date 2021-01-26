class Persona {
    private: 
        char nome[20];
        char cognome[20];
        char codice_fiscale[16];

    public:
        Persona();
        Persona(const char[20], const char[20]);
        
        char* get_nome();
        char* get_cognome();
};

Persona::Persona(){

};

Persona::Persona(const char nome[20], const char cognome[20])
{
    strcpy(this->nome, nome);
    strcpy(this->cognome, cognome);
}

char* Persona::get_nome()
{
    return this->nome;
}

char* Persona::get_cognome()
{
    return this->cognome;
}