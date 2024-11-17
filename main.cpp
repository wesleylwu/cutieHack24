#include "quiz.h"
#include <string>
#include <fstream>
#include <dirent.h>
#include <cstring>

int main()
{
    ifstream inFS;
    int choice;
    Quiz flashcards;
    cout << "Welcome to our quiz maker!" << endl << endl;
    while (true)
    {
        cout << "Options:" << endl;
        cout << "(1) Make new flashcard set" << endl;
        cout << "(2) Load flashcard set" << endl;
        cout << "(3) Exit Program" << endl;
        cout << "Enter a number choice: ";
        cin >> choice;
        cout << endl;


        if (choice == 1) {
            break;
        }

        else if (choice == 2) {
            cout << "What flashcard do you want to get?" << endl << endl;
             const char* directoryPath = ".";


            DIR* dir = opendir(directoryPath);
            if (dir == nullptr) {
                std::cerr << "Error opening directory." << std::endl;
                return 1;
            }


            struct dirent* entry;
            while ((entry = readdir(dir)) != nullptr) {
                if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != nullptr) {
                    std::cout << entry->d_name << std::endl;  
                }
            }


            closedir(dir);
            string filename;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            ifstream myFile(filename);
            if (!myFile) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            return 0;
            }
            string line;
            string question;
            string answer;

            while (getline(myFile, line)) {
        if (line == "...") { 
            if (!question.empty() && !answer.empty()) {
                Flashcards loadFlashCard(question, answer);
                flashcards.setList(loadFlashCard);
                question.clear();
                answer.clear();
            }
        }
        else if (question.empty()) {
            question = line; 
        }
        else {
            answer = line; 
        }
    }

    if (!question.empty() && !answer.empty()) {
        Flashcards loadFlashCard(question, answer);
        flashcards.setList(loadFlashCard);
    }

    myFile.close();
            break;
        }
       
        else if (choice == 3) {
           
            return 0;
        }

        else if(cin.fail() || 1 > choice || 4 < choice){
            cout << "\nInvalid Input\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << endl;
    }

    while (true)
    {
        cout << "Options:" << endl;
        cout << "(1) Add new flashcard" << endl;
        cout << "(2) Remove flashcard" << endl;
        cout << "(3) Study flashcards" << endl;
        cout << "(4) Test flashcards" << endl;
        cout << "(5) Display flashcards" << endl;
        cout << "(6) Exit Program" << endl;
        cout << "Enter a number choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            flashcards.addFlashcards();
        }

        else if (choice == 2) {
            flashcards.removeFlashcards();
        }
        
        else if (choice == 3) {
            flashcards.study();
        }

        else if (choice == 4) {
            flashcards.test();
        }

        else if (choice == 5) {
            flashcards.displayAllFlashcards();
        }

        else if (choice == 6) {
            cout << "How would you like to save (type the file name)?" << endl;
            string filename;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);
            filename+=".txt";
            ofstream myFile(filename, ofstream::trunc);
            if (!myFile) {
                std::cerr << "Error creating file!" << std::endl;
                return 1;
            }

            for(int i=0;i<flashcards.getList().size();i++){
                myFile << flashcards.getList().at(i).getQuestions() << endl;
                myFile << flashcards.getList().at(i).getAnswers() << endl;
                myFile << "..." << endl;
            }
            myFile.close();

            std::cout << "File created and saved successfully." << std::endl;
            return 0;
        }

        else if(cin.fail()){
            cout << "\nInvalid Input\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            cout << "\nInvalid Input \n" << endl;
        }

        cout << endl;
    }

    return 0;
}