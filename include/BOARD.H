#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<ctime>
#include"Object.h"
#include"scoreboard.h"
#include"Random_Ob.h"
using namespace std ;
class Board
{
    public:

        /** \brief using defalt difficulty.
         *
         *
         */
        Board();
        /** \brief given a integer to set the difficulty.
         *
         * \param int
         *
         */
        Board(int);

        /** \brief given two int to set the difficulty and the mode.
         *         first: 1:easy , 2: hard , 3:crazy;
         *         second : 1:normal , 2: Props 3: Props and a Obstacle.
         *
         * \param int
         * \param int
         *
         */
        Board(int,int);
        /** \brief return the game board.
         *      編號:1~7是正常方塊 21~30是特殊方塊。
         *         21是X: 22是*
         *
         * \return vector< vector<int > >;
         *
         */
        vector< vector<int> > get_board(); ///回傳主遊戲盤面

        /** \brief return the total score.
         *
         * \return int
         *
         */
        int Get_score(); ///回傳總分

        /** \brief 判斷遊戲是否已經LOSE
         *
         * \return bool 0:continue , 1:lose
         *
         */
        bool check_condition(); ///判斷遊戲是否已經LOSE , 0:continue , 1:lose ;

        /** \brief get next object .
         *
         * \return int
         *
         */
        int GetNextOb(); ///得到下一個方塊的編號

        /** \brief Given a saved object number if it exists , else return 0.
         *
         * \return int
         *
         */
        int get_save();  ///傳出SAVE的方塊編號
    private:
       // Object save;
        /** \brief 檢查磚塊是否在盤面內 1:是 0:否
         *
         * \param Object
         * \return bool
         *
         */
        bool check_inside(Object); ///檢查此磚塊是否在盤面內
        /** \brief 隨機抽取一個方塊
         *
         * \return Object
         *
         */
        Object random_choose();  ///隨機抽一個方塊
        /** \brief 連線消去的判定，如果連線就進行消掉的動作;
         *
         * \return int
         *
         */
        void bingo();

        /** \brief given a int to represent y coordinate.
         *
         * \param int
         * \return void
         *
         */
        void Erase_row(int);
        /** \brief given a int to represent x coordinate.
         *
         * \param int
         * \return void
         *
         */
        void Erase_column(int);

        vector< vector<int> > check;  ///建立二維陣列判斷磚塊堆積位置
        Object T,TT,TTT;
        Random_Ob Machine;  ///隨機抽取方塊的機器
        scoreboard SB;      ///計分器
        bool save_status;  ///如果目前有存取方塊則為1否則為0;
        bool ds_status; ///保存磚塊的狀態0:靜止 1:掉落中
        int combo;
        int time;
        clock_t start , finish; ///時間判定是否該下降 #222
        bool condition; ///遊戲是否結束的判定變數
        int status ; ///盤面狀態 0:沒有磚塊 1:有磚塊落下中 2:有磚塊但已靜止;
};

#endif // BOARD_H
