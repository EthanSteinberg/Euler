#include <iostream>

#include <vector>


using namespace std;

int main()
{
   int sum = 0;

   vector<int> numbers(10000,0);

   for (int i= 1; i<=10000; i++)
   {
      for (int b = 1; b<=i/2; b++)
      {
         if (i%b==0)
         {
            numbers[i-1]+= b;
         }
      }

      if (i == 220 || i == 284)
      {
         cout<<numbers[i-1]<<endl;
      }
   }

   for (int i =1; i<=10000; i++)
   {
      if (numbers[i-1] >i)
      {
         if (numbers[numbers[i -1]-1] == i)
         {
            sum+= i + numbers[i -1];
         }
      }
   }

   cout<<sum<<endl;
}


