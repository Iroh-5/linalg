#include <gtest/gtest.h>

#include "vec.hpp"

TEST(Basic, DefaultInitialization)
{
    [[maybe_unused]] mvp::Vector<int,                2> v2i;
    [[maybe_unused]] mvp::Vector<char,               2> v2c;
    [[maybe_unused]] mvp::Vector<float,              2> v2f;
    [[maybe_unused]] mvp::Vector<double,             2> v2d;
    [[maybe_unused]] mvp::Vector<long,               2> v2l;
    [[maybe_unused]] mvp::Vector<long long,          2> v2ll;

    [[maybe_unused]] mvp::Vector<unsigned,           2> v2u;
    [[maybe_unused]] mvp::Vector<unsigned char,      2> v2uc;
    [[maybe_unused]] mvp::Vector<unsigned long,      2> v2ul;
    [[maybe_unused]] mvp::Vector<unsigned long long, 2> v2ull;
}

TEST(Basic, AggregateInitialization)
{
    int x = 1;
    int y = 2;
    [[maybe_unused]] mvp::Vector<int, 2> v2i{x, y};
}

TEST(Basic, CopyConstructor)
{
    int x{1};
    mvp::Vector<int, 1> v1i{x};

    auto other{v1i};
    ASSERT_EQ(x, v1i.Get(0));
}

TEST(Basic, CopyAssignment)
{
    int x{1};
    mvp::Vector<int, 1> v1i{x};
    mvp::Vector<int, 1> v1i2;

    v1i2 = v1i;
    ASSERT_EQ(x, v1i2.Get(0));
}

TEST(Basic, MoveConstructor)
{
    int x{1};
    mvp::Vector<int, 1> v1i{x};

    auto other{std::move(v1i)};
    ASSERT_EQ(x, v1i.Get(0));

    // Cannot check moved-from object
}

TEST(Basic, MoveAssignment)
{
    int x{1};
    mvp::Vector<int, 1> v1i{x};
    mvp::Vector<int, 1> v1i2;

    v1i2 = v1i;
    ASSERT_EQ(x, v1i2.Get(0));

    // Cannot check moved-from object
}

TEST(Basic, Comparison)
{
    const int x = 1;
    const int y = 2;

    mvp::Vector<int, 2> a{x, x};
    mvp::Vector<int, 2> b{x, y};
    mvp::Vector<int, 2> c{y, x};

    ASSERT_TRUE (a == a);
    ASSERT_FALSE(a >  a);
    ASSERT_FALSE(a <  a);

    ASSERT_FALSE(b == a);
    ASSERT_TRUE (b >  a);
    ASSERT_FALSE(b <  a);

    ASSERT_FALSE(a == c);
    ASSERT_FALSE(a >  c);
    ASSERT_TRUE (a <  c);
}

TEST(Basic, Get)
{
    int x = 2;
    mvp::Vector<int, 1> v1i{x};
    ASSERT_EQ(x, v1i.Get(0));

    v1i.Get(0) = 3;
    ASSERT_EQ(3, v1i.Get(0));
}

TEST(Basic, At)
{
    int x = 1;
    int y = 2;
    mvp::Vector<int, 2> v2i{x, y};

    ASSERT_EQ(x, v2i.At(0));
    ASSERT_EQ(y, v2i.At(1));

    ASSERT_THROW(v2i.At(2), std::invalid_argument);
}

TEST(Basic, GetD)
{
    int x = 2;
    mvp::Vector<int, 1> v1i{x};
    ASSERT_EQ(1, v1i.GetD());
}

TEST(Math, OperatorUnaryMinus)
{
    mvp::Vector<int, 2> v2i{1, 2};

    ASSERT_EQ((mvp::Vector<int, 2>{-1, -2}), -v2i);
}

TEST(Math, OperatorMul)
{
    mvp::Vector<int, 2> v2i{1, 2};
    mvp::Vector<int, 2> v2i2{3, 4};

    ASSERT_EQ(11, v2i * v2i2);
}

TEST(Math, OperatorPlus)
{
    mvp::Vector<int, 3> v3i{1, 2, 3};
    mvp::Vector<int, 3> v3i2{3, 2, 1};

    ASSERT_EQ((mvp::Vector<int, 3>{4, 4, 4}), v3i + v3i2);
}

TEST(Math, OperatorBinaryMinus)
{
    mvp::Vector<int, 3> v3i{1, 2, 3};
    mvp::Vector<int, 3> v3i2{3, 2, 1};

    ASSERT_EQ((mvp::Vector<int, 3>{-2, 0, 2}), v3i - v3i2);
}
