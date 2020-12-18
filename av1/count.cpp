#include "count.hpp"

// Contar os números de acertos de cada candidato
// int countAcertos(std::string questoes[], int n_questoes, Questions *questions)
// {
//     std::string gabarito[] = {"A", "B", "C", "D", "E", "E", "D", "C", "B", "A"};
//     int acertos = 0;

//     for (int i = 0; i < n_questoes; ++i)
//     {
//         if (questoes[i] == gabarito[i])
//         {
//             acertos++;

//             switch (i)
//             {
//             case 0:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 1:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 2:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 3:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 4:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 5:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 6:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 7:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 8:
//                 questions[i].c_questions[i]++;
//                 break;
//             case 9:
//                 questions[i].c_questions[i]++;
//                 break;
//             default:
//                 break;
//             }
//         }
//     }
//     return acertos;
// }

// int countAcertos(std::string questoes[], int n_questoes)
// {
//     std::string gabarito[] = {"A", "B", "C", "D", "E", "E", "D", "C", "B", "A"};
//     int acertos = 0;

//     for (int i = 0; i < n_questoes; ++i)
//     {
//         if (questoes[i] == gabarito[i])
//         {
//             acertos++;
//         }
//         }
//     return acertos;
// }

int countAcertos(std::string questoes[], int n_questoes, Questions &questions)
{
    std::string gabarito[] = {"A", "B", "C", "D", "E", "E", "D", "C", "B", "A"};
    int acertos = 0;

    for (int i = 0; i < n_questoes; ++i)
    {
        if (questoes[i] == gabarito[i])
        {
            acertos++;

            switch (i)
            {
            case 0:
                questions.c_questions[i]++;
                break;
            case 1:
                questions.c_questions[i]++;
                break;
            case 2:
                questions.c_questions[i]++;
                break;
            case 3:
                questions.c_questions[i]++;
                break;
            case 4:
                questions.c_questions[i]++;
                break;
            case 5:
                questions.c_questions[i]++;
                break;
            case 6:
                questions.c_questions[i]++;
                break;
            case 7:
                questions.c_questions[i]++;
                break;
            case 8:
                questions.c_questions[i]++;
                break;
            case 9:
                questions.c_questions[i]++;
                break;
            default:
                break;
            }
        }
    }

    return acertos;
}