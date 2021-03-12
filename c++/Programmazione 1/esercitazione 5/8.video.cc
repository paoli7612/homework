#include <iostream>

using namespace std;

/* Programma per la gestione di una Catena di Anelli tutti di FERRO.
   Gli anelli della catena sono numerati a partire da 1. All'inizio la catena 
   eÕ vuota.
   Il programma deve fornire il seguente menu di operazioni:
   1) inserire un anello in posizione j (un anello alla volta)
      Le posizioni ammissibili vanno dalla prima a quella immediatamente 
      successiva all'ultima. Il programma da un messaggio di notifica nel caso
      in cui non sia possibile effettuare l'inserimento.
      Se l'inserimento ha successo il numero totale di anelli aumenta 
      ovviamente di una unitaÕ.
      Non esiste un limite al numero di anelli che si possono inserire 
      (ovviamente invocando piu' volte questa opzione).
   2) eliminare l'anello in posizione j (un anello alla volta) e
   ricongiungere gli altri
      Il programma da un messaggio di notifica nel caso in cui non sia 
      possibile effettuare l'estrazione.
   3) stampare la catena nel seguente formato:
       FFFF
       dove F indica un anello di FERRO. In questo esempio, la catena ha 4 
       anelli
   4) Terminare

  Dopo avere eseguito una delle operazioni possibili, il menu eÕ riproposto.
  Realizzare prima il solo menu, sostituendo ciascuna funzionalitaÕ con una
  semplice stampa del numero dell'opzione scelta.
*/


int main()
{
    int anelli = 0;
    while (1)
    {  
        if (anelli != 0)
            for (int a=0; a<anelli; a++)
                cout << "F";
        cout << endl;

        int s;
        cout << "\t1) inserisci anello\n\t2) elimina anello" << endl;
        do {
            cin >> s;
        } while (s<1 || s>2);
        
        switch(s){
            case 1:
                anelli++;
                break;
            case 2:
                if (anelli == 0)
                    cout << "Operazione impossibile" << endl;
                else
                    anelli--;
                break;
        }
    }
    
}