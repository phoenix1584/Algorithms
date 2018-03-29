/*
 * Copyright (c) 2018
 * Author: phoenix1584
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

// A divide and conquer program in C/C++ to find the smallest distance from a
// given set of points.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define DEBUG 0

// Class to hold information about the coordinates of a point.
// Using templates to allow generalization to non integer datatypes.
// Caution reagarding arithmatic operations is necessary in case of non integral data types.
class Point{
    public:
        int m_x;
        int m_y;

        Point(const int x, const int y) 
            :m_x(x),m_y(y) 
        {}

        Point(const Point& other_p)
            :m_x (other_p.m_x), m_y(other_p.m_y)
        {}

        Point(Point&& other_p){
            *this = std::move(other_p);
        }
       
        Point& operator=(const Point& other_p){
            m_x = other_p.m_x;
            m_y = other_p.m_y;
            return *this;
        } 
         
        void PrintPoint() const{
            std::cout << "x : " << m_x << ", y : " << m_y << "\n";
        }
};

// Utility function to compare the x coordinates.
auto Sort_X(const Point& lhs, const Point& rhs){
    return (lhs.m_x > rhs.m_x);
}

// Utility function to compare the x coordinates.
auto Sort_Y(const Point& lhs, const Point& rhs){
    return (lhs.m_y > rhs.m_y);
}

auto Dist(const Point& p_src, const Point& p_dst ) {
   return std::sqrt(std::pow(p_src.m_x - p_dst.m_x , 2) + std::pow(p_src.m_y - p_dst.m_y , 2)); 
}

float StripClosest(const std::vector<Point>& strip, float d){
    auto min =d;
    for (int i = 0; i < strip.size() ; ++i)
        for (int j = i+1; j < strip.size() && (strip[j].m_y - strip[i].m_y) < min; ++j){
            auto&& tmp_dist = Dist(strip[i],strip[j]);
            if ( tmp_dist < min)
                min = tmp_dist;
        }
    return min;
}

float CloseCalculator(std::vector<Point>& x_sorted_points,int start_point,int end_point){
    // Find the mid point of the range
    auto mid = x_sorted_points.size()/2;
    Point mid_point = x_sorted_points[mid];

    float dl = CloseCalculator(x_sorted_points,start_point,start_point + mid -1);
    float dr = CloseCalculator(x_sorted_points,start_point + mid ,end_point);
    float d = std::min(dl,dr);
    std::vector<Point> strip;
    for(auto i = start_point ; i < (end_point - start_point - 1) ; ++i){
        if(std::abs(x_sorted_points[i].m_x - mid_point.m_x) < d)
            strip.push_back(Point(x_sorted_points[i].m_x,x_sorted_points[i].m_y));
    }
    std::sort(strip.begin(),strip.end(),Sort_Y);
    return std::min(d,StripClosest(strip,d));
}


auto Closest(std::vector<Point>& points){
    std::sort(points.begin(),points.end(),Sort_X);
    return CloseCalculator(points,0,points.size() - 1);
}

int main(){
#if DEBUG
    Point p1(10,10);
    decltype (p1) p2(11,11);
    std::cout << ((Sort_X(p1,p2)) ? "p1" : "p2") << " is greater \n";
    std::cout << "Distance between p1 and p2 is : " << Dist(p1,p2) << "\n";
#endif
    
    std::vector<Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
#if DEBUG
    for (const auto& x : P){
        x.PrintPoint();
    }
#endif
    std::cout << "The closest distance is : " << Closest(P) << "\n";
       
}
