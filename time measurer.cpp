#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    cout << "Starting...\n";

    this_thread::sleep_for(chrono::seconds(1));

    cout << "One second has passed!\n";
}