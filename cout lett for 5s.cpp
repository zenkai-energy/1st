#include <iostream>
#include <time.h>

using namespace std;

int main() {

    char letter = '0';
    time_t start = time(NULL);
    time_t them = time(NULL);

    
     while (time(NULL) - them <= 5)
     {
         
         
         if (letter > '9') letter = '0';
    

        if (time(NULL) - start >= 1)
        {
            cout << letter << endl;
            
            start = time(NULL);

            letter++;
        }
        
        
       
     }
    

    return 0;
}