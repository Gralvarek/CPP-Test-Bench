//
//  Vector2D.hpp
//  Linear-Algebra-2D
//
//  Created by Vero on 14.06.20.
//  Copyright © 2020 Vero. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <stdio.h>
#include <ostream>
#include <math.h>

class Vector2D
{
public:
    
    Vector2D();
    Vector2D(double x, double y);
    
    double operator*(const Vector2D& v);
    Vector2D& operator*=(const double a);
    Vector2D operator+(const Vector2D& v);
    Vector2D operator-(const Vector2D& v);
    
    double Magnitude();
    void Normalize();
    

private:
    double m_x;
    double m_y;
    friend std::ostream& operator<<(std::ostream& str, const Vector2D& v);
    friend class Matrix2D;
};

#endif /* Vector2D_hpp */
