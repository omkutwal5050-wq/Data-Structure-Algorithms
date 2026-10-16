#include <iostream>
#include <vector>
using namespace std;
// om kutwal SY-12 Roll No. 70
int main() {
    int size, n;

    cout << "Enter total parking slots: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid parking slot size.\n";
        return 1;
    }

    vector<int> parking(size, -1);

    cout << "Enter number of vehicles: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of vehicles.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int vehicle;

        cout << "\nEnter vehicle number: ";
        cin >> vehicle;

        int index = vehicle % size;
        bool parked = false;

        cout << "Initial hash index: " << index << "\n";

        // Linear probing
        for (int j = 0; j < size; j++) {
            int slot = (index + j) % size;

            if (parking[slot] == -1) {
                parking[slot] = vehicle;
                cout << "Vehicle parked in slot "
                     << slot << "\n";
                parked = true;
                break;
            }
            else {
                cout << "Slot " << slot
                     << " is occupied. Checking next slot.\n";
            }
        }

        if (!parked) {
            cout << "Parking full! Vehicle "
                 << vehicle << " could not be parked.\n";
        }
    }

    cout << "\nFinal Parking Table:\n";
    cout << "Slot\tVehicle Number\n";

    for (int i = 0; i < size; i++) {
        cout << i << "\t";

        if (parking[i] == -1)
            cout << "Empty";
        else
            cout << parking[i];

        cout << "\n";
    }

    return 0;
}