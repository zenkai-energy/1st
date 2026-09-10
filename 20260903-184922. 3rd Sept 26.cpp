#include<iostream>
using namespace std;


int length (std::string into )
{
    int x = 0;
    int i = 0;
    while(1)
    {
        if(static_cast<int>(into[i]) > 0)
        {x++;}
        i++;
        if(i == into.length())break;
        else continue;

    }
    return x;
}



std:: string sort(std::string file)
{
    char x;
    int k = 0;
    while(k < length(file))
    {
        if(k==0){k++; continue;}
        if(file[k] > file[k-1])
        {x = file [k-1];
        file[k-1] = file[k];
        file[k] = x;
        if(k > 0)
        {k--; continue;}
        }
        k++;

    }
    return file;

}

 int factorial(int in)
 {
  int i = 1;
  while(i <= in)
  {
   in = in*i ;
    i++;
   if(i==1)break;
   else continue;
  }
  return in;
 
 
 }
 
 
 
 
int main()
{
    int some;
    cin >> some;
    cout << "factorial(" << some << ") is " << factorial(some) << endl;
    return 0;
}