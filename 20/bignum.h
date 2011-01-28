#include <vector>
#include <iostream>

using namespace std;

class bignum
{
public:
   bignum(int start) : number(1,start)
   {}

   void operator*= (int factor)
   {
      int size = number.size();

      number.push_back(0);
      number.push_back(0);

      vector<int> add(size +2,0);

      for (int i = 0; i<size; i ++)
      {
         int tempNum = number[i] * factor;

         number[i] = tempNum %10;

         add[i+1] += (tempNum/10) % 10;

         add[i+2] += (tempNum/100);
      }

      for (int i =0 ; i <add.size(); i++)
      {
         number[i] += add[i];

         add[i + 1] += number[i]/10;

         number[i] %= 10;
      }
   }

   friend ostream &operator<<(ostream &out, const bignum &num)
   {
      for (int i = num.number.size() - 1; i >=0; i--)
      {
         cout<<(int) num.number[i];
      }

      return out;
   }

   void getSum()
   {
      int sum = 0;

      for (int i = 0; i<number.size();i++)
      {
         sum+= number[i];
      }

      cout<<sum<<endl;
   }


private:
   vector<char> number;

};
