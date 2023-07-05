#include <bits/stdc++.h>
using namespace std;

const int MAX_GUESSES = 6;
string movie, maskedMovie, p1Name, p2Name;
char guess;
vector<int> guessedLetters(26);
vector<int> lettersOfMovie(26);
unordered_map<string, int> mp;
int choice, rounds, incorrectGuesses = 0, roundCount = 1, randomIndex;
unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
vector<string> movies = {"INCEPTION", "BATMAN", "TENET", "SPIDERMAN", "MISSION IMPOSSIBLE", "DARK KNIGHT RISES",
                          "BATMAN BEGINS", "TITANIC", "IRON MAN", "WONDER WOMAN", "JURASSIC PARK", "BULLET TRAIN",
                          "WORLD WAR Z", "ANT MAN", "HARRY POTTER", "THE SOCIAL NETWORK", "NOW YOU SEE ME",
                          "THE ITALIAN JOB", "RIO", "MEMENTO", "THE PRESTIGE", "OPPENHEIMER", "INTERSTELLAR",
                          "DUNKRIK", "AMERICAN PSYCHO", "JOKER", "THE MARTIX", "AVATAR", "DA VINCI CODE", "JOHN WICK",
                          "PASSENGERS", "THE HUNGER GAMES", "GHOST RIDER", "DAY AND KNIGHT", "EXTRACTION",
                          "The Grand Budapest Hotel", "TOY STORY", "BLACK PANTHER", "THE EXORCIST", "CONJURING",
                          "PARANORMAL ACTIVITIES", "FAST AND FURIOUS", "RUSH HOUR", "CENTRAL INTELLIGENCE",
                          "The Lord of the Rings", "TANGLED", "MOANA", "WALL E", "HAPPY FEET", "MULAN"};


// Function to display the hangman based on the number of incorrect guesses
void displayHangman(int incorrectGuesses) {
    cout << "  _______\n";
    cout << " |       |\n";

    if (incorrectGuesses >= 1) {
        cout << " |       O\n";
    } else {
        cout << " |\n";
    }

    if (incorrectGuesses >= 2) {
        if (incorrectGuesses == 2) {
            cout << " |       |\n";
        } else if (incorrectGuesses == 3) {
            cout << " |      /|\n";
        } else {
            cout << " |      /|\\\n";
        }
    } else {
        cout << " |\n";
    }
    
    if (incorrectGuesses >= 5) {
        if (incorrectGuesses == 5) {
            cout << " |      /\n";
        } else {
            cout << " |      / \\\n";
        }
    } else {
        cout << " |\n";
    }

    cout << " |\n";
    cout << "_|___\n";
    cout << "\n";
}




// Function to reset the game variables
void reset() {
    for (int i = 0; i < 26; i++) {
        guessedLetters[i] = 0;
        lettersOfMovie[i] = 0;
    }
    incorrectGuesses = 0;
}


// Function to update the masked movie string with the guessed letter
void updateMaskedMovie(string movie, string& maskedMovie, char guess) {
    for (int i = 0; i < movie.length(); i++) {
        if (movie[i] == guess) {
            maskedMovie[i] = guess;
        }
    }
}


// Function to display the masked movie string
void displayMaskedMovie(string maskedMovie) {
    cout << "Movie: ";
    for (char c : maskedMovie) {
        cout << c << " ";
    }
    cout << "\n";
}


// Function to play the game against the computer
void playWithComputer() {
    system("clear");
    reset();
    randomIndex = rand() % movies.size();
    movie = movies[randomIndex];
    maskedMovie = "";
    for (int i = 0; i < movie.size(); i++) {
        movie[i] = toupper(movie[i]);
        lettersOfMovie[movie[i] - 'A'] = 1;
        if (isalpha(movie[i]) && (vowels.find(movie[i]) == vowels.end()))
            maskedMovie += '_';
        else
            maskedMovie += movie[i];
    }

    cout << p2Name << ", try to guess the movie!\n";

    while (incorrectGuesses < MAX_GUESSES && maskedMovie != movie) {
        displayHangman(incorrectGuesses);
        displayMaskedMovie(maskedMovie);

        cout << "Guess a letter: ";
        cin >> guess;
        guess = toupper(guess);
        if (vowels.find(guess) != vowels.end()) {
            cout << "Vowels are already displayed. Try again.\n";
            continue;
        }
        if (guessedLetters[guess - 'A']) {
            cout << "You have already guessed that letter. Try again.\n";
            continue;
        }

        guessedLetters[guess - 'A'] = 1;

        if (lettersOfMovie[guess - 'A']) {
            updateMaskedMovie(movie, maskedMovie, guess);
            cout << "Correct guess!\n";
        } else {
            cout << "Incorrect guess!\n";
            incorrectGuesses++;
        }
        cout << "\n";
    }

    displayHangman(incorrectGuesses);
    displayMaskedMovie(maskedMovie);

    if (maskedMovie == movie) {
        cout << "Congratulations " << p2Name << "! You won!\n";
    } else {
        cout << "Sorry " << p2Name << ", you ran out of guesses. The movie was: " << movie << "\n\n";
    }
    
    cout << "1. Play another match with computer." << endl;
    cout << "2. Go to menu." << endl;
    cin >> choice;
    
    system("clear");

    if (choice == 1)
    playWithComputer();
    
    else if (choice == 2)
    return;
    
    else 
    cout << "Invalid Choice, returning to menu...\n\n";
    return;
}


// Function to play the game between two players
void game(string s1, string s2) {
    reset();
    cout << s1 << ", enter a movie: ";
    cin.ignore();
    getline(cin, movie);
    maskedMovie = "";
    for (int i = 0; i < movie.size(); i++) {
        movie[i] = toupper(movie[i]);
        lettersOfMovie[movie[i] - 'A'] = 1;
        if (isalpha(movie[i]) && (vowels.find(movie[i]) == vowels.end()))
            maskedMovie += '_';
        else
            maskedMovie += movie[i];
    }

    cout << s2 << ", try to guess the movie!\n";

    while (incorrectGuesses < MAX_GUESSES && maskedMovie != movie) {
        displayHangman(incorrectGuesses);
        displayMaskedMovie(maskedMovie);

        cout << "Guess a letter: ";
        cin >> guess;
        guess = toupper(guess);
        if (vowels.find(guess) != vowels.end()) {
            cout << "Vowels are already displayed. Try again.\n";
            continue;
        }
        if (guessedLetters[guess - 'A']) {
            cout << "You have already guessed that letter. Try again.\n";
            continue;
        }

        guessedLetters[guess - 'A'] = 1;

        if (lettersOfMovie[guess - 'A']) {
            updateMaskedMovie(movie, maskedMovie, guess);
            cout << "Correct guess!\n";
        } else {
            cout << "Incorrect guess!\n";
            incorrectGuesses++;
        }
        cout << "\n";
    }

    displayHangman(incorrectGuesses);
    displayMaskedMovie(maskedMovie);

    if (maskedMovie == movie) {
        mp[s2] += 10;
        cout << "Congratulations " << s2 << "! You guessed the movie correctly.\n";
    } else {
        cout << "Sorry " << s2 << ", you ran out of guesses. The movie was: " << movie << "\n\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(7));
    system("clear");
}


// Function to play the game between two players for multiple rounds
void twoPlayer(string s1, string s2, int n) {
    system("clear");
    if (roundCount <= rounds) {
        cout << "Round " << roundCount << "/" << rounds << " begins"<<endl<<endl;
    }
    roundCount++;

    if (n == 0) {
        cout << "All rounds are over.\n";
        if (mp[s2] > mp[s1]) {
            cout << "Congratulations " << s2 << ", you are the winner!\n";
        } else if (mp[s1] > mp[s2]) {
            cout << "Congratulations " << s1 << ", you are the winner!\n";
        } else {
            cout << "It's a tie. You both played well and scored " << mp[s1] << " points.\n";
        }
        mp.erase(s1);
        mp.erase(s2);
        roundCount = 1;
        cout << endl;
        return;
    }

    game(s1, s2);
    game(s2, s1);
    system("clear");
    cout << "Round " << roundCount - 1 << " Standings :\n" << s1 << ", your score is " << mp[s1] << ".\n" << s2 << ", your score is " << mp[s2] << ".\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(7));
    twoPlayer(s1, s2, n - 1);
}

void printMenu(){
    cout << "Pick 1 choice" << endl;
    cout << "1. Display rules of game" << endl;
    cout << "2. Play with computer." << endl;
    cout << "3. Play with friend." << endl;
    cout << "4. Exit" << endl << endl;
}

void printRules(){
    cout<<"In this game, you have to guess name of movie with only vowels being displayed."<<endl;
    cout<<"Each time an incorrect guess is made, the hang-man figure will get completed with 1 stick at a time."<<endl;
    cout<<"And once the figure is completed, you run out of chances. So make your choice carefully!"<<endl;
    cout<<"You can play with either computer or with your friend, i.e. 2-player."<<endl;
    cout<<"Good luck on guessing!!"<<endl;
    cout<<endl;
}

int main() {
    while (1) {
        printMenu();
        cin >> choice;
        
        system("clear");
        
        if(choice==1)
        {
            printRules();
        }

        else if (choice == 2) {
            cout << "Please enter your name:\n";
            cin >> p2Name;
            cout << endl;
            playWithComputer();
            system("clear");
        } 
        
        else if (choice == 3) {
            cout << "Enter the name of player 1:\n";
            cin >> p1Name;
            cout << "Enter the name of player 2:\n";
            cin >> p2Name;
            cout << "Enter the number of rounds you want to play:\n";
            cin >> rounds;
            twoPlayer(p1Name, p2Name, rounds);
        } 
        
        else if (choice == 4)
        break;
        
        else {
            cout << endl;
            cout << "Invalid Choice, Please enter a valid choice." << endl;
        }
    }

    return 0;
}
