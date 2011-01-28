#include <iostream>

#include <gmp.h>

using namespace std;


int gcd(int a,int b);

int main()
{

   int sumDen = 1;
   int sumNum = 1;

   int tested[100][100] = {};

   for (int den = 11; den <=99; den ++)
   {
      for (int num = 10; num<den; num++)
      {
         if (!(den %10 == 0 && num %10 == 0))// && !(den%11 == 0 &&num%11 == 0))
         {
            int gcd1 = gcd(num,den);
            int realDen = den/gcd1;
            int realNum = num/gcd1;

            if (realDen *gcd1 != den || realNum *gcd1 != num)
            {
               cout<<"The gcd was a fail"<<endl;
               return 5;
            }

            int testDen;
            int testNum;
            int gcd2;


            testDen = den % 10;
            testNum = num / 10;
            gcd2 = gcd(testNum,testDen);

            testDen /= gcd2;
            testNum /= gcd2;

            if (testDen == realDen && testNum == realNum && den/10 == num%10)
            {
               if (!tested[num][den]++)
               {
                  cout<<num<<' '<<den<<" 3 "<<gcd2<<':'<<realNum<<' '<<realDen<<endl;
                  sumDen *= realDen;
                  sumNum *= realNum;

   int gcf = gcd(sumDen,sumNum);

   cout<<sumDen/gcf<<' '<<sumNum/gcf<<endl;
               }

            }

         }
      }
   }

   int gcf = gcd(sumDen,sumNum);

   cout<<sumDen/gcf<<' '<<sumNum/gcf<<endl;
}


int gcd(int a,int b)
{
   static int arr[500][500] = {};

   if (b == 0)
   {
      return a;
   }

   else if (arr[a][b] != 0)
   {
      return arr[a][b];
   }

   else
   {
      arr[a][b] = gcd(b,a % b);
      return arr[a][b];
   }
}



