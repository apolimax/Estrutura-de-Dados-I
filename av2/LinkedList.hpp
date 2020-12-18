#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
    }

    LinkedList(const LinkedList<T> &other) // Construtor de cópia
    {
        clone(other);
    }
    // LinkedList& operator=
    LinkedList &operator=(const LinkedList<T> &other) // overload do operador de atribuição
    {
        if (&other == this)
        { // se o objeto está sendo atribuído à ele mesmo
            return *this;
        }
        clear();
        clone(other);
        return *this; // dereferenciando o ponteiro this pra retornar o valor para o qual ele aponta
    }
    // T& operator[]
    T &operator[](size_t index)
    {
        if (index >= size())
        {
            // erro (lançar excessão)
        }

        Node *current = first; // asterisco = ponteiro que aponta para first
        size_t currentIndex = 0;

        while (currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }

        return current->value;
    }

    ~LinkedList() // Destrutor
    {
        clear();
    }

    void insert(T value)
    {
        if (first != nullptr)
        {
            Node *last = first;
            while (last->next != nullptr) // enquanto o next do último tenha um valor
            {
                last = last->next; // last recebe próximo do last
            }
            Node *other = new Node();
            other->value = value;
            last->next = other;    // o next do último será igual ao novo node
            other->next = nullptr; // o next do último node adicionado deverá apontar para NULL;
            other->prev = last;    // o previous do novo node será igual a last do último node anteriormente
            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            first->prev = nullptr; // o previous do primeiro node deverá apontar para NULL;
            ++nodeCount;
        }
    }

    void insertAt(size_t position, T value)
    {
        if (position == 0)
        {
            insertAtFront(value);
            return;
        }

        if (position > size())
        { // O novo elemento a ser adicionado só pode ir até o último elemento
            return;
        }

        size_t currentPosition = 0;
        Node *previousNode = nullptr;
        Node *currentNode = first;
        Node *newNode = new Node();
        newNode->value = value;

        while (currentPosition < position)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            currentPosition++;
        }
        previousNode->next = newNode;
        newNode->next = currentNode;
        nodeCount++;
    };

    void insertAtFront(T value)
    {
        if (first == nullptr) // Se não há nenhum elemento na lista. No caso de (first == 0) ele adiciona duas vezes na frente
        {
            // Node *newNode = new Node();
            // newNode->value = value;
            // first->prev = newNode;
            // newNode->prev = nullptr;
            // newNode->next = first;
            first = new Node();
            first->value = value;
            first->prev = nullptr; // o previous do primeiro node deverá apontar para NULL;
            ++nodeCount;
            return;
        }

        Node *newNode = new Node();
        newNode->value = value;
        newNode->prev = nullptr;
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
        ++nodeCount;
    }

    void insertAtBack(T value)
    {
        if (last != nullptr)
        {
            Node *tmp = new Node();
            tmp->value = value;
            tmp->next = nullptr;
            tmp->prev = last;
            last->next = tmp;
            last = tmp;
            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            first->prev = nullptr; // o previous do primeiro node deverá apontar para NULL;
            first->next = nullptr;

            last = first;

            ++nodeCount;
        }
    }

    void removeAt(size_t position)
    {
        // verificar se a posição de memória é válida, ir até o elemento, copiar o endereço do elemento, liberar a memória
        if (position >= size())
        {
            return;
        }
        size_t currentPosition = 0;
        Node *currentNode = first;
        while (currentPosition < position)
        {
            // previousNode = currentNode;
            currentNode = currentNode->next;
            currentPosition++;
        }
        if (position == 0)
        {
            first = first->next;
            delete currentNode;
            --nodeCount;
        }
        else
        {
            Node *previousNode = currentNode->prev;
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
    }

    void removeAtFront()
    {
        if (size() == 0)
        {
            std::cout << "Não tem o que remover" << std::endl;
        }
        else if (size() == 1)
        {
            delete first;
            nodeCount--;
        }

        Node *temp = new Node();
        temp = first;
        first = first->next;
        first->prev = nullptr;
        delete temp;
        nodeCount--;
    }

    void removeAtBack()
    {
        if (size() == 0)
        {
            std::cout << "Não tem o que remover" << std::endl;
        }
        else if (size() == 1)
        {
            delete first;
            nodeCount--;
        }

        Node *temp = last->prev;
        delete last;
        last = temp;
        last->next = nullptr;
        // temp = last->prev;
        nodeCount--;
    }

    size_t size()
    {
        return nodeCount;
    }

    void print()
    {
        if (size() == 0)
        {
            return;
        }
        Node *current = first;
        do
        {
            std::cout << current->value << std::endl;
            current = current->next;
        } while (current != nullptr);
    }

    // size_t search(int value);

private:
    struct Node
    {
        T value;
        Node *prev;
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

    void clone(const LinkedList &other)
    {
        if (other.nodeCount == 0) // se o objeto a ser copiado estiver vazio, significa que os dois objetos já estão iguais
        {
            return;
        }
        Node *currentNode = other.first;
        while (currentNode != nullptr)
        {
            insert(currentNode->value);
            currentNode = currentNode->next;
        }
    }
};