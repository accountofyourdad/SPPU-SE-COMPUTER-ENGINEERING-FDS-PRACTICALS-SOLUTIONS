
/*Department of Computer Engineering has student's club named
'Pinnacle Club'. Students of second, third and final year of department
can be granted membership on request. Similarly one may cancel the
membership of club. First node is reserved for president of club and
last node is reserved for secretary of club. Write C++ program to
maintain club member‘s information using singly linked list. Store
student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.*/

#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    int prn, rollno;
    char name[50];     // array of name
    struct node *next; // pointer to the next node
};
class info
{
    node *s = NULL, *head1 = NULL, *temp1 = NULL, *head2 = NULL, *temp2 = NULL, *head = NULL, *temp = NULL;
    int b, c, i, j, ct; // initialized above(pointers)
    char a[20];

public:
    node *create();
    void insertp();
    void insertm();
    void delm();
    void delp();
    void dels();
    void display();
    void count();
    void rev(node *p);
    void concat();
};
node *info::create() // to create node again and again
{
    node *p = new (struct node); // new ptr to the struct
    cout << "enter name of student ";
    cin >> a;
    strcpy(p->name, a); // copy char array to the string
    cout << "\n  enter prn no. of student \n";
    cin >> b;
    p->prn = b;
    cout << "enter student rollno";
    cin >> c;
    p->rollno = c;
    p->next = NULL; // next is declared null as nothing further
    return p;       // return the pointer that is pointing to the node that we have created just now
}
void info::insertm() // insert member
{
    node *p = create();

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        temp = head;               // done this to not to lose the main head of the list
        while (temp->next != NULL) // till the end of the list
        {
            temp = temp->next;
        }
        temp->next = p; // now temp->next is having NULL value than is replaced with p(address of the node(next one))
    }
}
void info::insertp()
{
    node *p = create();

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        temp = head;       // changing head to the prcedent     //head reserved
        head = p;          // head given the value of the node of precedent
        head->next = temp; // given head's next the value of the previous head
    }
}

void info::display()
{
    if (head == NULL)
    {
        cout << "linklist is empty";
    }
    else
    {
        temp = head;
        cout << "     prn     rolln0    NAME   \n";
        while (temp->next != NULL)
        {
            cout << "    \n" << temp->prn << "    " << temp->rollno << "    " << temp->name;
            temp = temp->next;
        }
        cout << "    " << temp->prn << "    " << temp->rollno << "    " << temp->name;
    }
}
void info::delm()
{
    int m, f = 0;
    cout << "\n enter the prn no. of student whose data you want to delete";
    cin >> m; // which to be deleted
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->prn == m) // search for prn till last and delete it
        {
            s->next = temp->next;
            delete (temp); // delete pointer
            f = 1;         // after deleting set flag to 1 as we found that prn and deleted the node of that
        }
        s = temp;
        temp = temp->next;
    }
    if (f == 0) // if we not found i.e if the flag not set than to be executed
    {
        cout << "\n sorry memeber not deleted ";
    }
}
void info::delp()
{
    temp = head;       // reserve previous head
    head = head->next; // change the head to the next of its
    delete (temp);     // delete old head
}
void info::dels() // secretory is the person next to the head
{
    temp = head; // head reseve
    s = temp->next;
    temp->next = s->next;
    s->next = NULL; // s(temp(head))->next to be done null so that sec to be deleted(mem loc)
    delete (s);     // temp(secratery address)  will be dealocate mem loc i.e sec deleted finally
}
void info::count()
{
    temp = head;
    ct = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        ct++; // counter to how many time whle has run that much member
    }
    ct++; // last one with null also to be included
    cout << "  Count of members is:" << ct;
}

void info::concat()
{
    if (head != NULL)
    {
        int j;
        cout << "enter no. of members in list2";
        cin >> j;
        head1 = create();
        temp1 = head1;
        for (int i = 0; i < j - 1; i++)
        {
            temp1->next = create();
            temp1 = temp1->next;
        }
        temp1->next = NULL;

        // concadination

        temp = head;
        temp1 = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        } // now here temp->next will be null
        temp->next = temp1;
        display();
    }
    else
    {
        cout<<'\n !!! create list from the main menu than use this choice !!!';
    }
}
int main()
{
    info s;
    int i;

    char ch;
    do
    {
        cout << "\n choice the options";
        cout << "\n  1. To insert president   ";
        cout << "\n  2. To insert member   ";
        cout << "\n  3. To insert secretary ";
        cout << "\n  4. To delete president   ";
        cout << "\n  5. To delete member  ";
        cout << "\n  6. To delete secretary ";
        cout << "\n  7. To display data   ";
        cout << "\n  8. Count of members";
        cout << "\n  9.To concatenate two lists (for this first create a list from up than use this choice)";
        cout << "\n -->";
        cin >> i;
        switch (i)
        {
        case 1:
            s.insertp();
            break;
        case 2:
            s.insertm();
            break;
        case 3:
            s.insertm();
            break;
        case 4:
            s.delp();
            break;
        case 5:
            s.delm();
            break;
        case 6:
            s.dels();
            break;
        case 7:
            s.display();
            break;
        case 8:
            s.count();
            break;
        case 9:
            s.concat();
            break;
        default:
            cout << "\n unknown choice";
        }
        cout << "\n do you want to continue enter y/Y \n";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}