#include<iostream>
#include<chrono>
using namespace std;

void wait(int in){ time_t thistle = time(NULL); while(1) {  if(time(NULL) - thistle >= in) break; }}


bool duration(int x)
{
 static int vv = 0;
 static time_t then;
 if(vv < 1)
 {
  then = time(NULL);
  vv++;
 }
 if(time(NULL) - then <= x)
 return true;
 else return false;
}


std::string rotate(std::string file, int jj)  //rotate function. Parameters are the string to be rotated and how many times to rotate.
{  char x = '#'; int n = 0; int k;
 while(n < jj)
  {  x = file[0];
    k = 1; 
   while (k < file.length()) 
    { file[k - 1] = file[k]; 
      k++;  
    } 
    file[file.length() - 1] = x;    n++; } 
    return file;
    }



int main()
{
    std::string names[10] = {"a","b","c","d"};
    std::string am = " Hello world                             ";
    float m = 0; 
    int n = 0;
    while(duration(20))
    {
     wait(1);
     am = rotate(am,5);
     cout << am << endl;
    
    }
    
   
   
   
   
   
    return 0;
}