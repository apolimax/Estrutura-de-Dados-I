#include "worst.hpp"

void quickSort_C(Candidato *array, int low, int high)
{
    int i = low;
    int j = high;
    Candidato pivot = array[(i + j) / 2];
    Candidato temp;

    while (i <= j)
    {
        while (array[i].acertos < pivot.acertos)
            i++;
        while (array[j].acertos > pivot.acertos)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort_C(array, low, j);
    if (i < high)
        quickSort_C(array, i, high);
}

void quickSort_worst_questions(Questions &array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array.c_questions[(i + j) / 2];
    int temp;
    std::string temp_string;

    while (i <= j)
    {
        while (array.c_questions[i] < pivot)
            i++;
        while (array.c_questions[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array.c_questions[i];
            array.c_questions[i] = array.c_questions[j];
            array.c_questions[j] = temp;

            temp_string = array.questao[i];
            array.questao[i] = array.questao[j];
            array.questao[j] = temp;

            i++;
            j--;
        }
    }
    if (j > low)
        quickSort_worst_questions(array, low, j);
    if (i < high)
        quickSort_worst_questions(array, i, high);
}