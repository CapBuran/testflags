#pragma once

#include <stdint.h>
#include <initializer_list>

namespace EnumClassFlags
{
  template<typename EnumClass, typename EnumClassBaseType>
  class Flags
  {
#define flugs_operator_unary(op)\
  constexpr inline Flags operator op(Flags rhs) const noexcept { \
    return Flags(static_cast<EnumClassBaseType>(i) op static_cast<EnumClassBaseType>(rhs.i)); \
  } \
  constexpr inline Flags operator op(EnumClass rhs) const noexcept { \
    return Flags(static_cast<EnumClassBaseType>(i) op static_cast<EnumClassBaseType>(rhs)); \
  } \
  constexpr inline Flags& operator op##=(Flags rhs) noexcept { \
    reinterpret_cast<EnumClassBaseType&>(i) op##= static_cast<const EnumClassBaseType>(rhs.i);  return *this; \
  } \
  constexpr inline Flags& operator op##=(EnumClass rhs) noexcept { \
    reinterpret_cast<EnumClassBaseType&>(i) op##= static_cast<const EnumClassBaseType>(rhs); return *this; \
  }

#define flugs_operator_unary_uint8_t(op)\
  Flags& operator op##=(uint8_t count) noexcept { \
    reinterpret_cast<EnumClassBaseType&>(i) op##= count; return *this; \
  } \
  Flags operator op(uint8_t count) const noexcept { \
    return Flags(static_cast<EnumClassBaseType>(i) op count); \
  }

    static_assert((sizeof(EnumClass) <= sizeof(EnumClassBaseType)),
                  "Flags uses an int as storage, so an enum with underlying: (sizeof(EnumClass) <= sizeof(EnumClassBaseType) "
                  "long long will overflow.");
//    static_assert((std::is_enum<EnumClass>::value), "Flags is only usable on enumeration types.");
//    static_assert((std::is_enum<EnumClass>::EnumClass), "Flags is only usable on enumeration types.");

    struct Private;
    typedef int(Private::*Zero);

  public:

//    typedef EnumClass Values;

    constexpr inline Flags(EnumClass f) noexcept
      : i(f)
    {
    }

    constexpr inline Flags(EnumClassBaseType f = 0) noexcept
      : i(static_cast<EnumClass>(f))
    {
    }

    //constexpr inline Flags(Zero = nullptr) noexcept
    //  : i(static_cast<EnumClass>(nullptr))
    //{
    //}

    constexpr inline Flags(const std::initializer_list<EnumClass> flags) noexcept
      : i(initializer_list_helper(flags.begin(), flags.end()))
    {
    }

    constexpr inline bool operator!() const noexcept
    {
      return !static_cast<EnumClassBaseType>(i);
    }

    constexpr inline operator EnumClassBaseType() const noexcept
    {
      return static_cast<EnumClassBaseType>(i);
    }

    constexpr inline operator EnumClass() const noexcept
    {
      return i;
    }

    constexpr inline operator bool() const noexcept
    {
      return static_cast<EnumClassBaseType>(i) != 0;
    }

    constexpr inline Flags operator~() const noexcept
    {
      return Flags(~static_cast<EnumClassBaseType>(i));
    }

    constexpr inline bool operator==(const Flags& other) const noexcept
    {
      return static_cast<EnumClassBaseType>(i) == static_cast<EnumClassBaseType>(other.i);
    }

    constexpr inline bool operator==(const EnumClass& other) const noexcept
    {
      return static_cast<EnumClassBaseType>(i) == static_cast<EnumClassBaseType>(other);
    }

    constexpr inline bool operator!=(const Flags& other) const noexcept
    {
      return static_cast<EnumClassBaseType>(i) != static_cast<EnumClassBaseType>(other.i);
    }

    constexpr inline bool operator!=(const EnumClass& other) const noexcept
    {
      return static_cast<EnumClassBaseType>(i) != static_cast<EnumClassBaseType>(other);
    }

    flugs_operator_unary(|)
    flugs_operator_unary(&)
    flugs_operator_unary(^)
    flugs_operator_unary_uint8_t(>>)
    flugs_operator_unary_uint8_t(<<)

    constexpr inline bool operator%=(const EnumClass f) const noexcept
    {
      return
        (static_cast<EnumClassBaseType>(i) & static_cast<EnumClassBaseType>(f)) == static_cast<EnumClassBaseType>(f) &&
        (static_cast<EnumClassBaseType>(f) != 0 || static_cast<EnumClassBaseType>(i) == static_cast<EnumClassBaseType>(f));
    }

    constexpr inline bool operator+=(EnumClass f) noexcept
    {
      return *this |= f;
    }

    constexpr inline bool operator-=(EnumClass f) noexcept
    {
      return *this &= ~static_cast<EnumClassBaseType>(f);
    }

    constexpr inline Flags& SetFlags(EnumClass f, bool on) noexcept
    {
      return on ? operator+(f) : operator-(f);
    }

    constexpr inline bool TestFlags(EnumClass f) const noexcept
    {
      return operator%(f);
    }

  private:

    constexpr static inline EnumClass initializer_list_helper(
      typename std::initializer_list<EnumClass>::const_iterator it,
      typename std::initializer_list<EnumClass>::const_iterator end
    ) noexcept
    {
      return (it == end ? EnumClass(0) : (EnumClass(*it) | initializer_list_helper(it + 1, end)));
    }

    EnumClass i;
  };
}

#define DECLARE_FLAGS_OPERATORS(EnumType, EnumClassBaseType) \
 inline EnumType operator|(const EnumType& lhs, const EnumType& rhs) noexcept {return static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) | static_cast<EnumClassBaseType>(rhs)); } \
 inline EnumType operator|=(EnumType& lhs, const EnumType& rhs) noexcept { lhs = static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) | static_cast<EnumClassBaseType>(rhs)); return lhs; } \
 inline EnumType operator&(const EnumType& lhs, const EnumType& rhs) noexcept { return static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) & static_cast<EnumClassBaseType>(rhs)); } \
 inline EnumType operator&=(EnumType& lhs, const EnumType& rhs) noexcept { lhs = static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) & static_cast<EnumClassBaseType>(rhs)); return lhs; } \
 inline EnumType operator^(const EnumType& lhs, const EnumType& rhs) noexcept { return static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) ^ static_cast<EnumClassBaseType>(rhs)); } \
 inline EnumType operator^=(EnumType& lhs, const EnumType& rhs) noexcept { lhs = static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) ^ static_cast<EnumClassBaseType>(rhs)); return lhs; } \
 inline EnumType operator<<(const EnumType& lhs, uint8_t count) noexcept { return static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) << count); }; \
 inline EnumType operator>>(const EnumType& lhs, uint8_t count) noexcept { return static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) >> count); }; \
 inline EnumType operator<<=( EnumType& lhs, uint8_t count) noexcept { lhs = static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) << count); return lhs; }; \
 inline EnumType operator>>=( EnumType& lhs, uint8_t count) noexcept { lhs = static_cast<EnumType>(static_cast<EnumClassBaseType>(lhs) >> count); return lhs; }; \
 inline bool operator%=(const EnumType& lhs, const EnumType& rhs) noexcept { return (static_cast<EnumClassBaseType>(lhs) & static_cast<EnumClassBaseType>(rhs)) == static_cast<EnumClassBaseType>(rhs) && (static_cast<EnumClassBaseType>(rhs) != 0 || static_cast<EnumClassBaseType>(lhs) == static_cast<EnumClassBaseType>(rhs));}  

#define FLAGS08(EnumType) EnumClassFlags::Flags<EnumType, uint8_t> 
#define FLAGS16(EnumType) EnumClassFlags::Flags<EnumType, uint16_t> 
#define FLAGS32(EnumType) EnumClassFlags::Flags<EnumType, uint32_t>
#define FLAGS64(EnumType) EnumClassFlags::Flags<EnumType, uint64_t>

constexpr uint64_t BIT(uint64_t bit) noexcept { return (static_cast<uint64_t>(1) << bit); }
