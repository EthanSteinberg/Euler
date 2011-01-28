#include <iostream>

#include <gmp.h>

#include <cmath>

using namespace std;

int main()
{
   int totalSum = 0;

   for (int i = 2; i<= 354294;i++)
   {
      int sum = 0;
      for (int j = i; j > 0;j/=10)
      {
        sum += pow(j %10,5);
      }

      if (sum == i)
         totalSum += i;
   }

   cout<<totalSum<<endl;

}
