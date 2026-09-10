#include <iostream>
#include <time.h>

using namespace std;

int secs()
{
    static time_t start;
    static bool running = false;

    if (!running)
    {
        start = time(NULL);
        running = true;
        return 0;
    }

    return time(NULL) - start;
}

int main()
{
    char input;

    cout << "Enter something to start timer: ";
    cin >> input;

    secs();

    cout << "Timer started.\n";
    cout << "Enter q to stop it: ";

    cin >> input;

    if (input == 'q')
    {
        cout << "Seconds passed: " << secs() << endl;
    }

    return 0;
}