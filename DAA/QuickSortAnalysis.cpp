#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int stepDet = 0, stepRand = 0;

// ---------- DETERMINISTIC QUICK SORT ----------
int partitionDet(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // fixed pivot (last element)
    int i = low - 1;

    for (int j = low; j < high; j++) {
        stepDet++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        stepDet++; // counting recursive calls
        int pi = partitionDet(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// ---------- RANDOMIZED QUICK SORT ----------
int partitionRand(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        stepRand++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);
    return partitionRand(arr, low, high);
}

void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        stepRand++; // counting recursive calls
        int pi = randomizedPartition(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    vector<int> arr2 = arr1; // copy array

    quickSortDeterministic(arr1, 0, n - 1);
    quickSortRandomized(arr2, 0, n - 1);

    cout << "\nSorted array using Deterministic QuickSort:\n";
    for (int x : arr1) cout << x << " ";
    cout << "\nStep count (Deterministic): " << stepDet << endl;

    cout << "\nSorted array using Randomized QuickSort:\n";
    for (int x : arr2) cout << x << " ";
    cout << "\nStep count (Randomized): " << stepRand << endl;

    return 0;
}
