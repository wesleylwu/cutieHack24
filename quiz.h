#include <iostream>
#include <vector>
using namespace std;

class Quiz 
{
    private:
        vector<string> questions;
        vector<string> answers;

    public:
        Quiz(vector<string>, vector<string>);
        void setQuestions();
        void setAnswers();
        string getQuestions();
        string getAnswers();
        void test();
        void study();
};