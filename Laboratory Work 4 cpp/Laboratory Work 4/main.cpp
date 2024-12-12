#include "Queue.h"
#include "Queue.cpp"

int main(void) {
	int length = 5;
	Queue<int> exampleQueue(length);

	for (int i = 0; i < length; i += 1) { exampleQueue.m_Push(i + 1); }
	cout << "Value on top of queue: " << exampleQueue.topLayer() << endl;

	return 0;
}