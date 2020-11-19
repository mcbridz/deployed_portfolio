//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <list>
#include "Queue.h"
#include <sstream>

using namespace std;
void findMatch(string startWord, string endWord, list<string>& library);
bool oneLetterOff(string startWord, string endWord);
void findMatchHelper(string startWord, string endWord, list<string>& library, Queue<string>& path, Queue<string>& thingsToTry);
void tempLibrary(Queue<string>& thingsToTry, int position, string original);
void removeWordFromLibrary(string startWord, list<string>& library);
static bool doneMaster = false;
int main()
{
    ofstream log("log.txt");
    log << "Starting Program" << endl;
    ifstream inFile("FiveLetterWords.txt");
    if( !inFile.is_open() ) {
        cout << "Error opening file" << endl;
        return 1;
    }else{
        cout << "FiveLetterWords.txt is open." << endl;
    }
    list<string> library;
    while(!inFile.eof()){
        string input;
        inFile >> input;
        library.push_back(input);
        input = "";
    }
    //cout << "Library is built, first word is: " << library.front() << endl << "Last word is: " << library.back() << endl << endl;

    string startWord, endWord;
    cout << "Enter the start word for your ladder:";
    cin >> startWord;
    cout << "Enter the end word for your ladder:";
    cin >> endWord;
    for(int i=0;i<static_cast<int>(startWord.length());i++){
        startWord.at(i) = tolower(startWord.at(i));
    }
    for(int i=0;i<static_cast<int>(endWord.length());i++){
        startWord.at(i) = tolower(startWord.at(i));
    }
    findMatch(startWord, endWord, library);
}
bool oneLetterOff(string startWord, string endWord){
    if(startWord ==""){return false;}
    int count = 0;
    for(int i=0; i<static_cast<int>(startWord.length()); i++){
        if (startWord[i] != endWord[i]){
            count++;
        }
    }
    if(count > 1){
        return false;
    }else{
        return true;
    }
}
void tempLibrary(Queue<string>& thingsToTry, int position, string original){
    ofstream log("log.txt", std::ios_base::app | std::ios_base::out);
    log << "Building library around: " << original << endl;
    string temp = original;
    char insert = 'a';
    for(int i=0; i<26; i++){
        if(insert != original.at(position)){
            temp.at(position) = insert;
            thingsToTry.enqueue(temp);
        }
        insert++;
    }
}
bool libraryMatch(string input, list<string>& library){
    ofstream log("log.txt", std::ios_base::app | std::ios_base::out);
    log << "Starting function LIBRARYMATCH" << endl;
    log << "Start word is : " << input << endl;
    auto current = library.begin();
    while(current != library.end()){
        if(input == *current){
            *current = "";
            return true;
        }
        current++;
    }
    return false;
}
void findMatchHelper(string startWord, string endWord, list<string>& library, Queue<string>& path, Queue<string>& thingsToTry, bool* done){
    done = &doneMaster;
    ofstream log("log.txt", std::ios_base::app | std::ios_base::out);
    log << "Starting function FINDMATCHHELPER." << endl;
    log << "Current word is: " << startWord << endl << "Current target word is :" << endWord << endl;
    if (oneLetterOff(startWord, endWord)){
        *done = true;
        path.wordLadderPrint();
        cout << /*startWord << "->" << */endWord << endl;
        return;
    }else{
        for(int i=0; i<5; i++){
            tempLibrary(thingsToTry, i, startWord);
        }
        while(!thingsToTry.isEmpty()){
            if(*done == true) return;
            if(libraryMatch(thingsToTry.front(), library)){
                string nextWord = thingsToTry.front();
                path.enqueue(thingsToTry.dequeue());
                Queue<string> leftovers(thingsToTry);
                while(!thingsToTry.isEmpty()){
                    thingsToTry.dequeue();
                }
                findMatchHelper(nextWord, endWord, library, path, thingsToTry, done);
                if(*done == true) return;
                else {findMatchHelper(leftovers.front(), endWord, library, path, leftovers, done);}
            }
            else{
                thingsToTry.dequeue();
            }
        }
    }

}
void findMatch(string startWord, string endWord, list<string>& library){
    if(startWord == endWord){
        cout << startWord << "->" << endWord << endl;
        return;
    }else{
        if (oneLetterOff(startWord, endWord)){
            cout << startWord << "->" << endWord << endl;
            return;
        }else{
            removeWordFromLibrary(startWord, library);
            Queue<string> path;
            Queue<string> thingsToTry;
            path.enqueue(startWord);
            findMatchHelper(startWord, endWord, library, path, thingsToTry, &doneMaster);
            return;
        }
    }
}
void removeWordFromLibrary(string startWord, list<string>& library){
    auto current = library.begin();
    while(*current != startWord){
        current++;
    }
    *current = "";
}
