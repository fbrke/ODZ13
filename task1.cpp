#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "docs/phone.dat"; // файл с базой данных
    ifstream file(filename);
    if (!file) {
        cout << "Error " << filename << endl;
        return 1;
    }

    string brand;
    double minPrice, maxPrice;
    cout << "Vvedite brend: ";
    cin >> brand;
    cout << "Vvedite max i min cost: ";
    cin >> minPrice >> maxPrice;

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos = line.find_last_of(" ");
        if (pos == string::npos) continue;

        string model = line.substr(0, pos);
        double price = stod(line.substr(pos + 1));

        if (model.find(brand) != string::npos && price >= minPrice && price <= maxPrice) {
            cout << model << " " << price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No phones like this\n";
    }

    file.close();
    return 0;
}