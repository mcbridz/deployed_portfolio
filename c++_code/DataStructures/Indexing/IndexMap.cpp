//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "IndexMap.h"

using namespace std;

int primes[11] = {29, 47, 113, 397, 659, 1451, 3571, 6367, 12011, 24877, 31991};
int nextPrime(int currentPrime){
    if(primes[0] > currentPrime) return primes[0];
    for(int i=0; i<11; i++){
        if(primes[i+1] > currentPrime){
            return primes[i+1];
        }
    }
    return 31991;
}

IndexMap::IndexMap(int startingBuckets){
    keyCount = 0;
    buckets = new IndexRecord [startingBuckets];
    numBuckets = startingBuckets;
}
IndexMap::~IndexMap(){
    delete [] buckets;
    keyCount = 0;
    numBuckets = 0;
}
int hashFunction(const string key, const int modulus){
    int output = 1;
    for(int i=0; i < static_cast<int>(key.length()); i++){
        output += key.at(i);
    }
    output = output % modulus;
    return output;
}
void IndexMap::grow(){
    IndexRecord * temp;
    int newPrime = nextPrime(numBuckets);
    temp = new IndexRecord[newPrime];
    for(int i=0; i<numBuckets; i++){
        if(buckets[i].word != "?"){
            int newHash = hashFunction(buckets[i].word, newPrime);
            for(int r=0; r<newPrime; r++){
                int checker = (newHash+r) % newPrime;
                if(temp[checker].word == "?"){
                    temp[checker].word = buckets[i].word;
                    while(!buckets[i].locations.empty()){
                        temp[checker].locations.push_back(buckets[i].locations.back());
                        buckets[i].locations.pop_back();
                    }
                    break;
                }
            }
        }
    }
    numBuckets = newPrime;
    delete [] buckets;
    buckets = temp;
}
void IndexMap::add(const std::string &key, int pageNumber, int wordNumber){
    string temp;
    for(int i=0; i<static_cast<int>(key.length()); i++){
        temp += tolower(key[i]);
    }
    int hash = hashFunction(temp, numBuckets);
    bool done = false;
    for(int i=0; i < numBuckets; i++){
        if(done)break;
        int checker = (hash+i) % numBuckets;
        if(buckets[checker].word == "?" || buckets[checker].word == "#"){
            buckets[checker].word = temp;
            buckets[checker].locations.push_back(IndexLocation(pageNumber, wordNumber));
            keyCount++;
            done = true;
            break;
        }else if(buckets[checker].word == temp){
            buckets[checker].locations.push_back(IndexLocation(pageNumber, wordNumber));
            done = true;
            break;
        }
        if(done)break;
    }
    if(double(keyCount / numBuckets) >= 0.7){
        grow();
    }
}
void IndexMap::print() const{
    for(int i=0; i<numBuckets; i++){
        //if(buckets[i].word != "?"){
        cout << buckets[i].word << ": ";
        for(vector<IndexLocation>::const_iterator myIt = buckets[i].locations.begin(); myIt != buckets[i].locations.end(); ++myIt){
            cout << *myIt << " ";
        }
        cout << endl;
    }
    //  }
}
bool IndexMap::contains(const std::string &key) const{
    int hash = hashFunction(key, numBuckets);
    for(int i=0; i<numBuckets; i++){
        int checker = (hash+i) % numBuckets;
        if(buckets[checker].word == key){
            return true;
        }else if(buckets[checker].word == "?"){
            return false;
        }
    }
    return false;
}
IndexRecord IndexMap::get(const std::string &word) const{
    string temp;
    for(int i=0; i<word.length(); i++){
        temp += tolower(word[i]);
    }
    int hash = hashFunction(temp, numBuckets);
    for(int i=0; i<numBuckets; i++){
        int checker = (hash+i) % numBuckets;
        if(buckets[checker].word == temp){
            return buckets[checker];
        }else if(buckets[checker].word == "?"){
            cout << "Word not found." << endl;
            break;
        }
    }
}
int IndexMap::numKeys() const{
    return keyCount;
}
void IndexMap::findWordPairs(const std::string &key1, const std::string &key2) const{
    cout << "Positions where " << key1 << " is directly followed by " << key2 << ":" << endl;
    vector<IndexLocation> firstWord = get(key1).locations;
    vector<IndexLocation> secondWord = get(key2).locations;
    while(!firstWord.empty()){
        IndexLocation temp1 = firstWord.back();
        for(vector<IndexLocation>::iterator myIt = secondWord.begin(); myIt != secondWord.end(); ++myIt){
            int tempPage = temp1.pageNum;
            int tempWord = temp1.wordNum;
            if(myIt->wordNum == tempWord + 1 && (tempPage == myIt->pageNum)){
                cout << firstWord.back() << ", " << *myIt << endl;
            }else
                if(myIt->pageNum == tempPage - 1 && myIt->wordNum == 1){
                    cout << firstWord.back() << ", " << *myIt << endl;
                }
        }
        firstWord.pop_back();
    }
}
string IndexMap::firstWordOnPage(int pageNumber) const{
    cout << "Searching for first word on page number " << pageNumber << "." << endl;
    string output = "No match found.";
    for(int i=0; i<numBuckets; i++){
        if(buckets[i].word != "?"){
            for(vector<IndexLocation>::const_iterator myIt = buckets[i].locations.begin(); myIt != buckets[i].locations.end(); ++myIt){
                if(myIt->pageNum == pageNumber){
                    if(myIt->wordNum == 1){
                        output = "";
                        //cout << buckets[i].word << " is the first word on page " << pageNumber << "." << endl;
                        output += buckets[i].word;
                        output += " is the first word on page ";
                        output += to_string(pageNumber);
                        output += ".";
                        return output;
                    }
                }
            }
        }
    }
    return output;
}
