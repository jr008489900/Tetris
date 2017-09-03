#include <iostream>
#include <cmath>
#include "scoreboard.h"
using namespace std;

scoreboard::scoreboard()
{
    combo=0;
    score=0;
    mode=1;
    dif=1;
}
int scoreboard::Get()
{
    return score;
}

void scoreboard::set_dif(int a)
{
    dif=a;
}

void scoreboard::set_mode(int a)
{
    mode=a;
}

void scoreboard::input(int a)   ///分數計算規則: 基本分 P=難度(1,2,3)*模式(1,2,3)*200
{                               ///               之後再根據combo數 P*combo
    int P=dif*mode*200;
    if(score<99999999)
    {
        if(a!=0)
            combo+=a;
        else
            combo=a;

        if(combo<=3)
            score+=P*sqrt(combo*combo);
        else if(combo>3&&combo<=8)
            score+=P*2*sqrt(combo*combo);
        else if(combo>8&&combo<=13)
            score+=P*3*sqrt(combo*combo);
        else if(combo>13&&combo<20)
            score+=P*5*sqrt(combo*combo);
        else
            score+=P*5*sqrt(combo*combo);
    }
    else
        score=99999999;
    return ;
}

