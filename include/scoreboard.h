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
        int Get(); ///�^���`��

        /** \brief given a combo num to compute the score.
         *
         * \param int
         * \return void
         *
         */
        void input(int);

        /** \brief ���w���ץH�K�]�w���ƭ��v
         *
         * \param int
         * \return int
         *
         */
        void set_dif(int);
        void set_mode(int);
    private:
        int score;  ///�`�p����
        int combo;
        int dif;
        int mode;
};

#endif // SCOREBOARD_H
