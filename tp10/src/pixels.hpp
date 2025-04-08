#pragma once

#include "../lib/image_lib.hpp"

struct RGBA
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
};

struct RGB
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

struct Luma
{
    uint8_t l = 0;
};

template <typename To, typename From>
To convert(const From& stuff);

template <>
RGBA convert<RGBA, RGBA>(const RGBA& x)
{
    return x;
}

template <>
RGB convert<RGB, RGB>(const RGB& x)
{
    return x;
}

template <>
Luma convert<Luma, Luma>(const Luma& x)
{
    return x;
}

template <>
RGB convert<RGB, RGBA>(const RGBA& x)
{
    return { x.r, x.g, x.b };
}

template <>
RGBA convert<RGBA, RGB>(const RGB& x)
{
    return { x.r, x.g, x.b, 255 };
}

template <>
Luma convert<Luma, RGB>(const RGB& x)
{
    return Luma { image_lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& x)
{
    auto tab = image_lib::grayscale_to_rgb(x.l);
    return RGB { tab[0], tab[1], tab[2] };
}

template <>
Luma convert<Luma, RGBA>(const RGBA& x)
{
    return convert<Luma>(convert<RGB>(x));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& x)
{
    return convert<RGBA>(convert<RGB>(x));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    auto tab = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return RGBA { tab[0], tab[1], tab[2], tab[3] };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

template <typename P>
RGBA operator+(const P& lhs, const Luma& mask)
{
    auto result = convert<RGBA>(lhs);
    result.a    = (result.a * mask.l) / 255.0;
    return result;
}