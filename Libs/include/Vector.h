#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED
struct Vec2
{
    float x,y;

    Vec2 operator+(Vec2 &right)
    {
        Vec2 result;
        result.x = x+right.x;
        result.y = y+right.y;
        return result;
    };

    Vec2 operator-(Vec2 &right)
    {
        Vec2 result;
        result.x = x-right.x;
        result.y = y-right.y;
        return result;
    };

    Vec2 operator*(Vec2 &right)
    {
        Vec2 result;
        result.x = x*right.x;
        result.y = y*right.y;
        return result;
    };

    Vec2 operator/(Vec2 &right)
    {
        Vec2 result;
        result.x = x/right.x;
        result.y = y/right.y;
        return result;
    };

    template <class T>
    friend Vec2 operator*(const Vec2 &left,const T &a)
    {
        Vec2 result;
        result.x = left.x*a;
        result.y = left.y*a;
        return result;
    };

    template <class T>
    friend Vec2 operator/(const Vec2 &left,const T &a)
    {
        Vec2 result;
        result.x = left.x/a;
        result.y = left.y/a;
        return result;
    };

    template <class T>
     Vec2 operator/=(T a)
    {
        x/=a;
        y/=a;
        return *this;
    };

    template <class T>
     Vec2 operator*=(T a)
    {
        x*=a;
        y*=a;
        return *this;
    };

    template <class T>
    friend Vec2 operator+(const Vec2 &left,const T &a)
    {
        Vec2 result;
        result.x = left.x+a;
        result.y = left.y+a;
        return result;
    };

    template <class T>
    friend Vec2 operator-(const Vec2 &left,const T &a)
    {
        Vec2 result;
        result.x = left.x-a;
        result.y = left.y-a;
        return result;
    };


    float length(void)
    {
        return (float) sqrt(x*x+y*y);
    }
};


#endif // VEC2_H_INCLUDED
