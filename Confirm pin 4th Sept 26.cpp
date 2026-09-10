#include<iostream>
using namespace std;

const int minletters = 1;
const int mincharacters = 4; 

int length (std::string into ){    int x = 0;    int i = 0;    while(1)    {        if(static_cast<int>(into[i]) > 0)        {x++;}        i++;        if(i == into.length())break;        else continue;    }    return x;}


bool letters(std::string inn)
{
 int m = 0;
 int outt = 0;
 while(m < length(inn))
 {if ((inn[m] >= 'a' && inn[m] <= 'z') || (inn[m] >= 'A' && inn[m] <= 'Z'))
   outt++;
   m++;
 }
 if(outt >= minletters) return true;
 else return false;
}


int main()
{
    std::string pin = @@@@@@@@;
    std::string saved = $$$$$$$;
    std:: string in;
   int count = 0;
    while(1)
    {
     if(count == 0)
     {cout << "Enter pin" << endl;}
     else cout << "re enter pin" << endl;
     cin >> in;
     count++;
     
    if (saved == pin)
    {
     cout << "Broken" << endl;
     }
     
     
     if(length(in) < mincharacters)
     {
     cout << "should be at least " << mincharacters << " characters" << endl;
      continue;
     }
     
     
     if(!letters(in))
     {
      cout << "should be at least " << minletters << " letters \n So repeat." << endl;
      continue;
      }
     
     
     if(pin == in) break;
     
     
     
     cout << "Confirm pin" << endl;
     cin >> pin;
     
     if(pin == in)
     {
     cout << "saved pin" << endl;
     saved = pin;
     }
     else cout << "mismatch!" << endl;
     
    }
    
    
    
    
    
    int o = 0;
    while(o < length(pin))
    {
    
    cout << pin[o] << endl;
    o++;
    }
    return 0;
}