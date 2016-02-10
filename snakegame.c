/*Program Developed By oculto*/
/*Pretty basic snake game. Plenty of bugs too. Too much flickering of screen..etc*/
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
//#include<vector> 



#define nl  printf("\n");




const int height=25,width=50;
char map[25][50];
int tail,head;
typedef struct coord{
	int first;
	int second;
	
}coord;

struct coord snake[750];

coord foodpos;
int cd=1;
int find(coord x)
{ int i;
	for(i=0;i<tail;i++)
	 if(x.first==snake[i].first&&x.second==snake[i].second)
	  return 1;
	return 0;  
	
}

int mv()
{  int i;
	coord temp,x;
	x=snake[0];
	for(i=1;i<tail;i++)
	{
	temp=x;
	x=snake[i];
	snake[i]=temp;
    } 
}

void init()
{
	int i,j;
	for(i=0;i<height;i++)
	map[i][0]='|',map[i][width-1]='|';
	for(j=0;j<width;j++)
	map[0][j]='=',map[height-1][j]='=';
	
	for(i=1;i<height-1;i++)
	for(j=1;j<width-1;j++)
	map[i][j]=' ';
	snake[0].first=15;
	snake[0].second=15;
	snake[1].first=16;
	snake[1].second=15;
	cd=1;
	foodpos.first=foodpos.second=0;
	
	
}

void genfood()
{
	
	int x,y;
	x=y=0;
	do{
		x=rand()%(height-2)+1;
		y=rand()%(width-2)+1;
		
		
	}while(x==foodpos.first&&y==foodpos.second);

foodpos.first=x;
foodpos.second=y;

}

void move()
{
char c;
c=getch();
{
	//cout<<c;
	//Sleep(500);
 } 
if(c=='w')
{
	if(cd!=4)
	 cd=1;
//return;	 
}

else if(c=='a')
{
if (cd!=3)
cd=2;
}
else if(c=='s')
{
if(cd!=1)
cd=4;

}
else if(c=='d')
{
if(cd!=2)
cd=3;	
}
}

int refresh()
{    
     coord x,y;
	 x=snake[0];
     y=snake[tail-1];
     
	
	 if(cd==1)
       x.first--;
       if(cd==2)
       {
	   x.second--;
 
		}
	   if(cd==3)
       {
	   x.second++;
  
       
	   }
	   if(cd==4)
       x.first++;
     
     
	 		if(x.first==foodpos.first&&x.second==foodpos.second)
		 	{   mv();
			 	tail++;
			 	snake[0]=x;
				snake[tail-1]=y; 
		 		genfood();
		 		return 1;
		 		
			}
			
			else{
			
     
	   
     if(!find(x))
	 {  mv();
	 	snake[0]=x;
	 	
		 if(x.first==0||x.first==height-1||x.second==0||x.second==width-1)
		 {
		 	return -1;
		 	
		 }
		
	}
		 else
		 return -1;
		 	
}
	
	
}






int print()
{
int i,rv,j;/*
	HWND myconsole = GetConsoleWindow();
HDC mydc = GetDC(myconsole);

for(i = 40; i < 305; ++i)
    SetPixel(mydc, 127, i, RGB(160, 160, 160));
for(i = 40; i < 305; ++i)
    SetPixel(mydc, 515, i, RGB(160, 160, 160));

for(i = 128; i < 514; ++i)
    SetPixel(mydc, i, 35, RGB(160, 160, 160));
	   
for(i = 128; i < 514; ++i)
    SetPixel(mydc, i, 310, RGB(160, 160, 160));
 */ //ios_base::sync_with_stdio(false);
rv=0;
     system("cls");
     
	
	i=20;
	j=20;
	
	nl;
	nl;
	nl;
	
	//cout<<"\n\n\t\t==================================================";
					
	
	
	
	
	coord x;
	for(i=0;i<height;i++)
	{  printf("\t\t");
		for(j=0;j<width;j++)
		{  x.first=i;
		    x.second=j;
		   if(!find(x)) 
		    {  if(i==foodpos.first&&j==foodpos.second)
		        printf("@");
		       
		        else 
				 printf("%c",map[i][j]);		
			  
		
	      }
	      else
	      printf("O");
	  }
		nl;
	}
	
}





int main()
{ 
   tail=head=3;
	int i,rt=-2;
	init();
	genfood();
	
	printf("Enter difficulty level 1:2 (hard:easy)?");
	scanf("%d",&i);

while(1){
	  
	//
while(!kbhit())
{
    
    print();
    if(i==1)
    Sleep(100);
	else
	Sleep(300);	
	if(refresh()==-1)
	{
	 printf("\n\n\n\n\t\t\tYour score %d",tail-3);
	 return 0;
    }
	
}
move();

}
return 0;
}
