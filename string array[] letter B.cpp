#include<iostream>
using namespace std;

std::string letterB[] = {
"**** ",
"*   *",
"**** ",
"*   *",
"**** ",

}
;




int main()
{
    char a,b,c;
    cout << "Enter initials" << endl;
    cin >> a >> b >> c;
    
    
    
    int s = sizeof(letterB)/sizeof(letterB[0]);
    
    int k,m;
    k=0;
    m=0;
    
    
    
    if(a == 'b' && b == 'b' && c =='b')
    {
    while(m<4)
    { 
     k = 0;
     while (k<s)
     {
      cout << letterB[k] << endl;
      k++;
     }
     
     m++;
    }
    }
    else cout << a << b << c << endl;
    
    
    
    return 0;
}