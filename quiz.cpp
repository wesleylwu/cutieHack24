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

void Quiz::removeFlashcards()
{
    int num;
    vector<Flashcards> newFlashcards;
    cout << "What number flashcard would you like to remove? ";

    cin >> num;
    num -= 1;

    cout << endl;

    for (int i = 0; i < flashcard.size(); ++i)
    {
        if (num != i)
        {
            newFlashcards.push_back(flashcard.at(i));
        }
    }

    flashcard = newFlashcards;
}

void Quiz::displayAllFlashcards()
{
    for (int i = 0; i < flashcard.size(); ++i)
    {
        cout << i + 1 << ". ";
        cout << "Q: " << flashcard.at(0).getQuestions() << " A: " << flashcard.at(0).getAnswers() << endl;
    }
}