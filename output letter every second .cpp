#include <iostream>
#include <time.h>

using namespace std;

int main() {

    char letter = 'A';
    long int start = time(NULL);

    while (letter <= 'Z') {

        if (time(NULL) - start >= 1) {
            cout << letter << endl;

            letter++;
            start = time(NULL);
        }
    }

    return 0;
}