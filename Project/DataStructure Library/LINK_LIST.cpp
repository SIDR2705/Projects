#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
public:
    struct NodeS<T> *first;
    int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements of Singly Linear Linked list are : "
         << "\n";

    NodeS<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
public:
    struct NodeS<T> *first;
    struct NodeS<T> *last;
    int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout << "Elements of Singly Circular List are : "
         << "\n";
    if (first != NULL && last != NULL)
    {
        NodeS<T> *temp = first;
        do
        {
            cout << "| " << temp->data << "| -> ";
            temp = temp->next;
        } while (temp != last->next);

        cout << "\n";
    }
    else
    {
        cout << "Linked List is empty"
             << "\n";
    }
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
public:
    struct NodeD<T> *first;
    int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> *temp = first;
    cout << "Elements of Doubly Linked List are: "
         << "\n";

    cout << "NULL <=> ";
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        NodeD<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    //  int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
public:
    struct NodeD<T> *first;
    struct NodeD<T> *last;
    int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    last = NULL;
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = first;
    cout << "Elements of Doubly Circular List are: "
         << "\n";
    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout << "| " << temp->data << " | <-> ";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = last->next;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (iCount == 0) 
    {
        return;
    }
    else if (iCount == 1) 
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = first->next;
        delete last->next; // delete First->prev;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (iCount == 0) 
    {
        return;
    }
    else if (iCount == 1) 
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        last = last->prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL<int> obj1;
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55, 4);
    obj1.Display();
    cout << "Number of elements are : " << obj1.Count() << "\n";

    obj1.DeleteAtPos(4);
    obj1.Display();
    cout << "Number of elements are : " << obj1.Count() << "\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout << "Number of elements are : " << obj1.Count() << "\n";

    SinglyLL<char> obj2;

    obj2.InsertFirst('C');
    obj2.InsertFirst('B');
    obj2.InsertFirst('A');

    obj2.InsertLast('D');
    obj2.InsertLast('E');

    obj2.Display();
    cout << "Number of elements are : " << obj2.Count() << "\n";

    SinglyLL<double> obj3;

    obj3.InsertFirst(90.90);
    obj3.InsertFirst(80.80);
    obj3.InsertFirst(70.70);

    obj3.InsertLast(60.60);
    obj3.InsertLast(50.50);

    obj3.Display();
    cout << "Number of elements are : " << obj3.Count() << "\n";
    cout << "------------------------------------------------------------------------------------------------------"<< "\n";


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCL<int> obj4;
    obj4.InsertFirst(51);
    obj4.InsertFirst(21);
    obj4.InsertFirst(11);

    obj4.InsertLast(101);
    obj4.InsertLast(111);

    obj4.InsertAtPos(55, 4);
    obj4.Display();
    cout << "Number of elements are : " << obj4.Count() << "\n";

    obj4.DeleteAtPos(4);
    obj4.Display();
    cout << "Number of elements are : " << obj4.Count() << "\n";

    obj4.DeleteFirst();
    obj4.DeleteLast();

    obj4.Display();
    cout << "Number of elements are : " << obj4.Count() << "\n";

    SinglyCL<char> obj5;

    obj5.InsertFirst('C');
    obj5.InsertFirst('B');
    obj5.InsertFirst('A');

    obj5.InsertLast('D');
    obj5.InsertLast('E');

    obj5.InsertAtPos('S', 4);
    obj5.Display();
    cout << "Number of elements are : " << obj5.Count() << "\n";

    obj5.DeleteAtPos(4);
    obj5.Display();
    cout << "Number of elements are : " << obj5.Count() << "\n";

    obj5.DeleteFirst();
    obj5.DeleteLast();

    obj5.Display();
    cout << "Number of elements are : " << obj5.Count() << "\n";

    SinglyCL<double> obj6;

    obj6.InsertFirst(90.90);
    obj6.InsertFirst(80.80);
    obj6.InsertFirst(70.70);

    obj6.InsertLast(60.60);
    obj6.InsertLast(50.50);

    obj6.Display();
    cout << "Number of elements are : " << obj6.Count() << "\n";

    cout << "------------------------------------------------------------------------------------------------------"<< "\n";


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyLL<int> obj7;
    obj7.InsertFirst(51);
    obj7.InsertFirst(21);
    obj7.InsertFirst(11);

    obj7.InsertLast(101);
    obj7.InsertLast(111);

    obj7.InsertAtPos(55, 4);
    obj7.Display();
    cout << "Number of elements are : " << obj7.Count() << "\n";

    obj7.DeleteAtPos(4);
    obj7.Display();
    cout << "Number of elements are : " << obj7.Count() << "\n";

    obj7.DeleteFirst();
    obj7.DeleteLast();

    obj7.Display();
    cout << "Number of elements are : " << obj7.Count() << "\n";

    DoublyLL<char> obj8;

    obj8.InsertFirst('C');
    obj8.InsertFirst('B');
    obj8.InsertFirst('A');

    obj8.InsertLast('D');
    obj8.InsertLast('E');

    obj8.InsertAtPos('S', 4);
    obj8.Display();
    cout << "Number of elements are : " << obj8.Count() << "\n";

    obj8.DeleteAtPos(4);
    obj8.Display();
    cout << "Number of elements are : " << obj8.Count() << "\n";

    obj8.DeleteFirst();
    obj8.DeleteLast();

    obj8.Display();
    cout << "Number of elements are : " << obj8.Count() << "\n";

    DoublyLL<double> obj9;

    obj9.InsertFirst(90.90);
    obj9.InsertFirst(80.80);
    obj9.InsertFirst(70.70);

    obj9.InsertLast(60.60);
    obj9.InsertLast(50.50);

    obj9.Display();
    cout << "Number of elements are : " << obj9.Count() << "\n";
    cout << "------------------------------------------------------------------------------------------------------"<< "\n";
  
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCL<int> obj10;
    obj10.InsertFirst(51);
    obj10.InsertFirst(21);
    obj10.InsertFirst(11);

    obj10.InsertLast(101);
    obj10.InsertLast(111);

    obj10.InsertAtPos(55, 4);
    obj10.Display();
    cout << "Number of elements are : " << obj10.Count() << "\n";

    obj10.DeleteAtPos(4);
    obj10.Display();
    cout << "Number of elements are : " << obj10.Count() << "\n";

    obj10.DeleteFirst();
    obj10.DeleteLast();

    obj10.Display();
    cout << "Number of elements are : " << obj10.Count() << "\n";

    DoublyCL<char> obj11;

    obj11.InsertFirst('C');
    obj11.InsertFirst('B');
    obj11.InsertFirst('A');

    obj11.InsertLast('D');
    obj11.InsertLast('E');

    obj11.InsertAtPos('S', 4);
    obj11.Display();
    cout << "Number of elements are : " << obj11.Count() << "\n";

    obj11.DeleteAtPos(4);
    obj11.Display();
    cout << "Number of elements are : " << obj11.Count() << "\n";

    obj11.DeleteFirst();
    obj11.DeleteLast();

    obj11.Display();
    cout << "Number of elements are : " << obj11.Count() << "\n";

    DoublyCL<double> obj12;

    obj12.InsertFirst(90.90);
    obj12.InsertFirst(80.80);
    obj12.InsertFirst(70.70);

    obj12.InsertLast(60.60);
    obj12.InsertLast(50.50);

    obj12.Display();
    cout << "Number of elements are : " << obj12.Count() << "\n";

    cout << "------------------------------------------------------------------------------------------------------"<< "\n";
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
