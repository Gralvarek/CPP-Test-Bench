//
//  Matrix2D.cpp
//  Linear-Algebra-2D
//
//  Created by Vero on 14.06.20.
//  Copyright © 2020 Vero. All rights reserved.
//

#include "Matrix2D.hpp"

Matrix2D::Matrix2D()
{
    m_x1 = 0;
    m_y1 = 0;
    m_x2 = 0;
    m_y2 = 0;
}

Matrix2D::Matrix2D(double x1, double y1, double x2, double y2)
{
    m_x1 = x1;
    m_y1 = y1;
    m_x2 = x2;
    m_y2 = y2;
}

Matrix2D Matrix2D::operator+(const Matrix2D& m)
{
    Matrix2D matrix;
    matrix.m_x1 = m_x1 + m.m_x1;
    matrix.m_y1 = m_y1 + m.m_y1;
    matrix.m_x2 = m_x2 + m.m_x2;
    matrix.m_y2 = m_y2 + m.m_y2;
    return matrix;
}

Matrix2D Matrix2D::operator-(const Matrix2D& m)
{
    Matrix2D matrix;
    matrix.m_x1 = m_x1 - m.m_x1;
    matrix.m_y1 = m_y1 - m.m_y1;
    matrix.m_x2 = m_x2 - m.m_x2;
    matrix.m_y2 = m_y2 - m.m_y2;
    return matrix;
}

Matrix2D Matrix2D::operator*(const double a)
{
    Matrix2D matrix;
    matrix.m_x1 = m_x1 * a;
    matrix.m_y1 = m_y1 * a;
    matrix.m_x2 = m_x2 * a;
    matrix.m_y2 = m_y2 * a;
    return matrix;
}

Matrix2D& Matrix2D::operator*=(const double a)
{
    m_x1 *= a;
    m_y1 *= a;
    m_x2 *= a;
    m_y2 *= a;
    return *this;
}

Vector2D Matrix2D::operator*(const Vector2D& v)
{
    Vector2D vector;
    vector.m_x = v.m_x * m_x1 + v.m_y * m_x2;
    vector.m_y = v.m_x * m_y1 + v.m_y * m_y2;
    return vector;
}

Matrix2D Matrix2D::Transpose()
{
    Matrix2D matrix = *this;
    matrix.m_x2 = m_y1;
    matrix.m_y1 = m_x2;
    return matrix;
}

double Matrix2D::Determinant()
{
    return m_x1 * m_y2 - m_y1 * m_x2;
}

Matrix2D Matrix2D::Inverse()
{
    double det = Determinant();
    Matrix2D matrix;
    matrix.m_x1 = m_y2;
    matrix.m_y2 = m_x1;
    matrix.m_x2 = -m_x2;
    matrix.m_y1 = -m_y1;
    matrix *= 1/det;
    return matrix;
}

std::ostream& operator<<(std::ostream& str, const Matrix2D& m)
{
    return str << m.m_x1 << " " << m.m_x2 << std::endl << m.m_y1 << " " << m.m_y2;
}