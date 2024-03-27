// Quentin Cornier

#include <iostream>
#include <queue>
#include <string>

using namespace std;  // Pour éviter de commencer les commandes par std::

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cerr << "Error: No number passed" << endl;
        return 1;
    }

    const int startingNumber = atoi(argv[1]);

    queue<int> decomp;

    int number = startingNumber;
    int divider = 2;

    cout << to_string(startingNumber) << endl;

    while (number / divider >= 1) {

        if (number % divider == 0) {
            decomp.push(divider);
            number /= divider;
        } else {
            divider++;
        }
    }

    string result = to_string(startingNumber) + " = ";

    while (!decomp.empty()) {
        result += to_string(decomp.front()) + "x";
        decomp.pop();
    }

    result.pop_back();

    cout << result << endl;

    return 0;
}