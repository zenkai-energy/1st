#include<iostream>
#include<string>
#include<time.h>
using namespace std;

const int minletters = 6;
const int minnumbers = 1;
const int minchars = 4; 
const int minuppercase = 1;
const int minsymbols = 1;
const std::string error = "Pin must be atleast;\n " + std::to_string(minchars) + " characters \n " + std::to_string(minletters) + " letters \n at least " + std::to_string(minuppercase) + " uppercase,\n "+ std::to_string(minnumbers) + " number \n atleast " + std::to_string(minsymbols) + " symbols";


int length (std::string into ){    int x = 0;    int i = 0;    while(1)    {        if(static_cast<int>(into[i]) > 0)        {x++;}        i++;        if(i == into.length())break;        else continue;    }    return x;}


bool symbols ( std:: string ex)
{
 int j =0;
 int dd =0;
 while(j < length(ex))
 {
  if (!(ex[j] >= '0' && ex[j] <= '9') &&
    !(ex[j] >= 'A' && ex[j] <= 'Z') &&
    !(ex[j] >= 'a' && ex[j] <= 'z'))
    {dd++;}
    j++;

    

 }
 
 if(dd >= minsymbols)
 return true;
 else return false;
}


bool uppercase (std::string file)
{
 int h=0;
 int mm=0;
 while (h < length(file))
 {
  if(file[h] >= 'A' && file[h] <= 'Z')
  {mm++;}
  h++;
 }
 if(mm >= minuppercase)
 return true;
 else return false;

}


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


bool numbers(std::string innn)
{
 int v = 0;
 int k = 0;
 while(v < length(innn))
 {
  if(innn[v] <= '9' && innn[v] >= '0')
  {k++;}
  v++;
 }
 if(k >= minnumbers)
 return true;
 else return false;

}


int main()
{
    std::string pin = "@@@@@@@@";
    std::string saved = "$$$$$$$";
    std:: string in = "#######";
   int count = 0;
    while(1)
    { 
     if(count == 0) cout << "Enter pin" << endl;
     else cout << "re enter pin" << endl;
     count++;
     cin >> in;
    
     if(!(length(in) >= minchars && numbers(in) && letters(in) && uppercase(in) && symbols(in)))
     {
      cout << error << endl;
      continue;
     }
     
     
     cout << "confirm pin" << endl;
     cin >> pin;
     
     if(pin != in)
     {
      cout << "mismatched \n try again" << endl;
      continue;
     }
     else if(pin == in)
     {saved = pin;
     cout << "successfully saved pin" << endl;
     break;
     }
     
    }
    
    
    
    
     time_t es = time(NULL);
    int o = 0;
    while(o < length(pin))
    {
    while (time(NULL) <= es+1)
    {cout << pin[o] << endl;
    o++;}
    
    }
    return 0;
}