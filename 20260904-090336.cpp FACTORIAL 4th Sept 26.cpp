#include<iostream>
using namespace std;

int factorial(int in)
{ 
  int i = in;
  int k = i;
  while(k > 1)
  {
   i = i*(k-1);
   k--;
   }
   if(in <= 0)return 0;
   else return i;
}


int main()
{
    
    int input;
    cin >> input;
    cout << "factorial(" << input << ")" << endl;
    
    cout << factorial(input) << endl;
    return 0;
}