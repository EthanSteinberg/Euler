
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>

#include <string>
#include <bitset>

#include "board.h"

using namespace std;
void t_space::set(int i)
{
   if (i == 0)
   {
   }
   else
   {
      spaces.reset();
      spaces.set(i -1);
      number = i;
   }
}

t_space::t_space()
{
   spaces.set();
   number = 0;
}


bool t_space::has(int i)
{
   return spaces.test(i-1);
}
void t_space::rem(int i)
{
   spaces.reset(i - 1);
}
//Board
///
//
t_board::t_board(const string vars[9])
{
   for (int y = 0; y<9; y++)
   {
      for (int x = 0; x<9; x++)
      {
         int blah = vars[y].at(x) - '0';
         spaces[y][x].set(blah);

         if (blah  != 0)
         {
            setIn(x,y,blah);
         }
      }
   }
}
std::ostream &operator<< (std::ostream &out, const t_board &board)
{
   for (int y = 0; y<9; y++)
   {
      if (y%3 == 0)
      {
         out<<endl;
      }

      for (int x = 0; x<9; x++)
      {
         if (x%3 == 0)
         {
            out<<' ';
         }

         out<<board.spaces[y][x].number;
      }

      out<<endl;
   }

   return out;
}
void t_board::setIn(int x, int y, int blah)
{
   for (int i = 0; i <9; i++)
   {
      spaces[y][i].rem(blah);
      spaces[i][x].rem(blah);
   }

   for (int ix = x/3 * 3; ix < x/3 * 3+ 3; ix++)
   {
      for (int iy = y/3 * 3; iy < y/3 * 3+ 3; iy++)
      {
         spaces[iy][ix].rem(blah);
      }
   }
}
bool t_board::checkSquares()
{
   bool moved = 0;

   for (int y = 0; y<3; y++)
      for (int x = 0; x<3; x++)
      {
         for (int i = 1; i<=9; i++)
         {
            int found = 0;
            int foundx;
            int foundy;

            for (int iy = y * 3; iy < y * 3+ 3; iy++)
            {
               for (int ix = x * 3; ix < x * 3+ 3; ix++)
               {
                  if (spaces[iy][ix].has(i) && spaces[iy][ix].number == 0)
                  {
                     //              if(y == 2 && x == 1 && i == 5)
                     //               cout<<"WTF is this ****!!,"<<endl;
                     found++;
                     foundx = ix;
                     foundy = iy;
                  }

                  if (spaces[iy][ix].number == i)
                  {
                     //                  if(y == 2 && x == 1 && i == 5)
                     //                   cout<<"WTF is this ****!!"<<endl;
                     found = 2;
                  }
               }
            }

            if (found == 1)
            {
               moved++;
               spaces[foundy][foundx].set(i);
               setIn(foundx,foundy,i);
            }
         }
      }

   return moved;
}

bool t_board::checkBoxes()
{
   bool moved = 0;

   for (int y = 0; y<9; y++)
   {
      for (int x = 0; x<9; x++)
      {
         if (spaces[y][x].number == 0)
         {
            int set = 0;

            for (int i =1; i<=9; i++)
            {
               if (spaces[y][x].has(i))
               {
                  if (set == 0)
                  {
                     set = i;
                  }

                  else
                  {
                     set = -1;
                  }
               }
            }

            if (set != 0 && set != -1)
            {
               spaces[y][x].set(set);
               setIn(x,y,set);
               moved++;
            }
         }
      }
   }

   return moved;
}
bool t_board::checkRows()
{
   bool moved = 0;

   for (int b = 0; b<9; b++)
   {
      for (int i = 1; i<=9; i++)
      {
         int found = 0;
         int foundx;
         int foundy;

         for (int iy = 0, ix = b; iy<9; iy++)
         {
            if (spaces[iy][ix].has(i) && spaces[iy][ix].number == 0)
            {
               found++;
               foundx = ix;
               foundy = iy;
            }

            if (spaces[iy][ix].number == i)
            {
               found = 2;
            }
         }

         if (found == 1)
         {
            moved++;
            spaces[foundy][foundx].set(i);
            setIn(foundx,foundy,i);
         }

         found = 0;

         for (int ix = 0, iy = b; ix<9; ix++)
         {
            if (spaces[iy][ix].has(i) && spaces[iy][ix].number == 0)
            {
               found++;
               foundx = ix;
               foundy = iy;
            }

            if (spaces[iy][ix].number == i)
            {
               found = 2;
            }
         }

         if (found == 1)
         {
            moved++;
            spaces[foundy][foundx].set(i);
            setIn(foundx,foundy,i);
         }
      }
   }

   return moved;
}

bool t_board::guess()
{
   int zeros = 0;

   for (int y = 0; y <9 ; y++)
   {
      for (int x = 0; x< 9; x++)
      {
         if (spaces[y][x].number == 0)
         {
            zeros++;

            if (spaces[y][x].spaces.none())
            {
               return 0;
            }
         }
      }
   }

   if (zeros == 0)
   {
      return 1;
   }

   int least = 9;
   int leastx;
   int leasty;

   for (int y = 0; y <9 ; y++)
   {
      for (int x = 0; x< 9; x++)
      {
         if (spaces[y][x].number == 0)
         {
            int number = 0;

            for (int i = 1; i <= 9; i++)
            {
               if (spaces[y][x].has(i))
               {
                  number++;
               }
            }

            if (number <least)
            {
               if (number== 0)
               {
                  cout<<"WTF STUPID COMPUTER"<<endl;
               }

               least = number;
               leastx = x;
               leasty = y;
            }
         }
      }
   }

   t_board store(*this);

   for (int leasti = 1; leasti<=9; leasti++)
   {
      if (!spaces[leasty][leastx].has(leasti))
      {
         continue;
      }

      spaces[leasty][leastx].set(leasti);
      setIn(leastx,leasty,leasti);
      bool run;

      do
      {
         run = checkSquares() || checkBoxes() || checkRows();
      }
      while (run);

      if (guess() == 1)
      {
         return 1;
      }

      copy(&store.spaces[0][0], &store.spaces[8][8] + 1, &spaces[0][0]);
   }

   return 0;
}

