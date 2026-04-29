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

    int calcWPM(int chars, double sec) {
        return sec <= 0 ? 0 : (chars / 5.0) / (sec / 60.0);
    }

    double calcAcc(const string& ref, const string& typed) {
        int correct = 0;
        for (int i = 0; i < min(ref.size(), typed.size()); i++)
            if (ref[i] == typed[i]) correct++;
        return (double)correct / ref.size() * 100;
    }

public:
    Test(string t, int tl) : text(t), timeLimit(tl) {}

    void run(int &wpm, double &acc) {
        cout << "\nType this:\n" << text << "\n";
        cin.ignore();

        string input;
        auto start = high_resolution_clock::now();
        getline(cin, input);
        auto end = high_resolution_clock::now();

        double sec = duration<double>(end - start).count();
        wpm = calcWPM(input.size(), sec);
        acc = calcAcc(text, input);

        cout << "\nTime: " << sec
             << "\nWPM: " << wpm
             << "\nAccuracy: " << acc << "%\n";
    }
};


// ===== Module 3: Leaderboard =====
class Leaderboard {
private:
    vector<Player> scores;

public:
    void add(const Player& p) {
        scores.push_back(p);
    }

    void show() {
        sort(scores.begin(), scores.end(),
             [](const Player &a, const Player &b) {
                 return a.getWPM() > b.getWPM();
             });

        cout << "\nRank Name           WPM   Accuracy\n";
        cout << "----------------------------------\n";
        for (int i = 0; i < scores.size(); i++)
            scores[i].display(i + 1);
    }
};
// ===== Main Driver =====
int main() {
    cout << "Typing Speed Test\n";
    return 0;
}
