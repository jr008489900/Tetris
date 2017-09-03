#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

using namespace std ;

struct Point
{
    int x ;/**< coordinate x */
    int y ;/**< coordinate y */

    int num; ///number
};

class Object
{
    public:
        /** \brief constructor with no Point
         *
         *
         */
        Object();
        /** \brief make a Object with four Point and in the coordinate (5,2)
         *
         * \param Point Point Point Point
         * \return None
         *
         */
        Object( Point , Point , Point , Point ) ;
        /** \brief make a Object with three Point and in the coordinate (5,2)
         *
         * \param Point Point Point
         *
         */
        Object(Point , Point , Point ) ;
        /** \brief make Object with two Point and in the coordinate (5,2)
         *
         * \param Point Point
         *
         */
        Object(Point , Point );
        /** \brief make Object with one Point and in the coordinate (5,2)
         *
         * \param Point
         *
         */
        Object(Point);

        /** \brief input a char and move left right down depend on char
         *
         * \param char maybe a or s or d
         * \return void
         *
         */
        void move(char) ;
        /** \brief rotate the Object coordinate clockwise
         *
         * \return void
         *
         */
        void rotate() ;
        /** \brief get back the absolyte coordinate
         *
         * \return Point that is absolute coordinate
         *
         */
        Point get_coordinate();

        /** \brief get back the relative coordinate
         *
         * \return vector<Point> include all relative coordinate
         *
         */
        vector<Point> get_relative();

    private:


        vector < Point > arr2 ;/**<  Object relative coordinate */

        Point center ;/**<  Object absolute coordinate */

};

#endif // OBJECT_H
