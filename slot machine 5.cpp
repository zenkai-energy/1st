
 // SLOT MACHINE.   By ABE.   07.Sept.2026


 #include<iostream>
 #include<time.h>
 #include<string>
 using namespace std;





 void working()
 {
  
  std::string out = "working ";
  time_t start = time(NULL);
  int i = 0;
  
  while(i < 4) 
  {
   if(time(NULL) - start >= 1)
   {
   cout << out << endl;
   out = out + " .";
   i++;
   start = time(NULL);
   }
   
  }
  
  cout << "Done!" << endl;
  
 }
 
 
 int random(int in)
 {
  int k = 0;
  time_t n = time(NULL);
  
  while(time(NULL) - n < in)
  {
   if(k > 8 || k < 0)
   {
    k = 0;
    continue;
   }
   k++;
  }
  return k;
 }

bool twice(int a, int b, int c, int num )
{
 if((a == num)&&(b == num) || (a == num)&&(c == num) || (b == num)&&(c == num))
 return true;
 else return false;
}

bool thrice (int a, int b, int c, int num)
{
 if((a == num)&&(b == num)&&(c == num))
 return true;
 else return false;
}


 
float jackpot(int st, int nd, int rd)
{
 
 float out = 0;
 int k = 0;
 while (k < 10)
 {
  
  if(thrice(st,nd,rd,k))
  {
   if(k == 7) 
   {out = 3000.0; break;}
   out = (float(k) * 100.0) + 100.0;
   break;
  }


  if(twice(st,nd,rd,k))
  {
   if(k == 7) {out = 350.0; break;}
   out = (50.0 * float(k) + 10)/2 ;
  break;
  
  }
  
   
  k++;
 }
 return out;
}


void deposit(float & in)
{
  float q;
 while(1)
 {
  cout << "Please enter amt to deposit or 0 to council" << endl;
  cin >> q;
  if(q > 0)
  {
  in = in + q;
  working();
  cout << "Successfully deposited " << q << '$' <<endl;
  cout << "New amt is :" << in << '$' << endl;
  break;
  }
  else break;
 }
}





int main()
{
    int spins=1;
    float money=100.0;
    
    while(2)
    {
    
    cout << "\nWELCOME TO THE SLOT MACHINE. \n" << endl;
    cout << "          spins: " << spins << endl;
    cout << "          amount: "<< money << '$' << '\n'<< endl;
    
    cout << "Enter s to spin \nB to buy spins \nd to deposit funds \nx to quit" << endl;
    char r;
    cin >> r;
    
        if(r == 'd')
        {
         deposit(money);
         continue;
        }
    
        if(r == 'B')
         {
          while (1)
          {
          char t;
          
          cout << "enter A to purchase 1sp for $30.0 \nB to purchase 3sps for $45.0 \nC to purchase 10sps for $100 \n   or x to go back." << endl;
          cin >> t;
          if(t == 'x') break;
          
          time_t qwert = time(NULL);
          if(t == 'A' && money >=30.0)
          {
           while (time(NULL)-qwert < 1){}
           spins = spins + 1;
           money = money - 30;
           cout << "Successfully carried out purchase.\n" << endl;
           
          }
          else if(t == 'B' && money >= 45.0)
                {
                 while (time(NULL)-qwert < 1){}
                 spins = spins + 3;
                 money = money - 45;
                 cout << "Successfully carried out purchase.\n" << endl;
                }
                else if(t == 'C' && money >= 100.0)
                {
                 while (time(NULL)-qwert < 1){}
                 spins = spins + 10;
                 money = money - 100;
                 cout << "Successfully carried out purchase.\n" << endl;
                }
                else cout << "Insufficient funds" << endl;
          }
          continue;
         }
    
     while(r = 's')
     {
     if(spins > 0)
     {
     cout << "working . . . ..." << endl;
     int first, second, third;
     first = random(1);
     second = random(2);
     third = random(3);
     spins = spins - 1;
     cout << "[" << first << "] " << " [" << second << "] " << " [" << third << "]" << endl;
    
     money = money + jackpot(first, second, third);
     if(jackpot(first, second, third) > 0)
     cout <<"You've received :" << jackpot(first, second, third) << " $." << endl;
     else cout << "   ☹️   try again" << endl;
     break;
     }
     else cout << "not enough spins." << endl;
     break;
     }
    
    }
    
    return 0;
}