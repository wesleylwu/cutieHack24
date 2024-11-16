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
        static vector<Flashcards> flashcard;

    public:
        static void addFlashcards();
        static void removeFlashcards();
        static void displayAllFlashcards();
        static void test();
        static void study();
};