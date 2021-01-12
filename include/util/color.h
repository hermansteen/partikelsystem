#ifndef __COLOR_H__
#define __COLOR_H__

struct Color {
    constexpr Color() = default;
    constexpr Color(float r, float g, float b) : r(r), g(g), b(b) {}
    constexpr Color(const Color& rhs) noexcept : r(rhs.r), g(rhs.g), b(rhs.b) {}
    constexpr Color(Color&& rhs) noexcept
        : r(rhs.r), g(rhs.g), b(rhs.b)
    {
        rhs.r = 1.f;
        rhs.g = 1.f;
        rhs.b = 1.f;
    }

    inline Color& operator=(const Color& rhs) {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        return *this;
    }

    inline Color& operator=(Color&& rhs) noexcept {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        return *this;
    }

    float r = 1.f;
    float g = 1.f;
    float b = 1.f;
};

#endif // __COLOR_H__