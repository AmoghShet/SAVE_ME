#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <fstream.h>
#include <stdlib.h>
#include "H:/MOUSE.cpp"

fstream datafile;

const char smile = 1;
char s;
char name[30];
int soundlvl = 0;

struct Items
{
	int MeshCuter;
	int HP;
	struct Cellular
	{
		int On;
		float Battery;
		int Signal;
		int Ringer;
	} Phone;
};


Items Inventory;


void menu();
void save();
void load();
void soundcheck();
void change();
void rules();
void pt1();
void nameinput();
void pt2();
void pt3();
void pt3_2();
void hall();
void Story_vents();
void Story_vents2();
void vents2();
void vents3();
/*
void save()
{
	fstream File;
	File.open("H:\\Storage\\Save.dat", ios::app | ios::binary);
	File.write((char*)&One, sizeof(One));
	File.close();
}

void load()
{
	fstream File;
	File.open("H:\\Storage\\Save.dat", ios::app | ios::binary);
	File.read((char*)&One, sizeof(One));
	cout<<One.location
	<<One.soundlvl;
}
  */
void soundcheck()
{
	if(soundlvl>=5)
	{
		cout<<"\n\n"
		<<"Hey!";
	}
}


void menu()
{
	initmouse();
	int x,y,i;
	int g=DETECT,d,button;
	initgraph(&g, &d,"C:\\TC\\BGI");
	cleardevice();
	x=getmaxx()/2; //Set center for X axis
	y=getmaxy()/2; //Set center for Y axis

	int oc=0; //Value for outer circle
	int ic=100; //Value for inner circle

	for(int e=0;e<5;e++)     //The circle going outward
	{
		for(int i=50;i<150;i++)
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
	for(e=0;e<5;e++)     //The circle going inward
	{
		for(int i=50;i<150;i++)
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
	{delay(25);
	cout<<"\b\b\b  ";}
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

	initgraph(&g, &d,"C:\\TC\\BGI");
	delay(3500);
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
	delay(400);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
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
	outtextxy(x-45,y-205,"Version 1.10");

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
	{
	  showmouseptr();
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
	  exit(0);           //EXIT!!
	  if( xm>=50 && xm<=95 && ym>=367 && ym<=388 )
	  rules();          //Rules!!
	  if( xm>=50 && xm<=95 && ym>=407 && ym<=428 )
	  ;               //load!@!!
	  if( xm>=519 && xm<=608 && ym>=367 && ym<=388 )
	  change();	//change looog!!
	  if( xm>=273 && xm<=367 && ym>=388 && ym<=407 )
	  rules();       //start!!

	  }//button click
	}
	getch();
	closegraph();
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
	<<"5. Need I mention that my spelling is horrible?"
	<<"\n\n"
	<<"<<PRESS ANY KEY TO CONTINUE>>";
	getch();
	pt1();
}

void pt1()
{
	cleardevice();
	cout<<"\n\n";
	getch();
	cout<<"\n\n"
	<<"*You are in a dark room. You dont know where you are, nor do you remember how you got there. You see nothing more than the pitch black darkness, and hear nothing more than the echo of silence*";
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
	if (s=='1')
	{
		nameinput();
	}
	else
	{
		strcpy(name ,"Lil one");
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
	<<"----------------------------------------------------------"
	<<"\n\n\n"
	<<"So what is your name?"
	<<"\n\n"
	<<"You : ";
	cin>>name;
	cout<<"\n\n"
	<<"So I take it your name is "
	<<name;
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
	if (s=='1')
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
	cout<<"\n\n"
	<<"<<DO YOU WANT TO CLEAR THE SCREEN?(1/0)>>";
	cin>>s;
	if (s=='1')
	{
		cleardevice();
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
	getch();
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
	cout<<" luck favours you! The bonds loosen*"
	<<"\n\n"
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
	if (s=='1')
	{
		if (rand()%2 == 1)
		{
			hall();
		}
		else
		{
			soundlvl++;
			pt3_2();
		}
	}
	else
	{
		Story_vents();
	}
}

void pt3_2()
{
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n"
	<<"*You try, but you flich with the creak in the handle. You hope nobody heard you.*";
	getch();
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
	if (s=='1')
	{
		if (rand()%2 == 1)
		{
			hall();
		}
		else
		{
			soundlvl++;
			cout<<"\n\n"
			<<"*You get frustrated, and turn towards the vents.*";
			getch();
			Story_vents();
		}
	}
	else
	{
		Story_vents();
	}
}

void hall()
{
	cleardevice();
	cout<<"Youre in the hall";
}

void Story_vents()
{
	cleardevice();
	cout<<"*You see that the vents are near the cieling. The only way you can get there is by trying to climb those old boxes*";
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
			soundlvl++;
			cout<<"\n\n"
			<<"*You climb the vents, but a solitary box falls to the ground*";
		}
		else
		{
			if (rand()%4 == 2)
			{
				soundlvl += 2;
				cout<<"\n\n"
				<<"*You climb the vents, but a few boxes fall to the ground*";
			}
			else
			{
				soundlvl += 3;
				cout<<"\n\n"
				<<"*You climb the vents, but all the boxes fall to the ground*";
			}
		}
	}
	soundcheck();
}

void Story_vents2()
{
	cout<<"\n\n"
	<<"*You scramble ahead, as you feel the stale air blow past the vents*";
	getch();
	cout<<"\n\n"
	<<"*Your palms as sweaty, knees weak, arms are heavy.*";
	getch();
	cout<<"\n\n"
	<<"*You stop, realizing that the vents are made of metal; even the slightest of missteps could potential mean your motives being compramised*";
	getch();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go ahead."
	<<"\n\n"
	<<"Type anything else to stay still and try to clam your nerves"
	<<"\n\n"
	<<"You : ";
	cin>>s;
	if (s=='1')
	{
		if (rand()%4==1)
		{
			soundlvl++;
		}
		if (rand()%4==2)
		{
			soundlvl+=2;
		}
		if (rand()%4==0)
		{
			soundlvl+=3;
		}
	}
	else
	{
		cout<<"\n"
		<<"-----------------------------------------------------"
		<<"\n\n"
		<<"*You take a few heavy breaths, the only sound from your nasals. After what seems like an iternity, your heartbeat slows down, and calm yourself*";
		getch();
	}
	soundcheck();
	vents3();
}

void vents3()
{
	cout<<"\n\n";
	cout<<"*You forge ahead, but find that the vents are blocked by a mesh. ";
	if (Inventory.MeshCuter==0)
	{
		cout<<"But you dont have anything to cut it open.*" ;
		getch();
		cout<<"\n\n"
		<<"-----------------------------------------------------"
		<<"\n\n\n"
		<<"Type \"1\" to go back."
		<<"\n\n"
		<<"Type anything else to try and brute force your way through"
		<<"\n\n"
		<<"You : ";
		cin>>s;
		if (s=='1')
		{
			cout<<"-----------------------------------------------------";
			vents2();
		}
		else
		{
			soundlvl+=10;
			if (rand()%25==1)
			{
					cout<<"\n\n"
					<<"*It breaks open!*";
			}
			else
			{
					cout<<"\n\n"
					<<"*It dosnt budge! You decide to go back*";
					vents2();
			}

		}

	}
	else
	{
		cout<<"\n\nYou cut your way through with the Mesh cutter you have.";
	}

}

void vents2()
{
	cout<<"\n\n"
	<<"*You stop, realizing that the vents are made of metal; even the slightest of missteps could potential mean your motives being compromised*";
	getch();
	cout<<"\n\n"
	<<"-----------------------------------------------------"
	<<"\n\n\n"
	<<"Type \"1\" to go to the basement."
	<<"\n\n"
	<<"Type \"2\" to go ahead the vents."
	<<"\n\n"
	<<"Type anything else to stay still"
	<<"\n\n"
	<<"You : ";
	cin>>s;
}

void change()
{
	cleardevice();
	cout<<"\n\n"
	<<"*04-08-2018: Added Loading screen. "
	<<"\n"
	<<"*05-08-2018: Updated Loading screen."
	<<"\n"
	<<"*20-09-2018: Designed Theme."
	<<"\n"
	<<"*23-10-2018: Reduced Loading screen code (-300 Lines aprox)."
	<<"\n"
	<<"*29-10-2018: Formated Loading screen code (-200 Lines aprox)."
	<<"\n"
	<<"*30-10-2018: Formated overall code."
	<<"\n"
	<<"*10-12-2018: Updated Menu."
	<<"\n"
	<<"*25-02-2019: Rewrote entire code for better modifiability"
	<<"\n"
	<<"*26-02-2019: Added and worked on sound level"
	<<"\n"
	<<"06-03-2019: Began work on rudementry save system"
	<<"\n"
	<<"            Created structure for an inventory. Potential items include a meshcutter, a health pack and a phone.";
	getch();
	cleardevice();
	menu();
}

void main()
{
	clrscr();
	randomize();
	char test[30];

	/*Inventory.MeshCuter=0;
	Inventory.HP=0;
	Inventory.Phone.On=0;
	Inventory.Phone.Battery=(rand()%10)*10; //0 to 90% charge
	Inventory.Phone.Signal=rand()%4; //equalant to the 3 bars of signal
	Inventory.Phone.Ringer=0;
	cout<<"\n\n"
	<<"\t\t\t\tINVENTORY CHECK"
	<<"\n\nMeshCutter = "
	<<Inventory.MeshCuter
	<<"\nHP = "
	<<Inventory.HP
	<<"\nIs phone on? "
	<<Inventory.Phone.On
	<<"\nBattery Percentage = "
	<<Inventory.Phone.Battery
	<<"\nSignal Percentage = "
	<<Inventory.Phone.Signal
	<<"\nIs ringer on? "
	<<Inventory.Phone.Ringer;*/

	datafile.open("H:\\Storage\\SysOne\\Location.txt", ios::out);
	datafile<<"Storage";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\SoundLvl.txt", ios::out);
	datafile>>"0";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Meshcutter.txt", ios::out);
	datafile<<"0";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\HP.txt", ios::out);
	datafile<<"0";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\On.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Battery.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Signal.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Ringer.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();

	getch();
	menu();
	cout<<"\n\n"
	<<"<<PRESS ANY KEY TO EXIT>>";
	getch();
}