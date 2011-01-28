#include <iostream>

#include <gmp.h>

using namespace std;

int main()
{
   int sum = 1;
   for (int i = 2;i <=501;i++)
   {
      sum += 16 * i * i - 28 * i +16;
   }

   cout<<sum<<endl;
}
