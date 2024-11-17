#include "quiz.h"

void Quiz::test()
{
    srand(time(0));
    vector<int> indexUsed;
    string stringAnswer;
    int randIndex;
    bool flag = true;
    for(int i=0;i<flashcard.size();i++){//for every questions
        flag = true;
        while(flag){//find random index not repeating
            flag=false;
            randIndex = rand()%flashcard.size();
            for(int j=0;j<indexUsed.size();j++){
                if(indexUsed.at(j)==randIndex){
                    flag=true;
                }
            }
        }
        indexUsed.push_back(randIndex);


        Flashcards used = flashcard[randIndex];
        int usingIndex=randIndex;
        cout << i+1 <<". " << used.getQuestions() << endl;//print out question
        if(isSentence(used.getAnswers())){//if sentence, multiple choice
            vector<string> answerChoice;
            vector<int> answerChoiceIndex;
            for(int k = 0; k<3; k++){
                while(flag){//find random index not repeating
                    flag=false;
                    randIndex = rand()%flashcard.size();
                    for(int j=0;j<answerChoiceIndex.size();j++){
                        if(answerChoiceIndex.at(j) == randIndex || used.getQuestions()==flashcard[randIndex].getQuestions()){
                            flag=true;
                        }
                    }
                }
                answerChoice.push_back(flashcard[randIndex].getAnswers());
            }

            randIndex=rand()%4;
            answerChoice.insert(answerChoice.begin()+randIndex,used.getAnswers());
            flag=true;
            while(flag){
                flag=false;
                for(int k=0; k<4; k++){
                    cout << endl << k+1 << ". " << answerChoice[k] << endl;
                }
                cout << "Enter the number that you think it is correct." << endl;
                int intAnswer;
                cin >> intAnswer;
                if(cin.fail() || 1 > intAnswer || 4 < intAnswer){
                    cout << "\nInvalid Input\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    flag=true;
                }

                if(answerChoice[intAnswer-1] == used.getAnswers()){
                cout << "Correct!" << endl;
                }
                else{
                cout << "Incorrect!" << endl;
                i--;
                for(int k=0;k<indexUsed.size();k++){
                    if(indexUsed.at(k)==usingIndex){
                        indexUsed.erase(indexUsed.begin()+k);
                    }
                }
                }
            }

            
        }
        else{//if word or number, type it out
            string stringAnswer;
            cout << "\nEnter your answer: " << endl;
            cin >> stringAnswer;
            if(stringAnswer == used.getAnswers()){
                cout << "Correct!" << endl;
            }
            else{
                cout << "Incorrect!" << endl;
                i--;
                for(int k=0;k<indexUsed.size();k++){
                    if(indexUsed.at(k)==usingIndex){
                        indexUsed.erase(indexUsed.begin()+k);
                    }
                }
            }
        }
    }
}

bool Quiz::isSentence(string str){
    int unsigned start =0, end=str.length()-1; 
    while (start < str.length() && isspace(str[start])) {
        start++;
    }
    while (end > start && std::isspace(str[end])) {
        end--;
    }
    if (start > end) {
        return false;
    }
    for (int i = start; i <= end; i++) {
        if (std::isspace(str[i])) {
            return true;
        }
    }
    return false;
}


void Quiz::addFlashcards() {
    string question;
    string answer;

    cout << "Enter a question: " << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, question);
    cout << "Enter the answer: " << endl;
    getline(cin, answer);
    Flashcards newFlashCard = Flashcards(question, answer);
    flashcard.push_back(newFlashCard);
}

void Quiz::study() {
    cout << "asjdhf" << endl;
}

void Quiz::removeFlashcards()
{
    if (flashcard.size() == 0)
    {
        cout << "There are currently no flashcards stored." << endl;
        return;
    }

    int num;
    vector<Flashcards> newFlashcards;
    cout << "What number flashcard would you like to remove? ";

    cin >> num;
    if (num >= flashcard.size())
    {
        cout << endl;
        cout << "Invalid number. Try again: ";
        cin >> num;
    }
    num -= 1;

    cout << endl;

    for (int i = 0; i < flashcard.size(); ++i)
    {
        if (num != i)
        {
            newFlashcards.push_back(flashcard.at(i));
        }
    }

    flashcard = newFlashcards;
}

void Quiz::displayAllFlashcards()
{
    for (int i = 0; i < flashcard.size(); ++i)
    {
        cout << i + 1 << ". ";
        cout << "Q: " << flashcard.at(i).getQuestions() << "\n   A: " << flashcard.at(i).getAnswers() << endl;
    }
}