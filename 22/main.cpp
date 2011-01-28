#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <algorithm>

using namespace std;


int main()
{
   ifstream in("../22/names.txt");

   string input;

   in>>input;
   {
      //cout<< input<<endl;
   }


   int score = 0;

   vector<string> names;

   char k;
   string curname;
   bool inName = 0;

   for (int i = 0; i <input.size(); i++)
   {
      k = input[i];

      if (k == ',')
      {
         continue;
      }

      else if (k == '"')
      {
         if (!inName)
         {
            curname = "";
            inName = 1;
         }

         else
         {
            inName = 0;
            names.push_back(curname);
         }
      }

      else
         curname.push_back(k);
   }

   sort(names.begin(),names.end());

   for (auto it = names.begin();it != names.end();it++)
      cout<<*it<<' ';

   for (int i = 1;i<=names.size();i++)
   {
      int sum = 0;
      for (int b = 0;b<names[i-1].size();b++)
         sum+= names[i-1][b] - 'A' +1;

      score += sum * i;
   }


   cout<<endl<<score<<endl;




}

