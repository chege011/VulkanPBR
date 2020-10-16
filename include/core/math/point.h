//
// Created by 1129 on 2020/10/16.
//

#ifndef JADEHARE_CORE_MATH_POINT_H
#define JADEHARE_CORE_MATH_POINT_H

#include "tuple.h"

namespace jadehare{

    // Point2 Definition
    template<typename T>
    class Point2 : public Tuple2<Point2, T> {
    public:
        // Point2 Public Methods
        using Tuple2<Point2, T>::x;
        using Tuple2<Point2, T>::y;
        using Tuple2<Point2, T>::HasNaN;
        using Tuple2<Point2, T>::operator+;
        using Tuple2<Point2, T>::operator+=;
        using Tuple2<Point2, T>::operator*;
        using Tuple2<Point2, T>::operator*=;


        Point2() { x = y = 0; }


        Point2(T x, T y) : Tuple2<Point2, T>(x, y) {}

        template<typename U>
        explicit Point2(const Point2<U> &v)
                : Tuple2<Point2, T>(T(v.x), T(v.y)) {}

        template<typename U>
        explicit Point2(const Vector2<U> &v)
                : Tuple2<Point2, T>(T(v.x), T(v.y)) {}

        template<typename U>
        auto operator+(const Vector2<U> &v) const
        -> Point2<decltype(T{} + U{})> {
            DCHECK(!v.HasNaN());
            return {x + v.x, y + v.y};
        }

        template<typename U>
        Point2<T> &operator+=(const Vector2<U> &v) {
            DCHECK(!v.HasNaN());
            x += v.x;
            y += v.y;
            return *this;
        }

        // We can't do using operator- above, since we don't want to pull in
        // the Point-Point -> Point one so that we can return a vector
        // instead...
        template<typename U>
        auto operator-(const Point2<U> &p) const
        -> Vector2<decltype(T{} - U{})> {
            DCHECK(!p.HasNaN());
            return {x - p.x, y - p.y};
        }

        template<typename U>
        auto operator-(const Vector2<U> &v) const
        -> Point2<decltype(T{} - U{})> {
            DCHECK(!v.HasNaN());
            return {x - v.x, y - v.y};
        }

        template<typename U>
        Point2<T> &operator-=(const Vector2<U> &v) {
            DCHECK(!v.HasNaN());
            x -= v.x;
            y -= v.y;
            return *this;
        }
    };

    // Point3 Definition
    template<typename T>
    class Point3 : public Tuple3<Point3, T> {
    public:
        // Point3 Public Methods
        using Tuple3<Point3, T>::x;
        using Tuple3<Point3, T>::y;
        using Tuple3<Point3, T>::z;
        using Tuple3<Point3, T>::HasNaN;
        using Tuple3<Point3, T>::operator+;
        using Tuple3<Point3, T>::operator+=;
        using Tuple3<Point3, T>::operator*;
        using Tuple3<Point3, T>::operator*=;
        using Tuple3<Point3, T>::operator-;

        Point3() = default;


        Point3(T x, T y, T z) : Tuple3<Point3, T>(x, y, z) {}

        template<typename U>
        explicit Point3(const Point3<U> &p)
                : Tuple3<Point3, T>(T(p.x), T(p.y), T(p.z)) {}

        template<typename U>
        explicit Point3(const Vector3<U> &v)
                : Tuple3<Point3, T>(T(v.x), T(v.y), T(v.z)) {}

        template<typename U>
        auto operator+(const Vector3<U> &v) const

        -> Point3<decltype(T{} + U{})> {
            DCHECK(!v.HasNaN());
            return {x + v.x, y + v.y, z + v.z};
        }

        template<typename U>
        Point3<T> &operator+=(const Vector3<U> &v) {
            DCHECK(!v.HasNaN());
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        template<typename U>
        auto operator-(const Vector3<U> &v) const
        -> Point3<decltype(T{} - U{})> {
            DCHECK(!v.HasNaN());
            return {x - v.x, y - v.y, z - v.z};
        }

        template<typename U>
        Point3<T> &operator-=(const Vector3<U> &v) {
            DCHECK(!v.HasNaN());
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        // We can't do using operator- above, since we don't want to pull in
        // the Point-Point -> Point one so that we can return a vector
        // instead...
        template<typename U>
        auto operator-(const Point3<U> &p) const
        -> Vector3<decltype(T{} - U{})> {
            DCHECK(!p.HasNaN());
            return {x - p.x, y - p.y, z - p.z};
        }
    };

// Point2* Definitions
    using Point2f = Point2<float>;
    using Point2i = Point2<int>;

// Point3* Definitions
    using Point3f = Point3<float>;
    using Point3i = Point3<int>;
}

#endif //JADEHARE_POINT_H
