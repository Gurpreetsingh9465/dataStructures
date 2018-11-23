#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void TOH(int, char, char, char);
main()
{
    int n;
    char A = 'A', B = 'B', C = 'C';
    printf("no. of blocks\n");
    cin>>n;
    TOH(n, A, B, C);
    getch();
}
void TOH(int n,char BEG, char AUX, char END)
{
    static int x = 1;
    if(n>=1)
    {
        TOH(n-1, BEG, END, AUX);
        printf("%d %c to %c \n",x++ , BEG, END);
        TOH(n-1, AUX, BEG, END);
    }
}
