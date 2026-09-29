
 // SLOT MACHINE.   By ABE.   10.Sept.2026

 #include <unistd.h>
 #include <conio.h>
 #include<iostream>
 #include<time.h>
 #include<string>
 using namespace std;

const float price1 = 30.0;
const float price3 = 45.0;
const float price10 = 100.0; 


void wait(int in)
{
 time_t now = time(NULL);
 while (time(NULL)-now < in){}
}

 void working()
 {
  
  std::string out = "working ";
  int i = 0;
  while(i < 5) 
  {
   wait(1);
   cout << "\r" << out << flush;
   out = out + " .";
   i++;
   
   
  }
  
  cout << "Done!" << endl;
  wait(1);
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

void exchange(float & paper, int & spins, int in)
{
 working();
 if(in == 1)
 {
  if(paper >= price1)
  {
  paper = paper - price1;
  spins = spins + 1;
   cout << "\nSuccessfully carried out purchase.\n" << endl;
   wait(1);
  }
  else cout << "\ninsufficient funds" << endl;
  wait(1);
 }
 else if(in == 3)
       {
        if(paper >= price3)
        {
         paper = paper - price3;
         spins = spins + 3; 
          cout << "\nSuccessfully carried out purchase.\n" << endl;
          wait(1);
        }
        else cout << "\ninsufficient funds" << endl;
        wait(1);
       }
       else if(in == 10)
             {
              if(paper >= price10)
              {
               paper = paper - price10;
               spins = spins + 10;
                cout << "\nSuccessfully carried out purchase.\n" << endl;
                wait(1);
              }
              else cout << "\ninsufficient funds" << endl;
              wait(1);
             }
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
  cout << "\033[2J\033[H";
  cout << "Please enter amt to deposit \nor 0 to council" << endl;
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


void spin( int & spins, float & money)
{



   if(spins > 0)
    {
     
     cout << "working . . . ..." << endl;
     int first, second, third;
     first = random(1.2);
     second = random(1.1);
     third = random(1);
     spins = spins - 1;
     cout << "[" << first << "] " << " [" << second << "] " << " [" << third << "]" << endl;
     float winnings = jackpot(first, second, third);
     money = money + winnings;
     if(winnings > 0)
     cout <<"You've received :" << winnings << " $." << endl;
     else cout << "   ☹️   try again" << endl;
     wait(1);
    }
     else cout << "not enough spins." << endl;
     
 
     
}

void display_game(int spins, float money)
{
 cout << "\033[2J\033[H";
 cout << "\nWELCOME TO THE SLOT MACHINE. \n" << endl;
    cout << "          spins: " << spins << endl;
    cout << "          amount: "<< money << '$' << '\n'<< endl;
    

}

 


int main()
{
    int spins=3;
    float money=100.0;
    
    while(true)
    { 
    usleep(100000);
     
    
     display_game(spins,money);
    
    cout << "Enter s to spin \nB to buy spins \nd to deposit funds \nx to quit" << endl;
    char r = '0';
    if (_kbhit()) {r = _getch();}
    
        if(r == 'd')
        {
         deposit(money);
         
         continue;
        }
    
        if(r == 'B')
         {
          
          while (true)
          {
          char t;
          cout << "\033[2J\033[H";
          cout << "Options" << endl;
          cout << "'A' to purchase 1sp for $30.0 \n'B' to purchase 3sps for $45.0 \n'C' to purchase 10sps for $100 \n   or x to go back." << endl;
          cin >> t;
          if(t == 'x') break;
          
          
          if(t == 'A')
          {
           exchange(money,spins,1);
           
           
          }
          else if(t == 'B' )
                {
                 exchange(money,spins,3);
                 
                }
                else if(t == 'C')
                {
                
                
                 exchange(money,spins,10);
                
                }
                
          }
          continue;
         }
    
     if(r == 's')
     {
     cout << "\033[2J\033[H";
     cout << "How many spins?" << endl;
     
     int times;
     cin >> times;
     cout << "\033[2J\033[H";
     while(times > 0)
     {
     spin(spins,money);
     times--;
     }
     }
    
    }
    
    return 0;
}
//Eventually add:
//    A loop for repeated spins.
//   ✅ A balance/money variable.
//    Different rewards.
//    ✅A function for spinning.
//    Maybe use vector later.