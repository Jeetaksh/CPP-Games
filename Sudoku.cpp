#include <bits/stdc++.h>
using namespace std;

vector<pair<vector<string>,vector<string>>> easyPuzzles={
    {
        { 
        "020507000",
        "040208701",
        "000001480",
        "150000200",
        "960702100",
        "080006940",
        "206070514",
        "518004360",
        "007100009"
        },
        //This is puzzle 1 pair
        {
        "821547693",
        "649238751",
        "375691482",
        "153489276",
        "964752138",
        "782316945",
        "296873514",
        "518924367",
        "437165829"
        }
    },
    
    
    {
        { 
        "687004910",
        "913000000",
        "254700000",
        "045090001",
        "006105040",
        "000000200",
        "400560030",
        "002473090",
        "508921704"
        },
        //This is puzzle 2 pair
        {
        "687234915",
        "913856427",
        "254719683",
        "345692871",
        "726185349",
        "891347256",
        "479568132",
        "162473598",
        "538921764"
        }
    },
    
    
    {
        { 
        "310480925",
        "560000007",
        "240735680",
        "800000009",
        "702860000",
        "004051200",
        "000078094",
        "400000810",
        "005100000"
        },
        //This is puzzle 3 pair
        {
        "317486925",
        "568219347",
        "249735681",
        "851327469",
        "792864153",
        "634951278",
        "123678594",
        "476593812",
        "985142736"
        }
    },
    
    
    {
        { 
        "035002009",
        "040830002",
        "700009016",
        "090107238",
        "007080000",
        "000300507",
        "000405073",
        "001703924",
        "473008060"
        },
        //This is puzzle 4 pair
        {
        "135672489",
        "946831752",
        "728549316",
        "694157238",
        "357284691",
        "812396547",
        "269415873",
        "581763924",
        "473928165"
        }
    },
    
    
    {
        { 
        "802605371",
        "415803290",
        "000901004",
        "061080030",
        "209034000",
        "000002007",
        "024000708",
        "600010000",
        "000008620"
        },
        //This is puzzle 5 pair
        {
        "892645371",
        "415873296",
        "376921854",
        "761589432",
        "289734165",
        "543162987",
        "924356718",
        "638217549",
        "157498623"
        }
    }
};

vector<pair<vector<string>,vector<string>>> mediumPuzzles={
    {
        { 
        "060040000",
        "800706000",
        "000001002",
        "050000231",
        "743102005",
        "091030060",
        "000900720",
        "000000509",
        "170004300"
        },
        //This is puzzle 1 pair
        {
        "962345178",
        "815726943",
        "437891652",
        "658479231",
        "743162895",
        "291538467",
        "586913724",
        "324687519",
        "179254386"
        }
    },
    
    
    {
        { 
        "000406170",
        "062071000",
        "070000036",
        "508000300",
        "000538721",
        "000000800",
        "050890607",
        "003207080",
        "080004000"
        },
        //This is puzzle 2 pair
        {
        "935486172",
        "462371958",
        "871925436",
        "518742369",
        "649538721",
        "327619845",
        "254893617",
        "193267584",
        "786154293"
        }
    },
    
    
    {
        { 
        "000453678",
        "000008000",
        "870006000",
        "502000304",
        "000034092",
        "003260000",
        "008000009",
        "600080053",
        "007302180"
        },
        //This is puzzle 3 pair
        {
        "129453678",
        "365798421",
        "874126935",
        "592871364",
        "716534892",
        "483269517",
        "238615749",
        "641987253",
        "957342186"
        }
    },
    
    
    {
        { 
        "004068900",
        "500040078",
        "000197200",
        "000000000",
        "800034026",
        "201000097",
        "070920050",
        "000000002",
        "652400000"
        },
        //This is puzzle 4 pair
        {
        "724568931",
        "519342678",
        "386197245",
        "467219583",
        "895734126",
        "231685497",
        "178926354",
        "943851762",
        "652473819"
        }
    },
    
    
    {
        { 
        "000000200",
        "000259371",
        "520000900",
        "090370020",
        "002600000",
        "005024803",
        "003000098",
        "000860130",
        "078103000"
        },
        //This is puzzle 5 pair
        {
        "937481265",
        "846259371",
        "521736984",
        "194378526",
        "382615749",
        "765924813",
        "213547698",
        "459862137",
        "678193452"
        }
    }
};

vector<pair<vector<string>,vector<string>>> hardPuzzles={
    {
        { 
        "000005080",
        "905000002",
        "000400001",
        "030001400",
        "070000000",
        "008000370",
        "000734000",
        "820010000",
        "600080000"
        },
        //This is puzzle 1 pair
        {
        "764125983",
        "915368742",
        "382497651",
        "239871465",
        "476953218",
        "158246379",
        "591734826",
        "827619534",
        "653582197"
        }
    },
    
    
    {
        { 
        "000000027",
        "700002900",
        "050000000",
        "900605100",
        "001030008",
        "800000004",
        "020001000",
        "043020801",
        "000000050"
        },
        //This is puzzle 2 pair
        {
        "319568427",
        "786342915",
        "452197683",
        "974685132",
        "261734598",
        "835219764",
        "627851349",
        "543926871",
        "198473256"
        }
    },
    
    
    {
        { 
        "000901600",
        "508000000",
        "007600050",
        "000004000",
        "000000801",
        "906000000",
        "005000400",
        "000700000",
        "030009162"
        },
        //This is puzzle 3 pair
        {
        "342951687",
        "568472913",
        "197638254",
        "851394726",
        "473265891",
        "926817345",
        "685123479",
        "219746538",
        "734589162"
        }
    },
    
    
    {
        { 
        "030400500",
        "670005002",
        "040000100",
        "000870900",
        "800006003",
        "002000000",
        "007002005",
        "000090730",
        "000000009"
        },
        //This is puzzle 4 pair
        {
        "931427568",
        "678915342",
        "245683197",
        "354871926",
        "819256473",
        "762349851",
        "497132685",
        "126598734",
        "583764219"
        }
    },
    
    
    {
        { 
        "000000072",
        "000049800",
        "310000000",
        "000000400",
        "004100700",
        "160300020",
        "600050004",
        "500200000",
        "008090000"
        },
        //This is puzzle 5 pair
        {
        "489531672",
        "752649831",
        "316827549",
        "873962415",
        "924185763",
        "165374928",
        "691753284",
        "547218396",
        "238496157"
        }
    }
};

void displaySudoku(vector<string> &board){
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int findZeroInBoard(vector<string> &board){
    int zeros=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='0'){
                zeros++;
            }
        }
    }
    return zeros;
}

void playGame(vector<string> &board, vector<string> &solution){
    int remainingGuesses=3;
    int requiredGuesses=findZeroInBoard(board);
    int row,col;
    char val;
    
    while(requiredGuesses!=0 && remainingGuesses>0){
        system("clear");
        displaySudoku(board);
        cout<<"Enter the row, column and value respectively [r c v] (0-indexed)\n";
        cout<<"Enter row and column as -1 to view soluion.\n";
        cin>> row >> col >> val;
        if(row ==-1 && col == -1){
            system("clear");
            cout<<"You solved so far:\n";
            displaySudoku(board);
            cout<<"The solution is:\n";
            displaySudoku(solution);
            break;
        }
        if(row<0 || row>=9 || col<0 || col>=9 || val<'1' || val>'9'){
            cout<<"Invalid choice, please try again.\n";
            std::this_thread::sleep_for(std::chrono::seconds(4));
        }
        else if(board[row][col]!='0'){
            cout<<"This location in already marked, please try again.\n";
            std::this_thread::sleep_for(std::chrono::seconds(4));
        }
        else if(solution[row][col]==val){
            board[row][col]=val;
            requiredGuesses--;
            if(requiredGuesses==0){
                cout<<"You Won! Thanks for playing.\n";
                std::this_thread::sleep_for(std::chrono::seconds(8));
                system("clear");
                break;
            }
            system("clear");
            cout<<"Correct Guess\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            system("clear");
        }
        else{
            remainingGuesses--;
            if(remainingGuesses==0){
                cout<<"You have made maximum number of incorrect guesses and have lost the game.\n";
                cout<<"Thanks for playing.\n";
                std::this_thread::sleep_for(std::chrono::seconds(8));
                system("clear");
                break;
            }
            
            cout<<"You have made an incorrect guess, please try again.\n";
            cout<<"You have " << remainingGuesses << " guess(es) left.\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            
        }
    }
    
}

void printMenu(){
    cout<<"Welcome to Sudoku Game. Enter your choice.\n";
    cout<<"1) Display Rules\n";
    cout<<"2) Play Easy Mode\n";
    cout<<"3) Play Medium Mode\n";
    cout<<"4) Play Hard Mode\n";
    cout<<"5) Exit game\n\n";
}

void printRules(){
    system("clear");
    cout<<"Welcome to Sudoku Game. The rules of the game are:-\n";
    cout<<"The goal of the game is to fill each cell in the grid with a number from 1 to 9.\n";
    cout<<"Each row, column, and 3x3 subgrid must contain all the numbers from 1 to 9 without repetition.\n";
    cout<<"You can make a maximum of 3 incorrect Guesses.\n";
    cout<<"Find all the numbers to win. GoodLuck!!\n\n";
}

int main()
{   
    int choice;
    
    while (1) {
        printMenu();
        cin >> choice;
        
        system("clear");
        
        if(choice==1)
        {
            printRules();
        }

        else if(choice>=2 && choice <=4){
            int randomIndex = rand()%5;
            if(choice==2){
                playGame(easyPuzzles[randomIndex].first, easyPuzzles[randomIndex].second);
            }
            else if(choice==3){
                playGame(mediumPuzzles[randomIndex].first, mediumPuzzles[randomIndex].second);
            }
            else{
                playGame(hardPuzzles[randomIndex].first, hardPuzzles[randomIndex].second);
            }
        }
        
        else if (choice == 5){
            cout<<"Exitted Successfully. Thanks for playing!";
            break;
        }

        else {
            cout << "Invalid Choice, Please enter a valid choice." << endl;
        }
    }
    return 0;
}
