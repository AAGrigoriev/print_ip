#pragma once

#include <iostream>
#include <tuple>
#include <type_traits>

#include "traits.hpp"

namespace print_ip {

/*!
    @brief Print IP
    Print Integer Value
    @param[in] - integer (see is_integral)
    @param[in] - out Output stream
 */
template <typename T>
requires(std::is_integral_v<T>) void print_ip(T integer,
                                              std::ostream& out = std::cout) {
  const std::size_t count_bytes = sizeof(T);

  union {
    unsigned char bytes[count_bytes];
    T value;
  };

  value = integer;

  for (std::size_t i = count_bytes - 1; i > 0; --i) {
    out << std::to_string(bytes[i]) << ".";
  }
  out << std::to_string(*bytes);
}

/*!
   @brief Print IP
   Print for any type with method cbegin() and cend()
   @param[in] - T STL container
   @param[in] - out Output stream
*/
template <has_begin_end T>
void print_ip(const T& container, std::ostream& out = std::cout) {
  auto iterBeg = container.cbegin();
  for (auto iter = iterBeg; iter != container.end(); ++iter) {
    if (iter != iterBeg) {
      out << ".";
    }
    out << std::to_string(*iter);
  }
}

/*!
    @brief Print IP
    Print std::string
    @param[in] - T std::string
    @param[in] - out Output stream
*/
template <typename T>
requires(std::same_as<T, std::string>) void print_ip(
    const T& str,
    std::ostream& out = std::cout) {
  out << str;
}

class A {};

/*!
    @brief Print IP
    Print for any type with method cbegin() and cend()
    @param[in] - T std::tuple
    @param[in] - out Output stream
 */
template <instantiation_of<std::tuple> T>
void print_ip(const T& tuple, std::ostream out = std::cout) {
  // for each tuple
}

}  // namespace print_ip
