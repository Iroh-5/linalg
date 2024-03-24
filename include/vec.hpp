#pragma once

#include <array>
#include <concepts>
#include <limits>
#include <stdexcept>

namespace mvp {

template <typename T, std::size_t D>
requires ((std::floating_point<T> || std::integral<T>) && D > 0)
class Vector
{
public:
    constexpr Vector() noexcept
        : m_values{} {}

    template <typename... S>
    requires (sizeof...(S) == D && (std::same_as<S, T> && ...))
    constexpr Vector(S... args) noexcept
        : m_values{{args...}} {}

    constexpr auto operator <=>(const Vector<T, D>& other) const = default;

    constexpr T Get(std::size_t ind) const noexcept
    {
        return m_values[ind];
    }

    T& Get(std::size_t ind) noexcept
    {
        return m_values[ind];
    }

    const T& At(std::size_t ind) const
    {
        if (ind >= GetD())
        {
            throw std::invalid_argument{"Passed bad index"};
        }

        return m_values[ind];
    }

    T& At(std::size_t ind)
    {
        if (ind >= GetD())
        {
            throw std::invalid_argument{"Passed bad index"};
        }

        return m_values[ind];
    }

    std::size_t GetD() const noexcept
    {
        return D;
    }

    Vector<T, D> operator -() const noexcept
    {
        Vector<T, D> res;
        for (std::size_t i = 0; i < GetD(); ++i)
        {
            res.Get(i) = -this->Get(i);
        }

        return res;
    }

    T operator *(const Vector<T, D>& other) const noexcept
    {
        T res{0};
        for (std::size_t i = 0; i < GetD(); ++i)
        {
            res += this->Get(i) * other.Get(i);
        }

        return res;
    }

    Vector<T, D> operator +(const Vector<T, D>& other) const noexcept
    {
        Vector<T, D> res;
        for (std::size_t i = 0; i < GetD(); ++i)
        {
            res.Get(i) = this->Get(i) + other.Get(i);
        }

        return res;
    }

    Vector<T, D> operator -(const Vector<T, D>& other) const noexcept
    {
        return *this + (-other);
    }

private:
    std::array<T, D> m_values;
};

} // namespace mvp
