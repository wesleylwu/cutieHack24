#include <iostream>
#include <string>
using namespace std;

class Flashcards
{
    private:
        string question;
        string answer;
    public:
        Flashcards(string, string);
        void setQuestions(string);
        void setAnswers(string);
        string getQuestions();
        string getAnswers();
};