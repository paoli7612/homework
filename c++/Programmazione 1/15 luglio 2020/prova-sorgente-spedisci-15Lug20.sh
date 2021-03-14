#!/bin/bash

# ISTRUZIONI PER L'ESECUZIONE DI QUESTO SCRIPT
# bash prova-sorgente-spedisci-data_esame.sh nome_vostro_file_sorgente

crea_tester ()
{
    cat <<- EOF > righe_da_ultima_stampa.cc
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{

	if (argc < 2) {
		cerr<<"Argomenti mancanti"<<endl;
		return 1;
	}
	vector<string> linee_output;

	string linea_aggancio(argv[1]);
	string linea;
	bool buffering = false;

	while (getline( cin, linea )) {
		if (confronta_contenuto_linee(linea, linea_aggancio)) {
			buffering = true;
			linee_output.clear();
		}
		if (buffering)
			linee_output.push_back(linea);
	}

	// stampa le ultime linee a partire dall'ultima stampa
	for (std::vector<string>::const_iterator i = linee_output.begin();
	     i != linee_output.end(); ++i)
		std::cout << *i<<endl;

	return 0;
}
EOF

    g++ -Wall righe_da_ultima_stampa.cc -o righe_da_ultima_stampa

    if [ $? -ne 0 ]; then
	echo Compilazione del filtro delle righe di output fallita
	exit 1
    fi

    cat <<- EOF > controlla_output.cc
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		cout<<"Argomenti mancanti"<<endl;
		return 1;
	}

	int num_linee = atoi(argv[1]);

	cout<<"Ora leggo l'output del programma, e come ultima stampa dello stato"
	    <<endl<<"mi aspetto:"<<endl;

	for (int i = 0 ; i < num_linee ; i++)
		cout<<argv[i+2]<<endl;

	string linea;
	bool letta_una_linea = false;
	int indice_linea_corretta = 0;

	while (getline( cin, linea ) && indice_linea_corretta < num_linee) {
		letta_una_linea = true;
		string linea_corretta(argv[indice_linea_corretta+2]);

		if (!confronta_contenuto_linee(linea, linea_corretta)) {
			cout<<"La seguente riga:"<<endl;
			cout<<linea<<endl;
			cout<<"Non coincide con la riga attesa, ossia con:"
			    <<endl;
			cout<<linea_corretta<<endl;

			return 1;
		}
		indice_linea_corretta++;
	}

	cout<<endl;

	if (!letta_una_linea) {
		cout<<"Non ho trovato nessuna riga corretta di stampa dello stato!"
		    <<endl;
		cout<<"Verifica la presenza di tali righe nell'output"<<endl
		    <<"e la correttezza del formato di tali righe"<<endl;

		return 1;
	}

	cout<<"Test superato!!!"<<endl;
	cout<<"-------------------------------------------------------------"
	    <<endl;

	return 0;
}
EOF

    g++ -Wall controlla_output.cc -o controlla_output

    if [ $? -ne 0 ]; then
	echo Compilazione del controllore dell\'output fallita
	exit 1
    fi
}

stampa_msg_punto_insufficiente ()
{
    if [ "$1" != "" ]; then
	punto=$1
	echo Il tuo programma ha superato tutti i test relativi ai punti che
	echo precedono il punto $punto, ma non ha superato un test relativo al
	echo "punto $punto (ossia l'ultimo test effettuato finora)."
	echo
	echo "Il test del punto $punto potrebbe essere fallito semplicemente perche'"
	echo non hai ancora implementato il punto $punto.
	echo
	echo Per poter accedere alla correzione anche del $punto,
	echo "devi prima aver implementato il punto $punto ed aver corretto"
	echo " gli errori che fanno fallire l'ultimo test."
	echo
	if ! command -v sender &> /dev/null
	then
		echo "Sono eseguito su un PC personale, non spedisco nulla."
		exit
	else
		retval=$(sender $sorgente `whoami` | grep "moved successfully")
		if ! echo $retval | grep "not"
		then
			echo Ho spedito quindi il tuo compito per la correzione.
			echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
		else
			echo Non sono riuscito a spedire il file per la correzione.
			echo Contatta il docente del corso per chiarimenti se necessario.
		fi
	fi
	echo In ogni caso, hai superato abbastanza punti da poter accedere
	echo alla correzione del compito. Ho spedito quindi il compito
	echo per la correzione. Invocami di nuovo se vuoi fare
	echo spedire una nuova versione del tuo compito.
    else
	echo
	echo Per poter accedere alla correzione del compito,
	echo "devi prima correggere gli errori che fanno fallire l'ultimo test."
	echo
	echo Quindi NON ho spedito il tuo compito per la correzione.
    fi

    echo
    echo "Scorri in alto fino all'inizio dell'ultimo test, se vuoi controllare "
    echo "di che test si tratta e qual'e' stato l'input dato al tuo programma."
    echo
    echo Per correggere gli errori, puoi provare ad eseguire il tuo programma
    echo manualmente, dando lo stesso input provato da me.
    echo
    echo Quando il tuo programma superera\' questo test, eseguiro\' anche i successivi.
    echo

    rm controlla_output* righe_da_ultima_stampa*

    exit 1
}

esegui_test ()
{
    if [ $# -le 3 ]; then
	echo Troppo pochi parametri passati alla funzione esegui_test

	exit 1
    fi

    nome_test="$1"
    punto=$2
    input_test="$3"
    num_linee_da_controllare=$4
    prima_linea_stampa="$5"

    if [ $# -le $(($num_linee_da_controllare + 3)) ]; then
	echo Troppo pochi parametri passati alla funzione esegui_test
	echo $#

	exit 1
    fi

    echo
    echo ==== Inizio test $nome_test ====
    echo
    echo Eseguo il programma fornendo il seguente input: "$input_test"
    echo

    echo Ecco l\'output del programma, in cui non vedrai l\'input:
    echo

    # il comando echo DEVE supportare l\'opzione -e
    echo -e "$input_test" | ./$eseguibile | tee output_eseguibile.txt

    if [ $num_linee_da_controllare -ne 0 ]; then
	cat output_eseguibile.txt | \
	    ./righe_da_ultima_stampa "$prima_linea_stampa" \
	    | ./controlla_output $num_linee_da_controllare \
				 "$prima_linea_stampa" \
				 "$6" "$7" "$8" "$9"
    fi

    if [ $? -ne 0 ]; then
	stampa_msg_punto_insufficiente $punto
    fi
}

# - inserire sempre la scelta di uscire dal programma a fine input
esegui_tutti_test ()
{
    esegui_test "stampa senza reinizializzazione" "" "2 7" 0

    esegui_test "reinizializzazione a vuoto senza stampa" "" "1 0 7" 0

    esegui_test "reinizializzazione a vuoto" "" "1 0 2 7" 0

    esegui_test "reinizializzazione a una domanda di una parola" "" "1 1 prova\n  prova\n prova\n prova\n 1 2 7" 4 "1. prova" "a) prova" "* b) prova" "c) prova"

    esegui_test "reinizializzazione a due domande di una parola ciascuna" "" "1 2 prova\n prova\n prova\n prova\n 1 prova\n prova\n prova\n prova\n 2 2 7" 4 "2. prova" "a) prova" "b) prova" "* c) prova"

    esegui_test "reinizializzazione a due domande di piu parole ciascuna" "" "1 2 La prova pratica\n Facile\n Difficile\n Noiosa\n 0 I docenti sottovalutano\n Falso\n Solo un po vero\n Verissimo\n 1 2 7" 4 "2. I docenti sottovalutano" "a) Falso" "* b) Solo un po vero" "c) Verissimo"

    esegui_test "doppia reinizializzazione con seconda a vuoto" "" "1 2 La prova pratica\n Facile\n Difficile\n Noiosa\n 0 I docenti sottovalutano\n Falso\n Solo un po vero\n Verissimo\n 1 2 1 0 7" 0

    esegui_test "doppia reinizializzazione con seconda a una domanda" "" "1 2 La prova pratica\n Facile\n Difficile\n Noiosa\n 0 I docenti sottovalutano\n Falso\n Solo un po vero\n Verissimo\n 1 2 1 1 prova\n prova\n prova\n prova\n 1 2 7"  4 "1. prova" "a) prova" "* b) prova" "c) prova"

    esegui_test "salvataggio" 3 "1 2 La prova pratica\n Facile\n Difficile\n Noiosa\n 0 I docenti sottovalutano\n Falso\n Solo un po vero\n Verissimo\n 1 3 2 7" 4 "2. I docenti sottovalutano" "a) Falso" "* b) Solo un po vero" "c) Verissimo"

    esegui_test "caricamento" 4 "4 2 7" 4 "2. I docenti sottovalutano" "a) Falso" "* b) Solo un po vero" "c) Verissimo"

    esegui_test "caricamento dopo reinizializzazione" 4 "1 1 La prova pratica\n Facile\n Difficile\n Noiosa\n 0 2 4 2 7" 4 "2. I docenti sottovalutano" "a) Falso" "* b) Solo un po vero" "c) Verissimo"

    esegui_test "reinizializzazione dopo caricamento" 4 "4 1 1 La prova\n Facile\n Difficile\n Noiosa\n 1 2 7" 4 "1. La prova" "a) Facile" "* b) Difficile" "c) Noiosa"

    esegui_test "fai domanda con risposta giusta" 5 "4 5 1 a 7" 1 Esatto

    esegui_test "fai domanda con risposta sbagliata" 5 "4 5 1 b 7" 1 Sbagliato

    esegui_test "fai domanda a caso" 6 "4 6 b 7" 0

    return
}

# MAIN

sorgente=$1
eseguibile=a.out

if [ "$(echo -e)" != "" ]; then
    echo "In questa shell il comando echo non rispetta l'opzione -e"
    echo "Devi eseguirmi con una shell che rispetti tale opzione"
    echo "Una tale shell e' bash"
    exit
fi

if [ "$sorgente" = "" ]; then
    echo
    echo Devi fornirmi il nome del file sorgente da collaudare.
    echo
    echo Ossia devi invocarmi cosi\':
    echo bash $0 nome_tuo_file_sorgente.cc
    echo

    exit 1
fi

g++ -Wall -Werror $sorgente

if [ $? -ne 0 ]; then
    echo
    echo Compilazione del sorgente $sorgente fallita.
    echo Questo vuol dire che il file non e\' stato trovato dal compilatore,
    echo oppure che la compilazione ha generato degli errori o delle warning.
    echo Leggi le righe che precedono questo messaggio per vedere di che
    echo errore si tratta esattamente.
    echo
    echo Il tuo sorgente NON e\' stato spedito. Il sorgente deve compilarsi
    echo senza errori per poter essere spedito per la correzione.
    echo

    exit 1
fi

if [ ! -f $eseguibile ]; then
    echo Eseguibile $eseguibile non trovato
    exit 1
fi

crea_tester

esegui_tutti_test

echo
echo Complimenti, il tuo programma ha superato tutti i test!
echo
if ! command -v sender &> /dev/null
then
    echo "Sono eseguito su un PC personale, non spedisco nulla."
    exit
else
	retval=$(sender $sorgente `whoami` | grep "moved successfully")
	if ! echo $retval | grep "not"
	then
		echo Ho spedito quindi il tuo compito per la correzione.
		echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
	else
		echo Non sono riuscito a spedire il file per la correzione.
		echo Contatta il docente del corso per chiarimenti se necessario.
	fi
fi

rm controlla_output* righe_da_ultima_stampa*
