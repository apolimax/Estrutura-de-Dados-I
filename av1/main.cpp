#include <iostream>
#include <string>
#include <fstream>
#include "best.hpp"
#include "worst.hpp"
#include "count.hpp"
#include "questions.hpp"

int main(int argc, char *argv[])
{
	std::string file_name = argv[1];
	std::string answear_type = argv[2];
	int quantity = atoi(argv[3]);
	std::ifstream countNCandidates(file_name); // stream para calcular o número de candidatos
	std::ifstream file(file_name);			   // stream para ler os candidatos do arquivo
	int countCandidates = 0;
	// std::string currentQuestions[10]; // vetor de questões do candidato da vez
	// int c_questions[10] = {0};
	// std::string questao[10] = {"Questão 1", "Questão 2", "Questão 3", "Questão 4", "Questão 5", "Questão 6", "Questão 7", "Questão 8", "Questão 9", "Questão 10"};
	// Questions *questions = new Questions[10];
	Questions questions;

	if (!file.is_open())
	{
		std::cout << "Didn't read the file!\n";
	}

	std::string line;
	while (getline(countNCandidates, line))
	{
		countCandidates++;
	}
	// int acertos[countCandidates];

	//size_t total_palavras = countCandidates * 11; // em cada linha tem 11 palavras/letras

	std::cout << "Número de candidatos: " << countCandidates << "\n";

	std::string input;
	int i = 0;
	int j = 0;

	//Candidato studentsGrades[total_palavras];
	Candidato *studentsGrades = new Candidato[countCandidates];

	while (file >> input)
	{
		if (input.length() > 1)
		{
			studentsGrades[i].nome = input;
			// std::cout << studentsGrades[i].nome << "\n";
		}
		else
		{
			studentsGrades[i].respostas[j] = input;
			// std::cout << studentsGrades[i].respostas[j] << "\n";

			j++;
			if (j == 10)
			{
				j = 0;
				i++;
			}
		}
	}

	std::cout << "\n";

	// std::cout << "-- Candidatos e acertos --"
	// 		  << "\n";
	for (int i = 0; i < countCandidates; ++i)
	{

		studentsGrades[i].acertos = countAcertos(studentsGrades[i].respostas, 10, questions);
		// 	// studentsGrades[i].acertos = countAcertos(studentsGrades[i].respostas, 10, c_questions);
		// studentsGrades[i].acertos = countAcertos(studentsGrades[i].respostas, 10);
		// std::cout << studentsGrades[i].nome << " - " << studentsGrades[i].acertos << "\n";
	}

	// for (int i = 0; i < 10; ++i)
	// {
	// 	// std::cout << questions[i].questao[i] << " - " << questions[i].c_questions[i] << "\n";
	// 	std::cout << questions.c_questions[i] << "\n";
	// }

	if (answear_type == "best")
	{
		quickSort_D(studentsGrades, 0, countCandidates - 1);
		std::cout << "Os " << quantity << " melhores candidatos:"
				  << "\n";
		std::cout << "NOME"
				  << " - "
				  << "ACERTOS"
				  << "\n";

		// std::cout << "QUESTAO - ACERTOS"
		// 		  << "\n";
		for (int i = 0; i < quantity; ++i)
		{
			std::cout << studentsGrades[i].nome << " - " << studentsGrades[i].acertos << "\n";
		}
	}
	else if (answear_type == "worst")
	{
		quickSort_C(studentsGrades, 0, countCandidates - 1);
		std::cout << "Os " << quantity << " piores candidatos:"
				  << "\n";
		std::cout << "NOME"
				  << " - "
				  << "ACERTOS"
				  << "\n";
		for (int i = 0; i < quantity; ++i)
		{
			std::cout << studentsGrades[i].nome << " - " << studentsGrades[i].acertos << "\n";
		}
	}
	else if (answear_type == "best-questions")
	{
		quickSort_best_questions(questions, 0, 9);
		std::cout << "As " << quantity << " questões que tiveram mais acertos:"
				  << "\n";
		for (int i = 0; i < quantity; ++i)
		{
			std::cout << questions.questao[i] << " "
					  << ": " << questions.c_questions[i] << " acertos"
					  << "\n";
		}
	}
	else if (answear_type == "worst-questions")
	{
		quickSort_worst_questions(questions, 0, 9);
		std::cout << "As " << quantity << " questões que tiveram menos acertos:"
				  << "\n";
		for (int i = 0; i < quantity; ++i)
		{
			std::cout << questions.questao[i] << " "
					  << ": " << questions.c_questions[i] << " acertos"
					  << "\n";
		}
	}

	delete studentsGrades;
	// delete questions;

	return 0;
}