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
        void addFlashcards();
        void removeFlashcards();
        void displayAllFlashcards();
        void test();
        void study();
};