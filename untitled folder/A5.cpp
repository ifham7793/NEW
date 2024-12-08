#include <iostream>
using namespace std;

int computeAddress(int base, int i, int j, int rowSize, int colSize, string arrangement, string type) {
    int size = (type == "int") ? 4 : (type == "char") ? 1 : (type == "float") ? 4 : 0;
    int address = 0;
    if (arrangement == "ROW") {
        address = base + size * (i * colSize + j);
    } else if (arrangement == "COLUMN") {
        address = base + size * (j * rowSize + i);
    }
    return address;
}

int main() {
    int base, i, j, rowSize, colSize;
    string arrangement, type;
    cout << "Enter base address: ";
    cin >> base;
    cout << "Enter type (int/char/float): ";
    cin >> type;
    cout << "Enter number of rows and columns: ";
    cin >> rowSize >> colSize;
    cout << "Enter i and j indices: ";
    cin >> i >> j;
    cout << "Enter arrangement (ROW/COLUMN): ";
    cin >> arrangement;

    int address = computeAddress(base, i, j, rowSize, colSize, arrangement, type);
    cout << "The address of the element is: " << address << endl;
    return 0;
}
