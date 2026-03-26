#include <iostream>
using namespace std;

class Base
{
protected:
    int arr[10];
    int size;
    int top;

public:
    Base(int x)
    {
        size = x;
        top = -1;
    };
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual void display() = 0;
    virtual void topelement() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

class Stack : public Base
{
public:
    Stack(int x) : Base(x) {}

    bool isEmpty()
    {
        return top == -1;
    };

    bool isFull()
    {
        return top == size - 1;
    }

    void push()
    {
        if (isFull())
        {
            cout << "Stack is Overflow " << endl;
            return;
        }
        int val;
        cout << "Enter The value to be added ";
        cin >> val;
        cout << "Value Added Succesfully " << endl;

        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is UnderFlow " << endl;
            return;
        }
        top--;
        cout << "Value Popped Succesfully " << endl;
    }

    void display()
    {
        // cout << "Top = " << top << endl;

        if (isEmpty())
        {
            cout << "Stack is UnderFlow " << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };

    void topelement()
    {
        if (isEmpty())
        {
            cout << "Stack is UnderFlow " << endl;
            return;
        }

        cout << arr[top] << endl;
    }
};

int main()
{
    Base *b = new Stack(10);

    int choice;

    do
    {
        cout << "Stack Program System " << endl;
        cout << "1. Added The value " << endl;
        cout << "2. Pop The value " << endl;
        cout << "3. Display Top value " << endl;
        cout << "4. Display The value " << endl;
        cout << "5. Check if the Stack is Empty" << endl;
        cout << "6. Check if the Stack is Full" << endl;
        cout << "7. Exit the program" << endl;

        //    int choice;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b->push();
            break;

        case 2:
            b->pop();
            break;
        case 3:
            b->topelement();
            break;

        case 4:
            b->display();
            break;

        case 5:
            b->isEmpty();
            break;

        case 6:
            b->isFull();
            break;

        case 7:
            cout << "Program exited succesfully!";
            break;

        default:
            cout << "Enter The Valid Choice " << endl;
        }
    } while (choice != 7);
};