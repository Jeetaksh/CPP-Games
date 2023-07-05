#include <bits/stdc++.h>

using namespace std;

vector<string> words, sequence;
string s, word, p1Name, p2Name;
int i;

void addWord() {
    cin >> s;
    for (char& c : s) {
        c = toupper(c);
    }
    words.push_back(s);
}

bool isCorrect() {
    if (sequence.size() != words.size()) {
        return false;
    }
    for (i = 0; i < sequence.size(); i++) {
        if (words[i] != sequence[i]) {
            return false;
        }
    }
    return true;
}

void makeSequence() {
    sequence.clear();
    word = "";
    s+=' ';
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            sequence.push_back(word);
            word = "";
        }
        else {
            word += toupper(s[i]);
        }
    }
}

void printCorrectSequence() {
    cout << "The correct sequence was ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\nThank you for playing!\n\n";
}

void printRules() {
    system("clear");
    cout << "The rules are as follows:\n";
    cout << "You both have to remember all the words added in sequence.\n";
    cout << "After you tell them correctly, you will add a word to it.\n";
    cout << "The first person to tell an incorrect sequence loses.\n\n";
}

void printMenu() {
    cout<<"Welcome to the game. Enter a number:\n";
    cout<<"1) Display Rules\n";
    cout<<"2) Play Game\n";
    cout<<"3) Exit\n\n";
}

void playGame(){
    i = 0;
    cout << "Enter player 1 name: ";
    cin.ignore();
    getline(cin, p1Name);
    cout << endl;
    cout << "Enter player 2 name: ";
    getline(cin, p2Name);
    cout << endl << endl;

    while (true) {
        if (i == 0) {
            cout << p1Name << ". Please enter the first word of the sequence.\n";
            addWord();
            system("clear");
            cout<< p1Name << " added the word " << s;
            i++;
        }
        else if (i % 2 == 1) {
            cout << endl << p2Name << ". Please enter the sequence so far, separate the words by a single space.\n";
            cin.ignore();
            getline(cin, s);
            makeSequence();
            if (isCorrect()) {
                cout << "\nGreat, you guessed it perfectly! Add a word to it.\n";
                addWord();
                system("clear");
                cout<< p2Name << " added the word " << s;
            }
            else {
                system("clear");
                cout << "\nSorry " << p2Name << ", that was an incorrect sequence. " << p1Name << " wins.\n";
                printCorrectSequence();
                break;
            }
            i++;
        }
        else {
            cout << endl << p1Name << ". Please enter the sequence so far, separate the words by a single space.\n";
            cin.ignore();
            getline(cin, s);
            makeSequence();
            if (isCorrect()) {
                cout << "\nGreat, you guessed it perfectly! Add a word to it.\n";
                addWord();
                system("clear");
                cout<< p1Name << " added the word " << s;
            }
            else {
                system("clear");
                cout << "\nSorry " << p1Name << ", that was an incorrect sequence. " << p2Name << " wins.\n";
                printCorrectSequence();
                break;
            }
            i++;
        }
    }
}

int main() {
    while(1){
        printMenu();
        cin>>i;
        if(i==1){
            printRules();
        }
        else if(i==2){
            playGame();
        }
        else if(i==3){
            break;
        }
        else{
            system("clear");
            cout<<"Invalid choice, choose again.\n";
        }
    }
    
    return 0;
}
