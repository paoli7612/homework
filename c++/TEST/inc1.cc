// fun(vettore di interi v) ritorna un vettore r tale che
	// l'ultimo elemento di r = ultimo elemento di v
	//r contiene solo gli elementi di v <= al ultimo elemento del vettore (r o v)
	
#include <iostream>

using namespace std;

int* fun(const int vector[], int &dim){
	
	int* result = new int[dim];
	int index = 0;
	
	for (int i=0; i<dim-1; i++)
		if (vector[i] <= vector[dim-1])
			result[index++] = vector[i];
			
	dim = index;
	
	return result;
}

int main(){

	int dim = 10;
	int vector[dim] = {1, 6, 4, 7, 3, 4, 6, 10, 9, 4};
	
	int* vector = fun(vector, dim);
	
	for (int i=0; i<dim; i++)
		cout << r[i] << " ";
		
	return 0;
}	



