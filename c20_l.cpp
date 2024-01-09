#include <iostream>
#include <stdlib.h>
using namespace std;
class node
{
public:
    node *next; // creation of doubly linked list
    node *prev;
    int seat;
    string id;
    int status;
};
class cinemax
{
public:
    node *head, *tail, *temp; // pointers declared to the class node
    cinemax()
    {
        head = NULL; // pointer pointing to null as initialy list is empty i.e no node to point
    }
    void create_list();
    void display();
    void book();
    void cancel();
    void avail();
};
void cinemax::create_list()
{
    int i = 1;
    temp = new node;  // creation of forst node       //pointer of list (temp) has given new mem loc for a node of list so that head will point to it after words
    temp->seat = 1;   // seat is the seat number         //temp will have access to every datatype in class node and can be accessed by using ->
    temp->status = 0; // status = 0 means not booked
    temp->id = "null";
    tail = head = temp; // pointers will be at the same node as first node
    for (int i = 2; i <= 70; i++)
    {
        node *p;      // creating more nodes
        p = new node; // alocation of memory   to the node
        p->seat = i;
        p->status = 0;
        p->id = "null"; // don't care sbout id its just like our roll.no here for initialization we nave initialize it to null
        tail->next = p; // pointing pointer tail of the list to new node p          //tail's next given p but tail still prevous node
        p->prev = tail; // updating current node with the prevoius node             //so p's prev is given tails address
        tail = p;       // updating new taail of the list                           //after geting all info from tail tail is updated
        tail->next = head;
        head->prev = tail;
    }
}
void cinemax::display()
{
    {
        node *temp; // temp for transversing th list so that head should not be lost or else whole list will get vanished
        temp = head;
        int count = 0;
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "                               Screen this way" << endl;
        cout << "------------------------------------------------------------------------------------\n";
        while (temp->next != head)
        {
            if (temp->seat / 10 == 0) // checks the ans is equal to zero i.e questent i.e for numbers less than 10
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";
            if (temp->status == 0) // if not booked
                cout << "|___| ";
            else
                cout << "|_B_| ";
            count++;            // seats to be in next row if more than 7
            if (count % 7 == 0) // for 7 seats in a row
            {
                cout << endl; // go in next row in thetare
            }
            temp = temp->next;
        }
    }
}
void cinemax::book()
{
    int x;
    string y;
label: // when this called code agin start from here
    cout << "\n\n\nEnter seat number to be booked\n";
    cin >> x;
    cout << "Enter your ID number\n";
    cin >> y;
    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to book (1-70)\n";
        goto label; // will go to label
    }
    node *temp;
    temp = new node;
    temp = head; // given the address that is in head to temp pointer
    while (temp->seat != x)
    {
        temp = temp->next;
    }
    if (temp->status == 1) // for one line if statement we dont use bracket next line is considered
        cout << "Seat already booked!\n";
    else
    {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked!\n";
    }
}
void cinemax::cancel()
{
    int x;
    string y;
label1:
    cout << "Enter seat number to cancel booking\n";
    cin >> x;
    cout << "Enter you ID\n";
    cin >> y;
    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to cancel (1-70)\n";
        goto label1; // goes up to label1
    }
    node *temp;
    temp = new node;
    temp = head;
    while (temp->seat != x)
    {
        temp = temp->next;
    }
    if (temp->status == 0)
    {
        cout << "Seat not booked yet!!\n";
    }
    else
    {
        if (temp->id == y)
        {
            temp->status = 0;
            cout << "Seat Cancelled!\n";
        }
        else
            cout << "Wrong User ID !!! Seat cannot be cancelled!!!\n";
    }
}
void cinemax::avail() // shows avilable seats
{
    int r = 1;
    node *temp;
    temp = head;
    int count = 0;
    cout << "\n\n\n\n";
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "                                  Screen this way \n";
    cout << "------------------------------------------------------------------------------------\n";
    while (temp->next != head)
    {
        {
            if (temp->seat / 10 == 0)
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";
            if (temp->status == 0)
                cout << "|___| ";
            else if (temp->status == 1)
                cout << "-x-   ";
            count++;
            if (count % 7 == 0)
            {
                cout << endl;
            }
        }
        temp = temp->next;
    }
}
int main()
{
    cinemax obj;
    obj.create_list();
    int ch;
    char c = 'y';
    while (c == 'y')
    {
        obj.display();
        cout << "\n*********************************************\n";
        cout << "            CINEMAX MOVIE THEATRE\n";
        cout << "*********************************************\n";
        cout << "\nEnter Choice\n1.Current SeatStatus\n2.Book Seat \n3.Available Seat\n4.CancelSeat\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.display();
            break;
        case 2:
            obj.book();
            break;
        case 3:
            obj.avail();
            break;
        case 4:
            obj.cancel();
            break;
        default:
            cout << "Wrong choice input\n";
        }
        cout << "\nDo you want to perform any other operation : (y/n)\n";
        cin >> c;
    }
    return 0;
}