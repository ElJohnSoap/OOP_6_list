

#include <iostream>

struct Node
{
    int value;
    Node* nextNode;
};

class MyList
{
    Node* firstNode;
    Node* lastNode;
    int length;
public:
    MyList();
    int getLeigth();
    void add(int value);
    void insert(int value, int pos);
    void del(int pos);
    int operator [] (int index);
    void show();
};

int main()
{
    
}

MyList::MyList()
{
    firstNode = nullptr;
    length = 0;
}

int MyList::getLeigth()
{
    return length;
}

void MyList::add(int value)
{
    if (length == 0)
    {
        firstNode = new Node();
        firstNode->value = value;
        length++;
    }
    else
    {
        Node* temp = lastNode;
        lastNode = new Node();
        lastNode->value = value;
        temp->nextNode = lastNode;
    }
    length++;
}

void MyList::insert(int value, int pos)
{
    if (pos < 0 || pos>length);
    {
        return;
    }
    Node* newNode = new Node();
    newNode->value = value;
    Node* currentNode = firstNode;
    Node* afterNode = nullptr;
    if (pos == 0)
    {
        newNode->nextNode = firstNode;
        firstNode = newNode;
        length++;
        return;
    }
    if (pos == length)
    {
        add(value);
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        currentNode = currentNode->nextNode;
        afterNode = currentNode->nextNode;
    }
    currentNode->nextNode = newNode;
    newNode->nextNode = afterNode;
    length++;
}

void MyList::del(int pos)
{
    if (pos < 0 || pos >= length)
    {
        return;
    }
    Node* prevNode = nullptr;
    Node* currentNode = firstNode;
    Node* afterNode = nullptr;
    if (pos == 0)
    {
        firstNode = firstNode->nextNode;
        length--;
        return;
    }
    
    for (int i = 0; i < pos; i++)
    {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
        afterNode = currentNode->nextNode;
    }
    prevNode->nextNode = afterNode;
    length--;

}

int MyList::operator[](int index)
{
    if (index < 0 || index >= length)
    {
        return -1;
    }

    if (index == 0)
    {
        return firstNode->value;
    }

    Node* currentNode = firstNode;
    Node* afterNode = nullptr;
    for (int i = 0; i < index; i++)
    {
        currentNode = currentNode->nextNode;
        afterNode = currentNode->nextNode;
    }
    return currentNode->value;

}

void MyList::show()
{
    Node* currentNode = firstNode;
}
