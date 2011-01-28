#include <iostream>

#include <gmp.h>

using namespace std;

int main()
{
   int number = 3;

   mpz_t one,two, needs;

   mpz_init_set_ui(one,1);
   mpz_init_set_ui(two,1);
   mpz_init(needs);

   mpz_ui_pow_ui(needs,10,999);

   while (1)
   {
      if (number%2 != 0)
      {
         mpz_add(one,one,two);

         if (mpz_cmp(one,needs) >= 0)
         {
            break;
         }
      }

      else
      {
         mpz_add(two,two,one);

         if (mpz_cmp(two,needs) >= 0)
         {
            break;
         }
      }
      number++;
   }


   cout<<mpz_get_str(NULL,10,needs)<<endl;
   cout<<number<<endl;


}
