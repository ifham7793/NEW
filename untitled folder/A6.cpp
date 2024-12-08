#include <iostream>
using namespace std;

int computeAddress(int base, int i, int j, int k, int rowSize, int colSize, int depthSize, string arrangement, string type) {
    int size = (type == "int") ? 4 : (type == "char") ? 1 : (type == "float") ? 4 : 0;
    int address = 0;

    if (arrangement == "ROW") {
        address = base + size * (i * colSize * depthSize + j * depthSize + k);
    } else if (arrangement == "COLUMN") {
        address = base + size * (k * rowSize * colSize + j * rowSize + i);
    }
    return address;
}

int main() {
    int base, i, j, k, rowSize, colSize, depthSize;
    string arrangement, type;
    cout << "Enter base address: ";
    cin >> base;
    cout << "Enter type (int/char/float): ";
    cin >> type;
    cout << "Enter number of rows, columns, and depth: ";
    cin >> rowSize >> colSize >> depthSize;
    cout << "Enter i, j, and k indices: ";
    cin >> i >> j >> k;
    cout << "Enter arrangement (ROW/COLUMN): ";
    cin >> arrangement;

    int address = computeAddress(base, i, j, k, rowSize, colSize, depthSize, arrangement, type);
    cout << "The address of the element is: " << address << endl;
    return 0;
}
