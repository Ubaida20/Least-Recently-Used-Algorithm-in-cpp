#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int hit = 0, miss = 0, count = 1;
class cache
{
private:
    struct node
    {
        int data;
        struct node *next; // Pointer to next node in DLL
        struct node *prev; // Pointer to previous node in DLL
    } * head;

public:
    cache()
    {
        head = NULL;
    }
    bool empty() // when tack is empty
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void shift_mf(int x)
    {
        int repeat;
        node *ptr;
        ptr = head;
        if (!empty())
        {
            if (head->data == x) // if first block is required
            {
                repeat = head->data;
                head->next->prev = NULL;
                head = head->next;
                cout << "You Shifted '" << ptr->data << "' Block" << endl;
                delete ptr;
            }
            else // if not first
            {
                node *ptr = head;
                node *preptr = NULL;
                while (ptr->data != x)
                {
                    preptr = ptr;
                    ptr = ptr->next;
                }
                repeat = ptr->data;
                preptr->next = ptr->next;
                if (ptr->next != NULL) // if not the last block
                {
                    ptr->next->prev = preptr;
                }
                cout << "You Shifted '" << ptr->data << "' Block" << endl;
                delete ptr;
            }
            node *mr = new node;
            mr->next = NULL;
            node *last;
            last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            mr->data = repeat;
            last->next = mr;
            mr->prev = last;
        }
    }
    void insert(int capacity) // function to insert block in cache { //to keep record of Blocks and where cache full node *ptr;
        int repeat,
        value; // repeat to hold frequent block value,value is to take value from user ptr=new node;
    ptr->next = NULL;
    string ch;
    cout << "Please Enter the Value of Cache Block" << endl;
    cin >> value;
    if (empty()) // if empty cache
    {
        ptr->data = value;
        head = ptr;
        ptr->prev = NULL;
        cout << "You Inserted : " << ptr->data << endl
             << endl; // insertion
        count++;
        miss++; // miss when not present in cache
    }
    else
    { // if not epmty,then check for the same/repeated block
        node *check;
        check = head;
        bool present = false;
        if (empty())
        {
            present = false;
        }
        else
        {
            while (check != NULL) // check till end if not empty
            {
                if (check->data == value)
                {
                    present = true;
                    repeat = check->data;
                }
                check = check->next;
            }
        }
        if (present == true)
        {
            if (head->next == NULL)
            {
                hit++;
            }
            else if (count <= capacity || count >= capacity)
            {
                shift_mf(repeat);
                hit++; // hit when present in cache
            }
        }
        if (present == false)
        {
            if (capacity < count) // if greater then capacity,removes first
            {
                node *first;
                first = head;
                head = first->next;
                head->prev = NULL;
                first->next = NULL;
                delete first;
            }
            node *nw = new node; // insert block at end and miss increments
            nw->next = NULL;
            node *last;
            last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = nw;
            nw->prev = last;
            nw->data = value; // insertion
            count++;
            cout << "You Inserted : " << nw->data << endl
                 << endl;
            miss++;
        }
    }
    cout << "\t\tNO OF Misses : \t" << miss << "\n\t\tNO OF Hits : \t" << hit << endl;
} void display() // function to display cache blocks
{
    if (empty())
    {
        cout << "Your Cache has no Block" << endl;
    }
    else
    {
        node *ptr;
        ptr = head;
        cout << "Your Cache has :" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
    }
    cout << endl
         << endl;
};
int _tmain(int argc, _TCHAR *argv[])
{
    cache c;
    int cap, ch;
    cout << " LEAST RECENTLY USED(LRU) CACHE REPLACEMENT ALGORITHM" << endl;
    cout << "______________________________________________________________________________ _____" << endl;
    cout << "Enter the Capacity of Blocks in Your Cache" << endl;
    cin >> cap;
    do
    {
        cout << "1 \tPress '1' to get Required Block \n2. \tPress '2' to Display Cache Content \n3. \tPress '3' to  Exit\n"
             << endl;
        cout << "Please Enter Your Choice in Number 1-3" << endl;
        cin >> ch;
        if (ch == 1)
        {
            system("CLS");
            c.insert(cap);
        }
        if (ch == 2)
        {
            system("CLS");
            c.display();
        }
        if (ch == 3)
        {
            system("CLS");
            cout << "\n\n\n\n\n\n\n......................*THANK YOU*......................\n\n\n\n\n\n"
                 << endl;
        }
        if (ch != 1 && ch != 2 && ch != 3)
        {
            system("CLS");
            cout << "ERROR! Please Enter Valid Number" << endl;
        }
    } while (ch != 3);
    cout << endl;
    system("pause");
    return 0;
}
