#include <iostream>
using namespace std;


double calculateMultiplier(int remainingNonMineCells, int remainingCells) {
    double successProbability = static_cast<double>(remainingNonMineCells) / remainingCells;
    double multiplier = 1.0 / successProbability;
    return multiplier;
}

double getCombinedMultiplier(int gridSize, int totalMines, int taps) {
    int totalCells = gridSize * gridSize;
    int nonMineCells = totalCells - totalMines;
    double combinedMultiplier = 1.0;

    for (int i = 0; i < taps; ++i) {
        double currentMultiplier = calculateMultiplier(nonMineCells - i, totalCells - i);
        combinedMultiplier *= currentMultiplier;
    }

    return combinedMultiplier;
}

int main() {
    int gridSize = 5;
    int totalMines;
    int taps;

    cout << "Enter the number of mines: ";
    cin >> totalMines;

    cout << "Enter the number of taps: ";
    cin >> taps;

    if (totalMines >= gridSize * gridSize) {
        cout << "Invalid number of mines. The number of mines must be less than the total number of cells." << std::endl;
        return 1;
    }

    if (taps > gridSize * gridSize - totalMines) {
        cout << "Invalid number of taps. The number of taps must be less than or equal to the number of non-mine cells." <<endl;
        return 1;
    }

    double multiplier = getCombinedMultiplier(gridSize, totalMines, taps);
    cout << "Combined multiplier after " << taps << " taps with " << totalMines << " mines in a " << gridSize << "x" << gridSize << " grid: " << multiplier << endl;

    return 0;
}
