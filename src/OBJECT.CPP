#include "Object.h"
#include <vector>
#include <cmath>
Object::Object()
{

}

Object::Object( Point a , Point b , Point c , Point d )
{
    arr2.push_back( a ) ;
    arr2.push_back( b ) ;
    arr2.push_back( c ) ;
    arr2.push_back( d ) ;

    center.x = 5 ;
    center.y = 2 ;

}

Object::Object( Point a , Point b , Point c )
{
    arr2.push_back( a ) ;
    arr2.push_back( b ) ;
    arr2.push_back( c ) ;

    center.x = 5 ;
    center.y = 2 ;
}

Object::Object(Point a, Point b)
{
    arr2.push_back( a ) ;
    arr2.push_back( b ) ;

    center.x = 5 ;
    center.y = 2 ;
}

Object::Object(Point a)
{
    arr2.push_back( a ) ;

    center.x = 5 ;
    center.y = 2 ;
}

void Object::move(char input_direction ) ///�j�����y���ܰ�;
{
    if( input_direction == 'a' || input_direction == 'A' ) ///�V������
    {
        center.x -- ;
    }
    else if( input_direction == 'd' || input_direction == 'D' )  ///�V�k����
    {
        center.x ++ ;
    }
    else if( input_direction == 's' || input_direction == 'S' ) ///�V�U����
    {
        center.y ++ ;
    }

}
vector<Point> Object::get_relative()        ///�^�Ǭ۹�y��
{
    vector<Point> arrt=arr2;
    return arrt;
}
void Object::rotate()       ///�B�z������
{

    for( int i = 0 ; i < int(arr2.size()) ; i ++ )
    {
        swap( arr2[ i ].y , arr2[ i ].x ) ;
        arr2[ i ].x *= -1 ;
    }
}

Point Object::get_coordinate()  ///�o�쵴��y��
{
    Point output ;
    output.x = center.x ;
    output.y = center.y ;
    return output ;
}

