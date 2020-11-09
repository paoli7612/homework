#include <iostream>

using namespace std;

bool is_primo(int n){
    for (int i=2; (i*i)<n; i++)
        if ((n%i) == 0)
            return false;

    return true;
}


int main()
{   
    int n = 1000000;
    int g = 0;
    for (int i=2; i<n; i++){
        if (is_primo(i))
            g++;
        if (i%100 == 0){
            switch(g%10){
            case 1:cout <<"\033[1;31m" << "O" << "\033[0m";
            case 2:cout <<"\033[1;32m" << "O" << "\033[0m";
            case 3:cout <<"\033[1;33m" << "O" << "\033[0m";
            case 4:cout <<"\033[1;34m" << "O" << "\033[0m";
            case 5:cout <<"\033[1;35m" << "O" << "\033[0m";
            case 6:cout <<"\033[1;36m" << "O" << "\033[0m";
            case 7:cout <<"\033[1;37m" << "O" << "\033[0m";
            case 8:cout <<"\033[1;38m" << "O" << "\033[0m";
            case 9:cout <<"\033[1;39m" << "O" << "\033[0m";
            default:cout <<"\033[1;30m" << "O" << "\033[0m";
            }
            g = 0;
        }
    }
    return 0;
}