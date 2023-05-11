#include <iostream>
// #include <windows.h>
#include<bits/stdc++.h>

using namespace std;
char a[10][10][3];
int extra;
char p1,p2;

void board();
void put(int, int , char );
int checkwin(char );
void multiply(char,int,int );


int main()
{
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int k=0;k<3;k++)
            {
                a[i][j][k]=' ';
            }
        }
    }

    int r,c,counter=0,i=0;

    cout<<"\t\tPLAYER 1\nChoose a character: ";
    cin>>p1;
    cout<<"\n\n\n\t\tPLAYER 2\nChoose a character: ";
    cin>>p2;
    system("cls");

    do
    {
        extra=1;

            //player 1
            cout<<"\t\t\tPLAYER 1 ("<<p1<<")\n\n";
            board();
            while (true)
            {
                cout <<"\n\nChoose a spot x and y: ";
                cin>> r>> c;
                if(a[r][c][0]!=p2)
                    break;
            }
            put(r,c,p1);
            system("cls");
            if(i!=0)
            {
                counter=checkwin(p2);
                if(counter==1)
                    {cout<<"Player 1 Wins!!\n";
                    break;}
            }

            //player 2
            cout<<"\t\t\tPLAYER 2 ("<<p2<<")\n\n";
            board();
            while (true)
            {
                cout <<"\n\nChoose b spot: ";
                cin>> r>> c;
                if(a[r][c][0]!=p1)
                    break;
            }
            put(r,c,p2);
            system("cls");
            if(i!=0)
            {
                counter=checkwin(p1);
                if(counter==1)
                    {cout<<"Player 2 Wins!!\n";
                    break;}
            }

        i++;
    }
    while(counter!=1);
    board();

    return 0;
}

void board()
{
    cout << "       0       1       2       3       4       5       6       7       8       9\n";
    for (int i=0;i<10;i++)
    {
        cout << " " << i << " ";
        for (int j=0;j<10;j++)
        {
            cout<<"||";
            for (int k=0;k<3;k++)
            {
                cout<<a[i][j][k]<<" ";
            }
        }
        cout<<"|| "<< i<<"\n"<<endl;
    }
    cout << "       0       1       2       3       4       5       6       7       8       9";
}

void put(int r, int c, char player)
{
    char opp;
    (player==p1 )? opp=p2 : opp=p1;

    if ((r==0 || r==9) && (c==0 || c==9))
    {
        if(a[r][c][0]==opp)
        {
            a[r][c][0]=player;
        }
        else if(a[r][c][0]==' ')
            a[r][c][0]=player;
        else if (a[r][c][0]==player)
            multiply(player,r,c);
    }
    else if ((r==0 && (c>0 && c<9)) || (r==9 && (c>0 && c<9)) || (c==0 && (r>0 && r<9)) || (c==9 && (r>0 && r<9)))
        {
        if(a[r][c][0]==opp)
        {
            if(a[r][c][1]==opp)
            {
                multiply(player,r,c);
            }
            else if(a[r][c][1]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
                cout << "right\n";
            }
        }
        else if(a[r][c][0]==' ' && a[r][c][1]==' ')
            a[r][c][0]=player;
        else if(a[r][c][0]==player && a[r][c][1]==' ')
            a[r][c][1]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player)
            multiply(player,r,c);
    }
    else
    {
        if(a[r][c][0]==opp)
        {
            if(a[r][c][1]==' ' && a[r][c][2]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
            }
            else if(a[r][c][1]==opp && a[r][c][2]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
                a[r][c][2]=player;
            }
            else if(a[r][c][1]==opp && a[r][c][2]==opp)
            {
                multiply(player,r,c);
            }
        }
        else if(a[r][c][0]==' ' && a[r][c][1]==' ' && a[r][c][2]==' ')
            a[r][c][0]=player;
        else if(a[r][c][0]==player && a[r][c][1]==' ' && a[r][c][2]==' ')
            a[r][c][1]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player && a[r][c][2]==' ')
            a[r][c][2]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player && a[r][c][2]==player)
            multiply(player,r,c);
    }
}

int checkwin(char opp)
{
    int g=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
               if (a[i][j][1]==opp || a[i][j][2]==opp || a[i][j][0]==opp )   //mark is p2 if we want to check win for player 1
                {
                    g++;
                    break;
                }
        }
    }
    if(g==0)
        return 1;
    else
        return 0;
}

void multiply(char player,int row, int col)
{
    extra=0;
    a[row][col][0]=' ';
    a[row][col][1]=' ';
    a[row][col][2]=' ';

    if(row<9)
    {put( row+1, col, player);}
    if(col<9)
    {put(row, col+1,player);}
    if(row>0)
    {put( row-1, col, player);}
    if(col>0)
    {put( row, col-1,player);}

}