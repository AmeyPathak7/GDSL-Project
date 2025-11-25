#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
// Class        : QueueX
// Description  : Generic Implementation of Queue
// Author       : Ameya R Pathak
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
private:
    struct Queuenode<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: QueueX
    // Description  : Initializes an empty queue
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    QueueX()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Enqueue
    // Description  : Inserts a new element at the end of the queue
    // Input        : T no - The data to insert
    // Output       : None (Modifies the queue by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Enqueue(T no);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Dequeue
    // Description  : Removes and returns the first element from the queue
    // Input        : None
    // Output       : T - The data of the removed node, or NULL if queue is empty
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    T Dequeue();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the queue
    // Input        : None
    // Output       : None (Prints queue elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the queue
    // Input        : None
    // Output       : int - The number of nodes in the queue
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();
};

template <class T>
void QueueX<T>::Enqueue(T no)
{
    struct Queuenode<T> *newn = NULL;
    struct Queuenode<T> *temp = NULL;

    newn = new struct Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T QueueX<T>::Dequeue()
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if (first == NULL)
    {
        cout << "Unable to remove as Queue is Empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;
        first = first->next;
        delete temp;
        iCount--;
        return value;
    }
}

template <class T>
void QueueX<T>::Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        cout << " | " << temp->data << " | - ";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int QueueX<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
// Class        : StackX
// Description  : Generic Implementation of Stack
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template <class T>
class StackX
{
private:
    struct Stacknode<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: StackX
    // Description  : Initializes an empty stack
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    StackX()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: push
    // Description  : Pushes a new element onto the top of the stack
    // Input        : T no - The data to push
    // Output       : None (Modifies the stack by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void push(T no);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: pop
    // Description  : Removes and returns the top element from the stack
    // Input        : None
    // Output       : T - The data of the removed node, or -1 if stack is empty
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    T pop();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the stack
    // Input        : None
    // Output       : None (Prints stack elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the stack
    // Input        : None
    // Output       : int - The number of nodes in the stack
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();
};

template <class T>
void StackX<T>::push(T no)
{
    struct Stacknode<T> *newn = NULL;

    newn = new struct Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template <class T>
T StackX<T>::pop()
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if (first == NULL)
    {
        cout << "Stack is Empty\n";
        return -1;
    }
    else
    {
        temp = first;
        value = temp->data;
        first = first->next;
        delete temp;
        iCount--;
        return value;
    }
}

template <class T>
void StackX<T>::Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        cout << " | " << temp->data << " | " << "\n";
        temp = temp->next;
    }
}

template <class T>
int StackX<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
// Class        : SinglyCLL
// Description  : Generic Implementation of Singly Circular LinkedList
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    struct SinglyCLLnode<T> *next;
    T data;
};

template <class T>
class SinglyCLL
{
private:
    struct SinglyCLLnode<T> *first;
    struct SinglyCLLnode<T> *last;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: SinglyCLL
    // Description  : Initializes an empty singly circular linked list
    // Input        : None
    // Output       : None (Initializes first and last to NULL, iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    SinglyCLL();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Insertfirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Insertfirst(T no);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T no);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertAtPos
    // Description  : Inserts a new node at the specified position
    // Input        : T no - The data to insert, int pos - Position to insert at
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertAtPos(T no, int pos);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteFirst
    // Description  : Removes the first node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the first node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteFirst();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteLast
    // Description  : Removes the last node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the last node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteLast();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteAtPos
    // Description  : Removes the node at the specified position
    // Input        : int pos - Position to delete from
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteAtPos(int pos);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;

    cout << "Inside Constructor of SinglyCLL" << "\n";
}

template <class T>
void SinglyCLL<T>::Insertfirst(T no)
{
    struct SinglyCLLnode<T> *newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> *newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> *temp = NULL;
    struct SinglyCLLnode<T> *newn = NULL;

    int i = 0;

    if (pos < 1 || pos > iCount + 1)
    {
        return;
    }
    else if (pos == 1)
    {
        Insertfirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
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
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> *temp = NULL;
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
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
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> *temp = NULL;
    struct SinglyCLLnode<T> *target = NULL;
    int i;
    if (pos < 1 || pos > iCount)
    {
        return;
    }
    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::Display()
{
    struct SinglyCLLnode<T> *temp;
    if (first == NULL && last == NULL)
    {
        return;
    }

    temp = first;

    do
    {
        cout << "| " << temp->data << " | ->";
        temp = temp->next;
    } while (temp != last->next);

    cout << "\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
// Class        : DoublyCLL
// Description  : Generic Implementation of Doubly Circular LinkedList
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *prev;
    struct DoublyCLLnode<T> *next;
};

template <class T>
class DoublyCLL
{
private:
    struct DoublyCLLnode<T> *first;
    struct DoublyCLLnode<T> *last;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: DoublyCLL
    // Description  : Initializes an empty doubly circular linked list
    // Input        : None
    // Output       : None (Initializes first and last to NULL, iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    DoublyCLL();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the doubly circular linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertAtPos
    // Description  : Inserts a new node at the specified position
    // Input        : T no - The data to insert, int pos - Position to insert at
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertAtPos(T, int);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteFirst
    // Description  : Removes the first node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the first node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteFirst();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteLast
    // Description  : Removes the last node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the last node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteLast();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteAtPos
    // Description  : Removes the node at the specified position
    // Input        : int pos - Position to delete from
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteAtPos(int);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;

    cout << "Inside Constructor" << "\n";
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DoublyCLLnode<T> *newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

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
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> *temp = NULL;
    cout << "Elements of the LinkedList are : \n";

    temp = first;

    if (first == NULL && last == NULL)
    {
        cout << "The LinkedList is Empty \n";
        return;
    }
    do
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    } while (temp != first);
    cout << "\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    DoublyCLLnode<T> *newn = NULL;

    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>;

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        temp = first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
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
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
// Class        : SinglyLL
// Description  : Generic Implementation of Singly Linear LinkedList
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
private:
    struct SinglyLLnode<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: SinglyLL
    // Description  : Initializes an empty singly linear linked list
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    SinglyLL();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the singly linear linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertAtPOs
    // Description  : Inserts a new node at the specified position
    // Input        : T no - The data to insert, int pos - Position to insert at
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertAtPOs(T, int);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteFirst
    // Description  : Removes the first node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the first node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteFirst();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteLast
    // Description  : Removes the last node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the last node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteLast();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteAtPos
    // Description  : Removes the node at the specified position
    // Input        : int pos - Position to delete from
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct SinglyLLnode<T> *temp = NULL;
    temp = first;

    while (temp != NULL)
    {
        printf(" | %d | -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct SinglyLLnode<T> *newn = NULL;

    newn = new struct SinglyLLnode<T>;

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
    struct SinglyLLnode<T> *newn = NULL;
    struct SinglyLLnode<T> *temp = NULL;

    temp = first;

    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPOs(T no, int pos)
{
    struct SinglyLLnode<T> *temp = NULL;
    struct SinglyLLnode<T> *newn = NULL;
    int iCnt = 0;

    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    temp = first;

    if (pos < 1 || pos > iCount + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct SinglyLLnode<T> *temp = NULL;

    temp = first;

    if (first == NULL)
    {
        printf("The LinkedList is Empty !!\n");
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        iCount--;
    }
    else
    {
        first = first->next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct SinglyLLnode<T> *temp = NULL;

    temp = first;

    if (first == NULL)
    {
        printf("The LinkedList is Empty !!\n");
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        iCount--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    struct SinglyLLnode<T> *temp = NULL;
    struct SinglyLLnode<T> *target = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
// Class        : DoublyLL
// Description  : Generic Implementation of Doubly Linear LinkedList
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyLLnode
{
    T data;
    DoublyLLnode<T> *next;
    DoublyLLnode<T> *prev;
};

template <class T>
class DoublyLL
{
private:
    DoublyLLnode<T> *first;
    DoublyLLnode<T> *last;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: DoublyLL
    // Description  : Initializes an empty doubly linear linked list
    // Input        : None
    // Output       : None (Initializes first and last to NULL, iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    DoublyLL();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ~DoublyLL
    // Description  : Deallocates all nodes in the doubly linear linked list
    // Input        : None
    // Output       : None (Frees memory and sets first, last to NULL, iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ~DoublyLL();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T No - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T No - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertAtPos
    // Description  : Inserts a new node at the specified position
    // Input        : T No - The data to insert, int pos - Position to insert at
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertAtPos(T, int);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteFirst
    // Description  : Removes the first node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the first node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteFirst();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteLast
    // Description  : Removes the last node from the list
    // Input        : None
    // Output       : None (Modifies the list by removing the last node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteLast();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DeleteAtPos
    // Description  : Removes the node at the specified position
    // Input        : int pos - Position to delete from
    // Output       : None (Modifies the list if position is valid)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DeleteAtPos(int);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the doubly linear linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
    while (first != NULL)
    {
        DoublyLLnode<T> *temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    DoublyLLnode<T> *newn = new DoublyLLnode<T>(No);

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
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    DoublyLLnode<T> *newn = new DoublyLLnode<T>(No);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int pos)
{
    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        DoublyLLnode<T> *newn = new DoublyLLnode<T>(No);
        DoublyLLnode<T> *temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        DoublyLLnode<T> *temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        DoublyLLnode<T> *temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        DoublyLLnode<T> *temp = first;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        DoublyLLnode<T> *target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    cout << "NULL <-> ";
    DoublyLLnode<T> *temp = first;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
// Class        : BST
// Description  : Generic Implementation of Binary Search Tree
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *lChild;
    struct BSTnode<T> *rChild;
    BSTnode(T val) : data(val), lChild(NULL), rChild(NULL) {} // Constructor
};

template <class T>
class BST
{
private:
    BSTnode<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: BST
    // Description  : Initializes an empty binary search tree
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    BST();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ~BST
    // Description  : Deallocates all nodes in the binary search tree
    // Input        : None
    // Output       : None (Frees memory and sets first to NULL, iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ~BST();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Insert
    // Description  : Inserts a new node with the given data into the BST
    // Input        : T No - The data to insert
    // Output       : None (Modifies the tree by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Insert(T No);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Inorder
    // Description  : Performs an inorder traversal of the BST
    // Input        : None
    // Output       : None (Prints tree elements in inorder to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Inorder();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Preorder
    // Description  : Performs a preorder traversal of the BST
    // Input        : None
    // Output       : None (Prints tree elements in preorder to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Preorder();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Postorder
    // Description  : Performs a postorder traversal of the BST
    // Input        : None
    // Output       : None (Prints tree elements in postorder to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Postorder();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Search
    // Description  : Searches for a given value in the BST
    // Input        : T No - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool Search(T No);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of nodes in the BST
    // Input        : None
    // Output       : int - The number of nodes in the tree
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CountLeafNodes
    // Description  : Returns the number of leaf nodes in the BST
    // Input        : None
    // Output       : int - The number of leaf nodes in the tree
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int CountLeafNodes();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CountParentNodes
    // Description  : Returns the number of parent nodes in the BST
    // Input        : None
    // Output       : int - The number of parent nodes in the tree
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int CountParentNodes();
};

template <class T>
BST<T>::BST()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
BST<T>::~BST()
{
    if (first != NULL)
    {
        BST<T> leftTree;
        leftTree.first = first->lChild;
        BST<T> rightTree;
        rightTree.first = first->rChild;
        delete first;
        first = NULL;
        leftTree.~BST();
        rightTree.~BST();
    }
    iCount = 0;
}

template <class T>
void BST<T>::Insert(T No)
{
    BSTnode<T> *newn = new BSTnode<T>(No);

    if (first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        BSTnode<T> *temp = first;

        while (true)
        {
            if (No == temp->data)
            {
                cout << "Duplicate Element: Unable to insert Node\n";
                delete newn;
                break;
            }
            else if (No > temp->data)
            {
                if (temp->rChild == NULL)
                {
                    temp->rChild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rChild;
            }
            else
            {
                if (temp->lChild == NULL)
                {
                    temp->lChild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lChild;
            }
        }
    }
}

template <class T>
void BST<T>::Inorder()
{
    if (first != NULL)
    {
        BST<T> leftTree;
        leftTree.first = first->lChild;
        leftTree.Inorder();
        cout << first->data << "\t";
        BST<T> rightTree;
        rightTree.first = first->rChild;
        rightTree.Inorder();
    }
    cout << "\n";
}

template <class T>
void BST<T>::Preorder()
{
    if (first != NULL)
    {
        cout << first->data << "\t";
        BST<T> leftTree;
        leftTree.first = first->lChild;
        leftTree.Preorder();
        BST<T> rightTree;
        rightTree.first = first->rChild;
        rightTree.Preorder();
    }
    cout << "\n";
}

template <class T>
void BST<T>::Postorder()
{
    if (first != NULL)
    {
        BST<T> leftTree;
        leftTree.first = first->lChild;
        leftTree.Postorder();
        BST<T> rightTree;
        rightTree.first = first->rChild;
        rightTree.Postorder();
        cout << first->data << "\t";
    }
    cout << "\n";
}

template <class T>
bool BST<T>::Search(T No)
{
    BSTnode<T> *temp = first;
    int TimeComplexity = 0;
    bool bFlag = false;

    while (temp != NULL)
    {
        TimeComplexity++;
        if (No == temp->data)
        {
            bFlag = true;
            break;
        }
        else if (No > temp->data)
        {
            temp = temp->rChild;
        }
        else
        {
            temp = temp->lChild;
        }
    }

    cout << "Time Complexity of Search is: " << TimeComplexity << "\n";
    return bFlag;
}

template <class T>
int BST<T>::Count()
{
    return iCount;
}

template <class T>
int BST<T>::CountLeafNodes()
{
    if (first == NULL)
    {
        return 0;
    }
    if (first->lChild == NULL && first->rChild == NULL)
    {
        return 1;
    }
    BST<T> leftTree;
    leftTree.first = first->lChild;
    BST<T> rightTree;
    rightTree.first = first->rChild;
    return leftTree.CountLeafNodes() + rightTree.CountLeafNodes();
}

template <class T>
int BST<T>::CountParentNodes()
{
    if (first == NULL)
    {
        return 0;
    }
    BST<T> leftTree;
    leftTree.first = first->lChild;
    BST<T> rightTree;
    rightTree.first = first->rChild;
    int leftCount = leftTree.CountParentNodes();
    int rightCount = rightTree.CountParentNodes();
    if (first->lChild != NULL || first->rChild != NULL)
    {
        return 1 + leftCount + rightCount;
    }
    return leftCount + rightCount;
}

///////////////////////////////////////////////////////////////////////
// Class        : ArrayX
// Description  : Generic Implementation of Sorting Algorithms
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
public:
    T *Arr;
    int iSize;
    bool Sorted;

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ArrayX
    // Description  : Initializes an array of specified size
    // Input        : T no - The size of the array
    // Output       : None (Initializes array and sets Sorted to true)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ArrayX(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ~ArrayX
    // Description  : Deallocates the array
    // Input        : None
    // Output       : None (Frees array memory)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ~ArrayX();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Accept
    // Description  : Accepts elements from the user into the array
    // Input        : None
    // Output       : None (Fills array with user input and updates Sorted flag)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Accept();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the array
    // Input        : None
    // Output       : None (Prints array elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BubbleSort
    // Description  : Sorts the array using bubble sort algorithm
    // Input        : None
    // Output       : None (Sorts the array in ascending order)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void BubbleSort();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BubbleSortEfficient
    // Description  : Sorts the array using an optimized bubble sort algorithm
    // Input        : None
    // Output       : None (Sorts the array in ascending order)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void BubbleSortEfficient();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: SelectionSort
    // Description  : Sorts the array using selection sort algorithm
    // Input        : None
    // Output       : None (Sorts the array in ascending order)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void SelectionSort();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertionSort
    // Description  : Sorts the array using insertion sort algorithm
    // Input        : None
    // Output       : None (Sorts the array in ascending order)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(T no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    cout << "Enter " << iSize << " Elements : \n";

    int i = 0;
    for (i = 0; i < iSize; i++)
    {
        cout << "Enter the Element no : " << i + 1 << "\n";
        cin >> Arr[i];

        if (i > 0 && Sorted == true)
        {
            if (Arr[i] < Arr[i - 1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void ArrayX<T>::Display()
{
    cout << "Elements of the Array are : \n";

    int i = 0;
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << "\n";
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    if (Sorted == true)
    {
        return;
    }

    int i = 0, j = 0, temp = 0;

    for (i = 0; i < iSize; i++)
    {
        for (j = 0; j < iSize - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout << "Data After pass : " << i + 1 << "\n";
        Display();
    }
}

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = true;

    if (Sorted == true)
    {
        return;
    }

    for (i = 0; i < iSize && bFlag == true; i++)
    {
        bFlag = false;
        for (j = 0; j < iSize - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                bFlag = true;
            }
        }

        cout << "Data After pass : " << i + 1 << "\n";
        Display();
    }
}

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for (i = 0; i < iSize - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        if (i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0, Selected = 0;

    for (i = 1; i < iSize; i++)
    {
        for (j = i - 1, Selected = Arr[i]; (j >= 0) && (Arr[j] > Selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = Selected;
    }
}

///////////////////////////////////////////////////////////////////////
// Class        : ArrayXSearch
// Description  : Generic Implementation of Searching Algorithms
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
class ArrayXSearch
{
public:
    T *Arr;
    int iSize;
    bool Sorted;

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ArrayXSearch
    // Description  : Initializes an array of specified size
    // Input        : T no - The size of the array
    // Output       : None (Initializes array and sets Sorted to true)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ArrayXSearch(T no);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ~ArrayXSearch
    // Description  : Deallocates the array
    // Input        : None
    // Output       : None (Frees array memory)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    ~ArrayXSearch();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Accept
    // Description  : Accepts elements from the user into the array
    // Input        : None
    // Output       : None (Fills array with user input and updates Sorted flag)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Accept();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the array
    // Input        : None
    // Output       : None (Prints array elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: LinearSearch
    // Description  : Performs linear search to find an element in the array
    // Input        : T no - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool LinearSearch(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BiDirectionlSearch
    // Description  : Performs bidirectional search to find an element
    // Input        : T no - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool BiDirectionlSearch(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BinarySearchInc
    // Description  : Performs binary search on an increasing sorted array
    // Input        : T iNo - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool BinarySearchInc(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BinarySearchEfficientInc
    // Description  : Performs optimized binary search on an increasing sorted array
    // Input        : T iNo - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool BinarySearchEfficientInc(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BinarySearchDec
    // Description  : Performs binary search on a decreasing sorted array
    // Input        : T iNo - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool BinarySearchDec(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: BinarySearchEfficientDec
    // Description  : Performs optimized binary search on a decreasing sorted array
    // Input        : T iNo - The value to search for
    // Output       : bool - True if the value is found, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool BinarySearchEfficientDec(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CheckSortedInc
    // Description  : Checks if the array is sorted in increasing order
    // Input        : None
    // Output       : bool - True if the array is sorted in increasing order, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool CheckSortedInc();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CheckSortedDec
    // Description  : Checks if the array is sorted in decreasing order
    // Input        : None
    // Output       : bool - True if the array is sorted in decreasing order, false otherwise
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    bool CheckSortedDec();
};

template <class T>
ArrayXSearch<T>::ArrayXSearch(T no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
ArrayXSearch<T>::~ArrayXSearch()
{
    delete[] Arr;
}

template <class T>
void ArrayXSearch<T>::Accept()
{
    cout << "Enter " << iSize << " Elements : \n";

    int i = 0;
    for (i = 0; i < iSize; i++)
    {
        cout << "Enter the Element no : " << i + 1 << "\n";
        cin >> Arr[i];

        if (i > 0 && Sorted == true)
        {
            if (Arr[i] < Arr[i - 1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void ArrayXSearch<T>::Display()
{
    cout << "Elements of the Array are : \n";

    int i = 0;
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << "\n";
}

template <class T>
bool ArrayXSearch<T>::LinearSearch(T no)
{
    if (Sorted == true)
    {
        cout << "data is Sorted\n";
        return BinarySearchEfficientInc(no);
    }
    int i = 0;
    bool bFlag = false;

    for (i = 0; i < iSize; i++)
    {
        if (Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::BiDirectionlSearch(T no)
{
    if (Sorted == true)
    {
        cout << "data is Sorted\n";
        return BinarySearchEfficientInc(no);
    }

    int iStart = 0, iEnd = 0;
    bool bFlag = false;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::BinarySearchInc(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if (Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if (iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::BinarySearchEfficientInc(T iNo)
{
    if (Sorted == false)
    {
        cout << "Data is Not Sorted\n";
        return LinearSearch(iNo);
    }

    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if ((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
        else if (iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::BinarySearchDec(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if (Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if (iNo > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (iNo < Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::BinarySearchEfficientDec(T iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if ((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
        else if (iNo > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (iNo < Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::CheckSortedInc()
{
    bool bFlag = true;

    for (int i = 0; i < iSize - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }
    return bFlag;
}

template <class T>
bool ArrayXSearch<T>::CheckSortedDec()
{
    bool bFlag = true;

    for (int i = 0; i < iSize - 1; i++)
    {
        if (Arr[i] < Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }
    return bFlag;
}

///////////////////////////////////////////////////////////////////////
// Class        : SinglyLL_34
// Description  : Assignment 34
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyLLnode_34
{
    T data;
    struct SinglyLLnode_34<T> *next;
};

template <class T>
class SinglyLL_34
{
private:
    struct SinglyLLnode_34<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: SinglyLL_34
    // Description  : Initializes an empty singly linear linked list
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    SinglyLL_34();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the singly linear linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: FirstOccurence
    // Description  : Finds the first occurrence of a given value in the list
    // Input        : T No - The value to search for
    // Output       : None (Prints position of first occurrence or not found message)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void FirstOccurence(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: lastOccurence
    // Description  : Finds the last occurrence of a given value in the list
    // Input        : T No - The value to search for
    // Output       : None (Prints position of last occurrence or not found message)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void lastOccurence(T);

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Addition
    // Description  : Computes the sum of all elements in the list
    // Input        : None
    // Output       : int - The sum of all elements
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Addition();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Maximum
    // Description  : Finds the maximum element in the list
    // Input        : None
    // Output       : int - The maximum element
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Maximum();

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Minimum
    // Description  : Finds the minimum element in the list
    // Input        : None
    // Output       : int - The minimum element
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Minimum();
};

template <class T>
SinglyLL_34<T>::SinglyLL_34()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyLL_34<T>::Display()
{
    struct SinglyLLnode_34<T> *temp = NULL;
    temp = first;

    while (temp != NULL)
    {
        printf(" | %d | -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

template <class T>
int SinglyLL_34<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL_34<T>::InsertFirst(T no)
{
    struct SinglyLLnode_34<T> *newn = NULL;

    newn = new struct SinglyLLnode_34<T>;

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
void SinglyLL_34<T>::InsertLast(T no)
{
    struct SinglyLLnode_34<T> *newn = NULL;
    struct SinglyLLnode_34<T> *temp = NULL;

    temp = first;

    newn = new struct SinglyLLnode_34<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL_34<T>::FirstOccurence(T No)
{
    struct SinglyLLnode_34<T> *temp = NULL;
    bool bFlag = false;

    temp = first;

    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            bFlag = true;
            cout << No << ":" << "Found at Position :" << pos << "\n";
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (bFlag == false)
    {
        cout << No << ":" << "Element not Found" << "\n";
    }
}

template <class T>
void SinglyLL_34<T>::lastOccurence(T No)
{
    struct SinglyLLnode_34<T> *temp = NULL;
    bool bFlag = false;
    int count = 0;

    temp = first;

    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            bFlag = true;
            count = pos;
        }
        temp = temp->next;
        pos++;
    }

    if (bFlag == true)
    {
        cout << No << ":" << "Found at position : " << count << "\n";
    }

    if (bFlag == false)
    {
        cout << No << ":" << "Element not Found" << "\n";
    }
}

template <class T>
int SinglyLL_34<T>::Addition()
{
    int iSum = 0;

    struct SinglyLLnode_34<T> *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;

}

// Continuing from SinglyLL_34 class

template <class T>
///////////////////////////////////////////////////////////////////////
// Function Name: Maximum
// Description  : Finds the maximum element in the singly linear linked list
// Input        : None
// Output       : T - The maximum element in the list
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////
int SinglyLL_34<T>::Maximum()
{
    struct SinglyLLnode_34<T> *temp = NULL;
    int iMax = 0;

    temp = first;

    if (temp == NULL)
    {
        return 0;
    }

    iMax = temp->data;

    while (temp != NULL)
    {
        if (temp->data > iMax)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
///////////////////////////////////////////////////////////////////////
// Function Name: Minimum
// Description  : Finds the minimum element in the singly linear linked list
// Input        : None
// Output       : T - The minimum element in the list
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////
int SinglyLL_34<T>::Minimum()
{
    struct SinglyLLnode_34<T> *temp = NULL;
    int iMin = 0;

    temp = first;

    if (temp == NULL)
    {
        return 0;
    }

    iMin = temp->data;

    while (temp != NULL)
    {
        if (temp->data < iMin)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

///////////////////////////////////////////////////////////////////////
// Class        : SinglyLL_35
// Description  : Assignment 35
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyLLnode_35
{
    T data;
    struct SinglyLLnode_35<T> *next;
};

template <class T>
class SinglyLL_35
{
private:
    struct SinglyLLnode_35<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: SinglyLL_35
    // Description  : Initializes an empty singly linear linked list
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    SinglyLL_35()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the singly linear linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        temp = first;

        while (temp != NULL)
        {
            printf(" | %d | -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count()
    {
        return iCount;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T no)
    {
        struct SinglyLLnode_35<T> *newn = NULL;

        newn = new struct SinglyLLnode_35<T>;

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

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T no)
    {
        struct SinglyLLnode_35<T> *newn = NULL;
        struct SinglyLLnode_35<T> *temp = NULL;

        temp = first;

        newn = new struct SinglyLLnode_35<T>;

        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: EvenCount
    // Description  : Counts the number of even elements in the list
    // Input        : None
    // Output       : int - The number of even elements
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int EvenCount()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        int iCnt = 0;

        temp = first;

        while (temp != NULL)
        {
            if ((temp->data % 2) == 0)
            {
                iCnt++;
            }
            temp = temp->next;
        }
        return iCnt;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: OddCount
    // Description  : Counts the number of odd elements in the list
    // Input        : None
    // Output       : int - The number of odd elements
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int OddCount()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        int iCnt = 0;

        temp = first;

        while (temp != NULL)
        {
            if ((temp->data % 2) != 0)
            {
                iCnt++;
            }
            temp = temp->next;
        }
        return iCnt;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: SumDigit
    // Description  : Computes the sum of digits for each element in the list
    // Input        : None
    // Output       : None (Prints sum of digits for each element)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void SumDigit()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        int iDigit = 0, iSum = 0, iNo = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iSum = 0;

            while (iNo != 0)
            {
                iDigit = iNo % 10;
                iSum = iSum + iDigit;
                iNo = iNo / 10;
            }

            cout << "Sum of Digits of " << temp->data << " are : " << iSum << "\n";
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: ReverseDigit
    // Description  : Reverses the digits of each element in the list
    // Input        : None
    // Output       : None (Prints reversed digits for each element)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void ReverseDigit()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        int iDigit = 0, iRev = 0, iNo = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iRev = 0;

            while (iNo != 0)
            {
                iDigit = iNo % 10;
                iRev = (iRev * 10) + iDigit;
                iNo = iNo / 10;
            }
            cout << "Reverse of Digits of " << temp->data << " are : " << iRev << "\n";
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Palindrome
    // Description  : Checks if each element in the list is a palindrome
    // Input        : None
    // Output       : None (Prints whether each element is a palindrome)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Palindrome()
    {
        struct SinglyLLnode_35<T> *temp = NULL;
        int iDigit = 0, iRev = 0, iNo = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            int iTemp = iNo;
            iRev = 0;

            while (iNo != 0)
            {
                iDigit = iNo % 10;
                iRev = (iRev * 10) + iDigit;
                iNo = iNo / 10;
            }

            if (iTemp == iRev)
            {
                cout << iTemp << " is Palindrome"
                     << "\n";
            }
            else
            {
                cout << iTemp << " is Not Palindrome"
                     << "\n";
            }
            temp = temp->next;
        }
    }
};

///////////////////////////////////////////////////////////////////////
// Class        : SinglyLL_36
// Description  : Assignment 36
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyLLnode_36
{
    T data;
    struct SinglyLLnode_36<T> *next;
};

template <class T>
class SinglyLL_36
{
private:
    struct SinglyLLnode_36<T> *first;
    int iCount;

public:
    ///////////////////////////////////////////////////////////////////////
    // Function Name: SinglyLL_36
    // Description  : Initializes an empty singly linear linked list
    // Input        : None
    // Output       : None (Initializes first to NULL and iCount to 0)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    SinglyLL_36()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Display
    // Description  : Displays all elements in the singly linear linked list
    // Input        : None
    // Output       : None (Prints list elements to console)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void Display()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        temp = first;

        while (temp != NULL)
        {
            printf(" | %d | -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: Count
    // Description  : Returns the number of elements in the list
    // Input        : None
    // Output       : int - The number of nodes in the list
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    int Count()
    {
        return iCount;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertFirst
    // Description  : Inserts a new node at the beginning of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertFirst(T no)
    {
        struct SinglyLLnode_36<T> *newn = NULL;

        newn = new struct SinglyLLnode_36<T>;

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

    ///////////////////////////////////////////////////////////////////////
    // Function Name: InsertLast
    // Description  : Inserts a new node at the end of the list
    // Input        : T no - The data to insert
    // Output       : None (Modifies the list by adding a new node)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void InsertLast(T no)
    {
        struct SinglyLLnode_36<T> *newn = NULL;
        struct SinglyLLnode_36<T> *temp = NULL;

        temp = first;

        newn = new struct SinglyLLnode_36<T>;

        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: DisplayProduct
    // Description  : Computes and displays the product of digits for each element
    // Input        : None
    // Output       : None (Prints product of digits for each element)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void DisplayProduct()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        int iDigit = 0, iMult = 0, iNo = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iMult = 1;

            while (iNo != 0)
            {
                iDigit = iNo % 10;
                if (iDigit == 0)
                {
                    iDigit = 1;
                }
                iMult = iMult * iDigit;
                iNo = iNo / 10;
            }
            cout << "Product of Digits of " << temp->data << " are : " << iMult << "\n";
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: SumEvenOdd
    // Description  : Computes the sum of even and odd digits for each element
    // Input        : None
    // Output       : None (Prints sum of even and odd digits for each element)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void SumEvenOdd()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        int iDigit = 0, iNo = 0, iEven = 0, iOdd = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iEven = 0;
            iOdd = 0;

            while (iNo != 0)
            {
                iDigit = iNo % 10;

                if ((iDigit % 2) == 0)
                {
                    iEven = iEven + iDigit;
                }
                else
                {
                    iOdd = iOdd + iDigit;
                }
                iNo = iNo / 10;
            }
            cout << "Sum of Even Digits of " << temp->data << " are : " << iEven << "\n";
            cout << "Sum of Odd Digits of " << temp->data << " are : " << iOdd << "\n";
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CheckPerfect
    // Description  : Checks if each element in the list is a perfect number
    // Input        : None
    // Output       : None (Prints whether each element is a perfect number)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void CheckPerfect()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        int i = 0, iNo = 0, iSum = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iSum = 0;

            for (i = 1; i <= iNo / 2; i++)
            {
                if ((iNo % i) == 0)
                {
                    iSum = iSum + i;
                }
            }

            if (iSum == iNo)
            {
                cout << iNo << " is Perfect Number"
                     << "\n";
            }
            else
            {
                cout << iNo << " is Not Perfect Number"
                     << "\n";
            }
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: SumFactors
    // Description  : Computes the sum of factors for each element in the list
    // Input        : None
    // Output       : None (Prints sum of factors for each element)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void SumFactors()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        int i = 0, iNo = 0, iSum = 0;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            iSum = 0;

            for (i = 1; i <= iNo / 2; i++)
            {
                if ((iNo % i) == 0)
                {
                    iSum = iSum + i;
                }
            }
            cout << "Sum of Factors of " << iNo << " are : " << iSum << "\n";
            temp = temp->next;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Function Name: CheckPrime
    // Description  : Checks if each element in the list is a prime number
    // Input        : None
    // Output       : None (Prints whether each element is a prime number)
    // Author       : Pratik Kisan Namdas
    ///////////////////////////////////////////////////////////////////////
    void CheckPrime()
    {
        struct SinglyLLnode_36<T> *temp = NULL;
        int i = 0, iNo = 0;
        bool bFlag = true;

        temp = first;

        while (temp != NULL)
        {
            iNo = temp->data;
            bFlag = true;

            for (i = 2; i <= iNo / 2; i++)
            {
                if ((iNo % i) == 0)
                {
                    bFlag = false;
                    break;
                }
            }

            if (bFlag == true)
            {
                cout << iNo << " is Prime Number"<< "\n";
                     
            }
            else
            {
                cout << iNo << " is Not Prime Number"<< "\n";
                     
            }
            temp = temp->next;
        }
    }
};

///////////////////////////////////////////////////////////////////////
// Function Name: main
// Description  : Entry point function to test data structure implementations
// Input        : None
// Output       : int - Returns 0 on successful execution
// Author       : Pratik Kisan Namdas
///////////////////////////////////////////////////////////////////////
int main()
{
    // cout << "Inside Main\n";

    // QueueX<int> *iobj = new QueueX<int>();

    // iobj->Enqueue(11);
    // iobj->Enqueue(21);
    // iobj->Enqueue(51);
    // iobj->Enqueue(101);

    // cout << "Elements of Queue are : \n";
    // iobj->Display();

    // cout << "Removed Element is : " << iobj->Dequeue() << "\n";
    // iobj->Display();

    // cout << "Number of Elements in Queue are : " << iobj->Count() << "\n";

    // StackX<int> *istack = new StackX<int>();

    // istack->push(11);
    // istack->push(21);
    // istack->push(51);
    // istack->push(101);

    // cout << "Elements of Stack are : \n";
    // istack->Display();

    // cout << "Removed Element is : " << istack->pop() << "\n";
    // istack->Display();

    // cout << "Number of Elements in Stack are : " << istack->Count() << "\n";

    // SinglyCLL<int> *iscll = new SinglyCLL<int>();

    // iscll->Insertfirst(11);
    // iscll->Insertfirst(21);
    // iscll->InsertLast(51);
    // iscll->InsertLast(101);
    // iscll->InsertAtPos(75, 3);

    // cout << "Elements of Singly Circular Linked List are : \n";
    // iscll->Display();

    // cout << "Number of Elements in Singly Circular Linked List are : " << iscll->Count() << "\n";

    // iscll->DeleteFirst();
    // iscll->DeleteLast();
    // iscll->DeleteAtPos(3);

    // cout << "Elements of Singly Circular Linked List are : \n";
    // iscll->Display();

    // cout << "Number of Elements in Singly Circular Linked List are : " << iscll->Count() << "\n";

    // DoublyCLL<int> *idcll = new DoublyCLL<int>();

    // idcll->InsertFirst(11);
    // idcll->InsertFirst(21);
    // idcll->InsertLast(51);
    // idcll->InsertLast(101);
    // idcll->InsertAtPos(75, 3);

    // idcll->Display();

    // cout << "Number of Elements in Doubly Circular Linked List are : " << idcll->Count() << "\n";

    // idcll->DeleteFirst();
    // idcll->DeleteLast();
    // idcll->DeleteAtPos(3);

    // idcll->Display();

    // cout << "Number of Elements in Doubly Circular Linked List are : " << idcll->Count() << "\n";

    // SinglyLL<int> *isll = new SinglyLL<int>();

    // isll->InsertFirst(11);
    // isll->InsertFirst(21);
    // isll->InsertLast(51);
    // isll->InsertLast(101);
    // isll->InsertAtPOs(75, 3);

    // isll->Display();

    // cout << "Number of Elements in Singly Linear Linked List are : " << isll->Count() << "\n";

    // isll->DeleteFirst();
    // isll->DeleteLast();
    // isll->DeleteAtPos(3);

    // isll->Display();

    // cout << "Number of Elements in Singly Linear Linked List are : " << isll->Count() << "\n";

    // DoublyLL<int> *idll = new DoublyLL<int>();

    // idll->InsertFirst(11);
    // idll->InsertFirst(21);
    // idll->InsertLast(51);
    // idll->InsertLast(101);
    // idll->InsertAtPos(75, 3);

    // idll->Display();

    // cout << "Number of Elements in Doubly Linear Linked List are : " << idll->Count() << "\n";

    // idll->DeleteFirst();
    // idll->DeleteLast();
    // idll->DeleteAtPos(3);

    // idll->Display();

    // cout << "Number of Elements in Doubly Linear Linked List are : " << idll->Count() << "\n";

    // ArrayX<int> *iarr = new ArrayX<int>(6);

    // iarr->Accept();
    // iarr->Display();

    // cout << "BubbleSort\n";
    // iarr->BubbleSort();
    // iarr->Display();

    // cout << "BubbleSortEfficient\n";
    // iarr->BubbleSortEfficient();
    // iarr->Display();

    // cout << "SelectionSort\n";
    // iarr->SelectionSort();
    // iarr->Display();

    // cout << "InsertionSort\n";
    // iarr->InsertionSort();
    // iarr->Display();

    // ArrayXSearch<int> *iarrsearch = new ArrayXSearch<int>(6);

    // iarrsearch->Accept();
    // iarrsearch->Display();

    // bool bRet = false;

    // bRet = iarrsearch->LinearSearch(30);
    // if (bRet == true)
    // {
    //     cout << "Element Found\n";
    // }
    // else
    // {
    //     cout << "Element Not Found\n";
    // }

    // bRet = iarrsearch->BiDirectionlSearch(30);
    // if (bRet == true)
    // {
    //     cout << "Element Found\n";
    // }
    // else
    // {
    //     cout << "Element Not Found\n";
    // }

    // cout << "Checking for Sorted\n";
    // bRet = iarrsearch->CheckSortedInc();

    // if (bRet == true)
    // {
    //     cout << "Array is Sorted in Increasing order\n";
    //     bRet = iarrsearch->BinarySearchInc(30);
    //     if (bRet == true)
    //     {
    //         cout << "Element Found\n";
    //     }
    //     else
    //     {
    //         cout << "Element Not Found\n";
    //     }

    //     bRet = iarrsearch->BinarySearchEfficientInc(30);
    //     if (bRet == true)
    //     {
    //         cout << "Element Found\n";
    //     }
    //     else
    //     {
    //         cout << "Element Not Found\n";
    //     }
    // }
    // else
    // {
    //     cout << "Array is Not Sorted in Increasing order\n";
    // }

    // bRet = iarrsearch->CheckSortedDec();

    // if (bRet == true)
    // {
    //     cout << "Array is Sorted in Decreasing order\n";
    //     bRet = iarrsearch->BinarySearchDec(30);
    //     if (bRet == true)
    //     {
    //         cout << "Element Found\n";
    //     }
    //     else
    //     {
    //         cout << "Element Not Found\n";
    //     }

    //     bRet = iarrsearch->BinarySearchEfficientDec(30);
    //     if (bRet == true)
    //     {
    //         cout << "Element Found\n";
    //     }
    //     else
    //     {
    //         cout << "Element Not Found\n";
    //     }
    // }
    // else
    // {
    //     cout << "Array is Not Sorted in Decreasing order\n";
    // }

    // SinglyLL_34<int> *isll34 = new SinglyLL_34<int>();

    // isll34->InsertFirst(121);
    // isll34->InsertFirst(151);
    // isll34->InsertLast(51);
    // isll34->InsertLast(101);
    // isll34->InsertLast(111);

    // isll34->Display();

    // cout << "Number of Elements in Singly Linear Linked List are : " << isll34->Count() << "\n";

    // isll34->FirstOccurence(151);
    // isll34->lastOccurence(111);
    // cout << "Addition of Elements in Linked List : " << isll34->Addition() << "\n";
    // cout << "Maximum Element in Linked List : " << isll34->Maximum() << "\n";
    // cout << "Minimum Element in Linked List : " << isll34->Minimum() << "\n";

    // SinglyLL_35<int> *isll35 = new SinglyLL_35<int>();

    // isll35->InsertFirst(121);
    // isll35->InsertFirst(151);
    // isll35->InsertLast(51);
    // isll35->InsertLast(101);
    // isll35->InsertLast(111);

    // isll35->Display();

    // cout << "Number of Elements in Singly Linear Linked List are : " << isll35->Count() << "\n";

    // cout << "Number of Even Elements in Linked List : " << isll35->EvenCount() << "\n";
    // cout << "Number of Odd Elements in Linked List : " << isll35->OddCount() << "\n";

    // isll35->SumDigit();
    // isll35->ReverseDigit();
    // isll35->Palindrome();

    // SinglyLL_36<int> *isll36 = new SinglyLL_36<int>();

    // isll36->InsertFirst(28);
    // isll36->InsertFirst(151);
    // isll36->InsertLast(51);
    // isll36->InsertLast(101);
    // isll36->InsertLast(496);

    // isll36->Display();

    // cout << "Number of Elements in Singly Linear Linked List are : " << isll36->Count() << "\n";

    // isll36->DisplayProduct();
    // isll36->SumEvenOdd();
    // isll36->CheckPerfect();
    // isll36->SumFactors();
    // isll36->CheckPrime();

    // BST<int> *ibst = new BST<int>();

    // ibst->Insert(51);
    // ibst->Insert(21);
    // ibst->Insert(101);
    // ibst->Insert(11);
    // ibst->Insert(75);

    // cout << "Inorder Traversal : \n";
    // ibst->Inorder();

    // cout << "Preorder Traversal : \n";
    // ibst->Preorder();

    // cout << "Postorder Traversal : \n";
    // ibst->Postorder();

    // cout << "Total Number of Elements : " << ibst->Count() << "\n";

    // bRet = ibst->Search(75);
    // if (bRet == true)
    // {
    //     cout << "Element Found\n";
    // }
    // else
    // {
    //     cout << "Element Not Found\n";
    // }

    // cout << "Number of Leaf Nodes are : " << ibst->CountLeafNodes() << "\n";
    // cout << "Number of Parent Nodes are : " << ibst->CountParentNodes() << "\n";

    return 0;
}