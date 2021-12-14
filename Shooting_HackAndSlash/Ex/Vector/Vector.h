#pragma once
#include<cmath>

template<typename Vector_Component , typename Dicimal>
// �ėp�����ꂽ�񎟌��x�N�g���\����
// Vector_Component : x�Ay�����Ɏg�p����ϐ��^
// Dicimal : �����ȂǂɎg�p���鏬���^
struct Vector2 {
private:
    static constexpr Vector_Component ZERO = static_cast<Vector_Component>( 0 );
public:
    Vector_Component x , y;

    Vector2() = default;
    Vector2( Vector_Component x , Vector_Component y )
        : x{ x } , y{ y } {}

    // �x�N�g���̑傫�����v�Z���ĕԂ�
    [[nodiscard]] Dicimal length() const { return static_cast<Dicimal>( sqrt( ( x * x ) + ( y * y ) ) ); }
    // ���K�������x�N�g����Ԃ�
    [[nodiscard]] Vector2<Vector_Component , Dicimal> nomalize() const {
        // �傫����0�ł��鎞�̉��
        if(isZero() ){ return Vector2{ ZERO, ZERO }; }

        Dicimal temp = length();
        return Vector2{ x / temp, y / temp };
    }
    // �[���x�N�g�����ǂ���
    [[nodiscard]] bool isZero() const { return ( x == ZERO && y == ZERO ); }

#pragma region �v�Z�񍀉��Z�q�̃I�[�o�[���[�h
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator+( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x + other.x , y + other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator-( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x - other.x , y - other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator*( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x* other.x , y* other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator*( const Vector_Component& other ) const { return Vector2<Vector_Component , Dicimal>{x* other , y* other}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator/( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x / other.x , y / other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator/( const Vector_Component& other ) const { return Vector2<Vector_Component , Dicimal>{x / other , y / other}; }
#pragma endregion
#pragma region ����t���v�Z���Z�q�̃I�[�o�[���[�h
    Vector2<Vector_Component , Dicimal> operator+=( const Vector2<Vector_Component , Dicimal>& other ) {
        x += other.x; y += other.y;
        return *this;
    }
    Vector2<Vector_Component , Dicimal> operator-=( const Vector2<Vector_Component , Dicimal>& other ) {
        x -= other.x; y -= other.y;
        return *this;
    }
    Vector2<Vector_Component , Dicimal> operator*=( const Vector2<Vector_Component , Dicimal>& other ) {
        x *= other.x; y *= other.y;
        return *this;
    }
    Vector2<Vector_Component , Dicimal> operator/=( const Vector2<Vector_Component , Dicimal>& other ) {
        x /= other.x; y /= other.y;
        return *this;
    }
#pragma endregion
#pragma region ��r���Z�q�̃I�[�o�[���[�h
    [[nodiscard]] bool operator==( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x == other.x && y == other.y ); }
    [[nodiscard]] bool operator!=( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x != other.x || y != other.y ); }
    [[nodiscard]] bool operator>( const Vector2<Vector_Component , Dicimal>& other ) const { return length() > other.length(); }
    [[nodiscard]] bool operator>=( const Vector2<Vector_Component , Dicimal>& other ) const { return length() >= other.length(); }
    [[nodiscard]] bool operator<( const Vector2<Vector_Component , Dicimal>& other ) const { return length() < other.length(); }
    [[nodiscard]] bool operator<=( const Vector2<Vector_Component , Dicimal>& other ) const { return length() <= other.length(); }
#pragma endregion

    // �x�N�g�����m�̋���
    [[nodiscard]] Dicimal distance( const Vector2<Vector_Component , Dicimal>& other ) const { return ( *this - other ).length(); }
    // ����
    [[nodiscard]] Dicimal dot( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x * other.x ) + ( y * other.y ); }
    // �O��
    [[nodiscard]] Dicimal cross( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x * other.y ) - ( y * other.x ); }
};

using Vec2 = Vector2<float , float>;
using Point = Vector2<int , float>;
using LongVec2 = Vector2<double , double>;
using LongPoint = Vector2<long , long>;