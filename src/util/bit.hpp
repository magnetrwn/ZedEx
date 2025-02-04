#ifndef BIT_HPP_
#define BIT_HPP_

#include <cstdint>

#if __cplusplus < 202002L

namespace bit {
    template <typename T> constexpr bool is(T value, uint8_t bit) { return value & (1 << bit); }

    template <typename T> constexpr T set(T value, uint8_t bit) { return value | (1 << bit); }
    template <typename T> constexpr void set(T* value, uint8_t bit) { *value |= (1 << bit); }

    template <typename T> constexpr T reset(T value, uint8_t bit) { return value & ~(1 << bit); }
    template <typename T> constexpr void reset(T* value, uint8_t bit) { *value &= ~(1 << bit); }

    template <typename T> constexpr T toggle(T value, uint8_t bit) { return value ^ (1 << bit); }
    template <typename T> constexpr void toggle(T* value, uint8_t bit) { *value ^= (1 << bit); }
}

#else

#include <concepts>

namespace bit {
    template <typename T>
    concept bit_t = requires(T value, uint8_t bit) {
        { value & (1 << bit) } -> std::convertible_to<bool>;   /* bit::is()     */
        { value | (1 << bit) } -> std::convertible_to<T>;      /* bit::set()    */
        { value & ~(1 << bit) } -> std::convertible_to<T>;     /* bit::reset()  */
        { value ^ (1 << bit) } -> std::convertible_to<T>;      /* bit::toggle() */
    };

    template <bit_t T> constexpr bool is(T value, uint8_t bit) { return value & (1 << bit); }

    template <bit_t T> constexpr T set(T value, uint8_t bit) { return value | (1 << bit); }
    template <bit_t T> constexpr void set(T* value, uint8_t bit) { *value |= (1 << bit); }

    template <bit_t T> constexpr T reset(T value, uint8_t bit) { return value & ~(1 << bit); }
    template <bit_t T> constexpr void reset(T* value, uint8_t bit) { *value &= ~(1 << bit); }

    template <bit_t T> constexpr T toggle(T value, uint8_t bit) { return value ^ (1 << bit); }
    template <bit_t T> constexpr void toggle(T* value, uint8_t bit) { *value ^= (1 << bit); }
}

#endif

#endif