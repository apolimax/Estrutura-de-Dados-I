#ifndef WORST_CANDIDATES
#define WORST_CANDIDATES
#include "candidate.hpp"
#include "questions.hpp"
#include <string>

void quickSort_C(Candidato *numeros, int inicio, int fim);

void quickSort_worst_questions(Questions &array, int low, int high);

#endif