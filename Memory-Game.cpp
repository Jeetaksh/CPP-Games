#include <bits/stdc++.h>
using namespace std;

const int GRID_SIZE = 4;
const int NUM_PAIRS = 8;
int incorrectGuess = 0;

// Function to display the current state of the grid
void displayGrid(const std::vector<std::vector<char>>& grid) {
    std::cout << "   1 2 3 4\n";
    cout<<endl;
    int i=1;
    for (const auto& row : grid) {
        cout<<i++<<"  ";
        for (char num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

// Function to initialize the grid with numbers
std::vector<std::vector<char>> initializeGrid() {
    std::vector<std::vector<char>> grid(GRID_SIZE, std::vector<char>(GRID_SIZE, '#'));

    std::vector<char> numbers;
    for (char i = 'A'; i < 'A' + NUM_PAIRS; ++i) {
        numbers.push_back(i);
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    int index = 0;
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            grid[row][col] = numbers[index];
            index++;
        }
    }

    return grid;
}

// Function to check if all pairs have been matched
bool isGameComplete(const std::vector<std::vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char num : row) {
            if (num != ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to prompt the user for a guess and update the grid
void makeGuess(std::vector<std::vector<char>>& grid, std::vector<std::vector<char>>& hiddenGrid) {
    int guess1Row, guess1Col, guess2Row, guess2Col;

    std::cout << "Enter the row and column of the first card (separated by a space): ";
    std::cin >> guess1Row >> guess1Col;
    std::cout << "Enter the row and column of the second card (separated by a space): ";
    std::cin >> guess2Row >> guess2Col;

    guess1Row--;
    guess1Col--;
    guess2Row--;
    guess2Col--;

    if (guess1Row < 0 || guess1Row >= GRID_SIZE || guess1Col < 0 || guess1Col >= GRID_SIZE ||
        guess2Row < 0 || guess2Row >= GRID_SIZE || guess2Col < 0 || guess2Col >= GRID_SIZE || (guess1Row==guess2Row && guess1Col==guess2Col)) {
        std::cout << "Invalid input! Please try again.\n";
        return;
    }

    if (hiddenGrid[guess1Row][guess1Col] == ' ' || hiddenGrid[guess2Row][guess2Col] == ' ') {
        std::cout << "Invalid input! One or both cards have already been matched.\n";
        return;
    }

    if (grid[guess1Row][guess1Col] == grid[guess2Row][guess2Col]) {
        grid[guess1Row][guess1Col] = ' ';
        grid[guess2Row][guess2Col] = ' ';
        hiddenGrid[guess1Row][guess1Col] = ' ';
        hiddenGrid[guess2Row][guess2Col] = ' ';
        std::cout << "Matched!\n";
    } else {
        std::cout << "Not a match!\n";
        incorrectGuess++;
        if (incorrectGuess == 3) {
            std::cout << "You have reached the maximum number of incorrect guesses. Game over.\n";
            exit(0); // Terminate the program
        }
    }
}

// Function to start a new game
void startNewGame() {
    std::cout << "Starting a new game...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("clear");
    incorrectGuess = 0; // Reset the incorrect guess counter
}

int main() {
    bool gameInProgress = true;

    while (gameInProgress) {
        // Initialize the grid and the hidden grid
        std::vector<std::vector<char>> grid = initializeGrid();
        std::vector<std::vector<char>> hiddenGrid(GRID_SIZE, std::vector<char>(GRID_SIZE, 'X'));
        
        cout<<"You will be shown a grid.\n";
        cout<<"You have to memorize location of all pairs.\n";
        cout<<"You have to match all the pairs in less than 3 wrong attempts to win.\n";
        std::this_thread::sleep_for(std::chrono::seconds(15));
        system("clear");
        // Display the original grid for 1 minute
        displayGrid(grid);
        std::cout << "Memorize the grid for 1 minute...\n";
        std::this_thread::sleep_for(std::chrono::seconds(60));
        system("clear");

        // Play the game
        while (!isGameComplete(grid)) {
            // Display the hidden grid
            displayGrid(hiddenGrid);

            // Prompt the user for a guess and update the grid
            makeGuess(grid, hiddenGrid);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("clear");
        }

        std::cout << "Congratulations! You matched all the pairs!\n";

        // Ask if the player wants to play again
        char choice;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;

        if (choice == 'N' || choice == 'n') {
            gameInProgress = false;
        } else {
            incorrectGuess=0;
            startNewGame();
        }
    }

    return 0;
}
