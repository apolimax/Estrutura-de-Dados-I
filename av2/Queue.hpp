#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Queue
{
public:
    Queue()
    {
    }

    ~Queue() // Destrutor
    {
        clear();
    }

    void pushBack(T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;

        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        nodeCount++;
    }

    void popFront()
    {
        if (size() == 0)
        {
            std::cout << "Não tem o que remover" << std::endl;
            return;
        }

        Node *temp = new Node();
        temp = first;
        first = first->next;
        delete temp;
        nodeCount--;
    }

    T front()
    {
        return first->value;
    }

    T back()
    {
        return last->value;
    }

    size_t size()
    {
        return nodeCount;
    }

private:
    struct Node
    {
        T value;
        Node *next;
    };

    Node *first = nullptr;
    Node *last = nullptr;
    size_t nodeCount = 0;

    void clear()
    {
        if (size() == 0)
        {
            return;
        }
        Node *currentNode = first;
        while (currentNode != nullptr)
        {
            Node *temp = currentNode->next;
            delete currentNode;
            currentNode = temp;
        }
        nodeCount = 0;
        first = nullptr;
    }
};