#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>
#include<stdio.h>
#include "C:\MOUSE.CPP"

const char smile = 1, li = 179, slp = 196;
char s[10];
unsigned int BattCount = 0;  //Battery Counter
int Moved = 0; //Flag to see if he moved
int NewGame = 0; //Flag to see if player is starting a new game

class PlayerStats
{
	private:
		float health;

	public:
		char name[30];
		int soundlvl;
		char location;
		int won;
		char gamemode;
		struct Inven
		{
			int MedKits;
			unsigned int MeshCutter;
			struct Pho
			{
				int Battery;
				unsigned int Signal;
				unsigned int Ringer;
				unsigned int Power;
			}Phone;
			int Rope;
			int Axe;
		}Inventory;

		struct Lcs
		{
			int FrontDoor;
			int CompRoom;
			int Bedroom;
			int Vents;
			int FrontWindow;
		}Lock;

		struct Mls
		{
			int OpenedEvic;
			int Engaged;
		}Mail;

		struct Kys
		{
			int Frontoor;
			int Comproom;
			int Bedroom;
		}Keys;

		PlayerStats()
		{
			health = 100;
			strcpy(name ,"Lil one");
			soundlvl = 0;
			location = 's';
			won = 0;
			gamemode = '\0';
			Inventory.MedKits = 0;
			Inventory.MeshCutter = 0;
			Inventory.Phone.Signal = 0;
			Inventory.Phone.Battery = 0;
			Inventory.Phone.Ringer = 0;
			Inventory.Phone.Power = 0;
			Inventory.Rope = 0;
			Inventory.Axe = 0;
			Lock.FrontDoor = 1;
			Lock.CompRoom = 1;
			Lock.Bedroom = 1;
			Lock.Vents = 1;
			Lock.FrontWindow = 1;
			Mail.OpenedEvic = 0;
			Mail.Engaged = 0;
			Keys.Frontoor = 0;
			Keys.Comproom = 0;
			Keys.Bedroom = 0;
		}

		float ReturnHealth()
		{
			return health;
		}

		float UpdateHealth(float Val)
		{
			health = Val;
		}
}Player;


void save();
void reset();
void load();
void loaddisplay();
void readchangelog();
void transition();
void quit();
void map();
void menu();
void menu2();
void computer_clrscr();
void computer_shell();
void computer_main();
void computer_main_input();
void computer_mail_introtransition();
void computer_mail_exittransition();
void computer_mail();
void computer_mail_inbox();
void computer_mail_compose();
void computer_notes();
void computer_gamedir();
void computer_shutdown();
void phone();
void goback();
void battery();
void rules();
void pt1();
void nameinput();
void pt2();
void pt3();
void pt3_1();
void pt3_2();
void pt3_3();
void frontdoor();
void frontwindow();
void hallway1();
void hallway2();
void stairs();
void hallway4();
void hallway5();
void hallway6();
void kitchen();
void hall();
void closet();
void storeroom();
void vents();
void vents2();
void vents3();
void vents4();
void vents5();
void comproom();
void library1();
void library2();
void toilet();
void bedroom();
void balcony();
void woods();
void endgame();
void change();


void save()
{
	fstream savefile;
	if(!savefile)
	{
		cerr<<"<<ERROR: COULDN'T CREATE A SAVE FILE>>";
	}
	else
	{
		savefile.open ("H:\\SAVE.txt" , ios::out | ios::binary);
		savefile.write( (char*)&Player , sizeof(Player) );
	}
	savefile.close();
}

void reset()
{
	fstream resetfile;
	if(!resetfile)
	{
		cerr<<"<<ERROR: COULDN'T CREATE A SAVE FILE>>";
	}
	else
	{
		resetfile.open ("H:\\SAVE.txt" , ios::out | ios::binary);
	}
	resetfile.close();	
}

void load()
{
	fstream loadfile;
	if(!loadfile)
	{
		cerr<<"<<ERROR: \"SAVE.txt\" NOT FOUND>>";
	}
	else
	{
		loadfile.open("H:\\SAVE.txt" , ios::in | ios::binary);
		loadfile.read( (char*)&Player , sizeof(Player) );
	}
	loadfile.close();
	loaddisplay();
}

void loaddisplay()
{ 
	cleardevice();
	cout<<"\n\n"
	<<"\t\t\t\tPLAYER NAME: "
	<<Player.name
	<<"\n"
	<<"\t\t\t\tPLAYER HEALTH: "
	<<Player.ReturnHealth()
	<<"\n"
	<<"\t\t\t\tLOCATION: ";
	switch (Player.location) //Location Output
	{
		case 's':
		case 'S':
			cout<<"STORE ROOM";
			break;

		case 'c':
		case 'C':
			cout<<"CLOSET";
			break;

		case 'h':
		case 'H':
			cout<<"HALL";
			break;

		case 'k':
		case 'K':
			cout<<"KITCHEN";
			break;

		case 'v':
		case 'V':
			cout<<"VENTS";
			break;

		case 'w':
		case 'W':
			cout<<"VENTS 2";
			break;

		case 'u':
		case 'U':
			cout<<"VENTS 3";
			break;

		case 'x':
		case 'X':
			cout<<"VENTS 4";
			break;

		case 'z':
		case 'Z':
			cout<<"VENTS 5";
			break;

		case 'r':
		case 'R':
			cout<<"COMPUTER ROOM";
			break;

		case 'b':
		case 'B':
			cout<<"LEFT LIBRARY";
			break;

		case 'y':
		case 'Y':
			cout<<"RIGHT LIBRARY";
			break;

		case 't':
		case 'T':
			cout<<"UPSTAIRS TOILET";
			break;

		case 'm':
		case 'M':
			cout<<"BEDROOM";
			break;

		case 'o':
		case 'O':
			cout<<"BALCONY";
			break;

		case '1':
			cout<<"ENTRANCE";
			break;

		case '2':
			cout<<"LOWER HALLWAY";
			break;

		case '3':
			cout<<"STAIRS";
			break;

		case '4':
			cout<<"UPPER HALLWAY";
			break;

		case '5':
			cout<<"BEDROOM HALLWAY";
			break;

		case '6':
			cout<<"WINDOW SILL";
			break;
	}
	cout<<"\n\n"
	<<"\t\t\t<<PRESS ANY KEY TO PROCEED>>";
	map();
	getch();
	switch (Player.location) //Actual Load
	{
		case 's':
		case 'S':
			transition();
			storeroom();
			break;

		case 'c':
		case 'C':
			transition();
			closet();
			break;

		case 'h':
		case 'H':
			transition();
			hall();
			break;

		case 'k':
		case 'K':
			transition();
			kitchen();
			break;

		case 'v':
		case 'V':
			transition();
			vents();
			break;

		case 'w':
		case 'W':
			transition();
			vents2();
			break;

		case 'u':
		case 'U':
			transition();
			vents3();
			break;

		case 'x':
		case 'X':
			transition();
			vents4();
			break;

		case 'z':
		case 'Z':
			transition();
			vents5();
			break;

		case 'r':
		case 'R':
			transition();
			comproom();
			break;

		case 'b':
		case 'B':
			transition();
			library1();
			break;

		case 'y':
		case 'Y':
			transition();
			library2();
			break;

		case 't':
		case 'T':
			transition();
			toilet();
			break;

		case 'm':
		case 'M':
			transition();
			bedroom();
			break;

		case 'o':
		case 'O':
			transition();
			balcony();
			break;

		case '1':
			transition();
			hallway1();
			break;

		case '2':
			transition();
			hallway2();
			break;

		case '3':
			transition();
			stairs();
			break;

		case '4':
			transition();
			hallway4();
			break;

		case '5':
			transition();
			hallway5();
			break;

		case '6':
			transition();
			hallway6();
			break;
	}
}

void readchangelog()
{
	char ch;
	fstream logfile;
	logfile.open ("H:\\CHANGE.txt" , ios::in | ios::binary);
	if (!logfile)
	{
		cerr<<"<<ERROR: \"CHANGE.txt\" NOT FOUND>>";
	}
	else
	{
		logfile.get(ch);
		while(!logfile.eof())
		{
			cout<<ch;
			logfile.get(ch);
		}
	}
	logfile.close();
}

void transition()
{
	char ch = Player.location;
	fstream ledgerfile;
	ledgerfile.open ("H:\\LEDGER.txt" , ios::out | ios::binary);
	if (!ledgerfile)
	{
		cerr<<"<<ERROR: \"LEDGER.txt\" NOT FOUND>>";
	}
	else
	{
		ledgerfile.put(ch);
		ch = '\n';
		ledgerfile.put(ch);
	}
	ledgerfile.close();
	cleardevice();
	cout<<"\t\t\t\t"
	<<"<<WAIT ONE MOMENT>>"
	<<"\n\n\n\n\n";
	delay(750);
}

void quit()
{
	cleardevice();
	cout<<"\n\n"
	<<"\t\t\t\tARE YOU SURE? (Y/N)"
	<<"\n\n\n\n\n"
	<<"\t\t\t\t\tYou: ";
	cin>>s;
	if ( ( strcmpi("Y",s) == 0 ) || ( strcmpi("y",s) == 0 ) )
	{
		menu2();
	}
	else
	{
		switch (Player.location) //Back to where he was
		{
			case 's':
			case 'S':
				storeroom();
				break;

			case 'c':
			case 'C':
				closet();
				break;

			case 'h':
			case 'H':
				hall();
				break;

			case 'k':
			case 'K':
				kitchen();
				break;

			case 'v':
			case 'V':
				vents();
				break;

			case 'w':
			case 'W':
				vents2();
				break;

			case 'u':
			case 'U':
				vents3();
				break;

			case 'x':
			case 'X':
				vents4();
				break;

			case 'z':
			case 'Z':
				vents5();
				break;

			case 'r':
			case 'R':
				comproom();
				break;

			case 'b':
			case 'B':
				library1();
				break;

			case 'y':
			case 'Y':
				library2();
				break;

			case 't':
			case 'T':
				toilet();
				break;

			case 'm':
			case 'M':
				bedroom();
				break;

			case 'o':
			case 'O':
				balcony();
				break;

			case '1':
				hallway1();
				break;

			case '2':
				hallway2();
				break;

			case '3':
				stairs();
				break;

			case '4':
				hallway4();
				break;

			case '5':
				hallway5();
				break;

			case '6':
				hallway6();
				break;
		}
	}

}

void map()
{
	rectangle(40,300,600,375); //Outer Rectangle
	line(140,300,140,375); //H1
	line(240,300,240,375);
	line(340,300,340,375);
	line(440,300,440,375);
	line(520,225,520,300);
	rectangle(440,375,600,450);
	rectangle(440,225,600,300);
}

void menu()
{
	initmouse();
	int x,y,i;
	int g=DETECT,d,button;
	initgraph(&g, &d,"C:\\Turboc3C\\BGI");
	cleardevice();
	x=getmaxx()/2; //Set center for X axis
	y=getmaxy()/2; //Set center for Y axis

	int oc=0; //Value for outer circle
	int ic=100; //Value for inner circle

	for(int e=0 ; e<5 ; e++) //The circle going outward
	{
		for(int i=50 ; i<150 ; i++)
		{
			setcolor(7); //The text in white
			settextstyle(SMALL_FONT, HORIZ_DIR, 10);
			outtextxy(x,y,"Loading");
			settextstyle(SMALL_FONT, HORIZ_DIR, 5);
			outtextxy(x+5,y+5,"Please Wait");
			setcolor(8); //The circle in grey
			circle(x,y,oc);
			circle(x,y,ic);
			oc++;
			ic--;
			cleardevice();
		}
	}
	for(e=0 ; e<5 ; e++) //The circle going inward
	{
		for(int i=50 ; i<150 ; i++)
		{
			setcolor(7);
			settextstyle(SMALL_FONT, HORIZ_DIR, 10);
			outtextxy(x,y,"Loading");
			settextstyle(SMALL_FONT, HORIZ_DIR, 5);
			outtextxy(x+5,y+5,"Please Wait");
			setcolor(8);
			circle(x,y,oc);
			circle(x,y,ic);
			oc--;
			ic++;
			cleardevice();
		}
	}
	closegraph();
	_setcursortype(_NOCURSOR);
	delay(2000);
	cout<<"\n\n";delay(50);
	cout<<"A";delay(50);cout<<" ";delay(50);cout<<"g";delay(50);
	cout<<"a";delay(50);cout<<"m";delay(50);cout<<"e";delay(50);
	cout<<" ";delay(50);cout<<"b";delay(50);cout<<"y";delay(50);
	cout<<" ";delay(50);cout<<"A";delay(50);cout<<"m";delay(50);
	cout<<"o";delay(50);cout<<"g";delay(50);cout<<"h";delay(50);
	cout<<" ";delay(50);cout<<"&";delay(50);cout<<" ";delay(50);
	cout<<"D";delay(50);cout<<"w";delay(50);cout<<"i";delay(50);
	cout<<"j";delay(50);cout<<"i";delay(50);cout<<"t";delay(50);
	cout<<"h";delay(50);cout<<".";delay(2000);
	_setcursortype(_NORMALCURSOR);
	cout<<"\n\n";
	delay(25);
	_setcursortype(_NOCURSOR);
	cout<<"T";delay(50);cout<<"h";delay(50);cout<<"i";delay(50);
	cout<<"s";delay(50);cout<<" ";delay(50);cout<<"i";delay(50);
	cout<<"s";delay(50);cout<<" ";delay(50);cout<<"a";delay(50);
	cout<<" ";delay(50);cout<<"w";delay(50);cout<<"o";delay(50);
	cout<<"r";delay(50);cout<<"k";delay(50);cout<<" ";delay(50);
	cout<<"o";delay(50);cout<<"f";delay(50);cout<<" ";delay(50);
	cout<<"f";delay(50);cout<<"i";delay(50);cout<<"c";delay(50);
	cout<<"t";delay(50);cout<<"i";delay(50);cout<<"o";delay(50);
	cout<<"n";delay(50);cout<<".";delay(50);cout<<" ";delay(250);
	cout<<"A";delay(50);cout<<"n";delay(50);cout<<"y";delay(50);
	cout<<" ";delay(50);cout<<"s";delay(50);cout<<"i";delay(50);
	cout<<"m";delay(50);cout<<"i";delay(50);cout<<"l";delay(50);
	cout<<"a";delay(50);cout<<"r";delay(50);cout<<"i";delay(50);
	cout<<"t";delay(50);cout<<"i";delay(50);cout<<"e";delay(50);
	cout<<"s";delay(50);cout<<" ";delay(50);cout<<"t";delay(50);
	cout<<"o";delay(50);cout<<" ";delay(50);cout<<"a";delay(50);
	cout<<"n";delay(50);cout<<"y";delay(50);cout<<" ";delay(50);
	cout<<"r";delay(50);cout<<"e";delay(50);cout<<"a";delay(50);
	cout<<"l";delay(50);cout<<" ";delay(50);cout<<"p";delay(50);
	cout<<"e";delay(50);cout<<"r";delay(50);cout<<"s";delay(50);
	cout<<"o";delay(50);cout<<"n";delay(50);cout<<",";delay(50);
	cout<<" ";delay(50);cout<<"a";delay(50);cout<<"l";delay(50);
	cout<<"i";delay(50);cout<<"v";delay(50);cout<<"e";delay(50);
	cout<<" ";delay(50);cout<<"o";delay(50);cout<<"r";delay(50);
	cout<<" ";delay(50);cout<<"d";delay(50);cout<<"e";delay(50);
	cout<<"c";delay(50);cout<<"e";delay(50);cout<<"a";delay(50);
	cout<<"s";delay(50);cout<<"e";delay(50);cout<<"d";delay(50);
	cout<<",";delay(50);cout<<" ";delay(50);cout<<"i";delay(50);
	cout<<"s";delay(50);cout<<" ";delay(50);cout<<"p";delay(50);
	cout<<"u";delay(50);cout<<"r";delay(50);cout<<"e";delay(50);
	cout<<"l";delay(50);cout<<"y";delay(50);cout<<" ";delay(50);
	cout<<"c";delay(50);cout<<"o";delay(50);cout<<"i";delay(50);
	cout<<"n";delay(50);cout<<"c";delay(50);cout<<"i";delay(50);
	cout<<"d";delay(50);cout<<"e";delay(50);cout<<"n";delay(50);
	cout<<"t";delay(50);cout<<"a";delay(50);cout<<"l";delay(50);
	cout<<".";
	delay(2500);
	cout<<"  ";
	_setcursortype(_NOCURSOR);
	for (int ia=1;ia<=34;ia++)
	{
		delay(25);
		cout<<"\b\b\b  ";
	}
	clrscr();
	cout<<"\n\n"
	<<"A game by Amogh & Dwijith."
	<<"\n\n"
	<<"This is a work of fiction. Any similarities to any real person, alive or decea ";
	for (ia=1;ia<=80;ia++)
	{
		cout<<"\b\b\b  ";
		delay(25);
	}
	clrscr();
	cout<<"\n\nA game by Amogh & Dwijith  ";
	for (ia=1;ia<=34;ia++)
	{
		delay(25);
		cout<<"\b\b\b  ";
	}
	cout<<"\b\b";
	_setcursortype(_NORMALCURSOR);
	delay(1500);
	clrscr();
	menu2();
}

void menu2()
{
	int x,y;
	x=getmaxx()/2; //Set center for X axis
	y=getmaxy()/2; //Set center for Y axis
	int g=DETECT,d,button;
	initgraph(&g, &d,"C:\\TURBOC3\\BGI");
	delay(1500);
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	settextjustify(x,y);
	setcolor(8); //Color changed to grey for the lines
	outtextxy(x-70,y-78,"----");
	outtextxy(x-70,y-80,"----");
	outtextxy(x-70,y-42,"----");
	outtextxy(x-70,y-40,"----");
	setcolor(6); //Color changed to orange for the text
	outtextxy(x-70,y-60,"SAVE");

	delay(400);
	setcolor(8); //Color again to grey for the second batch of lines
	outtextxy(x-10,y-17,"  --");
	outtextxy(x-10,y-15,"  --");
	outtextxy(x-10,y-55,"  --");
	outtextxy(x-10,y-53,"  --");
	setcolor(6); //Color back to orange
	outtextxy(x-10,y-35,"  ME");
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);

	delay(400);
	setcolor(8);
	outtextxy(x-100,y+40,"A game by Amogh and Dwijith");
	outtextxy(x-105,y+55,"Copyrighted. Made in 2018-'19");

	setcolor(6);  //Allmenu items
	outtextxy(x-260,y+130,"Help");
	outtextxy(x-35,y+150,"Start Game");
	outtextxy(x+230,y+170,"Exit");
	outtextxy(x-260,y+170,"Load");
	outtextxy(x+205,y+130,"Change Log");

	setcolor(8);
	outtextxy(x-225,y-220,"\"Your choices brought you here, lets hope they get you out!\"");
	outtextxy(x-45,y-205,"Version 1.22");

	setcolor(8);  //Box around menu
	line(x-310,y+120,x+310,y+120); //Top Lengths
	line(x-307,y+123,x+312,y+123);
	line(x-310,y+120,x-310,y+200); //Left Heights
	line(x-307,y+123,x-307,y+203);
	line(x+310,y+120,x+310,y+200); //Right Heights
	line(x+312,y+123,x+312,y+203);
	line(x-310,y+200,x+310,y+200); //Bottom Lengths
	line(x-307,y+203,x+312,y+203);

	char ch;
	int xm, ym ;
	while( 1 )
	{       showmouseptr();

		getmousepos(&button,&xm,&ym);
		if( kbhit() )
		{
		     ch = getch();
		     if( ch == 27 )
			exit(0);
	     }
		rectangle(519,367,608,388); //change log
		rectangle(542,407,580,428); //exit
		rectangle(50,367,95,388);  //help
		rectangle(50,407,95,428);  //load
		rectangle(273,388,367,407); //Start game
		if(button & 1==1 )
		{
			if( xm>=542 && xm<=580 && ym>=407 && ym<=428 )
			{
				exit(0); //EXIT!!
			}
			if( xm>=50 && xm<=95 && ym>=367 && ym<=388 )
			{
				rules(); //Rulez!!
			}
			if( xm>=50 && xm<=95 && ym>=407 && ym<=428 )
			{
				//load(); //load!@!!
				computer_shell();
			}
			if( xm>=519 && xm<=608 && ym>=367 && ym<=388 )
			{
				change(); //change looog!!
			}
			if( xm>=273 && xm<=367 && ym>=388 && ym<=407 )
			{
				NewGame = 1;
				rules(); //start!!
			}
		}//button click
	}
	getch();
	closegraph();
 }

void computer_clrscr()
{
	textcolor(15);
	for (int i = 5 ; i<=24 ; i++)
	{
		gotoxy(11,i);
		for (int j = 1 ; j<=59 ; j++)
		{
			cprintf(" ");
		}
	}
}

void computer_shell()
{
	clrscr();
	cout<<"\n\n"
	<<"      *";
	for (int i = 1; i<=65 ; i++) //Top Bar
	{
		cout<<slp;
	}
	cout<<"*"<<"\n";
	cout<<"      "<<li<<"   ";
	for (i = 1; i<=59 ; i++) //Top Bezel
	{
		cout<<slp;
	}
	cout<<"   "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"  "<<li<<"                                                           "<<li<<"  "<<li<<"\n";
	cout<<"      "<<li<<"   ";
	for (i = 1; i<=59 ; i++) //Lower Bezel
	{
		cout<<slp;
	}
	cout<<"   "<<li<<"\n";
	cout<<"      *";
	for (i = 1; i<=65 ; i++) //Lower Bar
	{
		cout<<slp;
	}
	cout<<"*"<<"\n"
	<<"    /    __   __   __   __   __   __   __   __   __   __   __   __   __   \\"<<"\n"
	<<"  /   __|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_|__|_   \\"<<"\n"
	<<"/    |__| |__| |__| |__| |__| |__| |__| |__| |__| |__| |__| |__| |__| |__|    \\";
	computer_main();
}

void computer_main() //+4 on Y from Home PC (Resolution)
{
	computer_clrscr();
	_setcursortype(_NOCURSOR);
	gotoxy(13,6);
	textcolor(2);
	cprintf("OS Booted.");
	gotoxy(13,7);
	textcolor(15);
	cprintf("Checking for CSTMBTPKG.DLL: ");
	textcolor(14);
	cprintf("FOUND!");
	gotoxy(13,8);
	textcolor(15);
	cprintf("Copyright "); 
	textcolor(14);
	cprintf("AD Studios(c)");
	textcolor(15);
	cprintf(" . CSTMBTPKG now with ");
	textcolor(2);
	cprintf("C");
	textcolor(14);
	cprintf("O");
	textcolor(4);
	cprintf("L");
	textcolor(1);
	cprintf("O");
	textcolor(13);
	cprintf("R");
	textcolor(6);
	cprintf("S");
	textcolor(15);
	cprintf("!");
	gotoxy(13,11);
	textcolor(4);
	cprintf("COMMANDS         DESCRIPTION");
	gotoxy(13,12);
	textcolor(14);
	cprintf("MAIL");
	textcolor(15);
	cprintf("             Opens mail portal");
	gotoxy(13,13);
	textcolor(14);
	cprintf("NOTES");
	textcolor(15);
	cprintf("            Opens NOTES.EXE");
	gotoxy(13,14);
	textcolor(14);
	cprintf("GAMEDIR");
	textcolor(15);
	cprintf("          Opens C:\\GAMEDIR\\");
	gotoxy(13,15);
	textcolor(14);
	cprintf("SHUTDOWN");
	textcolor(15);
	cprintf("         Shuts Down PC");
	gotoxy(13,18);
	cprintf("USER:\\>");
	_setcursortype(_NORMALCURSOR);
	computer_main_input();
}

void computer_main_input() 
{
	gotoxy(20,18);
	textcolor(15);
	cin>>s;
	if ( strcmpi("MAIL",s) == 0 )
	{
		computer_mail_introtransition();
	}
	else
	{
		if ( strcmpi("NOTES",s) == 0 )
		{
			computer_notes();
		}
		else
		{
			if ( strcmpi("GAMEDIR",s) == 0 )
			{
				computer_gamedir();
			}
			else
			{
				if ( strcmpi("SHUTDOWN",s) == 0 )
				{
					computer_shutdown();
				}
				else
				{
					gotoxy(13,19);
					_setcursortype(_NOCURSOR);
					textcolor(4);
					cprintf("ERROR: INVALID COMMAND!");
					getch();
					computer_main();
				}
			}
		}
	}
	getch();
	textcolor(15);
}

void computer_mail_introtransition()
{
	computer_clrscr();
	textcolor(15);
	_setcursortype(_NOCURSOR);
	gotoxy(26,12);
	cprintf("Accessing");
	textcolor(14);
	cprintf(" Mail Portal");
	delay(1000);
	textcolor(15);
	cprintf(".");
	delay(100);
	cprintf(".");
	delay(1000);
	cprintf(".");
	delay(1000);
	_setcursortype(_NORMALCURSOR);
	textcolor(15);
	computer_mail();
}

void computer_mail_exittransition()
{
	computer_clrscr();
	textcolor(15);
	_setcursortype(_NOCURSOR);
	gotoxy(26,12);
	cprintf(" Closing");
	textcolor(14);
	cprintf(" Mail Portal");
	delay(1000);
	textcolor(15);
	cprintf(".");
	delay(100);
	cprintf(".");
	delay(1000);
	cprintf(".");
	delay(1000);
	_setcursortype(_NORMALCURSOR);
	textcolor(15);
	computer_main();
}

void computer_mail()
{
	computer_clrscr();
	textcolor(2);
	_setcursortype(_NOCURSOR);
	gotoxy(13,24);
	textcolor(2);
	cprintf("        Type \"EXIT\" to exit the portal");
	gotoxy(13,6);
	textcolor(14);
	cprintf("MAIL");
	gotoxy(13,7);
	textcolor(15);
	cprintf("1. Inbox");
	gotoxy(13,8);
	cprintf("2. Compose E-mail");
	gotoxy(13,11);
	textcolor(11);
	cprintf("You: ");
	_setcursortype(_NORMALCURSOR);
	textcolor(15);
	cin>>s;
	if ( (strcmpi("1",s) == 0) || (strcmpi("INBOX",s) == 0) )
	{
		computer_mail_inbox();
	}
	else
	{
		if ( (strcmpi("2",s) == 0) || (strcmpi("COMPOSE",s) == 0) )
		{
			computer_mail_compose();
		}
		else
		{
			if ( strcmpi("EXIT",s) == 0 )
			{
				computer_mail_exittransition();
			}
			else
			{
				gotoxy(13,11);
				textcolor(4);
				cprintf("ERROR: INVALID OPTION!");
				getch();
				textcolor(15);
				computer_mail();
			}
		}
	}
}

void computer_mail_inbox()
{
	computer_clrscr();
	textcolor(2);
	_setcursortype(_NOCURSOR);
	gotoxy(13,24);
	cprintf("        Type \"EXIT\" to go back");
	gotoxy(13,6);
	textcolor(14);
	cprintf("INBOX");
	gotoxy(13,7);
	textcolor(15);
	cprintf("1. tlryl                    Eviction Notice");
	gotoxy(13,8);
	cprintf("2. janice12                 Home");
	gotoxy(13,9);
	if ( Player.Mail.Engaged == 0  )
	{
		cprintf("3. adbill                   Get Free Coupons!");
	}
	else
	{
		cprintf("3. adbill                   Woah dude.");
	}
	gotoxy(13,12);
	cprintf("You: ");
	_setcursortype(_NORMALCURSOR);
	textcolor(15);
	cin>>s;
	_setcursortype(_NOCURSOR);
	if ( strcmpi("1",s) == 0 ) //Eviction Mail
	{
		computer_clrscr();
		gotoxy(13,6);
		textcolor(4);
		cprintf("(Two Weeks Ago)");
		gotoxy(13,8);
		textcolor(14);
		cprintf("FROM: ");
		textcolor(15);
		cprintf("tlryl@hotmail.com");
		gotoxy(13,9);
		textcolor(14);
		cprintf("TO:   ");
		textcolor(15);
		cprintf("terrydaniels@gmail.com");
		gotoxy(13,10);
		textcolor(14);
		cprintf("SUB:  ");
		textcolor(15);
		cprintf("Eviction Notice");
		gotoxy(12,12);
		textcolor(2);
		cprintf(" --------------------------------------------------------");
		gotoxy(13,14);
		textcolor(15);
		cprintf("Terry Daniels,");
		gotoxy(13,15);
		cprintf("This is an official notice of eviction. We request you");
		gotoxy(13,16);
		cprintf("to vacate the premises on the East Valley Park within");
		gotoxy(13,17);
		cprintf("the next week.");
		gotoxy(13,19);
		cprintf("Regards,");
		gotoxy(13,20);
		cprintf("The TLRYL Team.");
		getch();
		computer_mail_inbox();
	}
	else
	{
		if ( strcmpi("2",s) == 0 ) //Wife Mail
		{
			computer_clrscr();
			gotoxy(13,6);
			textcolor(4);
			cprintf("(Three Days Ago)");
			gotoxy(13,8);
			textcolor(14);
			cprintf("FROM: ");
			textcolor(15);
			cprintf("janice12@gmailmail.com");
			gotoxy(13,9);
			textcolor(14);
			cprintf("TO:   ");
			textcolor(15);
			cprintf("terrydaniels@gmail.com");
			gotoxy(13,10);
			textcolor(14);
			cprintf("SUB:  ");
			textcolor(15);
			cprintf("Home");
			gotoxy(12,12);
			textcolor(2);
			cprintf(" --------------------------------------------------------");
			gotoxy(13,14);
			textcolor(15);
			cprintf("Terry,");
			gotoxy(13,15);
			cprintf("You must know Terry that if not for the kids I'd have");
			gotoxy(13,16);
			cprintf("left you a long time ago; you make things SO HARD... but");
			gotoxy(13,17);
			cprintf("you must come back home Terry; the kids miss you & you");
			gotoxy(13,18);
			cprintf("NEVER call. Would it kill you to give a damned call??");
			gotoxy(13,20);
			cprintf("Janice");
			getch();
			computer_mail_inbox();
		}
		else
		{
			if ( strcmpi("3",s) == 0 ) //Coupon Mail
			{
				computer_clrscr();
				if (Player.Mail.Engaged == 0)
				{
					gotoxy(13,6);
					textcolor(4);
					cprintf("(Twelve Minutes Ago)");
					gotoxy(13,8);
					textcolor(14);
					cprintf("FROM: ");
					textcolor(15);
					cprintf("adbil@adbilco.org");
					gotoxy(13,9);
					textcolor(14);
					cprintf("TO:   ");
					textcolor(15);
					cprintf("terrydaniels@gmail.com");
					gotoxy(13,10);
					textcolor(14);
					cprintf("SUB:  ");
					textcolor(15);
					cprintf("Get Free Coupons!");
					gotoxy(12,12);
					textcolor(2);
					cprintf(" --------------------------------------------------------");
					gotoxy(13,14);
					textcolor(15);
					cprintf("Lucky Customer,");
					gotoxy(13,15);
					cprintf("You have been awarded free gift coupons! To redeem,");
					gotoxy(13,16);
					cprintf("simply reply to ");
					textcolor(11);
					cprintf("*this* ");
					textcolor(15);
					cprintf("e-mail address.");
					gotoxy(13,18);
					cprintf("Regards,");
					gotoxy(13,19);
					cprintf("AdBils - Best Offers, everywhere!");
				}
				else
				{
					gotoxy(13,6);
					textcolor(4);
					cprintf("(Just Now)");
					gotoxy(13,8);	
					textcolor(14);
					cprintf("FROM: ");
					textcolor(15);
					cprintf("adbil@adbilco.org");
					gotoxy(13,9);
					textcolor(14);
					cprintf("TO:   ");
					textcolor(15);
					cprintf("terrydaniels@gmail.com");
					gotoxy(13,10);
					textcolor(14);
					cprintf("SUB:  ");
					textcolor(15);
					cprintf("Woah dude");
					gotoxy(12,12);
					textcolor(2);
					cprintf(" --------------------------------------------------------");
					gotoxy(13,14);
					textcolor(15);
					cprintf("Woah okay, I didnt actually expect a response. I just");
					gotoxy(13,15);
					cprintf("spam these emails dude, I never ACTUALLY get a response.");
					gotoxy(13,16);
					cprintf("Idk what to do; my supervisor isnt here at the moment.");
					gotoxy(13,17);
					cprintf("I'll get back to you once he arrives.");
					gotoxy(13,19);
					cprintf("Jeff");
				}
				getch();
				computer_mail_inbox();
			}
			else
			{
				if ( strcmpi("EXIT",s) == 0 )
				{
					computer_mail();
				}
				else
				{
					gotoxy(13,13);
					textcolor(4);
					cprintf("ERROR: INVALID OPTION!");
					getch();
					computer_mail_inbox();
				}
			}
		}
	}
}

void computer_mail_compose()
{
	computer_clrscr();
	gotoxy(13,6);
	textcolor(14);
	cprintf("TO: ");
	gotoxy(13,7);
	cprintf("SUB: ");
	gotoxy(12,9);
	textcolor(4);
	cprintf(" ---------------------------------------------------------");
	gotoxy(17,6);
	textcolor(15);
	cin>>s;
	if ( strcmpi("adbil@adbilco.org",s) == 0  )
	{
		Player.Mail.Engaged = 1;
	}
	gotoxy(18,7);
	textcolor(15);
	cin>>s;
	gotoxy(13,11);
	textcolor(15);
	cin>>s;
	computer_clrscr(); //To mimick PC
	_setcursortype(_NOCURSOR);
	gotoxy(13,24);
	textcolor(2);
	cprintf("        Type \"EXIT\" to exit the portal");
	gotoxy(13,6);
	textcolor(14);
	cprintf("MAIL");
	gotoxy(13,7);
	textcolor(15);
	cprintf("1. Inbox");
	gotoxy(13,8);
	cprintf("2. Compose E-mail");
	gotoxy(13,11);
	textcolor(11);
	cprintf("You: ");
	gotoxy(26,11); //Message Box
	for (int i = 1 ; i<=26 ; i++)
	{
		cout<<slp;
	}
	gotoxy(25,12);
	cout<<li<<"                          "<<li;
	gotoxy(25,13);
	cout<<li<<"                          "<<li;
	gotoxy(25,14);
	cout<<li<<"        ";
	textcolor(2);
	cprintf("Mail Sent!        ");
	cout<<li;
	gotoxy(25,15); 
	cout<<li<<"                          "<<li;
	gotoxy(25,16);
	cout<<li<<"                          "<<li;
	gotoxy(26,17);
	for (i = 1 ; i<=26 ; i++)
	{
		cout<<slp;
	}
	getch();
	_setcursortype(_NORMALCURSOR);
	computer_mail();
}

void computer_notes()
{
	char ch;
	int index = 1;
	_setcursortype(_NOCURSOR);
	computer_clrscr();
	gotoxy(26,12);
	textcolor(14);
	cprintf("            NOTES");
	delay(1000);
	computer_clrscr();
	gotoxy(13,6);
	textcolor(14);
	cprintf("NOTES");
	gotoxy(13,7);
	textcolor(11);
	cprintf("(Note "); 
	cout<<index;
	textcolor(11);
	cprintf(" out of ");
	textcolor(11);
	cprintf("4)");
	gotoxy(13,24);
	textcolor(2);
	cprintf("        Press 'Esc' to close the application.");
	gotoxy(13,9);
	textcolor(15);
	cprintf("This is so stupid; life. What is this? Why? Why?");
	do
	{
		ch = getch();
		if ( (ch == 'a') || (ch == 'A') || (ch == 's') || (ch == 'S') )
		{
			index--;
			if ( index == 0 )
			{
				index = 4;
			}
		}
		else
		{
			if ( (ch == 'd') || (ch == 'D') || (ch == 'w') || (ch == 'W') )
			{
				index++;
				if ( index == 5 )
				{
					index = 1;
				}
			}	
		}
		computer_clrscr();
		gotoxy(13,6);
		textcolor(14);
		cprintf("NOTES");
		gotoxy(13,7);
		textcolor(11);
		cprintf("(Note "); 
		cout<<index;
		textcolor(11);
		cprintf(" out of ");
		textcolor(15);
		cprintf("4)");
		gotoxy(13,24);
		cprintf("        Press 'Esc' to close the application.");
		gotoxy(13,9);
		textcolor(15);
		switch (index)
		{
			case 1:
				cout<<"This is so stupid; life. What is this? Why? Why?";
				break;
			
			case 2:
				cout<<"I killed a dog today. Funny, I liked it.";
				break;

			case 3:
				cout<<"There are good days, there are bad days; then there\n            is today.";
				break;

			case 4:
				cout<<"Like a mannequin, I sit here among many.\n            All lifeless, a boring itenirary.\n            Hahaha. Stupid human society;\n            A sorority of stupiditty for posterity.";
				break;
			}
	} while (ch != 27);
	computer_main();
}

void computer_gamedir()
{
	computer_clrscr();
	gotoxy(13,6);
	cprintf("<FOLDER IS EMPTY>");
	getch();
	computer_main();
}

void computer_shutdown()
{
	computer_clrscr();
	_setcursortype(_NOCURSOR);
	gotoxy(26,12);
	textcolor(4);
	cprintf("     Shutting Down");
	delay(1000);
	textcolor(15);
	cprintf(".");
	delay(100);
	cprintf(".");
	delay(1000);
	cprintf(".");
	delay(1000);
	computer_clrscr();
	delay(500);
	_setcursortype(_NORMALCURSOR);
}

void phone()
{
	if ( Player.Inventory.Phone.Power == 1 )
	{
		cleardevice();
		cout<<"\n\n";
		cout<<"\t\t\t   *";
		for (int i = 1 ; i<=24 ; i++) //Top Bar
		{
			cout<<slp;
		}
		cout<<"*"<<"\n";
		cout<<"\t\t\t   "<<li<<"            o           "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"  ";
		for (i = 1 ; i<=24 ; i++) //Top Bezel
		{
			cout<<slp;
		}
		cout<<"  "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"Phone Battery:";
		if (Player.Inventory.Phone.Battery<10)
		{
			cout<<"0"
			<<Player.Inventory.Phone.Battery;
		}
		else
		{
			cout<<Player.Inventory.Phone.Battery;
		}
		cout<<"%   | |"<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"Phone Signal :"<<Player.Inventory.Phone.Signal<<"     | |"<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"Ringer       :";
		if (Player.Inventory.Phone.Ringer==0)
		{
			cout<<"OFF";
		}
		else
		{
			cout<<"ON ";
		}
		cout<<"   "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"  ";
		for (i = 1 ; i<=24 ; i++) //Bottom Bezel
		{
			cout<<slp;
		}
		cout<<"  "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"                        "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"           ()           "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"                        "<<li<<"\n";
		cout<<"\t\t\t   *";
		for (i = 1 ; i<=24 ; i++) //Bottom Bar
		{
			cout<<slp;
		}
		cout<<"*";
	}
	else
	{
		cleardevice();
		cout<<"\n\n";
		cout<<"\t\t\t   *";
		for (int i = 1 ; i<=24 ; i++) //Top Bar
		{
			cout<<slp;
		}
		cout<<"*"<<"\n";
		cout<<"\t\t\t   "<<li<<"            o           "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"  ";
		for (i = 1 ; i<=20 ; i++) //Top Bezel
		{
			cout<<slp;
		}
		cout<<"  "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"    ____________    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"   |            |   "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"   |            ||  "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"   |            ||  "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"   |____________|   "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<" "<<li<<"                    "<<li<<" "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"  ";
		for (i = 1 ; i<=24 ; i++) //Bottom Bezel
		{
			cout<<slp;
		}
		cout<<"  "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"                        "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"           ()           "<<li<<"\n";
		cout<<"\t\t\t   "<<li<<"                        "<<li<<"\n";
		cout<<"\t\t\t   *";
		for (i = 1 ; i<=24 ; i++) //Bottom Bar
		{
			cout<<slp;
		}
		cout<<"*";
	}
	getch();
	goback();
}

void goback()
{
	for(int i=0 ; i<=30 ; i++)
	{
		cout<<"\n";
	}
	delay(500);
	cout<<"\n"
	<<"<<PRESS ANY KEY TO GO BACK>>";
	getch();
	cleardevice();
	switch (Player.location) //Back to where he was
	{
		case 's':
		case 'S':
			storeroom();
			break;

		case 'c':
		case 'C':
			closet();
			break;

		case 'h':
		case 'H':
			hall();
			break;

		case 'k':
		case 'K':
			kitchen();
			break;

		case 'v':
		case 'V':
			vents();
			break;

		case 'w':
		case 'W':
			vents2();
			break;

		case 'u':
		case 'U':
			vents3();
			break;

		case 'x':
		case 'X':
			vents4();
			break;

		case 'z':
		case 'Z':
			vents5();
			break;

		case 'r':
		case 'R':
			comproom();
			break;

		case 'b':
		case 'B':
			library1();
			break;

		case 'y':
		case 'Y':
			library2();
			break;

		case 't':
		case 'T':
			toilet();
			break;

		case 'm':
		case 'M':
			bedroom();
			break;

		case 'f':
		case 'F':
			pt3_1();
			break;

		case 'o':
		case 'O':
			balcony();
			break;

		case '1':
			hallway1();
			break;

		case '2':
			hallway2();
			break;

		case '3':
			stairs();
			break;

		case '4':
			hallway4();
			break;

		case '5':
			hallway5();
			break;

		case '6':
			hallway6();
			break;
	}
}

void battery()
{
	if ( Player.Inventory.Phone.Power == 1 )
	{
		BattCount++;
		if ( BattCount >= 4 )
		{
			Player.Inventory.Phone.Battery -= 2;
		}

		if ( Player.Inventory.Phone.Battery <= 0 )
		{
			Player.Inventory.Phone.Power = 0;
		}
	}

}

void rules()
{
	cleardevice();
	cout<<"\n\n"
	<<"RULES: \n"
	<<"------"
	<<"\n\n"
	<<"1. This is a text based game created just as a side project. So dont expect any fancy graphics... or any graphics at all. "
	<<smile
	<<"\n\n"
	<<"2. As this game runs in the CMD, more often than not, words begin to get broken up. The fact that different monitors and operating systems all having different resolutions for the CMD does not help my cause. So as of right now, all one can do is bear with the breaks. Sorry for the inconvineance."
	<<"\n\n"
	<<"3. Limited by my lack of technical know-how, this game will only have prebuilt options available. Though I do hope to add actual user input some time in the future"
	<<"\n\n"
	<<"4. There will be some area where the game pauses and you have to press a charechter to proceed. Keep that in mind."
	<<"\n\n"
	<<"5. Type \"QUIT\" anytime you wish to quit the game."
	<<"\n\n"
	<<"6. Need I mention that my spelling is horrible?"
	<<"\n\n"
	<<"<<PRESS ANY KEY TO CONTINUE>>";
	getch();
	if( NewGame == 1 )
	{
		pt1();
	}
	else
	{
		menu2();
	}
}

void pt1()
{
	NewGame == 0;
	Player.gamemode = 't';
	Player.Inventory.Phone.Signal = 0;
	Player.Inventory.Phone.Battery = rand()%100; //99% max battery
	Player.Inventory.Phone.Power = 1;
	Player.Inventory.Phone.Ringer = rand()%2; //0=Silent ; 1=Not silent
	cleardevice();
	cout<<"\n\n\n\n";
	cout<<"*You are in a dark room. You dont know where you are, nor do you remember how you got there. You see nothing more than the pitch black darkness, and hear nothing more than the echo of silence*";
	getch();
	cout<<"\n\n"
	<<"*Suddenly, a door opens and light floods the room, chasing the once vile darkness out, You can see the silhoute of a man in the light*";
	getch();
	cout<<"\n\n\n"
	<<"Hello";
	getch();
	cout<<"\n\n"
	<<"How are you today?";
	getch();
	cout<<"\n\n\n"
	<<"*There is a momment of awkward silence. The once welcoming light now seems to be harsh and cruel, as there begins the rise of a palpable tension in the air";
	getch();
	cout<<"\n\n\n"
	<<"Anyway, whats your name?"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to choose to tell him your name."
	<<"\n\n"
	<<"Type anything else to choose to remain silent."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		nameinput();
	}
	else
	{
		cout<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n"
		<<"Ouch. Guess you dont trust me";
		getch();
		pt2();
	}
}

void nameinput()
{
	cout<<"\n\n"
	<<"-------------------------------------------------------"
	<<"\n\n\n"
	<<"So what is your name?"
	<<"\n\n"
	<<"You : ";
	cin>>Player.name;
	cout<<"\n\n"
	<<"So I take it your name is "
	<<Player.name;
	getch();
	pt2();
}

void pt2()
{
	cout<<"\n\n"
	<<"Anyways, I hope you are in no pain, I suppose?"
	<<"\n\n"
	<<"*You are stupified by the question. You scream out \"No Pain?\", but it comes of more of a whisper."
	<<"\n\n";
	getch();
	cout<<"Oh. It really does appear you ARE in pain. What do you want me to do?"
	<<"\n\n";
	getch();
	cout<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to demand the release of your bonds."
	<<"\n\n"
	<<"Type anything else to remain silent."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		cout<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Now now, the boss needs you exactly where you are. Lets say he has OCD and wants things perfectly balanced, as all things should be.";
		getch();
	}
	else
	{
		cout<<"\n\n"
		<<"-----------------------------------------------------";
		getch();
	}
	pt3();
}

void pt3()
{
	cout<<"\n\n "
	<<"Now, now. Sit there tight little one. Today...";
	getch();
	cout<<"\n\n\n"
	<<"*You stare blankly at the silhoute as he begins chuckeling.*";
	getch();
	cout<<"\n\n\n"
	<<"...Today the boss is gonna be in for a treat!";
	getch();
	cout<<"\n\n\n";
	cout<<"*The silhoute closes the door, flooding the room back with darkness. You sit there poundering. Where are you? Why were you taken?*";
	getch();
	cout<<"\n\n"
	<<"*You begin feeling the ropes that bind you.*";
	getch();
	cout<<"\n\n"
	<<"*And";
	delay(500);
	cout<<".";
	delay(500);
	cout<<".";
	delay(500);
	cout<<".";
	delay(500);
	cout<<" luck favours you! The bonds loosen*";
	getch();
	cout<<"\n\n"
	<<"*You feel around your pocket, until you find your phone.*";
	getch();
	cout<<"\n\n"
	<<"<<PRESS ANY KEY TO PULL OUT YOUR PHONE>>";
	getch();
	Player.location = 'f';
	phone();
	cout<<"<<YOU CAN PULL OUT YOUR PHONE BY TYPING \"PHONE\">>";
	getch();
	cout<<"\n\n"
	<<"*You see that your phone has no signal; maybe moving would help with the signal.*";
	getch();
	pt3_1();

}

void pt3_1()
{
	cout<<"<<YOU CAN PULL OUT YOUR PHONE BY TYPING \"PHONE\">>";
	getch();
	cout<<"*You see that your phone has no signal; maybe moving would help with the signal.*";
	getch();
	pt3_2();
}

void pt3_2()
{
	battery();
	cout<<"\n\n"
	<<"*You look around, and closely examine your surroundings. As your eyes adjust, you begin to see a small vent above you *";
	getch();
	cout<<"\n\n"
	<<"*You could try the door, but the vent seems abandoned. On the other hand, you dont know where the vent leads...*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go and try the door."
	<<"\n\n"
	<<"Type anything else to try the vents."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		if (rand()%2 == 1)
		{
			hallway2();
		}
		else
		{
			Player.soundlvl++;
			pt3_3();
		}
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			vents();
		}
	}
}

void pt3_3()
{
	battery();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n"
	<<"*You try, but you flich with the creak in the handle. You hope nobody heard you.*";
	getch();
	if (rand()%4 == 1)
	{
		Player.soundlvl++;
	}
	cout<<"\n\n"
	<<"*You could try the door again, but the vent seems abandoned. On the other hand, you dont know where the vent leads...*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go and try the door."
	<<"\n\n"
	<<"Type anything else to try the vents."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		if ( (rand()%3 == 1) || (rand()%3 == 2) )
		{
			cout<<"*The door squeaks slightly, but it creaks open, and you find yourself in the hall!*";
			getch();
			transition();
			hallway2();
		}
		else
		{
			Player.soundlvl++;
			cout<<"\n\n"
			<<"*You get frustrated, and turn towards the vents.*";
			getch();
			transition();
			vents();
		}
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			if ( strcmpi("PHONE",s) == 0 )
			{
				phone();
			}
			else
			{
				transition();
				vents();
			}
		}
	}
}

void frontdoor()
{
	cleardevice();
	if ( Player.Lock.FrontDoor == 1 )
	{
		cout<<"*The door is locked!*";
		getch();
		transition();
		hallway1();
	}
	else
	{
		cout<<"*You walk free*";
		woods();
	}
}

void frontwindow()
{
	cleardevice();
	if ( Player.Lock.FrontWindow == 1 )
	{
		cout<<"*The window is locked!*";
		getch();
		transition();
		hallway6();
	}
	else
	{
		cout<<"*The window opens!*";
		woods();
	}
}

void hallway1()
{
	battery();
	Player.location = '1';
	save();
	cleardevice();
	cout<<"\n\n"
	<<"*On your left, is a door to what appears to be the closet. On your right, the entrance to the hall. Ahead of you, lies the front door."
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"LEFT\" to go towards the closet."
	<<"\n\n"
	<<"Type \"RIGHT\" to head towards the hall."
	<<"\n\n"
	<<"Type \"FRONT\" to head towards the front door."
	<<"\n\n"
	<<"Type \"BACK\" to bo back into the hallway."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("LEFT",s) == 0 )
	{
		transition();
		closet();
	}
	else
	{
		if ( strcmpi("RIGHT",s) == 0 )
		{
			transition();
			hall();
		}
		else
		{
			if ( strcmpi("FRONT",s) == 0 )
			{
				transition();
				frontdoor();
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					hallway2();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							hallway1();
						}
					}
				}
			}

		}
	}
}

void hallway2()
{
	battery();
	Player.location = '2';
	save();
	cleardevice();
	cout<<"*You look around you. You see that theres a doorway that seems to be leading into the kitchen. On the far end of your left, you see what appears to be an ornate front door. Towards your right, you see a flight of stairs.*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"LEFT\" to go towards the front door."
	<<"\n\n"
	<<"Type \"RIGHT\" to head towards the stairs."
	<<"\n\n"
	<<"Type \"FRONT\" to head towards the kitchen."
	<<"\n\n"
	<<"Type \"BACK\" to bo back into the store room."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("LEFT",s) == 0 )
	{
		transition();
		hallway1();
	}
	else
	{
		if ( strcmpi("RIGHT",s) == 0 )
		{
			transition();
			stairs();
		}
		else
		{
			if ( strcmpi("FRONT",s) == 0 )
			{
				transition();
				kitchen();
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					storeroom();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							hallway2();
						}
					}
				}
			}
		}
	}
}

void stairs()
{
	battery();
	Player.location = '3';
	save();
	cleardevice();
	cout<<"*You the floorboards creak under you as you climb up the stairs. You could always turn back...*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"FRONT\" to keep climbing up."
	<<"\n\n"
	<<"Type \"BACK\" to bo back down the stairs."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("FRONT",s) == 0 )
	{
		transition();
		hallway4();
	}
	else
	{
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			hallway2();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					stairs();
				}
			}
		}
	}
}

void hallway4()
{
	battery();
	Player.location = '4';
	save();
	cleardevice();
	cout<<"*On your right, you see nothing but an empty wall with pictures. On your left, you see a door.*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"LEFT\" to try the door."
	<<"\n\n"
	<<"Type \"FRONT\" to head furthur on the hallway."
	<<"\n\n"
	<<"Type \"BACK\" down the stairs."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("LEFT",s) == 0 )
	{
		if ( Player.Lock.CompRoom == 1 )
		{
			cout<<"\n\n"
			<<"*You twist the lock, but it doesnt budge*";
			getch();
			if ( rand()%10 == 1 )
			{
				Player.soundlvl++;
			}
			transition();
			hallway4();
		}
		else
		{
			transition();
			comproom();
		}
	}
	else
	{
		if ( strcmpi("FRONT",s) == 0 )
		{
			transition();
			hallway5();
		}
		else
		{
			if ( strcmpi("BACK",s) == 0 )
			{
				transition();
				stairs();
			}
			else
			{
				if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
				{
					quit();
				}
				else
				{
					if ( strcmpi("PHONE",s) == 0 )
					{
						phone();
					}
					else
					{
						transition();
						hallway4();
					}
				}
			}
		}
	}
}

void hallway5()
{
	battery();
	Player.location = '5';
	save();
	cleardevice();
	cout<<"*On your right, there appears to be another closed door. On your left, there seems to be the entrance to a library of sorts*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"RIGHT\" to go towards the closed door."
	<<"\n\n"
	<<"Type \"LEFT\" to enter the library."
	<<"\n\n"
	<<"Type \"FRONT\" to go furthur down the hallway."
	<<"\n\n"
	<<"Type \"BACK\" to bo back the hallway you came."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("RIGHT",s) == 0 )
	{
		if ( Player.Lock.Bedroom == 1 )
		{
			cout<<"\n\n"
			<<"*You twist the lock, but it doesnt budge*";
			getch();
			if ( rand()%10 == 1 )
			{
				Player.soundlvl++;
			}
			transition();
			hallway5();
		}
		else
		{
			transition();
			bedroom();
		}
	}
	else
	{
		if ( strcmpi("LEFT",s) == 0 )
		{
			transition();
			library1();
		}
		else
		{
			if ( strcmpi("FRONT",s) == 0 )
			{
				transition();
				hallway6();
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					hallway4();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							hallway5();
						}
					}
				}
			}
		}
	}
}

void hallway6()
{
	battery();
	Player.location = '6';
	save();
	cleardevice();
	cout<<"*On your right, you see another door; the whirring of an exhaust fan inside. On your left, you see that the library is long, with another entrance. Ahead of you, you see a window*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"RIGHT\" to go towards the door."
	<<"\n\n"
	<<"Type \"LEFT\" to enter the library."
	<<"\n\n"
	<<"Type \"FRONT\" to try your luck with the window."
	<<"\n\n"
	<<"Type \"BACK\" to bo back the hallway you came."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("RIGHT",s) == 0 )
	{
		transition();
		toilet();

	}
	else
	{
		if ( strcmpi("LEFT",s) == 0 )
		{
			transition();
			library2();
		}
		else
		{
			if ( strcmpi("FRONT",s) == 0 )
			{
				transition();
				frontwindow();
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					hallway5();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							hallway6();
						}
					}
				}
			}
		}
	}
}

void kitchen()
{
	battery();
	Player.location = 'k';
	save();
	cleardevice();
	if ( Player.Inventory.Axe == 0 )
	{
		cout<<"*You are in the kitchen, and see an axe*"
		<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"BACK\" to go back to the hallway."
		<<"\n\n"
		<<"Type \"FRONT \" to go get the axe."
		<<"\n\n"
		<<"Type anything else to stay in the same location"
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			hallway2();
		}
		else
		{
			if ( strcmpi("FRONT",s) == 0 )
			{
				cout<<"\n\n"
				<<"*You pick up the axe*";
				Player.Inventory.Axe = 1;
				getch();
				transition();
				kitchen();
			}
			else
			{
				if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
				{
					quit();
				}
				else
				{
					if ( strcmpi("PHONE",s) == 0 )
					{
						phone();
					}
					else
					{
						transition();
						kitchen();
					}
				}	
			}
		}
	}
	else
	{
		cout<<"*You see that you are in the kitchen.*"
		<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"BACK\" to go back to the hallway."
		<<"\n\n"
		<<"Type anything else to stay in the same location"
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if ( strcmpi("BACK",s) == 0 )
		{
				transition();
				hallway2();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					kitchen();
				}
			}
		}
	}
}

void hall()
{
	battery();
	Player.location = 'h';
	save();
	cleardevice();
	if ( Player.Keys.Frontoor == 0 )
	{
		cout<<"*You see that you are in the hall.*";
		getch();
		cout<<"*You see something shimmer beneath the sofa*";
		getch();
		cout<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"FRONT\" to check the sofa."
		<<"\n\n"
		<<"Type \"BACK\" to go back to the hallway."
		<<"\n\n"
		<<"Type anything else to stay in the same location"
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if ( strcmpi("BACK",s) == 0 )
		{
				transition();
				hallway1();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					if ( strcmpi("FRONT",s) == 0 )
					{
						cout<<"\n\n"
						<<"*You look underneath and find a key!*";
						Player.Keys.Frontoor = 1;
						getch();
					}
					transition();
					hall();
				}
			}
		}
	}
	else
	{
		cout<<"*You see that you are in the hall.*"
		<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"BACK\" to go back to the hallway."
		<<"\n\n"
		<<"Type anything else to stay in the same location"
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if ( strcmpi("BACK",s) == 0 )
		{
				transition();
				hallway1();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					hall();
				}
			}
		}
	}
}

void closet()
{
	battery();
	Player.location = 'c';
	save();
	cleardevice();
	cout<<"*You see that you are in the closet; its quiet clamy, but you could hide.*"
	<<"\n\n";
	getch();
	if (Player.Inventory.MeshCutter == 0)
	{
		cout<<"*You see something shining, you pick it up and see that its meshcutter.*";
		getch();
		cout<<"\n\n"
		<<"*You pick up the mesh cutter*";
		getch();
		Player.Inventory.MeshCutter = 1;
		cout<<"\n\n";
	}
	cout<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"BACK\" to bo back to the hallway."
	<<"\n\n"
	<<"Type anything else to stay in the same location"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("BACK",s) == 0 )
	{
			transition();
			hallway1();
	}
	else
	{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					closet();
				}
			}
	}
}

void storeroom()
{
	battery();
	Player.location = 's';
	save();
	cleardevice();
	cout<<"*You see that you are back in the store room*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"FRONT\" to go ahead and try the door."
	<<"\n\n"
	<<"Type \"BACK\" to turn back to the vents."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("FRONT",s) == 0 )
	{
		transition();
		pt3_3();
	}
	else
	{
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			vents();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					storeroom();
				}
			}
		}
	}

}

void vents()
{
	battery();
	Player.location = 'v';
	save();
	cleardevice();
	cout<<"*You see that the vents are near the ceiling. The only way you can get there is by trying to climb those old boxes*";
	getch();
	cout<<"\n\n"
	<<"*You try climbing and...";
	getch();
	if (rand()%4 == 0)
	{
		cout<<"\n\n"
		<<"*You climb the vents*";
	}
	else
	{
		if (rand()%4 == 1)
		{
			Player.soundlvl++;
			cout<<"\n\n"
			<<"*You climb the vents, but a solitary box falls to the ground*";
		}
		else
		{
			if (rand()%4 == 2)
			{
				Player.soundlvl += 2;
				cout<<"\n\n"
				<<"*You climb the vents, but a few boxes fall to the ground*";
			}
			else
			{
				Player.soundlvl += 3;
				cout<<"\n\n"
				<<"*You climb the vents, but all the boxes fall to the ground*";
			}
		}
	}
	getch();
	transition();
	vents2();
}

void vents2()
{
	battery();
	Player.location = 'w';
	save();
	cleardevice();
	cout<<"\n\n"
	<<"*You scramble ahead, as you feel the stale air blow past you*";
	getch();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go ahead"
	<<"\n\n"
	<<"Type anything else to turn back."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		transition();
		vents3();
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			if ( strcmpi("PHONE",s) == 0 )
			{
				phone();
			}
			else
			{
				transition();
				storeroom();
			}
		}
	}
}

void vents3()
{
	battery();
	Player.location = 'u';
	save();
	cleardevice();
	if ( Player.Lock.Vents == 1 )
	{
		cout<<"\n\n"
		<<"*You see ahead that there is a mesh. How, do you cross?*";
		getch();
		cout<<"\n\n"
		<<"*You check your pockets for something that you can use, ";
		if (Player.Inventory.MeshCutter == 0)
		{
			cout<<"but you find nothing.*"
			<<"\n\n"
			<<"-----------------------------------------------------"
			<<"\n\n\n"
			<<"Type \"FRONT\" to go ahead and try to break open the mesh anyways."
			<<"\n\n"
			<<"Type \"BACK\" to turn back."
			<<"\n\n"
			<<"Type anything else to stay in the same location."
			<<"\n\n"
			<<"You : ";
			cin>>s;
			if ( strcmpi("FRONT",s) == 0 )
			{
				Player.soundlvl+=10;
				if ( rand()%101 == 1)
				{
					cout<<"\n\n"
					<<"*The mesh comes free!*";
					Player.Lock.Vents = 0;
					getch();
					transition();
					vents3();
				}
				else
				{
					cout<<"\n\n"
					<<"*The mesh doesn't budge*";
					getch();
					transition();
					vents3();
				}
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					vents2();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							vents3();
						}
					}
				}
			}
		}
		else
		{
			cout<<" and you pull out the meshcutter!*"
			<<"\n\n"
			<<"-----------------------------------------------------"
			<<"\n\n\n"
			<<"Type \"FRONT\" to go ahead and break open the mesh."
			<<"\n\n"
			<<"Type \"BACK\" to turn back."
			<<"\n\n"
			<<"Type anything else to stay in the same location."
			<<"\n\n"
			<<"You : ";
			cin>>s;
			if ( strcmpi("FRONT",s) == 0 )
			{
				cout<<"\n\n"
				<<"*The mesh comes free!*";
				Player.Lock.Vents = 0;
				getch();
				transition();
				vents3();
			}
			else
			{
				if ( strcmpi("BACK",s) == 0 )
				{
					transition();
					vents2();
				}
				else
				{
					if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
					{
						quit();
					}
					else
					{
						if ( strcmpi("PHONE",s) == 0 )
						{
							phone();
						}
						else
						{
							transition();
							vents3();
						}
					}
				}
			}
		}
	}
	else
	{
		cout<<"*You see that theres nothing ahead, exept the barbed rememanants of the mesh*"
		<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"FRONT\" to go ahead."
		<<"\n\n"
		<<"Type \"BACK\" to turn back."
		<<"\n\n"
		<<"Type anything else to stay in the same location."
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if ( strcmpi("FRONT",s) == 0 )
		{
			transition();
			vents4();
		}
		else
		{
			if ( strcmpi("BACK",s) == 0 )
			{
				transition();
				vents2();
			}
			else
			{
				if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
				{
					quit();
				}
				else
				{
					if ( strcmpi("PHONE",s) == 0 )
					{
						phone();
					}
					else
					{
						transition();
						vents3();
					}
				}
			}
		}
	}
}

void vents4()
{
	battery();
	Player.location = 'x';
	save();
	cleardevice();
	cout<<"\n\n"
	<<"*You scramble ahead, as you feel the stale air blow past you*";
	getch();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go ahead"
	<<"\n\n"
	<<"Type anything else to turn back."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		transition();
		vents5();
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			if ( strcmpi("PHONE",s) == 0 )
			{
				phone();
			}
			else
			{
				transition();
				vents3();
			}
		}
	}
}

void vents5()
{
	battery();
	Player.location = 'z';
	save();
	cleardevice();
	cout<<"*Ahead of you, you finally see slits of light; an exit to the mesh!*";
	getch();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go ahead"
	<<"\n\n"
	<<"Type anything else to turn back."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("1",s) == 0 )
	{
		transition();
		comproom();
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			if ( strcmpi("PHONE",s) == 0 )
			{
				phone();
			}
			else
			{
				transition();
				vents4();
			}
		}
	}
}

void comproom()
{
	battery();
	Player.location = 'r';
	save();
	cleardevice();
	cout<<"*You find yourself standing in a small room of sorts. It is bare, with nothing of worth to note exept a vent shaft and a computer by the wall*"
	<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"LEFT\" to go and access the computer."
	<<"\n\n"
	<<"Type \"BACK\" to turn and go back to the hallway."
	<<"\n\n"
	<<"Type \"FRONT\" to go to the vents."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("FRONT",s) == 0 )
	{
		transition();
		vents5();
	}
	else
	{
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			hallway4();
		}	
		else
		{
			if ( strcmpi("LEFT",s) == 0 )	
			{
				transition();
				computer_shell();
			}
			else
			{
				if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
				{
					quit();
				}
				else
				{
					if ( strcmpi("PHONE",s) == 0 )
					{
						phone();
					}
					else
					{
						transition();
						comproom();
					}	
				}
			}
		}
	}
}

void library1()
{
	battery();
	Player.location = 'b';
	save();
	cleardevice();
	cout<<"*You find yourself at the end of the library.*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"LEFT\" to go to the other end of the library."
	<<"\n\n"
	<<"Type \"RIGHT\" to go over to the table."
	<<"\n\n"
	<<"Type \"FRONT\" to go over and examine the bookcase."
	<<"\n\n"
	<<"Type \"BACK\" to turn and go back to the hallway."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("LEFT",s) == 0 )
	{
		transition();
		library2();
	}
	else
	{
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			hallway5();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					if ( strcmpi("RIGHT",s) == 0 )
					{
						if ( Player.Keys.Comproom == 0 )
						{
							cout<<"\n\n"
							<<"*You search the table's, and voila: you find a key!*";
							Player.Keys.Comproom == 1;
							getch();
						}
						else
						{
							cout<<"\n\n"
							<<"*You search the table's, but you seemed to have found everything there is to be found*";	
							getch();
						}
					}
					else
					{
						if ( strcmpi("FRONT",s) == 0 )	
						{
							if ( Player.Keys.Bedroom == 0 )
							{
								cout<<"\n\n"
								<<"*You examine the book case; old books, and an out of place vase. You instinctivly look inside the vase; voila, a key!*";
								Player.Keys.Bedroom == 1;
								getch();
							}
							else
							{
								cout<<"\n\n"
								<<"*You examine the book case; old books, and an empty out of place vase."
								getch();
							}
						}
					}
					transition();
					library1();
				}
			}
		}
	}
}

void library2()
{
	battery();
	Player.location = 'y';
	save();
	cleardevice();
	cout<<"*You find yourself at the other end of the library*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"RIGHT\" to go to the other end of the library."
	<<"\n\n"
	<<"Type \"BACK\" to turn and go back to the hallway."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("RIGHT",s) == 0 )
	{
		transition();
		library1();
	}
	else
	{
		if ( strcmpi("BACK",s) == 0 )
		{
			transition();
			hallway6();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					library2();
				}
			}
		}
	}
}

void toilet()
{
	battery();
	Player.location = 't';
	save();
	cleardevice();
	cout<<"*You find yourself in the toilet*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"BACK\" to go back into the hallway."
	<<"\n\n"
	<<"Type \"RIGHT\" to check the cabinet."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("BACK",s) == 0 )
	{
		transition();
		hallway6();
	}
	else
	{
		if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
		{
			quit();
		}
		else
		{
			if ( strcmpi("PHONE",s) == 0 )
			{
				phone();
			}
			else
			{
				if ( strcmpi("RIGHT",s) == 0 )
				{
					if ( Player.Inventory.Rope == 0 )
					{
						cout<<"\n\n"
						<<"*You examine the cabinet; bunch of meds... and find a rope!*"
						Player.Inventory.Rope == 1;
						getch();
						transition();
						toilet();
					}
					else
					{
						cout<<"\n\n"
						<<"*You examine the cabinet; bunch of meds*"
						getch();
						transition();
						toilet();
					}
				}
				else
				{
					transition();
					toilet();	
				}
			}
		}
	}
}

void bedroom()
{
	battery();
	Player.location = 'm';
	save();
	cleardevice();
	cout<<"*You see a bed; and a door*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"BACK\" to go back into the hallway."
	<<"\n\n"
	<<"Type \"RIGHT\" to check the door."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("BACK",s) == 0 )
	{
		transition();
		hallway5();
	}
	else
	{
		if ( strcmpi("RIGHT",s) == 0 )	
		{
			transition();
			balcony();
		}
		else
		{
			if ( (strcmpi("QUIT",s) == 0) || (strcmpi("EXIT",s) == 0) )
			{
				quit();
			}
			else
			{
				if ( strcmpi("PHONE",s) == 0 )
				{
					phone();
				}
				else
				{
					transition();
					bedroom();	
				}
			}
		}
	}
}

void balcony()
{
	battery();
	Player.location = 'o';
	save();
	cleardevice();
	cout<<"*You find yourself in the balcony. The ground seems to be 20-30 feet away, but freedom is so close...*"
	<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"BACK\" to go back into the bedroom."
	<<"\n\n"
	<<"Type \"FRONT\" to try and get off the balcony."
	<<"\n\n"
	<<"Type anything else to stay in the same location."
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if ( strcmpi("BACK",s) == 0 )
	{
		transition();
		bedroom();
	}
	else
	{
		if ( strcmpi("FRONT",s) == 0 )
		{
			if ( Player.Inventory.Rope == 1 )
			{
				cout<<"\n\n"
				<<"*You tie the rope to one end of the balcony's railings and gingerly climb down*";
				getch();
				transition();
				woods();
			}
			else
			{
				cout<<"\n\n"
				<<"*You jump off the balcony";
				delay(500);
				cout<<".";
				delay(500);
				cout<<".";
				delay(500);
				cout<<".";
				if ( rand()%2 == 1 )
				{
					cout<<" and you survive the landing!";
					Player.UpdateHealth(20);
					getch();
					transition();
					woods();
				}	
				else
				{
					cout<<" and you break your bones.";
					Player.UpdateHealth(0);
					getch();
					cout<<"\n\n";
					textcolor(4);
					cprintf("GAME OVER");
					getch();	
					endgame();
				}
			}
		} 	
	}
}

void woods()
{
	if ( Player.Mail.OpenedEvic == 1 )
	{
		cout<<"*You wander about, in a slight daze, but because of the email you have a slight sense of direction.*";
		getch();
		cout<<"\n\n"
		<<"*After what seems like hours, you reach the highway, and heave a sigh of relief; maybe the worst really was behind you.*"
		<<"\n\n";
		textcolor(2);
	}
	else
	{
		cout<<"*You wander about, in a slight daze.*";
		getch();
		if ( rand()%2 == 1 )
		{
			cout<<"\n\n"
			<<"*After what seems like hours, you reach the highway, and heave a sigh of relief; maybe the worst really was behind you.*"
			<<"\n\n";
			textcolor(2);
		}
		else
		{
			cout<<"\n\n"
			<<"* You roam for hours and hours, until your feet cant carry you anymore. You slip and fall onto the ground, cursing fate seconds before you black out*"	
			textcolor(4);
			Player.UpdateHealth(0);
		}
	}
		cprintf("GAME OVER");
		getch();
		endgame();
}

void endgame()
{
	_setcursortype(_NOCURSOR);
	cleardevice();
	cout<<"NAME: "
	<<Player.name
	<<"\n"
	<<"HEALTH: "
	<<Player.ReturnHealth()
	<<"\n"
	<<"SOUND LEVEL: "
	<<Player.soundlvl
	<<"\n"
	<<"SURVIVED? :";
	if ( Player.won == 1 )
	{
		textcolor(2);
		cprintf("YES");
	}
	else
	{
		textcolor(4);
		cprintf("NO");
	}
	cout<<"\n\n\n\n"
	<<"                  <<PRESS ANY KEY>>";
	getch();
	cleardevice();
	cout<<"A Game By Amogh & Dwijith. Thank You For Your Time.";
	for ( int i = 0 ; i<15 ; i++ ) 
	{
		delay(250);
		cout<<"\n";
	}
	getch();
	cout<<"A Game By Amogh & Dwijith. Thank You For Your Time.";
	for ( i = 0 ; i<15 ; i++ )
	{
		delay(250);
		cout<<"\n";
	}
	reset();
	menu2();
}

void change()
{
	cleardevice();
	readchangelog();
	cout<<"\n"
	<<"<<PRESS ANY KEY TO GO BACK>>";
	getch();
	cleardevice();
	menu2();
}

void main()
{
	clrscr();
	randomize();
	menu();
	getch();
}