#include <iostream>
#include <vector>
using namespace std;

class Quiz 
{
    private:
        vector<string> questions;
        vector<string> answers;

    public:
        void setQuestions();
        void setAnswers();
        string getQuestions();
        string getAnswers();
};