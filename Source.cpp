#include<iostream>
#include"Queue.h"

using namespace std;

int main()
{
	Queue<int> Q;

	for (int i=0; i<10; i++)
		Q.enQueue(i+1);

	cout << Q.Front() << endl << Q.Rear() << endl;

	Queue<int> Q2 = Q;

	cout << "Queue #2\n";
	for (int i = 0; i < 10; i++)
		cout << Q2.deQueue() << "  ";

	cout << "\nQueue #1\n";
	for (int i = 0; i < 10; i++)
		cout << Q.deQueue() << "  ";
}