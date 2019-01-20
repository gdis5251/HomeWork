#include "Queue.h"

void TestQueue()
{
	Queue que;
	QueueInit(&que);
	QueuePushBack(&que, 1);
	QueuePushBack(&que, 2);
	QueuePushBack(&que, 3);
	QueuePushBack(&que, 4);
	QueuePushBack(&que, 5);

	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);

}

int main(void)
{

	TestQueue();
	return 0;
}