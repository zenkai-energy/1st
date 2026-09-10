#include<iostream>
using namespace std;

int words (std::string file)
{
 int k = 0;
 int out = 1;
 while(k < file.length())
 {
  if(file[k] == ' ' && file[k + 1] != ' ')
  {out++;}
  
  k++;
 }
 
 return out;
}

int main()
{
    cout << words("Hello World!") << endl;
    return 0;
}