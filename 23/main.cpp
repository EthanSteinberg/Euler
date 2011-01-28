#include <iostream>

#include <set>

#include <gmp.h>

using namespace std;

int main()
{
   set<int> nums;

   mpz_t total;
   mpz_init(total);

   for (int i = 12;i<=28123-12;i++)
   {
      int sum = 1;

      for (int b = 2; b*b<=i; b++)
      {
         if (i%b==0)
         {
            sum+= b;
            if (b*b !=i)
               sum+= i/b;
         }
      }

      if (sum >i)
         nums.insert(i);
   }

   for (int i = 1; i<= 28123;i++)
   {
            mpz_add_ui(total,total, i);
      for (auto it = nums.begin();it != nums.end();it++)
      {
         if (*it > i/2)
            break;

         else if (nums.count(i - *it))
         {
            mpz_sub_ui(total,total, i);
            break;
         }
      }
   }


   cout<<mpz_get_str(NULL,10,total)<<endl;



}
