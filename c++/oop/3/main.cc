#include <iostream>

using namespace std;

#include "player.hpp"

int main(int argc, char** argv)
{
    Player p(10, 10);
    Player p2(23, -2);

    p.stampa();
    p2.stampa();

    p.muovi(1, 1);
    p.stampa();

    return 0;
}