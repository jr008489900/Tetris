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

void Object::move(char input_direction ) ///磚塊的座標變動;
{
    if( input_direction == 'a' || input_direction == 'A' ) ///向左移動
    {
        center.x -- ;
    }
    else if( input_direction == 'd' || input_direction == 'D' )  ///向右移動
    {
        center.x ++ ;
    }
    else if( input_direction == 's' || input_direction == 'S' ) ///向下移動
    {
        center.y ++ ;
    }

}
vector<Point> Object::get_relative()        ///回傳相對座標
{
    vector<Point> arrt=arr2;
    return arrt;
}
void Object::rotate()       ///處理旋轉方塊
{

    for( int i = 0 ; i < int(arr2.size()) ; i ++ )
    {
        swap( arr2[ i ].y , arr2[ i ].x ) ;
        arr2[ i ].x *= -1 ;
    }
}

Point Object::get_coordinate()  ///得到絕對座標
{
    Point output ;
    output.x = center.x ;
    output.y = center.y ;
    return output ;
}


