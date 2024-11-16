#include "quiz.h"

void Quiz::test()
{
    srand(time(0));

}

void Quiz::study()
{
    throw runtime_error("study not implemented");
}

void Quiz::addFlashcards() {
    string question;
    string answer;

    cout << "Enter a question: " << endl;
    getline(cin, question);
    cout << "Enter the answer: " << endl;
    getline(cin, answer);
    Flashcards newFlashCard = Flashcards(question, answer);
    flashcard.push_back(newFlashCard);
}