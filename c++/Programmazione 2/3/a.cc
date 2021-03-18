#include <iostream>
#include <cstring>

using namespace std;

struct node_t {
	int value;
	node_t *next;
};

int main() {

	node_t* head = NULL;

	head = new node_t;
	head->value = 1;
	head->next = new node_t;
	head->next->value = 2;
	head->next->next = head;

	node_t* node = head;
	while (true)
	{
		cout << node->value << endl;
		node = node->next;
		char i;
		cin >> i;
	}

	return 0;
}