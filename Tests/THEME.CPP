#include<conio.h>
#include <iostream.h>
#include <process.h>
#include<dos.h>
void Play()
{ //	clrscr();
	for(int i=1;i<=2;i++)
{
	sound(73.424);
	delay(500);
	nosound();	//1
	delay(100);
	  cout<<"there we go...";
	if( kbhit() ) exit(0);
	sound(73.424);
	delay(500);
	nosound();	//2
	delay(100);
	  cout<<"there we go...";
	if( kbhit() ) exit(0);
	sound(98);
	delay(500);
	nosound();	//3
	delay(100);
	  cout<<"there we go...";
	if( kbhit() ) exit(0);
	sound(98);
	delay(500);
	nosound();	//4
	delay(100);
	if( kbhit() ) exit(0);
	sound(82.4141);
	delay(500);
	nosound();	//5
	delay(100);
	  cout<<"there we go...";
	if( kbhit() ) exit(0);
	sound(82.4141);
	delay(500);
	nosound();	//6
	delay(100);
	  cout<<"there we go...";
	if( kbhit() ) exit(0);
	sound(98);
	delay(500);
	nosound();	//7
	delay(100);
	if( kbhit() ) exit(0);
	sound(82.4141);
	delay(500);
	nosound();	//8
	delay(100);
}
	if( kbhit() ) exit(0);
	sound(73.424);
	delay(500);
	nosound();	//9
	delay(100);
  }


  void main()
  {
  while( !kbhit() )
  {
  cout<<"there we go...";
  Play();
  }
  }
  
  