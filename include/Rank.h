#ifndef RANK_H
#define RANK_H

#include<vector>
#include <string>
using namespace std;

struct Data
{
    string name;    ///�m�W
    int score;      ///����
};

class Rank ///�Ʀ�]
{
public:
    Rank();   ///�q�ɮפ���m�W , ���ư��n�B�z ��� vector<Data> �� ;
    /** \brief given the name and the score to input the data to RankBoard.
     *
     * \param string
     * \param int
     * \return void
     *
     */
    void input(string,int);   ///��J�m�W�P����
    /** \brief given the name and set the defalt score to 0.
     *
     * \param string
     * \return void
     *
     */
    void input(string);    ///��J�m�W ���ƹw�]��0;
    /** \brief ///�^�Ǥw���Ӥ��ƱƧǪ���ƥB�u��10��
     *
     * \return vector<Data>
     *
     */
    vector<Data> Get_data();  ///�^�Ǥw���Ӥ��ƱƧǪ���ƥB�u��10��C

    /** \brief ///�M�ŰO�ƥ����Ҧ����
     *
     * \return void
     *
     */
    void Delete_Data();
private:
    vector<Data> table;
};

#endif // RANK_H
