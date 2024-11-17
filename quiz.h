#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include "flashcards.h"

using namespace std;

class Quiz 
{
    private:
        vector<Flashcards> flashcard;

    public:
        bool isSentence(string );
        void addFlashcards();
        void removeFlashcards();
        void removeFlashcardHelper(vector<Flashcards> &, int);
        void displayAllFlashcards();
        int displayQuestions(vector<Flashcards>);
        void test();
        void study();
};