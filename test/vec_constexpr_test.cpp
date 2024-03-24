#include <gtest/gtest.h>

#include "vec.hpp"

TEST(ConstexprBasic, DefaultInitialization)
{
    [[maybe_unused]] constexpr mvp::Vector<int,                2> v2i;
    [[maybe_unused]] constexpr mvp::Vector<char,               2> v2c;
    [[maybe_unused]] constexpr mvp::Vector<float,              2> v2f;
    [[maybe_unused]] constexpr mvp::Vector<double,             2> v2d;
    [[maybe_unused]] constexpr mvp::Vector<long,               2> v2l;
    [[maybe_unused]] constexpr mvp::Vector<long long,          2> v2ll;

    [[maybe_unused]] constexpr mvp::Vector<unsigned,           2> v2u;
    [[maybe_unused]] constexpr mvp::Vector<unsigned char,      2> v2uc;
    [[maybe_unused]] constexpr mvp::Vector<unsigned long,      2> v2ul;
    [[maybe_unused]] constexpr mvp::Vector<unsigned long long, 2> v2ull;
}

TEST(ConstexprBasic, AggregateInitialization)
{
    [[maybe_unused]] constexpr mvp::Vector<int,    2> v2i{1, 2};
    [[maybe_unused]] constexpr mvp::Vector<double, 2> v2d{1.0, 2.0};
    [[maybe_unused]] constexpr mvp::Vector<float,  2> v2f{1.0f, 2.0f};
}


TEST(ConstexprBasic, CopyConstructor)
{
    constexpr mvp::Vector<int, 1> v1i{1};

    const auto other{v1i};
    static_assert(1 == v1i.Get(0));
}

TEST(ConstexprBasic, MoveConstructor)
{
    constexpr mvp::Vector<int, 1> v1i{1};

    const auto other{std::move(v1i)};
    static_assert(1 == v1i.Get(0));

    // Cannot check moved-from object
}

TEST(ConstexprBasic, Comparison)
{
    constexpr mvp::Vector<int, 2> a{1, 1};
    constexpr mvp::Vector<int, 2> b{1, 2};
    constexpr mvp::Vector<int, 2> c{2, 1};

    static_assert(a == a);
    static_assert(!(a > a));
    static_assert(!(a <  a));

    static_assert(!(b == a));
    static_assert(b >  a);
    static_assert(!(b <  a));

    static_assert(!(a == c));
    static_assert(!(a >  c));
    static_assert(a <  c);
}

TEST(ConstexprBasic, Get)
{
    constexpr mvp::Vector<int, 2> v1i{1, 2};

    static_assert(1 == v1i.Get(0));
    static_assert(2 == v1i.Get(1));
}

// TODO: Add math tests
