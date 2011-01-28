#include <iostream>

#include <gmp.h>

#include <algorithm>

using namespace std;

int main()
{
   int arr[] = {0,1,2,3,4,5,6,7,8,9};
   const int size = 10;

   int count = 0;

   int p = 1;
   for (; p<1000000;p++)
   {

      int k = -1;
      for (int i =0; i<size -1; i++)
      {
         if (arr[i] < arr[i +1] && i >k)
         {
            k = i;
         }
      }

      if (k == -1)
      {
         break;
      }

      int l = 0;
      for (int i = 0; i<size; i++)
      {
         if (arr[k] < arr[i] && i>l)
         {
            l = i;
         }
      }

      swap(arr[k],arr[l]);

      for (int i = k +1, b = size -1; i<b; i++,b--)
      {
         swap(arr[i],arr[b]);
      }
   }

      for (int i =0;i <size;i++)
      {
         cout<<arr[i]<<',';
      }
      cout<<endl<<p<<endl;



}
