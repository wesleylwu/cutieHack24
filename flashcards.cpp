#include "flashcards.h"
#include <string>

Flashcards::Flashcards(string q, string a)
{
    question = q;
    answer = a;
}

void Flashcards::setQuestions(string q)
{
    question = q;
}

void Flashcards::setAnswers(string a)
{
    answer = a;
}

string Flashcards::getQuestions()
{
    return question;
}

string Flashcards::getAnswers()
{
    return answer;
}