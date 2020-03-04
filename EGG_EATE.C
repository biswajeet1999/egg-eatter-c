#include<conio.h>
#include<graphics.h>
#include<dos.h>
int x=300,y=460;
int ex,ey =8;
int count=0;
int lyf = 3;
void basket(int a)
{
 cleardevice();
 setcolor(RED);
 x = x+a;
 pieslice(x,y,180,360,20);
 setcolor(WHITE);
}
void start()
{
 setcolor(RED);
 settextstyle(8,0,3);
 setbkcolor(GREEN);
 outtextxy(100,230,"WELCOME TO EGG EATER ^_^");
 delay(2000);
 setbkcolor(0);
}
void check()
{
 if((ex >= x-20 && ex <= x+20) && ey>=460){
    count++;
    basket(0);
    ex = rand()%630;
    ey = 8;
    sector(ex,ey,0,360,5,10);
 }else if(ey >=460){
   basket(0);
   ex = rand()%630;
   ey = 8;
   sector(ex,ey,0,360,5,10);
 }
}
void scoreboard()
{
 char score[15];
 cleardevice();
 setbkcolor(RED);
 setcolor(GREEN);
 settextstyle(8,0,3);
 sprintf(score,"SCORE: %d",count);
 outtextxy(100,230,score);
}

void main()
{
 char c;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 start();
 cleardevice();
 basket(0);
 ex = rand()%630;

 while(1){
  check();
  sector(ex,ey,0,360,5,10);
  if(!kbhit()){
    basket(0);
    ey+=9;
    check();
    sector(ex,ey,0,360,5,10);
    delay(100);
    check();
  }
  else{
    c = getche();
    check();
    if(c == ','){
     check();
      delay(10);
      if(x == 20){
	basket(0);
	ey+=2;
	sector(ex,ey,0,360,5,10);
	check();
      }else{
	basket(-10);
	ey+=2;
	sector(ex,ey,0,360,5,10);
	check();
     }
    }
    else if(c == '.'){
     check();
      delay(10);
      if(x == 620){
	basket(0);
	ey+=2;
	sector(ex,ey,0,360,5,10);
      }else{
	basket(10);
	ey+=2;
	sector(ex,ey,0,360,5,10);
     }
    }
    else if(c == 13)
     break;
  }
 check();
 }
 scoreboard();
 delay(2000);
 closegraph();
}