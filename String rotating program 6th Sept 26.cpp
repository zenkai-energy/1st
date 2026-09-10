#include<iostream>
#include<string>
using namespace std;

void wait(int in)              //self explained waiting function. Parameter is the seconds to wait.
{ time_t thistle = time(NULL);
 while(1)
   {  if(time(NULL) - thistle >= in) break;
   }
}

int length (std::string into ) //length finder function. Parameter is the string to be measured.
{    int x = 0;    int i = 0;
    while(1)
        {        if(static_cast<int>(into[i]) > 0)
                {x++;}        i++;        if(i == into.length())break;
                        else continue;                            
                        }    
return x;
}

std::string rotate(std::string file, int jj)  //rotate function. Parameters are the string to be rotated and how many times to rotate.
{
 
 char x = '#';
 int n = 0;
 int k = 1;
 while(n < jj)
 {
  x = file[0];
  while (k < length(file))
  {
   
   file[k - 1] = file[k];
   k++;
  }
  file[length(file) - 1] = x;
  
  n++;
 }
 return file;
}

int main()
{
    
    std::string these = "____________*";  //What is to be rotated in the loop.
    
    cout << "length is " << length(these) << endl;
    
    
    int seconds = 1;      //iteration between every cout or output.
    int gogeta = 0;       //loop counter.
    int duration = 12;    //how long the loop runs.
    
    while(1)
    {
     
     cout << these << endl;
     these = rotate(these,1);
     wait(seconds);
     gogeta++;
     if(gogeta >= duration) break;
    }
    
    
    
    
    return 0;
}