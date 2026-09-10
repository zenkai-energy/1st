
 // SLOT MACHINE.   By ABE.   07.Sept.2026


 #include<iostream>
 #include<time.h>
 #include<string>
 using namespace std;

const float price1 = 30.0;
const float price3 = 45.0;
const float price10 = 100.0; 



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

void exchange(float & paper, int & spins, int in)
{
 time_t qwert = time(NULL);
 while (time(NULL)-qwert < 1){}
 if(in == 1)
 {
  if(paper >= price1)
  {
  paper = paper - price1;
  spins = spins + 1;
   cout << "Successfully carried out purchase.\n" << endl;
  }
  else cout << "insufficient funds" << endl;
 }
 else if(in == 3)
       {
        if(paper >= price3)
        {
         paper = paper - price3;
         spins = spins + 3; 
          cout << "Successfully carried out purchase.\n" << endl;
        }
        else cout << "insufficient funds" << endl;
       }
       else if(in == 10)
             {
              if(paper >= price10)
              {
               paper = paper - price10;
               spins = spins + 10;
                cout << "Successfully carried out purchase.\n" << endl;
              }
              else cout << "insufficient funds" << endl;
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


void spin( int & spins, float & money)
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
     float winnings = jackpot(first, second, third);
     money = money + winnings;
     if(winnings > 0)
     cout <<"You've received :" << winnings << " $." << endl;
     else cout << "   ☹️   try again" << endl;
    }
     else cout << "not enough spins." << endl;
     
 
     
}


int main()
{
    int spins=3;
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
     cout << "How many spins?" << endl;
     int times;
     cin >> times;
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