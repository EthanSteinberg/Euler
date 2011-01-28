#include <iostream>

#include <cstdlib>

#include <gmp.h>

using namespace std;

int main()
{
   int primes[1000] = {1,0};


   int i = 2;
   while (i <=1000)
   {
      for (int b = 2 * i; b<=1000;b+=i)
      {
         primes[b-1] = 1;
      }

      while (primes[i++] == 1) ;
   }
/*
   for (int a =0; a<1000;a++)
   {
      if (primes[a] == 0)
         cout<<a+1<<endl;
   }
*/

   int max = -1;
   int maxa = -1;
   int maxb = -1;

   for (int a = -1000;a<=1000;a++)
   {
      for (int b =-1000;b<=1000;b++)
      {
         if (primes[labs(b)-1] == 1)
            continue;

         int len = 1;
         bool done = 0;

         do
         {
            done = 0;
            long x = len * len + len * a + b;

            if (labs(x) > 1000)
            {
               for (int t = 2; t * t <= labs(x);t++)
               {
                  if (x%t == 0)
                     done = 1;
               }
            }

            else
            {
               if (primes[labs(x) -1] == 1)
                  done = 1;
            }
            len++;
         }
         while (done == 0);

         if (len > max)
         {
            max = len;
            maxa = a;
            maxb = b;
            cout<<"set by : "<<maxa<<" "<<maxb<<" "<<len<<endl;
         }
      }
   }        

   cout<<max<<endl<<maxa<<endl<<maxb<<endl;
}
