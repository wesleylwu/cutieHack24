#include <iostream>
#include <vector>
#include "flashcards.h"

using namespace std;

class Quiz 
{
    private:
        vector<Flashcards> flashcards;

    public:
        Quiz(Flashcard);
        void test();
        void study();
};