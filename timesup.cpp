#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

void choose_player()
{
    extern int active_team;
    extern int nb_team1;
    extern vector<string> team1;
    extern int nb_team2;
    extern vector<string> team2;

    if (active_team == 1)
    {
        cout << "Team 1 is playing" << endl;
        int randNum = rand()%(nb_team1);
        cout << team1[randNum] << " is playing" << endl;
    }
    if (active_team == -1)
    {
        cout << "Team 2 is playing" << endl;
        int randn = rand()%(nb_team2);

        cout << team2[randn] << " is playing" << endl;
    }
    active_team *= -1;
}

void play(int nb_words, vector<string> words)
{
    extern int active_team;
    extern int score_team1;
    extern int score_team2;
    if (nb_words == 0) return;

    string entry;
    cout << nb_words << " is the current number of words in the list" << endl;
    int randNum = rand()%(nb_words);
    cout << "\n\n\n\n\n\n" << "         WORD TO GUESS : " << words[randNum] << "\n\n\n\n\n\n" << endl;
    cout << "Press n to next, s to skip, next for next player" << endl;
    cin >> entry;
    if (entry == "next")
    {
        choose_player();
        play(nb_words, words);
    }
    system("clear");
    while (entry != "n" && entry != "s" && entry != "next")
    {
        cin >> entry;
    }
    if (entry == "s")
    {
        play(nb_words, words);
    }
    if (entry == "n")
    {
        if (active_team == 1) score_team1 ++;
        else score_team2 ++;
        nb_words -= 1;
        words.erase(words.begin()+(randNum));
        play(nb_words, words);
    }
    return;
}

//public variables
vector<string> team1;
vector<string> team2;
int nb_team1;
int nb_team2;
int active_team = 1;
int score_team1 = 0;
int score_team2 = 0;
//////////////////

int main()
{
    int nb_words;
    vector<string> words;
    string word;
    string player;
    cout << "\n\n\n\n";
    cout << "How many people in Team1?" << endl;
    cin >> nb_team1;
    cout << "Enter Names:" << endl;
    for (int i = 0; i < nb_team1 ; i++)
    {
        cin >> player;
        team1.push_back(player);
    }
    cout << "How many people in Team2?" << endl;
    cin >> nb_team2;
    cout << "Enter Names:" << endl;
    for (int i = 0; i < nb_team2 ; i++)
    {
        cin >> player;
        team2.push_back(player);
    }
    cout << "How many words do you want to play with?" << endl;
    cin >> nb_words;
    int words_left = nb_words;
    cout << "You are playing w/ " << nb_words << " words" << endl;
    int not_use_first = 0;
    while (words.size() < nb_words)
    {
        cout << "Enter a word:" << endl;
        getline(cin, word);
        if (not_use_first > 0) words.push_back(word);
        system("clear");
        words_left -= 1;
        cout << "You have " << words_left + 1 << " more words to enter " << endl;
        not_use_first ++;
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "  eeeee " << endl;
    }
    for (int i = 0 ; i < 3; i++)
    {
        system("clear");
        if (i>0)
        {
            cout << "THE ROUND IS OVER\n" << endl;
            cout << "Team 1's score is  : "  << score_team1 << endl;
            cout << "Team 2's score is  : "  << score_team2 << endl;
            cout << "\n\n";
        }
        choose_player();
        cout << "Type \"start\" when ready to play" << endl;
        string start;
        while (start != "start") cin >> start;
        play(nb_words, words);
        cout << "Team 1's score is  : "  << score_team1 << endl;
        cout << "Team 2's score is  : "  << score_team2 << endl;
    }
}

