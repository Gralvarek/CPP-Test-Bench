//
//  Matrix2D.hpp
//  Linear-Algebra-2D
//
//  Created by Vero on 14.06.20.
//  Copyright © 2020 Vero. All rights reserved.
//

#ifndef Matrix2D_hpp
#define Matrix2D_hpp

#include <stdio.h>
#include <ostream>
#include "Vector2D.hpp"

class Matrix2D
{
public:
    
    Matrix2D();
    Matrix2D(double x1, double y1, double x2, double y2);
    
    Matrix2D operator+(const Matrix2D& m);
    Matrix2D operator-(const Matrix2D& m);
    Matrix2D& operator*=(const double a);
    Matrix2D operator*(const double a);
    Vector2D operator*(const Vector2D& v);
    
    Matrix2D Transpose();
    double Determinant();
    Matrix2D Inverse();
    
private:
    double m_x1, m_y1, m_x2, m_y2;
    friend std::ostream& operator<<(std::ostream& str, const Matrix2D& m);
};

#endif /* Matrix2D_hpp */
