#include "quiz.h"
#include <string>

int main()
{
    int choice;
    cout << "Welcome to our quiz maker!" << endl << endl;

    while (choice != 3)
    {
        cout << "Options:" << endl;
        cout << "(1) Add new flashcard" << endl;
        cout << "(2) Remove flashcard" << endl;
        cout << "(3) Study flashcards" << endl;
        cout << "(4) Exit Program" << endl;
        cin >> choice;

        if (choice == 1) {
            Quiz::addFlashcards();
        }

        else if (choice == 2) {
            Quiz::removeFlashcards();
        }
        
        else if (choice == 3) {
            Quiz::study();
        }

        else if (choice == 4) {
            return 0;
        }

        else {
            cout << "Invalid input. Please enter valid number: " << endl << endl;
        }
    }

    return 0;
}