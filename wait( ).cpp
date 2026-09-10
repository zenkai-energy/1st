#include<iostream>
#include<chrono>
using namespace std;


void wait(int in)
{
 time_t thistle = time(NULL);
 while(1)
 {
  if(time(NULL) - thistle >= in) break;
 }
}





int main()
{    
    
    int duration = 3;
    int seconds = 1;
    time_t times = time(NULL);
    int n = 0;
    
    while(1)
    {
     
     if(time(NULL) - times > n)
     {
      
      cout << "Hello World!" << endl;
      n = n + seconds;
      
     }
     if(n >= duration) break;
     
    }
    wait(5);
    cout << "broken" << endl;
    
    
    return 0;
}