C.no.\tCountry name\tCaptain\tWin/Loss/Draw\tRuns\tPoints\n";
			for(int j=0; j<n; j++)
			teams[j].output();
			break;
			}
		case 5: exit(0);

	}
	getch();
	}while(1);


}                                                                                                                                                                                                                                                                                                                                       e<<"0";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\HP.txt", ios::out);
	datafile<<"0";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\On.txt", ios::out);
	datafile<<"1";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Battery.txt", ios::out);
	datafile<<"90";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Signal.txt", ios::out);
	datafile<<"3";
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Phone\\Ringer.txt", ios::out);
	datafile<<"0";
	datafile.close();

	datafile.open("H:\\Storage\\SysOne\\Location.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\SoundLvl.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\Meshcutter.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
	datafile.close();
	datafile.open("H:\\Storage\\SysOne\\HP.txt", ios::in);
	datafile>>test;
	cout<<"\n"
	<<test;
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
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 &y);

	if( x>=100 && x<=350 && y>=100 && y<=150 )
	{
	      setcolor( GREEN );
	      settextstyle(4, 0, 6);
	      outtextxy(100, 100, "Merry X'MAS and HAPPY New Year");

	}
	else
	{
	      setcolor( RED );
	      settextstyle(4, 0, 6);
	      outtextxy(100, 100, "Merry X'MAS and HAPPY New Year");

	}
	//Click detection
	if( button == 1 )
	{
	     if( x>=10 && x<=100 && y>=10 && y<=100 )
		exit(0) ;
	}
 }
getch();
closegraph() ;
}








