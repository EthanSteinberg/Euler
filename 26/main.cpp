#include <iostream>

#include <gmp.h>

#include <vector>

#include <algorithm>


using namespace std;

int findCycle(int num);


int main()
{
   int max = 0;
   int maxnum;

   for (int i = 1; i<984; i++)
   {
      cout<<i<<": "<<findCycle(i)<<endl;
   }


   for (int i = 1; i<1000; i++)
   {
      int cyc = findCycle(i);

      if (cyc > max)
      {
         max = cyc;
         maxnum = i;
      }
   }

   cout<<max<<' '<<maxnum<<endl;


}


int findCycle(int num)
{
   vector<pair<int,long long>> numbers;

   mpz_t divisor;
   mpz_init_set_ui(divisor,1);

   bool hitANum = 0;

   mpz_t tempRem;
   mpz_t tempCur;

   mpz_init(tempRem);
   mpz_init(tempCur);

   for (;;)
   {

      mpz_mod_ui(tempRem,divisor,num);
      long long remainder = mpz_get_ui(tempRem);

      mpz_tdiv_q_ui(tempCur,divisor,num);

      int curnum = mpz_get_ui(tempCur) % 10;

      auto it = find(numbers.begin(),numbers.end(),make_pair(curnum,remainder));

      if (curnum != 0)
      {
         hitANum = 1;
      }

      int sum = 0;
      if (it != numbers.end() && hitANum)
      {
         if (curnum == 0)
         {
            return 0;
            cout<<"Ending on zero, ";
         }

         for (; it !=numbers.end(); it++)
         {
            cout<<it->first<<", ";
            sum++;
         }

         return sum;
      }

      if (hitANum)
      {
         numbers.push_back(make_pair(curnum,remainder));
      }

      mpz_mul_ui(divisor,divisor,10);
   }
}









