#ifndef __VEC2_H__
#define __VEC2_H__

#include <cmath>

struct vec2 {
    float x = 0.f;
    float y = 0.f;

    constexpr vec2() = default;
    constexpr vec2(float x, float y) : x(x), y(y) {}
    constexpr vec2(const vec2& rhs) noexcept : x(rhs.x), y(rhs.y) {}
    constexpr vec2(vec2&& rhs) noexcept : x(rhs.x), y(rhs.y) { rhs.x = 0.f; rhs.y = 0.f; }

    inline constexpr vec2 operator+(const vec2& rhs) const noexcept {
        return vec2{ x + rhs.x, y + rhs.y };
    }

    inline constexpr vec2 operator+(float rhs) const noexcept {
        return vec2{ x + rhs, y + rhs };
    }
    
    inline constexpr vec2 operator-(const vec2& rhs) const noexcept {
        return vec2{ x - rhs.x, y - rhs.y };
    }

    inline constexpr vec2 operator-(float rhs) const noexcept {
        return vec2{ x - rhs, y - rhs };
    }

    inline constexpr vec2 operator*(const vec2& rhs) const noexcept {
        return vec2{ x * rhs.x, y * rhs.y };
    }

    inline constexpr vec2 operator*(float rhs) const noexcept {
        return vec2{ x * rhs, y * rhs };
    }

    inline constexpr vec2 operator/(const vec2& rhs) const noexcept {
        return vec2{ x / rhs.x, y / rhs.y };
    }
    
    inline constexpr vec2 operator/(float rhs) const noexcept {
        return vec2{ x / rhs, y / rhs };
    }

    inline vec2& operator=(const vec2& rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    inline vec2& operator=(vec2&& rhs) noexcept {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    inline constexpr vec2& operator+=(const vec2& rhs) noexcept {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    inline constexpr vec2& operator+=(float rhs) noexcept {
        x += rhs;
        y += rhs;
        return *this;
    }

    inline constexpr vec2& operator-=(const vec2& rhs) noexcept {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    inline constexpr vec2& operator-=(float rhs) noexcept {
        x -= rhs;
        y -= rhs;
        return *this;
    }

    inline constexpr vec2& operator*=(const vec2& rhs) noexcept {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }

    inline constexpr vec2& operator*=(float rhs) noexcept {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    inline constexpr vec2& operator/=(const vec2& rhs) noexcept {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    inline constexpr vec2& operator/=(float rhs) noexcept {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    inline float length() const {
        return std::sqrt(x * x + y * y);
    }

    inline vec2 normalized() const {
        const float len = length();
        return vec2(x / len, y / len);
    }
};

#endif // __VEC2_H__