
/*
Pizza parlor accepting maximum M orders.
Orders are served in first come first served basis. Order once placed can not be cancelled.
Write C++ program to simulate the system using circular queue using array.
*/

#include <iostream>
#include <cstdlib>
#define size 5
using namespace std;

class pizza
{
    int front, rear, q[size]; // arrey of queue q[size]

public:
    pizza()
    {
        front = -1; // initalize yo one less than zero so that by incrementing we can get 0 position and the job will be easy
        rear = -1;
    }
    int isfull()
    {

        if ((front == 0 && rear == size - 1) || front == rear + 1)      //circular LL so here front == rear+1 when full
        {
            return 1; // this means the que ue is full
        }
        else
        {
            return 0;
        }
    }
    int isempty()
    {
        if (front == -1 && rear == -1) // if both of them are -1 that means the arrey(queue is empty)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void add()
    {
        if (isfull() == 0)
        {
            cout << "\n Enter the Pizza ID: ";
            if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                cin >> q[rear];
            }
            else
            {
                rear = (rear + 1) % size;
                cin >> q[rear];
            }
            char c;
            cout << " Do you want to add another order ? ";
            cin >> c;
            if (c == 'y' || c == 'Y')
                add();
        }
        else
        {
            cout << "\n Orders are full ";
        }
    }
    void serve()
    {
        if (isempty() == 0)
        {
            if (front == rear)
            {
                cout << "\n Order served is : " << q[front];
                front = -1; // order served so deleted order i.e mage one less han zero
                rear = -1;
            }
            else
            {
                cout << "\n Order served is : " << q[front];
                front = (front + 1) % size; // incremented as before one has been served so. as befor to add order we done front++ so here thet to delete order
            }
        }
        else
        {
            cout << "\n Orders are empty ";
        }
    }
    void display()
    {
        if (isempty() == 0) // that means is not empty
        {
            for (int i = front; i != rear; i = (i + 1) % size)      // i = (i + 1) % size    as above also we have done this to increment counter i
            {
                cout << q[i] << "< -";
            }
            cout << q[rear];            //rear to be displayed differnt 
        }
        else
        {
            cout << "\n Orders are empty";
        }
    }
    void check()
    {
        int ch;
        cout << "\n\n * * * * PIZZA PARLOUR * * * * \n\n";
        cout << "\n 1. Add a Pizza \n 2. Display the Orders \n 3. Serve a pizza \n 4. Exit \n Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:

            display();
            break;

        case 3:

            serve();
            break;

        case 4:

            exit(0);

        default:
            cout << "Invalid choice ";

            check();
        }
        char ch1;
        cout << "\n Do you want to continue? ";
        cin >> ch1;
        if (ch1 == 'y' || ch1 == 'Y')
            check();
    }
};
int main()
{
    pizza p1;
    p1.check();
    return 0;
}