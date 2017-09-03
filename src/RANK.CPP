#include "Rank.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


Rank::Rank()    ///一開始就需先進行讀檔處理
{
    fstream fin;
    fin.open("rank.txt",ios::in);
    string n;
    int s;
    while(fin>>n>>s)
    {
        Data d;
        d.name=n;
        d.score=s;
        table.push_back(d);
    }
}

void Rank::input(string a)  ///處理規則:    每次只取前10名分數高者 相同名字用分數高者取代
{
    int i;
    bool check=false;
    vector <Data> line;
    Data d;
    d.name=a;
    d.score=0;
    for(i=0;i<int(table.size());i++)
        line.push_back(table[i]);
    for(i=0;i<int(line.size());i++) ///一樣名字,比分數
    {
        if(line[i].name==d.name)
        {
            check=true;
            if(line[i].score<d.score)
                line[i].score=d.score;
            break;
        }
    }
    if(check==false)
    {
        line.push_back(d);

        for(i=0;i<int(line.size());i++)
        {
            for(int j=i+1;j<int(line.size());j++)
            {
                if(line[i].score<line[j].score)
                {
                    swap(line[i].name,line[j].name);
                    swap(line[i].score,line[j].score);
                }
            }
        }

    }
    else
    {
        for(i=0;i<int(line.size());i++)
        {
            for(int j=i+1;j<int(line.size());j++)
            {
                if(line[i].score<line[j].score)
                {
                    swap(line[i].name,line[j].name);
                    swap(line[i].score,line[j].score);
                }
            }
        }
    }
    ofstream fout("rank.txt");
    if(table.size()<10)
    {
        for(i=0;i<int(table.size());i++)
        {
            table[i].name=line[i].name;
            table[i].score=line[i].score;
            fout<<table[i].name<<" "<<table[i].score<<endl;
        }
        if(check==false)
        {
            table.push_back(line[table.size()]);
            fout<<table[table.size()-1].name<<" "<<table[table.size()-1].score<<endl;
        }
    }
    else if(table.size()>=10)
    {
        for(i=0;i<10;i++)
        {
            table[i].name=line[i].name;
            table[i].score=line[i].score;
            fout<<table[i].name<<" "<<table[i].score<<endl;
        }
    }
}

void Rank::input(string a,int b)     ///處理規則:    每次只取前10名分數高者 相同名字用分數高者取代
{
    int i;
    bool check=false;
    vector <Data> line;
    Data d;
    d.name=a;
    d.score=b;
    for(i=0;i<int(table.size());i++)
        line.push_back(table[i]);
    for(i=0;i<int(line.size());i++) ///一樣名字,比分數
    {
        if(line[i].name==d.name)
        {
            check=true;
            if(line[i].score<d.score)
                line[i].score=d.score;
            break;
        }
    }
    if(check==false)
    {
        line.push_back(d);

        for(i=0;i<int(line.size());i++)
        {
            for(int j=i+1;j<int(line.size());j++)
            {
                if(line[i].score<line[j].score)
                {
                    swap(line[i].name,line[j].name);
                    swap(line[i].score,line[j].score);
                }
            }
        }

    }
    else
    {
        for(i=0;i<int(line.size());i++)
        {
            for(int j=i+1;j<int(line.size());j++)
            {
                if(line[i].score<line[j].score)
                {
                    swap(line[i].name,line[j].name);
                    swap(line[i].score,line[j].score);
                }
            }
        }
    }
    ofstream fout("rank.txt");
    if(table.size()<10)
    {
        for(i=0;i<int(table.size());i++)
        {
            table[i].name=line[i].name;
            table[i].score=line[i].score;
            fout<<table[i].name<<" "<<table[i].score<<endl;
        }
        if(check==false)
        {
            table.push_back(line[table.size()]);
            fout<<table[table.size()-1].name<<" "<<table[table.size()-1].score<<endl;
        }
    }
    else if(table.size()>=10)
    {
        for(i=0;i<10;i++)
        {
            table[i].name=line[i].name;
            table[i].score=line[i].score;
            fout<<table[i].name<<" "<<table[i].score<<endl;
        }
    }
}

vector<Data> Rank::Get_data()   ///回傳資料
{
    return table;
}

void Rank::Delete_Data()    ///清除資料
{
    table.clear();
    fstream fin;
    fin.open("rank.txt",ios::out);
}
