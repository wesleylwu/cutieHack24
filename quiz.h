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
        vector<Flashcards> flashcards;

    public:
        static void test();
        static void study();
};