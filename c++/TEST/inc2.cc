#include <iostream>

using namespace std;

main()
{
for (int i = 1 ; i < 3 ; i++)
 for (int j = i ; j < 4 ; j++) {
 cout<<i<<" "<<j<<" " ;
 if (j % 2 == 0)
 j++ ;
 }
}

struct simone_t {
	int a;
};

int main(int argc, char** argv){
	simone_t a;
	a.a;
	return 0;
}

