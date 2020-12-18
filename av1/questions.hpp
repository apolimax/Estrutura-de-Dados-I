#ifndef COUNT_QUESTIONS
#define COUNT_QUESTIONS
#include <string>

struct Questions
{
    std::string questao[10] = {"Questão 1", "Questão 2", "Questão 3", "Questão 4", "Questão 5", "Questão 6", "Questão 7", "Questão 8", "Questão 9", "Questão 10"};
    // std::string questao[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    int c_questions[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

#endif