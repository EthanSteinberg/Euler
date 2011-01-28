#include <iostream>

#include <gmp.h>

#include <set>

#include <cmath>

#include <string>

using namespace std;

int main()
{
   set<string> numbers;
   long long total = 0;

   mpz_t x;
   mpz_init(x);

   for (int a = 2; a <= 100;a++)
   {
      for (int b = 2;b <= 100;b++)
      {
        mpz_ui_pow_ui(x,a,b);
         if (!numbers.count(mpz_get_str(NULL,16,x)))
            numbers.insert(mpz_get_str(NULL,16,x)),total++;
      }
   }

   cout<<total<<endl<<numbers.size();
}

