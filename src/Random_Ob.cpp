#include<ctime>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Random_Ob.h"
using namespace std;

Random_Ob::Random_Ob()
{
    status=7;
    for(int i=1;i<=7;i++)
        arr.push_back(i);
    mode=1;
}

void Random_Ob::set_mode(int a)
{
    mode=a;
}

Object Random_Ob::pick()
{
    if(status<=0)
    {
        status=7;
        for(int i=1;i<=7;i++)
            arr.push_back(i);
    }
    srand(time(NULL));
    int temp=(rand()%(status--));
    int x=arr[temp];
    arr.erase(arr.begin()+temp);
    Point a,b,c,d ;
    switch(x)
    {
    case 1:
        a.x=0;      a.y=0;      a.num=1;
        b.x=-1;     b.y=0;      b.num=1;
        c.x=1;      c.y=0;      c.num=1;
        d.x=2;      d.y=0;      d.num=1;
        break ;

    case 2:
        a.x=0;      a.y=0;      a.num=2;
        b.x=1;      b.y=0;      b.num=2;
        c.x=0;      c.y=-1;     c.num=2;
        d.x=1;      d.y=-1;     d.num=2;
        break;

    case 3:
        a.x=0;      a.y=0;      a.num=3;
        b.x=-1;     b.y=0;      b.num=3;
        c.x=1;      c.y=0;      c.num=3;
        d.x=0;      d.y=-1;     d.num=3;
        break ;

    case 4:
        a.x=0;      a.y=0;      a.num=4;
        b.x=0;      b.y=1;      b.num=4;
        c.x=1;      c.y=0;      c.num=4;
        d.x=1;      d.y=-1;     d.num=4;
        break;

    case 5:
        a.x=0;      a.y=0;      a.num=5;
        b.x=0;      b.y=1;      b.num=5;
        c.x=-1;     c.y=0;      c.num=5;
        d.x=-1;     d.y=-1;     d.num=5;
        break;

    case 6:
        a.x=0;      a.y=0;      a.num=6;
        b.x=1;      b.y=0;      b.num=6;
        c.x=-1;     c.y=0;      c.num=6;
        d.x=-1;     d.y=-1;     d.num=6;
        break;

    case 7:
        a.x=0;      a.y=0;      a.num=7;
        b.x=1;      b.y=0;      b.num=7;
        c.x=-1;     c.y=0;      c.num=7;
        d.x=-1;     d.y=1;      d.num=7;
        break ;

    }
    if(mode==2)
    {
        if(status==6)
        {
            int t=rand()%3+1;
            switch(t)
            {
            case 1:
                b.num=22;
                break;
            case 2:
                c.num=22;
                break;
            case 3:
                d.num=22;
                break;
            default:
                break;
            }
        }
    }
    else if(mode==3)
    {
        if(status==6)
        {

            int t=rand()%100+1;
            if(t<=60)
            {
                t=rand()%3+1;
                switch(t)
                {
                case 1:
                    b.num=21;
                    break;
                case 2:
                    c.num=21;
                    break;
                case 3:
                    d.num=21;
                    break;
                default:
                    break;
                }
            }

        }
        else if(status==2)
        {
            int t=rand()%3+1;
            switch(t)
            {
            case 1:
                b.num=22;
                break;
            case 2:
                c.num=22;
                break;
            case 3:
                d.num=22;
                break;
            default:
                break;
            }
        }
    }
    return Object(a,b,c,d);
}
