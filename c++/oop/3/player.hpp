#include <iostream>
#include <cstring>

#include "sprite.hpp"

class Player : public Sprite {
    private:
        string nome;
    public:        
        Player(int x, int y) : Sprite(x, y){}
        void stampa();
};

void Player::stampa()
{
    cout << "<Player x=" << x << " y=" << y << ">" << endl;
}