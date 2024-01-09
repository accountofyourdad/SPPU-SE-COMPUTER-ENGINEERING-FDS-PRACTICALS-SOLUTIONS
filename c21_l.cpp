/*
 Write C++ program for storing appointment schedule for day.
Appointments are booked randomly using linked list. Set start
and end time and min and max duration for visit slot. Write
functions for
A) Display free slots
B) Book appointment
C) Sort list based on time
D) Cancel appointment (check validity, time bounds,
availability)
E) Sort list based on time using pointer manipulation

*/
#include <iostream>
using namespace std;
struct sll_node
{
    int start;             // start timing
    int end;               // ending timing
    int min;               // at that how many min duration
    int max;               // at that how many max duration
    int flag;              // for status of the seat
    struct sll_node *next; // for traversing to the next node
} *head;                   // pointer head pointing the struct

class app_shedule
{
    int size; // no of nodes or applications
public:
    void create_shedule();
    void display_shedule();
    void book_appointment();
    void cancel_appointment();
    void sort_appointment();
} a1; // class short form now no need to declare class obj (or one obj applicable)

int main()
{
    int ch;
    char ans;

    do
    {
        cout << "\n\n---------menu---------";
        cout << "\nenter your choice from bellow :";
        cout << "\n  1. create appointment shedule";
        cout << "\n  2. display free slot";
        cout << "\n  3. book appointment";
        cout << "\n  4. cancel an appointment";
        cout << "\n  5. sort slots based on time";
        cout << "\n  6. EXIT";
        cout << "\n--->";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a1.create_shedule();
            break;
        case 2:
            a1.display_shedule();
            break;
        case 3:
            a1.book_appointment();
            break;
        case 4:
            a1.cancel_appointment();
            break;
        case 5:
            a1.sort_appointment();
            break;
        case 6:
            exit(0);
        default:
            cout << "invalid choice";
            break;
        }
    } while (ch != 6);
}

void app_shedule ::create_shedule()
{
    int i;
    struct sll_node *temp, *last;
    head = NULL;
    cout << "how many appointmaint slots to be made : ";
    cin >> size;
    for (i = 0; i < size; i++)
    {
        temp = new sll_node;
        cout << "\n\n\t  enter start time : ";
        cin >> temp->start;
        cout << "\n\n\t  enter end time : ";
        cin >> temp->end;
        cout << "\n\n\t  enter minimum duration : ";
        cin >> temp->min;
        cout << "\n\n\t  enter minimum duration : ";
        cin >> temp->max;
        temp->flag = 0;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            last = temp;
        } //      !!!!! attention here  this else part !!!!!!
        else
        {
            last->next = temp; // as temp is the address of the newly made node
            last = last->next; // basically made temp as last but as dynamic so used last->next
        }
    }
}
void app_shedule ::display_shedule()
{
    int count = 1;         // is the count
    struct sll_node *temp; // for traversing
    temp = head;
    while (temp != NULL) // here also we need to access full list so we have to take it till temp!=null
    {
        cout << "\n\n\t " << count;
        cout << "\t " << temp->start;
        cout << "\t " << temp->end;
        cout << "\t " << temp->min;
        cout << "\t " << temp->max;
        if (temp->flag)
        {
            cout << "\t-booked-";
        }
        else
            cout << "\t--free--";
        temp = temp->next;
        count++;
    }
}
void app_shedule ::book_appointment()
{
    int start;
    struct sll_node *temp;
    temp = head;
    cout << "\n\n\t please enter apointment time : ";
    cin >> start;
    while (temp != NULL) // this not till temp->next != null as the apointment can be at the end also with no problem so
    {
        if (start == temp->start)
        {
            if (temp->flag == 0)
            {
                cout << "\n\n\t appointment slot booked ";
                temp->flag = 1;
            }
            else
                cout << "\n\n\t appointment slot not avilable ";
        }
        temp = temp->next;
    }
}
void app_shedule ::cancel_appointment()
{ // at a time two get book and at a time two ges deleted
    int start;
    struct sll_node *temp;
    temp = head;
    cout << "\n\n\t enter appointment time to cancel : ";
    cin >> start;
    while (temp != NULL) // normally we require this one not temp->next !=null
    {

        if (temp->start == start)
        {
            cout << "\n\n\t appointment slot solt canceled...";
            temp->flag = 0;
        }
        else
            cout << "\n\n\t appointment you were talking about was not booked";
        temp = temp->next;
    }
}
void app_shedule::sort_appointment()
{
    int i, j, val;
    struct sll_node *temp;
    for (i = 0; i < size; i++)
    {
        temp = head;
        while (temp->next != NULL) // as last element gets already sorted in this type of search
        {
            if (temp->start > temp->next->start) // sorting upon start of appointmaint
            {
                val = temp->start;
                temp->start = temp->next->start;
                temp->next->start = val;

                val = temp->end;
                temp->end = temp->next->end;
                temp->next->end = val;

                val = temp->min;
                temp->min = temp->next->min;
                temp->next->min = val;

                val = temp->max;
                temp->max = temp->next->max;
                temp->next->max = val;
            }
            temp = temp->next;
        }
    }
    cout << "\n\n\t appointment slot sorted ";
}