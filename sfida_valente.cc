#include <iostream>
#include <fstream>
#include <climits>

// Vittoria sua
// neanche solo uno switch che ha nei *case* tutti gli interi rappresentabili sembra essere
// ... lontanamente realizzabile (in termini di tempo) si genera poi un file in utilizzabile dalla sua grandezza

// Forse con un linguaggio di piu "basso livello" del c++ o una macchina piu potente.. per ora.. no 

using namespace std;

int main(int argc, char** argv){
    ofstream file("main.cc");
    file << "#include <iostream>" << endl
        << endl
        << "int main(){" << endl
        << "    int n;" << endl
        << "    cin >> n;" << endl;

    for (int c=INT_MIN; c<INT_MAX; c++){
        file << "   switch(n){" << endl
            << "       case " << c << ":" << endl;
        file << "       break;" << endl;
    }

    file << "   return 0;\n}";
    file.close();
    return 0;
}
