#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
// #include <locale>
#include "levenshtein.h"

int main(int argc, char *argv[])
{
    std::string dictionary = argv[1];
    std::string target = argv[2];
    std::ifstream dict(dictionary);
    std::ifstream targ(target);

    std::string input;
    std::unordered_map<std::string, int> dicionario;
    std::unordered_map<std::string, int> texto;
    std::unordered_map<std::string, std::vector<std::string>> wrong_words;

    if (!dict.is_open())
    {
        std::cout << "Didn't read the dictionary file!\n";
    }

    if (!targ.is_open())
    {
        std::cout << "Didn't read the target file!\n";
    }

    // Armazenando todos os verbetes do dicionário dentro de um dicionario
    while (dict >> input)
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower); // convertendo para miníscula a palavra do dicionario
        std::pair<std::string, int> temp(input, 1);
        dicionario.insert(temp);
    }

    // Armazenando todos as palavras do texto alvo dentro de um dicionario
    while (targ >> input)
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower); // convertendo para miníscula a palavra do texto alvo
        while (ispunct(input.back()))                                    //se no final da palavra tiver pontução, remover a pontução
        {
            input = input.erase(input.size() - 1);
        }

        while (ispunct(input.front())) //se no início da palavra tiver pontução, remover a pontução
        {
            input = input.erase(0, 1);
        }
        std::pair<std::string, int> temp(input, 1);
        texto.insert(temp);
    }
    // std::cout << dicionario.find("Abreu-PI")->second;
    std::unordered_map<std::string, int>::const_iterator got;
    for (auto &x : texto)
    {
        // std::cout << x.first << ": " << x.second << std::endl;
        std::string aux = x.first;
        got = dicionario.find(aux);
        if (got == dicionario.end()) // se a palavra não existir no dicionário
        {
            // std::cout << "not found";
            // if (aux.back() == 's') // se a a palavra não existir e terminar com 's'
            // {
            //     aux = aux.erase(aux.size() - 1); // deleta o 's'
            //     got = dicionario.find(aux);
            //     if (got == dicionario.end()) // se a palavra sem 's' ainda não existir no dicionário
            //     {
            //         std::pair<std::string, std::vector<std::string>> temp(aux, std::vector<std::string>());
            //         wrong_words.insert(temp);
            //     }
            // }
            std::pair<std::string, std::vector<std::string>> temp(x.first, std::vector<std::string>());
            wrong_words.insert(temp);
        }
        // else
        // {
        // }
    }

    int distancia = 0;
    int count;
    for (auto &x : wrong_words)
    {
        count = 0;
        for (auto &y : dicionario)
        {
            distancia = levenshtein(x.first, y.first);
            if (distancia <= 3)
            {
                count++;
                x.second.push_back(y.first);
            }
            if (count == 5)
                break;
        }
    }

    for (auto &x : wrong_words)
    {
        std::cout << x.first << ":" << std::endl;
        for (size_t i = 0; i < x.second.size(); ++i)
        {
            std::cout << "  - " << x.second[i] << std::endl;
        }
        std::cout << "\n";
    }
}
