// COMSC-210 | Lab 13 | Barsbek
// This program reads 50 scores from an external file into a std::array
// and computes statistics such as highest, lowest, average, and median.
// Note: No global variables were used. The size = 50  is specified
// directly in function parameters to avoid using globals.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int findHighestScore(const vector<int>& vec);
double findAvgScore(const vector<int>& vec);
int findLowestScore(const vector<int>& vec);
double findMedianScore(vector<int> vec);

int main() {
    const int MAX_AMOUNT{50};
    ifstream fileInput{"data.txt"};
    if (!fileInput) {
        cerr << "File not found";
        return 1;
    }

    vector<int> leaderboard{};
    for (int i{0}; i < MAX_AMOUNT; ++i) {
        int score;
        fileInput >> score;
        leaderboard.push_back(score);
    }

    // Test
    cout << "Highest score: " << findHighestScore(leaderboard) << '\n';
    cout << "Lowest score: " << findLowestScore(leaderboard) << '\n';
    cout << fixed << setprecision(2);
    cout << "Average score: " << findAvgScore(leaderboard) << '\n';
    cout << "Median score: " << findMedianScore(leaderboard) << '\n';

    return 0;
}

int findHighestScore(const vector<int>& vec) {
    return *max_element(vec.begin(), vec.end());
}

int findLowestScore(const vector<int>& vec) {
    return *min_element(vec.begin(), vec.end());
}

double findAvgScore(const vector<int>& vec) {
    double sumInitial{0.0};
    return accumulate(vec.begin(), vec.end(), sumInitial) / vec.size();
}

// findMedianScore() calculates the median of an array
// arguments: vector<int> vec
// return: median value as double
double findMedianScore(vector<int> vec) {
    sort(vec.begin(), vec.end()); // Sort a copy of the arr for median calculation
    size_t middle{vec.size() / 2}; // Middle index of the arr

    // If number of elements is even, average the two middle values
    if (vec.size() % 2 == 0) {
        return (vec.at(middle - 1) + vec.at(middle)) / 2.0;
    } else {
        return vec.at(middle); // If odd, returns the middle val
    }
}