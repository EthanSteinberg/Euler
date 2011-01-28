#include <iostream>

#include <gmp.h>

using namespace std;

int main()
{
   mpz_t num;
   mpz_t mult;

   mpz_init_set_ui(num,1);
   mpz_init(mult);

   mpz_ui_pow_ui(mult,10,10);

   for (int i = 1;i <= 7830457;i++)
   {
      mpz_mul_ui(num,num,2);
      mpz_mod(num,num,mult);
   }

   mpz_mul_ui(num,num,28433);
   mpz_add_ui(num,num,1);

   cout<<mpz_get_str(NULL,10,num)<<endl;

}
