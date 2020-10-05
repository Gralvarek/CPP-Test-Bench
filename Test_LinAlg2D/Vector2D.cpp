//
//  Vector2D.cpp
//  Linear-Algebra-2D
//
//  Created by Vero on 14.06.20.
//  Copyright © 2020 Vero. All rights reserved.
//

#include "Vector2D.hpp"


Vector2D::Vector2D()
{
    m_x = 0.0f;
    m_y = 0.0f;
}

Vector2D::Vector2D(double x, double y)
{
    m_x = x;
    m_y = y;
}

double Vector2D::operator*(const Vector2D& v)
{
    return m_x * v.m_x + m_y * v.m_y;
}

Vector2D& Vector2D::operator*=(const double a)
{
    m_x *= a;
    m_y *= a;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D &v)
{
    Vector2D vector;
    vector.m_x = this->m_x + v.m_x;
    vector.m_y = this->m_y + v.m_y;
    return vector;
}

Vector2D Vector2D::operator-(const Vector2D &v)
{
    Vector2D vector;
    vector.m_x = this->m_x - v.m_x;
    vector.m_y = this->m_y - v.m_y;
    return vector;
    
}

double Vector2D::Magnitude()
{
    return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2D::Normalize()
{
    double mag = Magnitude();
    *this *= 1/mag;
}

std::ostream& operator<<(std::ostream& str, const Vector2D& v)
{
    return str << "( " << v.m_x << " , "  << v.m_y << " )";
}
