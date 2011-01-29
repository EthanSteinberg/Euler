#include <iostream>

#include <gmp.h>

#include <fstream>
#include <string>

#include <bitset>

#include "board.h"

#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int sum = 0;

   srand(time(NULL));

   ifstream in("../96/sudoku.txt");
   string str;

   while (in>>str)
   {
      if (str >= "01" && str <= "50")
      if (str.length() == 2)
      {
         cout<<str;
         string vars[9];

         for (int i = 0; i <9; i++)
         {
            in>>vars[i];
         }

         t_board board(vars);
         
         bool run;
         do
         {
            run = board.checkSquares() || board.checkBoxes() || board.checkRows();
         }
         while (run);

         if (board.guess() == 0)
            cout<<"Fail at \n"<<endl;

         int smallsum = 0;
         smallsum += board.spaces[0][0].number * 100;
         smallsum += board.spaces[0][1].number * 10;
         smallsum += board.spaces[0][2].number * 1;

         cout<<": "<<smallsum<<endl;

         if (str == "06" || str == "10" || str == "49")
            cout<<board<<endl;
         sum+= smallsum;
      }
   }

   cout<<sum<<endl;
}
