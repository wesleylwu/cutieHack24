#include "quiz.h"
#include <unordered_set>

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
       cout << i+1 <<". " << used.getQuestions() << endl;
       if (isSentence(used.getAnswers())) { 
           if(flashcard.size()<4){
               string stringAnswer;
               cout << "\nEnter your answer: " << endl;
               getline(cin, stringAnswer);
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
           else{
               vector<string> answerChoice;
               unordered_set<int> usedIndices;
               usedIndices.insert(randIndex); 
               while (answerChoice.size() < 3) {
                   int incorrectIndex = rand() % flashcard.size();
                   if (usedIndices.find(incorrectIndex) == usedIndices.end()) { 
                       answerChoice.push_back(flashcard[incorrectIndex].getAnswers());
                       usedIndices.insert(incorrectIndex);
                   }
               }

               int correctPosition = rand() % 4;
               answerChoice.insert(answerChoice.begin() + correctPosition, used.getAnswers());

               int userChoice;
               bool validInput = false;
               while (!validInput) {
                   for (int k = 0; k < 4; k++) {
                       cout << k + 1 << ". " << answerChoice[k] << endl;
                   }
                   cout << "Enter the number of the correct answer: ";
                   cin >> userChoice;


                   if (cin.fail() || userChoice < 1 || userChoice > 4) {
                       cout << "\nInvalid input. Please try again.\n" << endl;
                       cin.clear();
                       cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   } else {
                       validInput = true;
                   }
               }


               if (answerChoice[userChoice - 1] == used.getAnswers()) {
                   cout << "Correct!" << endl;
               } else {
                   cout << "Incorrect!" << endl;
                   i--; 
                   indexUsed.pop_back(); 
               }
           }
       }
       else{ //if word or number, type it out
           string stringAnswer;
           cout << "\nEnter your answer(if you don't know, enter idk): " << endl;
           cin >> stringAnswer;
           if(stringAnswer == used.getAnswers()){
               cout << "Correct!" << endl;
           }
           else if(stringAnswer == "idk"){
               cout << "The correct answer is: " << used.getAnswers() << endl;
               i--;
               for(int k=0;k<indexUsed.size();k++){
                   if(indexUsed.at(k)==usingIndex){
                       indexUsed.erase(indexUsed.begin()+k);
                   }
               }
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
    int num;
    int numChoice;
    char category;
    string answer;
    bool choice = true;
    bool cont = true;
    vector<Flashcards> previousCards;
    vector<Flashcards> remainingCards;
    remainingCards = flashcard;

    while (cont)
    {
        choice = true;
        cout << "Remaining questions not studied: " << endl;
        displayQuestions(remainingCards);
        cout << endl;
        cout << "Previous questions studied: " << endl;
        displayQuestions(previousCards);
        cout << endl;

        cout << "Select the category of questions you would like to study (R or P) or 'q' if you would like to quit: ";
        cin >> category;
        if (category == 'q')
        {
            break;
        }
        bool flag=true;
        while(flag){
            if(category != 'R' && category != 'r' && category != 'P' && category != 'p'){
                cout << "Invalid category. Try again: ";
                cin >> category;
                cout << endl;
                continue;
            }
            else if(remainingCards.empty()&&(category=='r' || category == 'R')){
                cout << "No remaining flashcard. Try again: ";
                cin >> category;
                cout << endl;
            }
            else if(previousCards.empty()&&(category=='p' || category == 'P')){
                cout << "No previous flashcard. Try again: ";
                cin >> category;
                cout << endl;
            }
            else{
                flag=false;
            }
        }

        cout << "Select the card number in category " << category << " you would like to study: ";
        cin >> num;
        num -= 1;

        if (category == 'R' || category == 'r')
        {
            while (num < 0 || num >= remainingCards.size())
            {
                cout << "Invalid number. Try again: ";
                cin >> num;
                num -=1;
                cout << endl;
            }
        }

        else if (category == 'P' || category == 'p')
        {
            while (num < 0 || num >= remainingCards.size())
            {
                cout << "Invalid number. Try again: ";
                cin >> num;
                num -= 1;
                cout << endl;
            }
        }
        
        if (category == 'R' || category == 'r')
        {
            cout << remainingCards.at(num).getQuestions() << endl;
            while (choice)
            {
                cout << "Enter your answer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, answer);
                if (answer == remainingCards.at(num).getAnswers())
                {
                    cout << "Correct!" << endl;
                }
                else 
                {
                    cout << "Incorrect. Try again." << endl;
                }
                cout << "Type 1 to go back to questions or another key to try again: " << endl;
                cin >> numChoice;
                if (numChoice == 1)
                {
                    choice = false;
                    removeFlashcardHelper(remainingCards, previousCards, num);
                }
            }
        }
        if (category == 'P' || category == 'p')
        {
            cout << previousCards.at(num).getQuestions() << endl;
            while (choice)
            {
                cout << "Enter your answer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, answer);
                if (answer == previousCards.at(num).getAnswers())
                {
                    cout << "Correct!" << endl;
                }
                else 
                {
                    cout << "Incorrect. Try again." << endl;
                }
                cout << "Type 1 to go back to questions or another key to try again: " << endl;
                cin >> numChoice;
                if (numChoice == 1)
                {
                    choice = false;
                }
            }
        }
    }
}

void Quiz::removeFlashcardHelper(vector<Flashcards> &fc1, vector<Flashcards> &fc2, int n)
{
    vector<Flashcards> newFlashcards;
    
    for (int i = 0; i < fc1.size(); ++i)
    {
        if (n != i)
        {
            newFlashcards.push_back(flashcard.at(i));
        }
        else
        {
            fc2.push_back(flashcard.at(i));
        }
    }

    fc1 = newFlashcards;
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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

bool Quiz::displayQuestions(vector<Flashcards> cards)
{
    if (cards.size() == 0)
    {
        cout << "None" << endl;
        return true;
    }

    for (int i = 0; i < cards.size(); ++i)
    {
        cout << i + 1 << ". ";
        cout << "Q: " << cards.at(i).getQuestions() << endl;
    }

    return false;
}

vector<Flashcards> Quiz::getList()
{
    return flashcard;
}

void Quiz::setList(Flashcards c)
{
    flashcard.push_back(c);
}