#include <iostream>
#include <cstdio>

#include <gmp.h>

#include <set>
using namespace std;

int main()
{
   set<int> nums;

   int sum = 0;

   int arr[] = {1,2,3,4,5,6,7,8,9};
   const int size = 9;

   while(1)
   {
      int k = -1;
      for (int i = 0;i < size;i++)
      {
         if (arr[i] < arr[i + 1] && i>k)
            k = i;
      }

      if (k == -1)
         break;

      int l = -1;
      for (int i = 0;i < size;i ++)
      {
         if (arr[k] < arr[i] && i>l)
            l = i;
      }

      swap(arr[k],arr[l]);

      for (int a = k + 1, b = size -1;a<b;a++,b--)
         swap(arr[a],arr[b]);

      int x = (arr[5] * 1000 + arr[6] * 100 + arr[7] * 10 + arr[8]) ;
      if (!nums.count(x))
      {
         if(( (arr[0] * (arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4]) )== x) || ( (arr[0] * 10 + arr[1]) * (arr[2] * 100 + arr[3] * 10 + arr[4]) == x) )

         {

            //cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4];
            //printf("%d%d%d%d%d: ",arr[0],arr[1],arr[2],arr[3],arr[4]);
            //cout<<x<<endl;
            nums.insert(x);
            sum += x;
         }
      }
         

   }
            //printf("%d%d%d%d%d: ",arr[0],arr[1],arr[2],arr[3],arr[4]);

      cout<<sum<<endl;

}
