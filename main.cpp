#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ===== Module 1: Player =====
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
    vector<Test> tests = {
        Test("the quick brown fox jumps over the lazy dog", 30),
        Test("practice makes perfect and consistency is the key to success", 60),
        Test("object oriented programming uses encapsulation inheritance polymorphism and abstraction", 90)
    };

    Leaderboard board;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        string name;
        cout << "Enter name: ";
        cin >> name;

        Player p(name);

        int choice;
        cout << "1.Easy 2.Medium 3.Hard: ";
        cin >> choice;

        Test &t = tests[choice - 1];
        int wpm;
        double acc;

        t.run(wpm, acc);
        p.setScore(wpm, acc);

        board.add(p);
        board.show();

        cout << "Again? (y/n): ";
        cin >> again;
    }
}
