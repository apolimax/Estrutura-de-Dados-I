#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

int main(int argc, char *argv[])
{
    LinkedList<int> list;
    Stack<int> stack;
    Queue<int> queue;

    std::string file_name = argv[1];
    std::ifstream instructions(file_name);

    if (!instructions.is_open())
    {
        std::cout << "Didn't read the file!\n";
    }
    std::string line;
    // std::stringstream ss;

    while (getline(instructions, line))
    {

        std::stringstream stream(line);
        std::string operacao;
        std::string estrutura;
        char space;
        int n1;
        int n2;
        stream >> estrutura >> operacao >> n1 >> n2;
        if (estrutura == "list")
        {
            if (operacao == "size")
            {
                std::cout << "Tamanho da lista: " << list.size() << "\n";
            }
            else if (operacao == "insertAt")
            {
                std::cout << "Inserindo elemento na posicao " << n1 << " da lista: " << n2 << "\n";
                list.insertAt(n1, n2);
            }
            else if (operacao == "removeAt")
            {
                std::cout << "Removendo elemento na posicao " << n1 << " da lista: " << n2 << "\n";
                list.removeAt(n1);
            }
            else if (operacao == "insertAtFront")
            {
                std::cout << "Inserindo elemento no comeco da lista: " << n1 << "\n";
                list.insertAtFront(n1);
            }
            else if (operacao == "insertAtBack")
            {
                std::cout << "Inserindo elemento no final da lista: " << n1 << "\n";
                list.insertAtBack(n1);
            }
            else if (operacao == "removeAtFront")
            {
                std::cout << "Removendo elemento no comeco da lista: "
                          << "\n";
                list.removeAtFront();
            }
            else if (operacao == "removeAtBack")
            {
                std::cout << "Removendo elemento no final da lista: "
                          << "\n";
                list.removeAtBack();
            }
            else if (operacao == "print")
            {
                std::cout << "Imprimindo lista:"
                          << "\n";
                list.print();
            }
        }
        else if (estrutura == "stack")
        {
            if (operacao == "size")
            {
                std::cout << "Tamanho da pilha: " << stack.size() << "\n";
            }
            else if (operacao == "push")
            {
                std::cout << "Inserindo elemento na pilha: " << n1 << "\n";
                stack.push(n1);
            }
            else if (operacao == "top")
            {
                std::cout << "Elemento do topo da pilha: " << stack.top() << "\n";
            }
            else if (operacao == "pop")
            {
                std::cout << "Removendo elemento da pilha"
                          << "\n";
                stack.pop();
            }
        }
        else if (estrutura == "queue")
        {
            if (operacao == "size")
            {
                std::cout << "Tamanho da fila: " << queue.size() << "\n";
            }
            else if (operacao == "pushBack")
            {
                std::cout << "Inserindo elemento da fila: " << n1 << "\n";
                queue.pushBack(n1);
            }
            else if (operacao == "popFront")
            {
                std::cout << "Removendo elemento da fila"
                          << "\n";
                queue.popFront();
            }
            else if (operacao == "front")
            {
                std::cout << "Primeiro elemento da fila: " << queue.front() << "\n";
            }
            else if (operacao == "back")
            {
                std::cout << "Ultimo elemento da fila: " << queue.back() << "\n";
            }
        }
    }
}