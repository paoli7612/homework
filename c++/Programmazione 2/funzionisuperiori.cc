#include <iostream>

using namespace std;

int map(int (*fun)(const int*, const int), const int* array, const int len)
{
	return fun(array, len);
}

int sum(const int* array, const int len)
{
	int s = 0;
	for (int i=0; i<len; i++)
		s += array[i];
	return s;
}

int prod(const int* array, const int len)
{
	int s = 1;
	for (int i=0; i<len; i++)
		s *= array[i];
	return s;
}

int main(int argc, char **argv)
{
	int a[] = {1, 2, 3, 4};

	cout << map(sum, a, 4) << endl;
	cout << map(prod, a, 4) << endl;


	return 0;
}
