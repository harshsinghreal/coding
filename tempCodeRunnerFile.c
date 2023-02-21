

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int gd= DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
printf("CARROM BOARD DESIGN\n");
delay(500);
printf("BY SAMRAT SUBEDI");
delay(1000);
setcolor(YELLOW);
rectangle(200,100,450,350);
setcolor(WHITE);
circle(215,115,10);
circle(215,335,10);
circle(435,115,10);
circle(435,335,10);
circle(325,225,30);
//BORDER
setcolor(WHITE);
line(230,150,230,300);
line(240,150,240,300);
line(420,150,420,300);
line(410,150,410,300);
line(260,305,390,305);
line(260,315,390,315);
line(260,145,390,145);
line(260,135,390,135);
//INCLINED LINES
setcolor(GREEN);
line(235,130,260,160);
line(235,320,260,290);
line(415,130,390,160);
line(415,320,390,290);
//INCLINED LINES CIRCLE
circle(260,160,8);
circle(260,290,8);
circle(390,160,8);
circle(390,290,8);
//BORDER CIRCLE
setcolor(WHITE);
circle(235,150,5);
circle(235,300,5);
circle(415,150,5);
circle(415,300,5);
circle(260,140,5);
circle(390,140,5);
circle(260,310,5);
circle(390,310,5);
delay(1000);
//COINS
setcolor(RED);
circle(325,225,5);
delay(1000);
setcolor(WHITE);
circle(325,248,5);
delay(1000);
circle(325,238,5);
delay(1000);
circle(336,219,5);
delay(1000);
circle(314,219,5);
delay(1000);
circle(307,212,5);
delay(1000);
circle(343,212,5);
delay(1000);
setcolor(BLUE);
circle(337,232,5);
delay(1000);
circle(314,231,5);
delay(1000);
circle(312,245,5);
delay(1000);
circle(337,243,5);
delay(1000);
circle(347,225,5);
delay(1000);
circle(302,225,5);
delay(1000);
circle(325,213,5);
delay(1000);
circle(335,205,5);
delay(1000);
circle(315,205,5);
delay(1000);
setcolor(WHITE);
circle(348,236,5);
delay(1000);
circle(305,236,5);
delay(1000);
circle(325,201,5);
delay(1000);
circle(335,295,7);
floodfill(335,295,WHITE);
getch();
closegraph()


