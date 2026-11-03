/* Online Leaderboard Ranking using Heap Sort */
#include <iostream>
#include <string>
using namespace std;
// om kutwal SY-12 Roll No. 70

struct Player {
    string name;
    int score;
};

// Max Heapify (parent must be larger than its children)
void maxHeapify(Player arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].score > arr[largest].score)
        largest = left;
    if (right < n && arr[right].score > arr[largest].score)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min Heapify (parent must be smaller than its children)
void minHeapify(Player arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].score < arr[smallest].score)
        smallest = left;
    if (right < n && arr[right].score < arr[smallest].score)
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Heap Sort using Max Heap -> Ascending order
void heapSortAscending(Player arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Move the largest element to the end, then rebuild the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Heap Sort using Min Heap -> Descending order
void heapSortDescending(Player arr[], int n) {
    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Move the smallest element to the end, then rebuild the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void display(Player arr[], int n, bool showRank) {
    if (showRank)
        cout << "Rank\tPlayer\t\tScore\n";
    else
        cout << "Player\t\tScore\n";

    for (int i = 0; i < n; i++) {
        if (showRank)
            cout << i + 1 << "\t";
        cout << arr[i].name << "\t\t" << arr[i].score << "\n";
    }
}

int main() {
    const int MAX = 100;
    Player players[MAX], temp[MAX];
    int n = 0, choice;

    do {
        cout << "\nom kutwal sy-12 roll no.70";
        cout << "\n===== Online Leaderboard Ranking =====\n";
        cout << "1. Enter Player Scores\n";
        cout << "2. Display Original Scores\n";
        cout << "3. Heap Sort - Max Heap (Ascending)\n";
        cout << "4. Heap Sort - Min Heap (Descending Leaderboard)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of players (max " << MAX << "): ";
                cin >> n;
                if (n <= 0 || n > MAX) {
                    cout << "Invalid number of players.\n";
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    cout << "Enter name and score of player " << i + 1 << ": ";
                    cin >> players[i].name >> players[i].score;
                }
                break;
            case 2:
                if (n == 0) { cout << "No data entered.\n"; break; }
                cout << "\nOriginal Scores:\n";
                display(players, n, false);
                break;
            case 3:
                if (n == 0) { cout << "No data entered.\n"; break; }
                for (int i = 0; i < n; i++) temp[i] = players[i];
                heapSortAscending(temp, n);
                cout << "\nScores in Ascending Order (Max Heap):\n";
                display(temp, n, false);
                break;
            case 4:
                if (n == 0) { cout << "No data entered.\n"; break; }
                for (int i = 0; i < n; i++) temp[i] = players[i];
                heapSortDescending(temp, n);
                cout << "\nLeaderboard in Descending Order (Min Heap):\n";
                display(temp, n, true);
                break;
            case 5:
                cout << "Program Terminated.\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}