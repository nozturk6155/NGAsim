#ifndef VECTOR2D_H
#define VECTOR2D_H

//Cismin hareketlerini koordine etmek icin olustulur
class Vector2D
{
    public:
        Vector2D(){}
        Vector2D(float x, float y);
        float getX();
        float getY();
        void setX(float x);
        void setY(float y);
        Vector2D operator+(const Vector2D& v2) const;
        Vector2D operator*(float scalar);
        Vector2D& operator*=(float scalar);
        Vector2D operator-(const Vector2D& v2) const;

        Vector2D operator/(float scalar);
        Vector2D& operator/=(float scalar);
        void normalize();
        friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;
            return v1;
        }
        friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;
            return v1;
        }
        float length();
        virtual ~Vector2D(){}

    private:
        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
