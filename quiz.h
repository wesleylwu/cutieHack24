#include <iostream>
#include <vector>
#include "flashcards.h"

using namespace std;

class Quiz 
{
    private:
        vector<Flashcards> flashcards;

    public:
        Quiz(Flashcards );
        void test();
        void study();
};