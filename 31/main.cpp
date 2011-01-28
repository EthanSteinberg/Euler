#include <iostream>

#include <gmp.h>

using namespace std;

   int types[] = {1,2,5,10,20,50,100,200};
   const int size = 8;
   const int am = 200;
   int sums[am][size] = {};

int count(int n,int m);

int main()
{



   for (int i = 0; i<200; i++)
      for (int b = 0; b<size; b++)
      {
         sums[i][b] = -1;
      }

   cout<<count(am,size)<<endl;


}

int count(int n,int m)
{
   if (n == 0)
   {
      return 1;
   }
   if (n < 0)
   {
      return 0;
   }

   if (m <= 0)
   {
      return 0;
   }

   if (sums[n-1][m-1] != -1)
   {
     return sums[n-1][m-1];
   }

   return sums[n-1][m-1] = count(n, m - 1) + count(n - types[m-1], m);
}
