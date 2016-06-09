#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;

const double MAX_CAPACITY = 1.0;

vector<double> GenerateRandomNumbers(int N) {
    vector<double> numbers;
    srand(time(0));
    for (int i = 0; i < N; i++) {
        const double random_variable = (double) rand() / (double) RAND_MAX;
        numbers.push_back(random_variable);
    }
    return numbers;
}

int NextFitBinPacking(vector<double> random_numbers) {
    vector<double> binstorage;
    for (int i = 0; i < random_numbers.size(); i++) {
        const double current_number = random_numbers[i];
        if (binstorage.empty()) {
            binstorage.push_back(current_number);
        } else {
            double last_number = binstorage[binstorage.size() - 1];
            if (current_number + last_number <= MAX_CAPACITY) {
                binstorage[binstorage.size() - 1] += current_number;
            } else {
                binstorage.push_back(current_number);
            }
        }
    }
    return binstorage.size();
}

int FirstFitBinPacking(vector<double> random_numbers) {
    priority_queue<double, vector<double>, greater<double> > binstorage;
    for (int i = 0; i < random_numbers.size(); i++) {
        const double current_number = random_numbers[i];
        if (binstorage.empty()) {
            binstorage.push(current_number);
        } else {
            double smallest_number = binstorage.top();
            if (smallest_number + current_number <= MAX_CAPACITY) {
                binstorage.pop();
                binstorage.push(smallest_number + current_number);
            } else {
                binstorage.push(current_number);
            }
        }
    }
    return binstorage.size();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "See Usage below" << endl << "./TestBinPackingAlgorithms <Number of Items>" << endl;
        return 1;
    }
    stringstream ss(argv[1]);
    int N;
    ss >> N;
    vector<double> random_numbers = GenerateRandomNumbers(N);
    const int number_of_bins_next_fit = NextFitBinPacking(random_numbers);
    const int number_of_bins_first_fit = FirstFitBinPacking(random_numbers);
    sort(random_numbers.begin(), random_numbers.end(), greater<double>());
    const int number_of_bins_first_fit_decreasing = FirstFitBinPacking(random_numbers);
    cout << "Number of bins:" << endl;
    cout << "Next Fit: " << number_of_bins_next_fit << endl;
    cout << "First Fit: " << number_of_bins_first_fit << endl;
    cout << "First Fit Decreasing: " << number_of_bins_first_fit_decreasing << endl;
}

