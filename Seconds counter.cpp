#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {

    int counter = 0;

    while (counter < 10) {
        cout << counter << endl;

        counter++;

        this_thread::sleep_for(chrono::seconds(1));
    }
}