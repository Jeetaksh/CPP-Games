#include <bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY_CELL = ' ';
const char PLAYER_SYMBOL = 'X';
const char COMPUTER_SYMBOL = 'O';

enum Difficulty {
    EASY = 1,
    DIFFICULT = 2
};

struct Move {
    int row;
    int col;
};

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        vector<char> row(BOARD_SIZE, EMPTY_CELL);
        board.push_back(row);
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "Tic Tac Toe" << endl;
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (j != 0)
                cout << "|";
            cout << ' ' << board[i][j] << ' ';
        }
        cout << endl;
        if (i != BOARD_SIZE - 1)
            cout << "-----------" << endl;
    }
    cout << endl;
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY_CELL);
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL)
                return false;
        }
    }
    return true;
}

bool checkWin(const vector<vector<char>>& board, char symbol) {
    // Check rows and columns for a win
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;

        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }

    // Check diagonals for a win
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char symbol) {
    if (isMoveValid(board, row, col)) {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

Move getRandomMove(const vector<vector<char>>& board) {
    Move move;
    do {
        move.row = rand() % BOARD_SIZE;
        move.col = rand() % BOARD_SIZE;
    } while (!isMoveValid(board, move.row, move.col));
    return move;
}

int evaluateBoard(const vector<vector<char>>& board) {
    if (checkWin(board, PLAYER_SYMBOL))
        return -1;  // Player wins
    else if (checkWin(board, COMPUTER_SYMBOL))
        return 1;   // Computer wins
    else
        return 0;   // Draw
}

int miniMax(vector<vector<char>>& board, int depth, bool isMaximizingPlayer);

Move findBestMove(vector<vector<char>>& board) {
    int bestScore = INT_MIN;
    Move bestMove;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = COMPUTER_SYMBOL;
                int score = miniMax(board, 0, false);
                board[i][j] = EMPTY_CELL;

                if (score > bestScore) {
                    bestScore = score;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    return bestMove;
}

int miniMax(vector<vector<char>>& board, int depth, bool isMaximizingPlayer) {
    int score = evaluateBoard(board);

    if (score != 0)
        return score;

    if (isBoardFull(board))
        return 0;

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = COMPUTER_SYMBOL;
                    int currentScore = miniMax(board, depth + 1, false);
                    board[i][j] = EMPTY_CELL;

                    bestScore = max(bestScore, currentScore);
                }
            }
        }

        return bestScore;
    } else {
        int bestScore = INT_MAX;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = PLAYER_SYMBOL;
                    int currentScore = miniMax(board, depth + 1, true);
                    board[i][j] = EMPTY_CELL;

                    bestScore = min(bestScore, currentScore);
                }
            }
        }

        return bestScore;
    }
}

void playWithComp()
{
    system("clear");
    vector<vector<char>> board;
    initializeBoard(board);
    srand(static_cast<unsigned>(time(0)));

    int choice;
    cout << "1. Easy\n2. Difficult\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case Difficulty::EASY:
        {
            while (true) {
                displayBoard(board);
                int row, col;
                cout << "Enter your move (row [0-2] and column [0-2]): ";
                cin >> row;
                cin >> col;

                if (makeMove(board, row, col, PLAYER_SYMBOL)) {
                    if (checkWin(board, PLAYER_SYMBOL)) {
                        displayBoard(board);
                        cout << "Congratulations! You win!" << endl;
                        break;
                    }

                    if (isBoardFull(board)) {
                        displayBoard(board);
                        cout << "It's a draw!" << endl;
                        break;
                    }

                    Move computerMove = getRandomMove(board);
                    makeMove(board, computerMove.row, computerMove.col, COMPUTER_SYMBOL);

                    displayBoard(board);
                    cout << "Computer marked row " << computerMove.row << " and column " << computerMove.col << "." << endl;

                    if (checkWin(board, COMPUTER_SYMBOL)) {
                        cout << "Computer wins!" << endl;
                        break;
                    }

                    if (isBoardFull(board)) {
                        cout << "It's a draw!" << endl;
                        break;
                    }
                } else {
                    cout << "Invalid move! Try again." << endl;
                }
            }

            break;
        }
        case Difficulty::DIFFICULT:
        {
            while (true) {
                displayBoard(board);
                int row, col;
                cout << "Enter your move (row [0-2] and column [0-2]): ";
                cin >> row;
                cin >> col;

                if (makeMove(board, row, col, PLAYER_SYMBOL)) {
                    if (checkWin(board, PLAYER_SYMBOL)) {
                        displayBoard(board);
                        cout << "Congratulations! You win!" << endl;
                        break;
                    }

                    if (isBoardFull(board)) {
                        displayBoard(board);
                        cout << "It's a draw!" << endl;
                        break;
                    }

                    Move computerMove = findBestMove(board);
                    makeMove(board, computerMove.row, computerMove.col, COMPUTER_SYMBOL);

                    displayBoard(board);
                    cout << "Computer marked row " << computerMove.row << " and column " << computerMove.col << "." << endl;

                    if (checkWin(board, COMPUTER_SYMBOL)) {
                        cout << "Computer wins!" << endl;
                        break;
                    }

                    if (isBoardFull(board)) {
                        cout << "It's a draw!" << endl;
                        break;
                    }
                } else {
                    cout << "Invalid move! Try again." << endl;
                }
            }

            break;
        }
        default:
            cout << "Invalid choice. Exiting..." << endl;
            break;
    }
}

// Function to check if the board is full (game is a tie)
bool checkTie(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void playWithFriend()
{
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Empty Tic Tac Toe board

    int row, col;
    string p1, p2;
    
    cout<<"Player 1 enter your name:"<<endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, p1);
    
    cout<<"Player 2 enter your name:"<<endl;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, p2);
    
    char currentPlayer = 'X';
    
    cout<<p1<<" has 'X' and "<<p2<<" has 'O'."<<endl;

    while (true) {
        displayBoard(board);

        // Get the current player's move
        if(currentPlayer=='X')
        cout << p1 << ", enter your move (row [0-2] and column [0-2]): ";
        
        else
        cout << p2 << ", enter your move (row [0-2] and column [0-2]): ";
        
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board with the current player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            
            if(currentPlayer=='X')
            cout << p1 << " wins!\n";
            
            else
            cout << p2 << " wins!\n";
            
            break;
        }

        // Check if the game is a tie
        if (checkTie(board)) {
            cout << "It's a tie!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void printRules(){
    cout<<"This is the classic game TIC TAC TOE."<<endl;
    cout<<"The game is played on a grid that's 3 squares by 3 squares."<<endl;
    cout<<"Players take turns putting their marks in empty squares."<<endl;
    cout<<"The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner."<<endl;
    cout<<"When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie."<<endl;
    cout<<"Good luck!!"<<endl;
    cout<<endl;
    return;
}

void printMenu(){
    cout<<"Enter your choice:"<<endl;
    cout<<"1. Display rules"<<endl;
    cout<<"2. Play with computer"<<endl;
    cout<<"3. Play with friend (2-player)"<<endl;
    cout<<"4. Exit"<<endl;
    return;    
}

int main() {
    
    while(1)
    {
        int choice;
        printMenu();
        cin>>choice;
        
        if(choice==1)
        {   
            system("clear");
            printRules();
        }
        
        else if(choice==2)
        {   
            system("clear");
            playWithComp();
            continue;
        }
        
        else if(choice==3)
        {   
            system("clear");
            playWithFriend();
            continue;
        }
        
        else if(choice==4)
        break;
        
        else
        {
            cout<<"Invalid input! Enter again"<<endl;
            continue;
        }
    }
    
    cout<<"Thank you for playing!!"<<endl;
    
    return 0;
}
