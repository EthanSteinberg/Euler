#include <iostream>

using namespace std;


int main()
{
   int year = 1900;
   int sun = 0;

   int day = 0;
   for (; year<=2000; year++)
   {
      for (int i =0; i<12; i++)
      {
         switch (i)
         {
         case 0:
            day += 31;
            break;

         case 1:
            day += 28 + (year%4==0 && (year%400==0 || year%100!=0));
            break;

         case 2:
            day += 31;
            break;

         case 3:
            day += 30;
            break;

         case 4:
            day += 31;
            break;

         case 5:
            day += 30;
            break;

         case 6:
            day += 31;
            break;

         case 7:
            day += 31;
            break;

         case 8:
            day += 30;
            break;

         case 9:
            day += 31;
            break;

         case 10:
            day += 30;
            break;

         case 11:
            day += 31;
            break;
         }

         day%=7;
      if (day%7 == 6 && year!=1900)
         sun++;

      }
   }
      cout<<sun<<endl;
}
