#pragma once

#include <cmath>
#include <type_traits>

template <typename T, unsigned int window,
          class = typename std::enable_if<std::is_arithmetic<T>::value && window != 0>::type>
class MAFilter {
public:
  T process(const T new_value) {
    if (!is_init_) {
      filtered_value_ = new_value;
      is_init_ = true;
    } else {
      const float delta{static_cast<float>(new_value) - filtered_value_};
      const float correction{delta / window};
      filtered_value_ += std::is_floating_point<T>::value ? correction : std::round(correction);
    }
    return filtered_value_;
  }

  T filteredValue() const {
    return filtered_value_;
  }

  void reset() {
    filtered_value_ = {};
    is_init_ = false;
  }

  bool isInitialized() const {
    return is_init_;
  }

private:
  T filtered_value_{};
  bool is_init_{false};
};