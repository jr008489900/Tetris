#include "interface.h"
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include"utilwin32.h"
using namespace std;


Interface::Interface()
{
    left = 0;
    top = 0;
    right = 12;
    bottom = 22;
    score=0;
    mode=0;
}

void Interface::output_Rank()
{
    ///Output the Rank which get from "Rank Class" and print it one by one.

    vector<Data> arr;
    arr=go_rank.Get_data();

    gotoxy (2,5);
    SetColor(11);
    cout<<"Rank";

    gotoxy (9,5);
    SetColor(11);
    cout<<"N a m e ";

    gotoxy (18,5);
    SetColor(11);
    cout<<"Score";

    SetColor(15);

    for (int i=0 ; i<int(arr.size());i++)
    {
        gotoxy (2,i+7);
        cout<<i+1;

        gotoxy (9,i+7);
        cout<<arr[i].name;

        gotoxy (18,i+7);
        cout<<arr[i].score;

    }
    gotoxy (0,22);
    cout<<"Press [B] to Menu Press [E] to End;";
    gotoxy (0,23);
    cout<<"Press [C] to Clear:";
    repress:
        int trash=getch();

        if (trash==224)
        {
            trash=getch();

        }
        if (trash==98)
        {
            system("cls");
            output_menu();
            return ;
        }
        else if (trash==101)
        {
            return ;
        }
        else if (trash==99)
        {
            system("cls");
            gotoxy(5,8);
            cout<<"Are you sure?";
            gotoxy(5,12);
            cout<<"(Y/N)";
            char tr;
            tr=getch();
            if (tr=='Y'||tr=='y')
            {
                system("cls");
                go_rank.Delete_Data();
                output_menu();
            }
            else
            {
                system("cls");
                output_Rank();
            }

        }
        else
        {
            cout<<"\a";
            goto repress;
        }

}

void Interface::output_menu()
{
    ///output menu and give options to choose
    setWindowsize();  ///set the size of window
    int trash;
    SetColor(10);
    Stop:
    system("cls");
    draw();


    SetColor(15);

    gotoxy(6,6);
    cout<<" T E T R I S ";

    int Color=0; ///for outside options (like: start,rank,and end)
    int diff=0;///for middle options (like: easy , hard , crazy)
    ///int mode=0;///for inside options (like: classic , extra ,nightmare)
    while (1)
    {
        if (trash==13)
        {
            if (Color%3==0)
            {
                Difficult:
                system("cls");
                draw();
                SetColor(15);
                gotoxy(6,6);
                cout<<" Difficulty  ";
                gotoxy (0,22);
                cout<<"Press [B] to Menu :";
                trash=0;
                while (1)
                {
                    if (trash==13)
                    {
                        system("cls");
                        draw();
                        SetColor(15);
                        gotoxy(8,6);
                        cout<<" Mode ";
                        gotoxy (0,22);
                        cout<<"Press [B] to Back :";
                        trash=0;
                        while (1)
                        {
                            if (trash==13)
                            {
                                goto print;
                            }
                            if (trash==98)
                            {
                                goto Difficult;
                            }
                            else if (trash==80)
                            {
                                mode++;
                            }
                            else if (trash==72)
                            {
                                mode--;
                            }
                            while (mode<0)
                            {
                                mode+=3;
                            }
                            if (mode%3==0)
                            {
                                gotoxy(6,11);
                                SetColor(112);
                                cout<<"  Classic  ";
                                SetColor(15);
                                gotoxy(6,13);
                                cout<<"  Extra  ";
                                SetColor(15);
                                gotoxy(6,15);
                                cout<<"  Nightmare  ";
                            }
                            else if (mode%3==1)
                            {
                                gotoxy(6,11);
                                SetColor(15);
                                cout<<"  Classic  ";
                                SetColor(112);
                                gotoxy(6,13);
                                cout<<"  Extra  ";
                                SetColor(15);
                                gotoxy(6,15);
                                cout<<"  Nightmare  ";
                            }
                            else
                            {
                                gotoxy(6,11);
                                SetColor(15);
                                cout<<"  Classic  ";
                                SetColor(15);
                                gotoxy(6,13);
                                cout<<"  Extra  ";
                                SetColor(112);
                                gotoxy(6,15);
                                cout<<"  Nightmare  ";
                                SetColor(15);
                            }
                            gotoxy(0,23);
                            trash=getch();
                            if (trash==224)
                            {
                                trash=getch();

                            }
                        }
                    }
                    if (trash==98)
                    {
                        goto Stop;
                    }
                    else if (trash==80)
                    {
                        diff++;
                    }
                    else if (trash==72)
                    {
                        diff--;
                    }
                    while (diff<0)
                    {
                        diff+=3;
                    }
                    if (diff%3==0)
                    {
                        gotoxy(8,11);
                        SetColor(112);
                        cout<<"  Easy  ";
                        SetColor(15);
                        gotoxy(8,13);
                        cout<<"  Hard  ";
                        SetColor(15);
                        gotoxy(8,15);
                        cout<<"  Crazy  ";
                    }
                    else if (diff%3==1)
                    {
                        gotoxy(8,11);
                        SetColor(15);
                        cout<<"  Easy  ";
                        SetColor(112);
                        gotoxy(8,13);
                        cout<<"  Hard  ";
                        SetColor(15);
                        gotoxy(8,15);
                        cout<<"  Crazy  ";
                    }
                    else
                    {
                        gotoxy(8,11);
                        SetColor(15);
                        cout<<"  Easy  ";
                        SetColor(15);
                        gotoxy(8,13);
                        cout<<"  Hard  ";
                        SetColor(112);
                        gotoxy(8,15);
                        cout<<"  Crazy  ";
                        SetColor(15);
                    }
                    gotoxy(0,23);
                    trash=getch();
                    if (trash==224)
                    {
                        trash=getch();

                    }
                }
            }
            else if (Color%3==1)
            {
                break;
            }
            else
                return ;

        }
        else if (trash==80)
        {
            Color++;
        }
        else if (trash==72)
        {
            Color--;
        }
        while (Color<0)
        {
            Color+=3;
        }
        if (Color%3==0)
        {
            gotoxy(8,11);
            SetColor(112);
            cout<<"  Start  ";
            SetColor(15);
            gotoxy(8,13);
            cout<<"  Rank  ";
            SetColor(15);
            gotoxy(8,15);
            cout<<"  End  ";

        }
        else if (Color%3==1)
        {
            gotoxy(8,11);
            SetColor(15);
            cout<<"  Start  ";
            SetColor(112);
            gotoxy(8,13);
            cout<<"  Rank  ";
            SetColor(15);
            gotoxy(8,15);
            cout<<"  End  ";
        }
        else
        {
            gotoxy(8,11);
            SetColor(15);
            cout<<"  Start  ";
            SetColor(15);
            gotoxy(8,13);
            cout<<"  Rank  ";
            SetColor(112);
            gotoxy(8,15);
            cout<<"  End  ";
        }
        gotoxy(0,23);
        trash=getch();
        if (trash==224)
        {
            trash=getch();

        }
    }
    print:
    if (mode%3==0)
    {
        mode = 1;
    }
    else if (mode%3==1)
    {
        mode = 2;
    }
    else
    {
        mode = 3;
    }
    if (Color%3==1)
    {
        system("cls");
        output_Rank();
        return ;
    }
    else if (diff%3==0)
    {
        system("cls");
        time = 400;
        difficulty = 1;
        start();
    }
    else if (diff%3==1)
    {
        system("cls");
        time = 250;
        difficulty = 2;
        start();
    }
    else
    {
        system("cls");
        time = 100;
        difficulty = 3;
        start();
    }
}


void Interface::start()
{
    ///to start the game , we have to print out the interface and all blocks
    draw();
    small_draw(25,0);
    small_draw(25,11);
    ///
    vector< vector<int> > temp;
    hidecursor();
    Board Game(difficulty,mode);
    int save;
    int next;
    ///
    while(!Game.check_condition())
    {
        temp = Game.get_board();


        for (int i=1;i<=20;i++)
        {
            for (int j=1;j<=10;j++)
            {
                gotoxy(2*j,i);
                if (temp[i][j]==1)
                {
                    SetColor(11);
                    cout<<"¡½";
                }
                else if (temp[i][j]==2)
                {
                    SetColor(12);
                    cout<<"¡½";
                }
                else if (temp[i][j]==3)
                {
                    SetColor(13);
                    cout<<"¡½";
                }
                else if (temp[i][j]==4)
                {
                    SetColor(14);
                    cout<<"¡½";
                }
                else if (temp[i][j]==5)
                {
                    SetColor(10);
                    cout<<"¡½";
                }
                else if (temp[i][j]==6)
                {
                    SetColor(9);
                    cout<<"¡½";
                }
                else if (temp[i][j]==7)
                {
                    SetColor(15);
                    cout<<"¡½";
                }
                else if(temp[i][j]==21)
                {
                    SetColor(141);
                    cout<<"¡»";
                }
                else if(temp[i][j]==22)
                {
                    SetColor(7);
                    cout<<"¡¹";
                }
                else
                {
                    SetColor(8);
                    cout<<"¡¼";
                }
            }
        }
        next = Game.GetNextOb();
        SetColor (169);
        gotoxy (28,1);
        cout<<"NEXT";
        Blocks (next,29,2);
        save = Game.get_save();
        SetColor (26);
        gotoxy (28,12);
        cout<<"SAVE";
        Blocks (save,29,13);
        ///to prevent users from pressing two keys too rapidly , we cut the "sleep time" ,and it can execute smoothly.
        for (int i=0;i<(time/10);i++)
        {
            if (kbhit())
                break;
            delay(8);
        }
        score=Game.Get_score();
        SetColor(15);
        gotoxy(0,30);
        cout << "Score: " << score;
        gotoxy(50,31);

        ///cover
        for (int i=1;i<=40;i++)
        {
            for (int j=2;j<=60;j++)
            {
                gotoxy(j,i);
            }
        }

        for (int i=1;i<6;i++)
        {
            for (int j=1;j<6;j++)
            {
                gotoxy (24+2*j,1+i);
                cout<<"  ";
                gotoxy (24+2*j,12+i);
                cout<<"  ";

            }
        }
    }

    system("cls");

    back_Menu();
}

void Interface::back_Menu()

    ///output the backmenu when game over.
{

    draw();

    gotoxy(6,6);
    cout<<" Game Over!";
    int Color=0;
    int trash;
    while (1)
    {
        if (trash==13)
        {

            if (Color%3==0)
            {
                system("cls");
                reenter:
                gotoxy(6,6);


                cout<<"Enter your name:";

                gotoxy(6,7);
                cout<<"(at most 8 letters)";

                for (int i=0;i<5;i++)
                {
                    gotoxy(6+i*2,12);
                    SetColor(255);
                    cout<<"  ";
                }
                gotoxy(6,12);
                SetColor(240);
                string name_str;
                cin>>name_str;
                SetColor(15);
                if (name_str.length()>8)
                {
                    system("cls");
                    SetColor (76);
                    gotoxy(0,4);
                    cout<<"Warning:You have to enter less than 9 letters!";
                    SetColor(15);
                    goto reenter;
                }
                go_rank.input(name_str,score);
                cin.sync();

                system("cls");
                output_menu();
                return ;


            }
            else if (Color%3==1)
            {
                system("cls");
                output_menu();
                return;
            }
            else
            {
                return;
            }


        }
        else if (trash==80)
        {
            Color++;
        }
        else if (trash==72)
        {
            Color--;
        }
        while (Color<0)
        {
            Color+=3;
        }
        if (Color%3==0)
        {
            gotoxy(4,11);
            SetColor(112);
            cout<<" Register score ";
            SetColor(15);
            gotoxy(4,13);
            cout<<" Back to menu ";
            SetColor(15);
            gotoxy(4,15);
            cout<<"  End  ";

        }
        else if (Color%3==1)
        {
            gotoxy(4,11);
            SetColor(15);
            cout<<" Register score ";
            SetColor(112);
            gotoxy(4,13);
            cout<<" Back to menu ";
            SetColor(15);
            gotoxy(4,15);
            cout << "  End  ";
        }
        else
        {
            gotoxy(4,11);
            SetColor(15);
            cout<<" Register score ";
            SetColor(15);
            gotoxy(4,13);
            cout<<" Back to menu ";
            SetColor(112);
            gotoxy(4,15);
            cout << "  End  ";
        }
        gotoxy(0,23);
        trash=getch();
        if (trash==224)
        {
            trash=getch();

        }
    }
}
void Interface::draw()
{
    ///draw a frame in queue
    SetColor(10);
    for (int i=top;i<bottom;i++)
    {
        for(int j=left;j<right;j++)
        {
            if (i==0&&j==0)
            {
                cout<<"¢z";
            }
            else if (i==0&&j==11)
            {
                cout<<"¢{"<<endl;
            }
            else if  (i==21&&j==0)
            {
                cout<<"¢|";
            }
            else if (i==21&&j==11)
            {
                cout<<"¢}"<<endl;;
            }
            else if (i==0||i==21)
            {
                cout<<"¢w";
            }
            else if (j==0)
            {
                cout<<"¢x";
            }
            else if (j==11)
            {
                cout<<"¢x"<<endl;
            }
            else
            {
                cout<<"  ";
            }
        }
    }
}

void Interface :: small_draw (int x,int y)
{
    ///draw a small frame in queue
    SetColor(9);
    for (int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            gotoxy (x+j,y+i);
            if (i==0&&j==0)
            {
                cout<<"¢z";
            }
            else if (i==0&&j==6)
            {
                cout<<"¢{"<<endl;
            }
            else if  (i==6&&j==0)
            {
                cout<<"¢|";
            }
            else if (i==6&&j==6)
            {
                cout<<"¢}"<<endl;;
            }
            else if (i==0||i==6)
            {
                cout<<"¢w";
            }
            else if (j==0)
            {
                cout<<"¢x";
            }
            else if (j==6)
            {
                cout<<"¢x"<<endl;
            }
            else
            {
                cout<<"  ";
            }
        }
    }
}

void Interface::Blocks (int n , int x , int y)
{
    ///output the block for every type with switch case
    switch (n)
    {
    case 1:
        SetColor(11);
        for(int i=0 ; i<4;i++)
        {
            gotoxy (x-1,y+i);
            cout<<"¡½";
        }
        break;
    case 2:
        SetColor(12);
        gotoxy (x-1,y);
        cout<<"¡½¡½";
        gotoxy (x-1,y+1);
        cout<<"¡½¡½";
        break;
    case 3:
        SetColor(13);
        gotoxy(x-3 , y);
        cout<<"¡½¡½¡½";
        gotoxy(x-1 , y+1);
        cout<<"¡½";
        break;
    case 4:
        SetColor(14);
        gotoxy(x-1 ,y);
        cout<<"¡½";
        gotoxy(x-1 ,y+1);
        cout<<"¡½¡½";
        gotoxy(x+1,y+2);
        cout<<"¡½";
        break;
    case 5:
        SetColor(10);
        gotoxy(x+1,y);
        cout<<"¡½";
        gotoxy(x-1,y+1);
        cout<<"¡½¡½";
        gotoxy(x-1,y+2);
        cout<<"¡½";
        break;
    case 6:
        SetColor(9);
        gotoxy (x-1,y);
        cout<<"¡½¡½";
        gotoxy (x+1,y+1);
        cout<<"¡½";
        gotoxy(x+1,y+2);
        cout<<"¡½";
        break;
    case 7:
        SetColor(15);
        gotoxy (x-3 , y);
        cout<<"¡½";
        gotoxy (x-3 , y+1);
        cout<<"¡½¡½¡½";
        break;
    default:
        break;
    }
}




