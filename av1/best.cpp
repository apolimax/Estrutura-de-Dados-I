#include "best.hpp"

void quickSort_D(Candidato *array, int low, int high)
{
    int i = low;
    int j = high;
    Candidato pivot = array[(i + j) / 2];
    Candidato temp;

    while (i <= j)
    {
        while (array[i].acertos > pivot.acertos)
            i++;
        while (array[j].acertos < pivot.acertos)
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
        quickSort_D(array, low, j);
    if (i < high)
        quickSort_D(array, i, high);
}

void quickSort_best_questions(Questions &array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array.c_questions[(i + j) / 2];
    int temp;
    std::string temp_string;

    while (i <= j)
    {
        while (array.c_questions[i] > pivot)
            i++;
        while (array.c_questions[j] < pivot)
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
        quickSort_best_questions(array, low, j);
    if (i < high)
        quickSort_best_questions(array, i, high);
}

// void quickSort_best_questions(int *array, int low, int high)
// {
//     int i = low;
//     int j = high;
//     int pivot = array[(i + j) / 2];
//     int temp;

//     while (i <= j)
//     {
//         while (array[i] > pivot)
//             i++;
//         while (array[i] < pivot)
//             j--;
//         if (i <= j)
//         {
//             temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;

//             i++;
//             j--;
//         }
//     }
//     if (j > low)
//         quickSort_best_questions(array, low, j);
//     if (i < high)
//         quickSort_best_questions(array, i, high);
// }