#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ===== Module 1: Player =====
class Player {
private:
    string name;
    int wpm;
    double accuracy;

public:
    Player(string n = "");
    void setScore(int w, double a);
    int getWPM() const;
    void display(int rank) const;
};

// ===== Module 2: Test =====
class Test {
private:
    string text;
    int timeLimit;

    int calcWPM(int chars, double sec);
    double calcAcc(const string& ref, const string& typed);

public:
    Test(string t, int tl);
    void run(int &wpm, double &acc);
};

// ===== Module 3: Leaderboard =====
class Leaderboard {
private:
    vector<Player> scores;

public:
    void add(const Player& p);
    void show();
};

// ===== Main Driver =====
int main() {
    cout << "Typing Speed Test\n";
    return 0;
}
