#ifndef RANK_H
#define RANK_H

#include<vector>
#include <string>
using namespace std;

struct Data
{
    string name;    ///姓名
    int score;      ///分數
};

class Rank ///排行榜
{
public:
    Rank();   ///從檔案中把姓名 , 分數做好處理 放到 vector<Data> 中 ;
    /** \brief given the name and the score to input the data to RankBoard.
     *
     * \param string
     * \param int
     * \return void
     *
     */
    void input(string,int);   ///輸入姓名與分數
    /** \brief given the name and set the defalt score to 0.
     *
     * \param string
     * \return void
     *
     */
    void input(string);    ///輸入姓名 分數預設為0;
    /** \brief ///回傳已按照分數排序的資料且只取10位
     *
     * \return vector<Data>
     *
     */
    vector<Data> Get_data();  ///回傳已按照分數排序的資料且只取10位。

    /** \brief ///清空記事本的所有資料
     *
     * \return void
     *
     */
    void Delete_Data();
private:
    vector<Data> table;
};

#endif // RANK_H
