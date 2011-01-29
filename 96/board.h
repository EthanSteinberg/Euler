#include <ostream>

#include <string>
#include <bitset>

struct t_space
{
   t_space();
   std::bitset<9> spaces;
   int number;

   void set(int i);
   bool has(int i);
   void rem(int i);
};



struct t_board
{
   t_space spaces[9][9];

   t_board(const std::string vars[9]);

   friend std::ostream &operator<< (std::ostream &out, const t_board &board);

   void setIn(int x, int y, int blah);
   bool checkBoxes();
   bool checkSquares();
   bool checkRows();

   bool guess();
};
