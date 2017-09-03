#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include"utilwin32.h"

class scoreboard
{
    public:
        scoreboard();
        /** \brief get total score.
         *
         * \param int
         * \return int
         *
         */
        int Get(); ///回傳總分

        /** \brief given a combo num to compute the score.
         *
         * \param int
         * \return void
         *
         */
        void input(int);

        /** \brief 給定難度以便設定分數倍率
         *
         * \param int
         * \return int
         *
         */
        void set_dif(int);
        void set_mode(int);
    private:
        int score;  ///總計分數
        int combo;
        int dif;
        int mode;
};

#endif // SCOREBOARD_H
