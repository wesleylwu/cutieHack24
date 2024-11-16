#include <iostream>
#include <string>
using namespace std;

class Flashcards
{
    private:
        string questions;
        string answers;
    public:
        Flashcards(string, string);
        void setQuestions(string);
        void setAnswers(string);
        string getQuestions();
        string getAnswers();
};