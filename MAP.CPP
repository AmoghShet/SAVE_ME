/*ASSIGNMENT NO.: 1
  TOPIC         : CLASSES AND OBJECTS
  DESCRIPTION   : SIMULATING A CRICKET CUP
  D.O.S.        : 20-06-19
*/
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
class cricketcup
{
	int c_no;
	char c_name[20];
	char c_cap[30];
	int win;
	int loss;
	int draw;
	int points;            /*5 points for win, 2 for draw, 0 for loss */
	int total_runs;
  public:
	void input();
	char* get_cname(){return c_name;}
	void output_country_info();
	int get_c_no(){return c_no;}
	char* get_captain(){return c_cap;}
	void update(int status);
	void calculate_points(){points=5*win+2*draw;}
	void output();
	int get_points(){return points;}
	cricketcup(){
	c_no=0;
	strcpy(c_cap,"\0");
	strcpy(c_name,"\0");
	points=0;
	total_runs=0;
	loss=0;
	win=0;
	draw=0;
	}
};

void cricketcup::output()
{
	cout<<c_no<<"\t"<<c_name<<"\t\t"<<c_cap<<"\t"
	    <<win<<"/"<<loss<<"/"<<draw<<"\t\t"
	    <<total_runs<<"\t"<<points<<endl;
}

void cricketcup::output_country_info()
{
	cout<<"\n\nCountry no.:  "<<c_no
	    <<"\nCountry name:  "<<c_name
	    <<"\nCaptain:  "<<c_cap
	    <<"\nWins:  "<<win
	    <<"\nDraws:  "<<draw
	    <<"\nLosses:  "<<loss
	    <<"\nPoints:  "<<points
	    <<"\nRuns:  "<<total_runs;
}

void cricketcup::update(int status)
{
	if(status==1)
	{
		win++;
		points+=5;
	}
	else if(status==0)
	{
		draw++;
		points+=2;
	}
	else
	{
		loss++;
	}
	int runs;
	cout<<"\nHow many runs did the team score\n";
	cin>>runs;
	total_runs+=runs;
}
int count=1;
void cricketcup::input()
{
	clrscr();
	c_no=count++;
	cout<<"For country "<<c_no<<endl<<endl;
	cout<<"Enter country name\n";
	gets(c_name);
	cout<<"Enter captain name\n";
	gets(c_cap);
	cout<<"Enter no. of wins\n";
	cin>>win;
	cout<<"Enter no. of loss\n";
	cin>>loss;
	cout<<"Enter no. of draws\n";
	cin>>draw;
	cout<<"Enter no. of runs scored\n";
	cin>>total_runs;
}


void bubblesort_points(cricketcup teams[],int n)
{
	for(int i=0; i<n; i++)
	{
	  for(int j=0; j<n-1-i; j++)
	  {
	  if(teams[i].get_points()<teams[i+1].get_points())
	  {
		cricketcup temp=teams[i];
		teams[i]=teams[i+1];
		teams[i+1]=temp;
	  }

	  }

	}
}

void main()
{
	int op;
	int n;
	cricketcup teams[20];

	cout<<"\t\t\t\tWORLD CRICKET CUP\n\n\n\n";
	cout<<"How many teams are playing in this cup?\n";
	cin>>n;
	clrscr();
	for(int i=0; i<n; i++){ teams[i].input(); teams[i].calculate_points(); }

	do{
	clrscr();
	cout<<"\n\n\n\t\t\tWORLD CRICKET 