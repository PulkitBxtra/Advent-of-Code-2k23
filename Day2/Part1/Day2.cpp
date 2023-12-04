#include<bits/stdc++.h>
using namespace std;

int validGame=0;
vector<int> validGames;

int invalidGame=0;
vector<int> invalidGames;

struct Game {
    int gameId;
    int red=0;
    int blue=0;
    int green=0;
};

int r=0;
int g=0;
int b=0;

int main() {
    string line;
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }


        int i = 0;
        int n = line.size() - 1;

        int lineNumber = 0;

        while (line[i] != ':') {
            if (line[i] == ' ') {
                i++;
                lineNumber = line[i] - '0';
                i++;
            }

            if (line[i] == ':') {
                break;
            }

            if ((line[i] >= '0' && line[i] <= '9') && line[i] != ':') {

                lineNumber *= 10;
                lineNumber += line[i] - '0';
            }

            i++;
        }

        Game game;
        game.gameId = lineNumber;

        for (int j = i; j < n; j++) {

        int number = 0;
        int tens = 1;

        while (line[j] >= '0' && line[j] <= '9') {
            number = number * 10 + (line[j] - '0');
            j++;
        }

        // Assuming j+2 is within the bounds of the array or string
        // cout << number << " " << line[j + 1] << endl;

        if(number!=0){
            if(line[j+1]=='r'){
                r+=number;
                game.red+=number;
            }

            if(line[j+1]=='g'){
                g+=number;
                game.green+=number;
            }

            if(line[j+1]=='b'){
                b+=number;
                game.blue+=number;
            }
        }

        number = 0;
        tens = 1;
    }

        int number=0;
        cout<<"GameId: "<<game.gameId<<" ";
        cout<<"Red:"<< game.red<<" ";
        cout<<"blue:"<< game.blue<<" ";
        cout<<"Green:"<< game.green<<" ";
        cout<<endl;


        if(game.red >= 12){
            invalidGames.push_back(game.gameId);
        }

        else if(game.green >= 13){
            invalidGames.push_back(game.gameId);
        }

        else if(game.blue>=14){
            invalidGames.push_back(game.gameId);
        }

        

        else{
            cout<<"validGame: "<<game.gameId<<endl;
            validGames.push_back(game.gameId);
        }
    }

    int ans=0;

    for(auto i:invalidGames){
        cout<<i<<" ";
        ans+=i;
    }

    cout<<ans;

    return 0;
}
