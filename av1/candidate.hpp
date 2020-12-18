#ifndef CANDIDATE
#define CANDIDATE
#include <string>

struct Candidato
{
    std::string nome;
    std::string respostas[10];
    int acertos = 0;
};

#endif