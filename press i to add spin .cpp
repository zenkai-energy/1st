#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

using namespace std;

void display_game(int spins, float money)
{
 cout << "\033[2J\033[H";
 cout << "\nWELCOME TO THE SLOT MACHINE. \n" << endl;
    cout << "spins: " << spins << endl;
    cout << "amount: "<< money << '$' << '\n'<< endl;
    
    cout << "a. spin" << endl;
    cout << "b. buy spins" << endl;
    cout << "c. deposit" << endl;

}

bool pressed(char key)
{
 // Check whether a key has been pressed
 
 
  while (1)
  {
        fd_set input;
        FD_ZERO(&input);
        FD_SET(STDIN_FILENO, &input);

        timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        if (select(STDIN_FILENO + 1, &input, NULL, NULL, &timeout) > 0)
        {
            char k;
            read(STDIN_FILENO, &k, 1);
            
            
            
            if(key == k) return true;
            else return false;

            
   
        }
  }
}


 


void addspins(int & in)
{
 // Save the normal keyboard settings
    termios oldSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);

    // Make keyboard input immediate
    termios newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    bool running = true;
    

    while (running)
    {
     cout << "\rpress i to add spins :" << in << flush;
       if(pressed('i')){in++;}
       else if(pressed('q')) running = false;
       else if(pressed('o'))in--;
    }
 

    usleep(10000); // 0.2 seconds = 200000
    

    // Restore normal keyboard settings
    tcsetattr(STDIN_FILENO, TCSANOW, & oldSettings);
    
}



int main()
{    int spins = 1;
    while (true)
    {
    
    display_game(spins,100);
    char x;
    if(pressed('b'))addspins(spins);
    }

    return 0;
}