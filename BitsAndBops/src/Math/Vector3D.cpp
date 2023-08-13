#include "Vector3D.h"
#include <math.h>

Vector3D Vector3D::Right()
{
    return Vector3D(1, 0, 0);
}

Vector3D Vector3D::Up()
{
    return Vector3D(0, 1, 0);
}

Vector3D Vector3D::Front()
{
    return Vector3D(0, 0, 1);
}

Vector3D::Vector3D(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

float Vector3D::Length()const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::Normaliz()const
{
    float Len = Length();
    if (Len == 0)
        return Vector3D();
    return Vector3D(x / Len, y / Len, z / Len);
}

Vector3D Vector3D::operator+(const Vector3D& b) const
{
    return Vector3D(x + b.x, y + b.y, z + b.z);
}

Vector3D Vector3D::operator-(const Vector3D& b) const
{
    return Vector3D(x - b.x, y - b.y, z - b.z);
}

Vector3D Vector3D::operator * (float f) const
{
    return Vector3D(x * f , y * f , z * f);
}

Vector3D Vector3D::operator/(float f) const
{
    if (f == 0)
        return Vector3D(0,0,0);
    return Vector3D(x / f , y / f , z / f);
}

Vector3D& Vector3D::operator+=(const Vector3D& b)
{
    x += b.x;
    y += b.y;
    z += b.z;
    return *this;
    // TODO: 在此处插入 return 语句
}

Vector3D& Vector3D::operator-=(const Vector3D& b)
{
    x -= b.x;
    y -= b.y;
    z -= b.z;
    return *this;
    // TODO: 在此处插入 return 语句
}

float Vector3D::Dot(const Vector3D* b) const
{
    return (x * b->x + y * b->y + z * b->z);
}

Vector3D Vector3D::Cross(const Vector3D* b) const
{
    Vector3D vector;
    vector.x = y * b->z - z * b->y;
    vector.y = z * b->x - x * b->z;
    vector.z = x * b->y - y * b->x;
    return vector;
}

Vector3D& Vector3D::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator+() const
{
    return *this;
}

//Vector3D Vector3D::Projection(Vector3D& b) const
//{
//    float fTmp = b.Length();
//    Vector3D vp = b * ((*this).Dot(b)) / (fTmp * fTmp);
//    return vp;
//}

float Vector3D::GetAngle(const Vector3D* b)const
{
    float Len1 = Length();
    float Len2 = b->Length();

    float temp = x * b->x + y * b->y + z * b->z;

    return (acos(temp / (Len1 * Len2))) * 180.0f / 3.14f;;
}
