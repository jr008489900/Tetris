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
         *      �s��:1~7�O���`��� 21~30�O�S������C
         *         21�OX: 22�O*
         *
         * \return vector< vector<int > >;
         *
         */
        vector< vector<int> > get_board(); ///�^�ǥD�C���L��

        /** \brief return the total score.
         *
         * \return int
         *
         */
        int Get_score(); ///�^���`��

        /** \brief �P�_�C���O�_�w�gLOSE
         *
         * \return bool 0:continue , 1:lose
         *
         */
        bool check_condition(); ///�P�_�C���O�_�w�gLOSE , 0:continue , 1:lose ;

        /** \brief get next object .
         *
         * \return int
         *
         */
        int GetNextOb(); ///�o��U�@�Ӥ�����s��

        /** \brief Given a saved object number if it exists , else return 0.
         *
         * \return int
         *
         */
        int get_save();  ///�ǥXSAVE������s��
    private:
       // Object save;
        /** \brief �ˬd�j���O�_�b�L���� 1:�O 0:�_
         *
         * \param Object
         * \return bool
         *
         */
        bool check_inside(Object); ///�ˬd���j���O�_�b�L����
        /** \brief �H������@�Ӥ��
         *
         * \return Object
         *
         */
        Object random_choose();  ///�H����@�Ӥ��
        /** \brief �s�u���h���P�w�A�p�G�s�u�N�i��������ʧ@;
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

        vector< vector<int> > check;  ///�إߤG���}�C�P�_�j����n��m
        Object T,TT,TTT;
        Random_Ob Machine;  ///�H��������������
        scoreboard SB;      ///�p����
        bool save_status;  ///�p�G�ثe���s������h��1�_�h��0;
        bool ds_status; ///�O�s�j�������A0:�R�� 1:������
        int combo;
        int time;
        clock_t start , finish; ///�ɶ��P�w�O�_�ӤU�� #222
        bool condition; ///�C���O�_�������P�w�ܼ�
        int status ; ///�L�����A 0:�S���j�� 1:���j�����U�� 2:���j�����w�R��;
};

#endif // BOARD_H