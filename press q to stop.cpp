#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

using namespace std;

int main()
{
    // Save the normal keyboard settings
    termios oldSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);

    // Make keyboard input immediate
    termios newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    bool running = true;
    int number = 0;

    while (running)
    {
        cout << number << endl;
        number++;

        // Check whether a key has been pressed
        fd_set input;
        FD_ZERO(&input);
        FD_SET(STDIN_FILENO, &input);

        timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        if (select(STDIN_FILENO + 1, &input, NULL, NULL, &timeout) > 0)
        {
            char key;
            read(STDIN_FILENO, &key, 1);

            if (key == 'q')
            {
                running = false;
            }
        }

        usleep(200000); // 0.2 seconds
    }

    // Restore normal keyboard settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    cout << "Stopped." << endl;

    return 0;
}