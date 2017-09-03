#ifndef INTERFACE_H
#define INTERFACE_H
#include"Board.h"
#include<string>
#include"scoreboard.h"
#include"Rank.h"

class Interface
{
public:
    Interface();

    /** \brief print the main menu.
     *
     * \return void
     *
     */
    void output_menu();
private:
    /** \brief start the game.
     *
     * \return void
     *
     */
    void start();
    /** \brief draw a frame.
     *
     * \return void
     *
     */
    void draw();
    /** \brief output the rank.
     *
     * \return void
     *
     */
    void output_Rank();
    /** \brief draw a small frame.
     *
     * \return void
     *
     */
    void small_draw(int , int);
    /** \brief print the block type (for next or save).
     *
     * \return void
     *
     */
    void Blocks (int , int ,int);
    /** \brief print the block type (for next or save).
     *
     * \return void
     *
     */
    void back_Menu ();

    Rank go_rank;
    int time ;
    int score;
    int difficulty;
    int mode;   ///for inside options (like: classic , extra ,nightmare)
    int left , top, right , bottom;
};


#endif // INTERFACE_H
