

class Sprite {
    protected:
        int x, y;

    public:
        Sprite(int, int);
        void muovi(int, int);
};

Sprite::Sprite(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Sprite::muovi(int dx, int dy)
{
    x += dx;
    y += dy;
}

