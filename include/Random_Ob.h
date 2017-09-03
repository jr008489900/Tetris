#ifndef RANDOM_OB_H
#define RANDOM_OB_H

#include"Object.h"
#include<vector>
using namespace std;

class Random_Ob   ///隨機抽取方塊 ， 且7個不同磚塊為一週期。
{
    public:
        Random_Ob();
        Object pick();
        /** \brief given a int to set the difficulty .
         *
         * \param int
         * \return void
         *
         */
        void set_mode(int);
    private:
        /** \brief record the status of the class ,
         *
         * \param
         * \param
         * \return
         *
         */
        int status;
        vector<int> arr;
        int mode;

};

#endif // RANDOM_OB_H
