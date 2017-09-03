#include "Board.h"
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<iostream>
#include"utilwin32.h"
#include<windows.h>
#include<queue>
using namespace std;

Board::Board()  ///��l�Ƹ��
{
    time=500;
    Machine.set_mode(1);  ///�j��������]�w��1:�u�|���X���`���
    SB.set_dif(1);         ///�O���O�s������
    SB.set_mode(1);     ///�O���O�s���Ҧ�
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

    switch(difficulty)     ///�ھ����׫����C���������ɶ�
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
    Machine.set_mode(1);    ///�j��������]�w�Ҧ�1:���`�j�� 2:�[�W�S���D�� 3:���S���D��&��ê�����X
    SB.set_dif(difficulty);///�O���OŪ������
    SB.set_mode(1);///�O���OŪ��mode
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

    Machine.set_mode(mode); ///�j��������]�w�Ҧ�1:���`�j�� 2:�[�W�S���D�� 3:���S���D��&��ê�����X
    SB.set_dif(difficulty); ///�O���OŪ������
    SB.set_mode(mode);  ///�O���OŪ��mode
    switch(difficulty)      ///�ھ����׫����C���������ɶ�
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

int Board::Get_score() ///�^���`��
{
    return SB.Get();
}

 bool Board::check_inside(Object B) ///�ˬd���j���O�_�b�L���� 1:���` 0:�W�X
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

 void Board::Erase_column(int x) ///������
 {
     queue<int> wait_erase;
     for(int i=1;i<=20;i++)
     {
         if(check[i][x]==22)
            wait_erase.push(i);     ///�p�G���h�����榳�S������n�t�~�A���@�������C
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
void Board::Erase_row(int y)    ///���h�C
 {
    queue<int> wait_erase;
    for(int j=1;j<=10;j++)
    {
        if(check[y][j]==22)
            wait_erase.push(j);     ///�p�G���h�C�����榳�S��������b���@�������h��
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

    if(status==0) ///status:: 0:�S���j�� 1:���j�����U�� 2:���j�����w�R��æb���P�_�O�_���h;
    {
        status=1;
        if(!check_inside(T))
            condition=1;
        combo=0;
    }
    else if(status==1)  ///�j�������������A
    {
        Object TOB=T;
        if(kbhit()&&finish-start<=time) ///�p�G�W�L�@�w�ɶ��|�۰ʤU���@��
        {

            int a=getch();
            if(a==224)
                a=getch();
            Point temp=TOB.get_coordinate();
            vector<Point> arrt=TOB.get_relative();
            for(int i=0;i<int(arrt.size());i++)
                check[temp.y-arrt[i].y][arrt[i].x+temp.x]=0;

            if(a==75||a==77)    ///�����Υk �A�Ͽj�������Υk��
            {
                if(a==75)
                    T.move('a');
                else
                    T.move('d');        ///���T�w���ʫ�O�_�b�L�����A�A�л\��l���
                if(!check_inside(T))
                    T=TOB;
                temp=T.get_coordinate();
                arrt=T.get_relative();
                for(int i=0;i<int(arrt.size());i++)
                    check[temp.y-arrt[i].y][arrt[i].x+temp.x]=arrt[i].num;
            }
            else if(a==80)  ///���U�i�Ͽj�������@�檺�\��
            {
                while(check_inside(T))
                {
                    Object Ttemp=T;     ///���T�w���ʫ�O�_�b�L�����A�A�л\��l���
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
            else if(a==' ') ///���U�ť���A�����������\��C
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
            else if(a==72||a=='x'||a=='X')  ///����
            {
                Object Ttemp=T;

                vector<Point> arrt=Ttemp.get_relative();        ///���T�w���ʫ�O�_�b�L�����A�A�л\��l���
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
                if(!save_status&&!ds_status)   ///�O�s���
                {
                    save_status=1;      ///�p�G�ثe���s������h��1�_�h��0;
                    vector<Point> ar=T.get_relative();
                   // Point subceter=T.get_coordinate();
                    for(int i=0;i<int(ar.size());i++)
                        check[temp.y-ar[i].y][ar[i].x+temp.x]=0;
                    Object Qjec(ar[0],ar[1],ar[2],ar[3]);
                    status=2;
                    TTT=Qjec;
                }
                else if(save_status&&!ds_status)    ///���X���
                {
                    ds_status=1;    ///�O�s�j�������A0:�R�� 1:������
                    save_status=0;
                    T=TTT;
                    status=1;
                }
            }
            /*_______________________________________________*////new
            else    ///���U�D���`����ɡA�Ȱ�60��
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
        else ///�W�X�ɶ��N���U���@�檺�ʧ@
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
    else if(status==2)  ///���j�����w�R��ݧP�_�O�_�Ӯ��h�����A�C
    {
        bingo();
        SB.input(combo);
        combo=0;
        T=TT;
        TT=Machine.pick();
        status=0;
        ds_status=0;
    }

    return check;   ///�^��Board
}
void Board::bingo() ///���h�P�w
{
    vector< vector<int> > temp=check;
    for(int i=1;i<=20;i++)
    {
        bool ch=1; ///�P�w�O�_�@�C�����Ʀr�B�D0||21(�u���S�����22���);
        for(int j=1;j<=10;j++)
        {
            if(check[i][j]==0||check[i][j]==21)
                ch=0;
        }
        if(ch)
        {
            Erase_row(i);   ///���@�C�Y�i���hrow
        }
    }
}
int Board::GetNextOb()  ///�^�ǤU�@�տj�����s��
{
    vector<Point> tarr=TT.get_relative();
    return tarr[0].num;
}

int Board::get_save()   ///�^��save�_�Ӫ��j���s��
{
    vector<Point> tarr=TTT.get_relative();
    if(save_status)
        return tarr[0].num;
    else
        return 0;
}