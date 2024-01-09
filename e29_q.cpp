/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include <iostream>
#define MAX 10 // queue length(MAX) declared in global scope
using namespace std;
struct queue
{
	int data[MAX]; // arey made i.e queue using arrey
	int front, rear;
};
class Queue
{
	struct queue q;

public:
	Queue() { q.front = q.rear = -1; } // when the queue is in empty condition
	int isempty();
	int isfull();
	void enqueue(int);
	int delqueue();
	void display();
};
int Queue::isempty()
{										// here front =rear at initial as only rear incremented
	return (q.front == q.rear) ? 1 : 0; // if condition defined in differnt way      return 1 if true else 0
}
int Queue::isfull()
{
	return (q.rear == MAX - 1) ? 1 : 0; // sees if the rear has value one less than MAX as (numbering start from zero)
}
void Queue::enqueue(int x)
{							// basically add element to the rear of arrey by incrementing rear
	q.data[++(q.rear)] = x; // Enqueue: Adds an item from the back of the queue.
}
int Queue::delqueue()
{								// incrementing front pointer so that the first element will get neglected and out objective will be successful
	return q.data[++(q.front)]; // Dequeue: Removes an item from the front of the queue
}
void Queue::display()
{
	int i;
	cout << "\n";							// front will always be one less than the starting
	for (i = q.front + 1; i <= q.rear; i++) // for i < q.rear the last element get skip , for i = q.front our input option will be displayed
		cout << "\t" << q.data[i];
}
int main()
{
	Queue obj;
	int ch, x;
	do
	{
		cout << "\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
		cin >> ch;
		switch (ch) // case n:   to    case n+1:     considered as case n
		{
		case 1:
			if (!obj.isfull())
			{
				cout << "\n Enter data : \n";
				cin >> x;
				obj.enqueue(x);
				cout << endl;
			}
			else
				cout << "Queue is overflow!!!\n\n";
			break;
		case 2:
			if (!obj.isempty())
				cout << "\n Deleted Element = " << obj.delqueue() << endl;
			else
			{
				cout << "\n Queue is underflow!!!\n\n";
			}
			cout << "\nRemaining Jobs : \n";
			obj.display();
			break;
		case 3:
			if (!obj.isempty())
			{
				cout << "\n Queue contains : \n";
				obj.display();
			}
			else
				cout << "\n Queue is empty!!!\n\n";
			break;
		case 4:
			cout << "\n Exiting Program...";
		}
	} while (0 < ch && ch < 4);
	return 0;
}
