#pragma once
#include<cmath>

template<typename Vector_Component , typename Dicimal>
// 汎用化された二次元ベクトル構造体
// Vector_Component : x、y成分に使用する変数型
// Dicimal : 長さなどに使用する小数型
struct Vector2 {
private:
    static constexpr Vector_Component ZERO = static_cast<Vector_Component>( 0 );
public:
    Vector_Component x , y;

    Vector2() = default;
    Vector2( Vector_Component x , Vector_Component y )
        : x{ x } , y{ y } {}

    // ベクトルの大きさを計算して返す
    [[nodiscard]] Dicimal length() const { return static_cast<Dicimal>( sqrt( ( x * x ) + ( y * y ) ) ); }
    // 正規化したベクトルを返す
    [[nodiscard]] Vector2<Vector_Component , Dicimal> nomalize() const {
        // 大きさが0である時の回避
        if(isZero() ){ return Vector2{ ZERO, ZERO }; }

        Dicimal temp = length();
        return Vector2{ x / temp, y / temp };
    }
    // ゼロベクトルかどうか
    [[nodiscard]] bool isZero() const { return ( x == ZERO && y == ZERO ); }

#pragma region 計算二項演算子のオーバーロード
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator+( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x + other.x , y + other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator-( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x - other.x , y - other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator*( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x* other.x , y* other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator*( const Vector_Component& other ) const { return Vector2<Vector_Component , Dicimal>{x* other , y* other}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator/( const Vector2<Vector_Component , Dicimal>& other ) const { return Vector2<Vector_Component , Dicimal>{x / other.x , y / other.y}; }
    [[nodiscard]] Vector2<Vector_Component , Dicimal> operator/( const Vector_Component& other ) const { return Vector2<Vector_Component , Dicimal>{x / other , y / other}; }
#pragma endregion
#pragma region 代入付き計算演算子のオーバーロード
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
#pragma region 比較演算子のオーバーロード
    [[nodiscard]] bool operator==( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x == other.x && y == other.y ); }
    [[nodiscard]] bool operator!=( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x != other.x || y != other.y ); }
    [[nodiscard]] bool operator>( const Vector2<Vector_Component , Dicimal>& other ) const { return length() > other.length(); }
    [[nodiscard]] bool operator>=( const Vector2<Vector_Component , Dicimal>& other ) const { return length() >= other.length(); }
    [[nodiscard]] bool operator<( const Vector2<Vector_Component , Dicimal>& other ) const { return length() < other.length(); }
    [[nodiscard]] bool operator<=( const Vector2<Vector_Component , Dicimal>& other ) const { return length() <= other.length(); }
#pragma endregion

    // ベクトル同士の距離
    [[nodiscard]] Dicimal distance( const Vector2<Vector_Component , Dicimal>& other ) const { return ( *this - other ).length(); }
    // 内積
    [[nodiscard]] Dicimal dot( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x * other.x ) + ( y * other.y ); }
    // 外積
    [[nodiscard]] Dicimal cross( const Vector2<Vector_Component , Dicimal>& other ) const { return ( x * other.y ) - ( y * other.x ); }
};

using Vec2 = Vector2<float , float>;
using Point = Vector2<int , float>;
using LongVec2 = Vector2<double , double>;
using LongPoint = Vector2<long , long>;