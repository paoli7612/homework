#include <iostream>

using namespace std;

/*
    Decidere da quale server scricare un film sulla base del peso del film

    Il primo server va ad una velocità di 200KB/sec ma solo per i primi 60 minuti,
        poi la velocità scende a 50KB/sec
    
    il secondo server va ad una velocità di 100KB/s

    se il film è grande 644 840 KB, quale ci conviene utilizzare?
*/

typedef int byte;
typedef int bytesec;
typedef int sec;
// bytesec = byte/sec
// byte = bytesec*sec
// sec = byte/bytesec

int main()
{
    const sec s1_t_v_1 = 3600; // Tempo durata velocità 1 del server 1
    const int s1 = 1, s2 = 2; // Indici dei due server
    const bytesec v1_1 = 200, v1_2 = 50, v2 = 100; // velocita dei server 1 e 2.. il server 1 ha due velocità diversa
    const byte b_1_1 = v1_1 * s1_t_v_1; // quanti byte scarica il primo server alla prima velocità

    byte film;
    cout << "Inserisci la lunghezza del film" << endl;
    cin >> film;

    int server;
    sec tempo;

    cout << b_1_1 << " " << film << endl;

    if (b_1_1 >= film){
        server = s1;
        tempo = film/v1_1;
    } else {
        // server 1
        sec t1; // tempo di download dal primo server
        t1 = b_1_1 / v1_1;
        t1 += (film - b_1_1) / v1_2;
        // server 2
        sec t2; // tempo di download dal secondo server
        t2 = film / v2;
        if (t1 <= t2)
        {
            server = s1;
            tempo = t1;
        }
        else
        {
            server = s2;
            tempo = t2;
        }       
    }


    cout << "conviene utilizzare il " << server << " server che impiegherà " << tempo << " secondi" << endl;
}