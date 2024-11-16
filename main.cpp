#include "quiz.h"
#include <string>

int main()
{
    int choice;
    Quiz flashcards;
    cout << "Welcome to our quiz maker!" << endl << endl;

    while (choice != 3)
    {
        cout << "Options:" << endl;
        cout << "(1) Add new flashcard" << endl;
        cout << "(2) Remove flashcard" << endl;
        cout << "(3) Study flashcards" << endl;
        cout << "(4) Test flashcards" << endl;
        cout << "(5) Display flashcards" << endl;
        cout << "(6) Exit Program" << endl;
        cout << "Enter a number choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            flashcards.addFlashcards();
        }

        else if (choice == 2) {
            flashcards.removeFlashcards();
        }
        
        else if (choice == 3) {
            flashcards.study();
        }

        else if (choice == 4) {
            flashcards.test();
        }

        else if (choice == 5) {
            flashcards.displayAllFlashcards();
        }

        else if (choice == 6) {
            return 0;
        }

        else {
            cout << "Invalid input. Please enter valid number: " << endl;
        }

        cout << endl;
    }

    return 0;
}