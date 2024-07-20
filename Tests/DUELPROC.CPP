#include <conio.h>

int main(void)
{
   clrscr();
   cprintf("Press any key to continue:");
   while (!kbhit())  ;
   cprintf("A key was pressed");
   return 0;
   getch();
}