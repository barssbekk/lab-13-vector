// COMSC-210 | Lab 12 | Barsbek
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

int findHighestScore(const array<int, 50>& arr);
double findAvgScore(const array<int, 50>& arr);
int findLowestScore(const array<int, 50>& arr);
double findMedianScore(array<int, 50> arr);

int main() {
    const int MAX_AMOUNT{50};
    ifstream fileInput{"data.txt"};
    if (!fileInput) {
        cerr << "File not found";
        return 1;
    }

    array<int, MAX_AMOUNT> leaderboard{};
    for (int& score : leaderboard)  // To input data into array
        fileInput >> score;

    // Test
    cout << "Highest score: " << findHighestScore(leaderboard) << '\n';
    cout << "Lowest score: " << findLowestScore(leaderboard) << '\n';
    cout << fixed << setprecision(2);
    cout << "Average score: " << findAvgScore(leaderboard) << '\n';
    cout << "Median score: " << findMedianScore(leaderboard) << '\n';

    return 0;
}

int findHighestScore(const array<int, 50>& arr) {
    return *max_element(arr.begin(), arr.end());
}

int findLowestScore(const array<int, 50>& arr) {
    return *min_element(arr.begin(), arr.end());
}

double findAvgScore(const array<int, 50>& arr) {
    double sumInitial{0.0};
    return accumulate(arr.begin(), arr.end(), sumInitial) / arr.size();
}

// findMedianScore() calculates the median of an array
// arguments: array<int, 50> arr
// return: median value as double
double findMedianScore(array<int, 50> arr) {
    sort(arr.begin(), arr.end()); // Sort a copy of the arr for median calculation
    size_t middle{arr.size() / 2}; // Middle index of the arr

    // If number of elements is even, average the two middle values
    if (arr.size() % 2 == 0) {
        return (arr.at(middle - 1) + arr.at(middle)) / 2.0;
    } else {
        return arr.at(middle); // If odd, returns the middle val
    }
}