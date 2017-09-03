#include "Board.h"
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<iostream>
#include"utilwin32.h"
#include<windows.h>
#include<queue>
using namespace std;

Board::Board()  ///初始化資料
{
    time=500;
    Machine.set_mode(1);  ///磚塊抽取器設定為1:只會產出正常方塊
    SB.set_dif(1);         ///記分板存取難度
    SB.set_mode(1);     ///記分板存取模式
    combo=0;
    condition=0;
    vector<int>temp ;
    for(int i=0;i<23;i++)
    {
        for(int j=0;j<12;j++)
        {
            temp.push_back(0);
        }
        check.push_back(temp) ;
    }
    for(int i=0;i<12;i++)
    {
        check[0][i]=-1;
        check[21][i]=-1;
        check[22][i]=-1;
    }
    for(int i=0;i<23;i++)
    {
        check[i][0]=-1;
        check[i][11]=-1;
    }
    status=0;
    T=Machine.pick();
    TT=Machine.pick();
    save_status=0;
    ds_status=0;
}

Board::Board(int difficulty)
{

    switch(difficulty)     ///根據難度指派每次掉落的時間
    {
    case 1:
        time=400;   break;
    case 2 :
        time=250;   break;
    case 3:
        time=100;   break;
    default:
        time=400;   break;
    }
    Machine.set_mode(1);    ///磚塊抽取器設定模式1:正常磚塊 2:加上特殊道具 3:有特殊道具&障礙物產出
    SB.set_dif(difficulty);///記分板讀取難度
    SB.set_mode(1);///記分板讀取mode
    combo=0;
    condition=0;
    vector<int>temp ;
    for(int i=0;i<23;i++)
    {
        for(int j=0;j<12;j++)
        {
            temp.push_back(0);
        }
        check.push_back(temp) ;
    }
    for(int i=0;i<12;i++)
    {
        check[0][i]=-1;
        check[21][i]=-1;
        check[22][i]=-1;
    }
    for(int i=0;i<23;i++)
    {
        check[i][0]=-1;
        check[i][11]=-1;
    }
    status=0;
    T=Machine.pick();
    TT=Machine.pick();
    save_status=0;
    ds_status=0;
}
Board::Board(int difficulty , int mode)
{
    start=clock();

    Machine.set_mode(mode); ///磚塊抽取器設定模式1:正常磚塊 2:加上特殊道具 3:有特殊道具&障礙物產出
    SB.set_dif(difficulty); ///記分板讀取難度
    SB.set_mode(mode);  ///記分板讀取mode
    switch(difficulty)      ///根據難度指派每次掉落的時間
    {
    case 1:
        time=400;   break;
    case 2 :
        time=250;   break;
    case 3:
        time=100;   break;
    default:
        time=400;   break;
    }

    combo=0;
    condition=0;
    vector<int>temp ;
    for(int i=0;i<23;i++)
    {
        for(int j=0;j<12;j++)
        {
            temp.push_back(0);
        }
        check.push_back(temp) ;
    }
    for(int i=0;i<12;i++)
    {
        check[0][i]=-1;
        check[21][i]=-1;
        check[22][i]=-1;
    }
    for(int i=0;i<23;i++)
    {
        check[i][0]=-1;
        check[i][11]=-1;
    }
    status=0;
    T=Machine.pick();
    TT=Machine.pick();
    save_status=0;
    ds_status=0;
}
bool Board::check_condition()
{
    bool t=condition;
    return t;
}

int Board::Get_score() ///回傳總分
{
    return SB.Get();
}

 bool Board::check_inside(Object B) ///檢查此磚塊是否在盤面內 1:正常 0:超出
 {
    Point t=B.get_coordinate();
    vector<Point> arrt=B.get_relative();
    bool st=0;
    for(int i=0;i<int(arrt.size());i++)
    {
        if(check[t.y-arrt[i].y][arrt[i].x+t.x]!=0)
            st=1;
    }
    return !st;
 }

 void Board::Erase_column(int x) ///消除行
 {
     queue<int> wait_erase;
     for(int i=1;i<=20;i++)
     {
         if(check[i][x]==22)
            wait_erase.push(i);     ///如果消去的那行有特殊方塊要另外再做一次消除列
         if(check[i][x]==21)
            combo++;
         check[i][x]=0;
     }
     combo++;
     while(!wait_erase.empty())
     {
         Erase_row(wait_erase.front());
         wait_erase.pop();
         combo++;
     }
     return ;
 }
void Board::Erase_row(int y)    ///消去列
 {
    queue<int> wait_erase;
    for(int j=1;j<=10;j++)
    {
        if(check[y][j]==22)
            wait_erase.push(j);     ///如果消去列的那行有特殊方塊有在做一次次消去行
        if(check[y][j]==21)
            combo++;
    }
    for(int j=y;j>=1;j--)
    {
        if(j!=1)
            for(int k=1;k<=10;k++)
            {
                check[j][k]=check[j-1][k];
            }
        else
            for(int k=1;k<=10;k++)
                check[j][k]=0;
    }
    combo++;
    while(!wait_erase.empty())
    {
        Erase_column(wait_erase.front());
        wait_erase.pop();
        combo++;
    }
     return;
 }
vector< vector<int> > Board::get_board()
{

    if(status==0) ///status:: 0:沒有磚塊 1:有磚塊落下中 2:有磚塊但已靜止並在此判斷是否消去;
    {
        status=1;
        if(!check_inside(T))
            condition=1;
        combo=0;
    }
    else if(status==1)  ///磚塊掉落中的狀態
    {
        Object TOB=T;
        if(kbhit()&&finish-start<=time) ///如果超過一定時間會自動下降一格
        {

            int a=getch();
            if(a==224)
                a=getch();
            Point temp=TOB.get_coordinate();
            vector<Point> arrt=TOB.get_relative();
            for(int i=0;i<int(arrt.size());i++)
                check[temp.y-arrt[i].y][arrt[i].x+temp.x]=0;

            if(a==75||a==77)    ///按左或右 ，使磚塊左移或右移
            {
                if(a==75)
                    T.move('a');
                else
                    T.move('d');        ///先確定移動後是否在盤面內，再覆蓋原始資料
                if(!check_inside(T))
                    T=TOB;
                temp=T.get_coordinate();
                arrt=T.get_relative();
                for(int i=0;i<int(arrt.size());i++)
                    check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
            }
            else if(a==80)  ///按下可使磚塊掉落一格的功能
            {
                while(check_inside(T))
                {
                    Object Ttemp=T;     ///先確定移動後是否在盤面內，再覆蓋原始資料
                    T.move('s');
                    Point temp=Ttemp.get_coordinate();
                    vector<Point> arrt=Ttemp.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=0;
                    if(!check_inside(T))
                    {
                        status=2;
                        temp=Ttemp.get_coordinate();
                        arrt=Ttemp.get_relative();
                        for(int i=0;i<int(arrt.size());i++)
                            check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                        break;
                    }
                    temp=T.get_coordinate();
                    arrt=T.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                }
            }
            else if(a==' ') ///按下空白鍵，直接掉落的功能。
            {
                while(1)
                {
                    Object Ttemp=T;
                    T.move('s');
                    Point temp=Ttemp.get_coordinate();
                    vector<Point> arrt=Ttemp.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=0;
                    if(!check_inside(T))
                    {
                        status=2;
                        temp=Ttemp.get_coordinate();
                        arrt=Ttemp.get_relative();
                        for(int i=0;i<int(arrt.size());i++)
                            check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                        break;
                    }
                    temp=T.get_coordinate();
                    arrt=T.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                }
            }
            else if(a==72||a=='x'||a=='X')  ///旋轉
            {
                Object Ttemp=T;

                vector<Point> arrt=Ttemp.get_relative();        ///先確定移動後是否在盤面內，再覆蓋原始資料
                if(arrt[0].num!=2)
                {
                    T.rotate();
                    if(!check_inside(T))
                        T=TOB;
                    temp=T.get_coordinate();
                    arrt=T.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                }
            }
            /*____________________________________________*////new
            else if(a=='c'||a=='C')
            {
                if(!save_status&&!ds_status)   ///保存方塊
                {
                    save_status=1;      ///如果目前有存取方塊則為1否則為0;
                    vector<Point> ar=T.get_relative();
                   // Point subceter=T.get_coordinate();
                    for(int i=0;i<int(ar.size());i++)
                        check[temp.y-ar[i].y][ar[i].x+temp.x]=0;
                    Object Qjec(ar[0],ar[1],ar[2],ar[3]);
                    status=2;
                    TTT=Qjec;
                }
                else if(save_status&&!ds_status)    ///釋出方塊
                {
                    ds_status=1;    ///保存磚塊的狀態0:靜止 1:掉落中
                    save_status=0;
                    T=TTT;
                    status=1;
                }
            }
            /*_______________________________________________*////new
            else    ///按下非正常按鍵時，暫停60秒
            {
                gotoxy(0,80);
                cout << "Pause. Press normal key to start\n";
                clock_t A ,B;
                A=clock();
                for(int i=0;i<10000;i++)
                {
                    B=clock();
                    Sleep(10);
                    gotoxy(0,90);
                    cout << setw(2) << 60-((B-A)/1000);
                    if(kbhit()||((B-A)/1000>=60))
                        break;
                    gotoxy(0,100);
                }

                gotoxy(0,0);
            }
        }
        else ///超出時間就做下降一格的動作
        {
                Object Ttemp=T;
                T.move('s');
                Point temp=Ttemp.get_coordinate();
                vector<Point> arrt=Ttemp.get_relative();
                for(int i=0;i<int(arrt.size());i++)
                    check[temp.y-arrt[i].y][arrt[i].x+temp.x]=0;
                if(!check_inside(T))
                {
                    status=2;
                    temp=Ttemp.get_coordinate();
                    arrt=Ttemp.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                }
                else
                {
                    temp=T.get_coordinate();
                    arrt=T.get_relative();
                    for(int i=0;i<int(arrt.size());i++)
                        check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
                }
                start=clock();
        }
        finish=clock();
    }
    else if(status==2)  ///有磚塊但已靜止需判斷是否該消去的狀態。
    {
        bingo();
        SB.input(combo);
        combo=0;
        T=TT;
        TT=Machine.pick();
        status=0;
        ds_status=0;
    }

    return check;   ///回傳Board
}
void Board::bingo() ///消去判定
{
    vector< vector<int> > temp=check;
    for(int i=1;i<=20;i++)
    {
        bool ch=1; ///判定是否一列全為數字且非0||21(只有特殊方塊22能消);
        for(int j=1;j<=10;j++)
        {
            if(check[i][j]==0||check[i][j]==21)
                ch=0;
        }
        if(ch)
        {
            Erase_row(i);   ///滿一列即可消去row
        }
    }
}
int Board::GetNextOb()  ///回傳下一組磚塊的編號
{
    vector<Point> tarr=TT.get_relative();
    return tarr[0].num;
}

int Board::get_save()   ///回傳save起來的磚塊編號
{
    vector<Point> tarr=TTT.get_relative();
    if(save_status)
        return tarr[0].num;
    else
        return 0;
}
