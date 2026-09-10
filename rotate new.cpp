#include<iostream>
#include<chrono>
using namespace std;

void wait(int in){ time_t thistle = time(NULL); while(1) {  if(time(NULL) - thistle >= in) break; }}


//Duration starts here. while...
time_t kakarott = time(NULL); 
int d;
bool duration(int in)
{
 while (d <= in)
 {
  if(time(NULL) - kakarott >= d)
  d++;
  return true;
 }
 return false;
}


std::string rotate(std::string file)  
//rotate function. Parameters are the string to be rotated and how many times to rotate.
{  char x = '#';
  int n = 0;
  int k = 1;
 while(n < 2)
  {  x = file[0];
    while (k < file.length())
      {      file[k - 1] = file[k];   k++;  }
        file[file.length() - 1] = x;    n++; }
         return file;
         }



int main()
{
    std::string names[10] = {" ","🤞"};
    std::string am = "                         Hello world   ";
    float m = 0;
    std::string me; 
    int n = 0;
    while(duration(40))
    {
     wait(1);
     am = rotate(am);
     me = me + "🔥" + names[n];
     n++;
     cout << me << endl;
     if(n >= 4)n=0;
    }
    
   
   
   
   
   
    return 0;
}