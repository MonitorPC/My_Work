#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int amountOfCity;
    cin >> amountOfCity;

    int minl = 10000;
    vector<int> truePath(amountOfCity);
    int currentlenth = 0;

    vector<int> data(amountOfCity);
    for (int i = 0; i < amountOfCity; i++) {
        data[i] = i;
    }

    vector<vector<int>> distances(amountOfCity);
    for (int i = 0; i < amountOfCity; i++) {
        vector<int> distance(amountOfCity);
        for (int j = 0; j < amountOfCity; j++) {
            cin >> distance[j];
        }
        distances[i] = distance;
    }

    
    do {
        currentlenth = 0;
        if (data[0] == 0) {
            for (int i = 0; i < amountOfCity - 1; i++) {
                int a = data[i];
                int b = data[i + 1];
                currentlenth += distances[a][b];
            }
            currentlenth += distances[data[amountOfCity -1]][data[0]];
            if (minl > currentlenth) {
                minl = currentlenth;
                for (int i = 0; i < amountOfCity; i++) {
                    truePath[i] = data[i];
                }
                
            }
        }
    } while (next_permutation(data.begin(), data.end()));
    cout << minl << endl;
    for (int i = 0; i < amountOfCity; i++) {
        cout << truePath[i] << " ";
    }
    cout << "0";
    return 0;
}
