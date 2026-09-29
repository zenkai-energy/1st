#include<iostream>
using namespace std;

int pow(int m, int n)
{
 if(n <= 1) return m;
 else return m * pow(m,n-1);

}

long int tet(int m, int n)
{
 if(n <= 1) return m;
 else return pow(tet(m,n-1),m);

}


int main()
{
    cout << tet(4,3) << endl;
    return 0;
}