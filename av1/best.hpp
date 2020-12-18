#ifndef BEST_CANDIDATES
#define BEST_CANDIDATES
#include "candidate.hpp"
#include "questions.hpp"
#include <string>

void quickSort_D(Candidato *numeros, int inicio, int fim);

void quickSort_best_questions(Questions &array, int low, int high);
// void quickSort_best_questions(Questions *array, int low, int high);

#endif