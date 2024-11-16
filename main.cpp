#include "quiz.h"
#include <string>

int main()
{
    int choice;
    Quiz flashcards;
    cout << "Welcome to our quiz maker!" << endl;
    cout << "(1) Add new flashcard" << endl;
    cout << "(2) Study flashcards" << endl;
    cout << "(3) Exit Program" << endl;
    cin >> choice;
    while (choice != 1 || choice != 2 || choice != 3) {
        cout << "Invalid input. Please enter valid number.";
        cin >> choice;
    }

    if (choice == 1) {
        flashcards.addFlashcards();
    }

    if (choice == 2) {
        flashcards.study();
    }

    if (choice == 3) {
        return 0;
    }

    return 0;
}