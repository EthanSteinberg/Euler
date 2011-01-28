#include <iostream>

#include "bignum.h"

int main()
{
   bignum myNumber(1);

   cout<<myNumber<<endl;

   myNumber*=11;
   cout<<myNumber<<endl;

   myNumber*=99;
   cout<<myNumber<<endl;

   myNumber*=87;
   cout<<myNumber<<endl;

   myNumber*=100;
   cout<<myNumber<<endl;


   bignum real(1);

   for (int i = 1;i <=100;i++)
   {
      real*= i;
   }

   cout<<real<<endl;

   real.getSum();
}
