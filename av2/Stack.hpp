#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Stack
{
public:
    Stack() // construtor
    {
        Top = nullptr;
    };

    ~Stack() // destrutor
    {
        while (!isEmpty())
        {
            pop();
        }
    };

    void push(T d) // adicionar um node à pilha
    {
        // primeiro criar um novo node pra receber o dado que está sendo inserido
        Node *temp = new Node;
        temp->data = d;
        temp->next = Top; // o next do node temporário aponta para o antigo Top da pilha
        Top = temp;       // o novo Top da pilha passa a ser o node temp recentemente criado
    };

    void pop() // deletar o Top node do pilha
    {
        if (isEmpty())
        {
            std::cout << "A pilha está vazia" << std::endl;
            return; // precisa tratar
        }
        else
        {
            T value = Top->data;
            Node *oldTop = Top;
            Top = Top->next;
            delete oldTop;
            // return value;
        }
    };

    T top() // retorna o elemento no topo da pilha
    {
        if (isEmpty())
        {
            std::cout << "A pilha está vazia" << std::endl;
            exit(1); // precisa tratar
        }
        else
        {
            return Top->data;
        }
    };

    size_t size() // retorna a quantidade de elementos da pilha
    {
        size_t count = 0;
        if (isEmpty())
        {
            return count;
        }
        else
        {
            Node *current = Top;
            while (current != nullptr)
            {
                count++;
                current = current->next;
            }
            return count;
        }
    };

private:
    struct Node
    {
        T data;
        Node *next; // next do node é o que está abaixo dele
    };

    bool isEmpty()
    {
        return (Top == nullptr);
    }
    Node *Top;
};