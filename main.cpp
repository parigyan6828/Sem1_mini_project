#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
// ── Player ─────────────────────────────
class Player {
private:
    string name;
    int wpm;
    double accuracy;

public:
    Player(string n = "") : name(n), wpm(0), accuracy(0) {}

    void setScore(int w, double a) {
        wpm = w;
        accuracy = a;
    }

    int getWPM() const { return wpm; }

    void display(int rank) const {
        cout << left << setw(5) << rank
             << setw(15) << name
             << right << setw(6) << wpm << " WPM   "
             << fixed << setprecision(1) << accuracy << "%\n";
    }
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
