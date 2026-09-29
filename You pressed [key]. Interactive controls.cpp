#include <iostream>
#include <unistd.h>
#include <conio.h>
using namespace std;

int main() {
    cout << "Press a key to interact...\n";

    while (true) 
    {
        if (_kbhit()) 
        {
            char key = _getch();

            cout << "You pressed: " << key << endl;
            
        }

        
        usleep(10000); // 2 seconds = 2000000
    }
}