#pragma once

/*
    Simplifies writing of getter/setter code

    Usage:
    class Foo {
        PROPERTY(float, number)
    };

    Foo foo;
    foo.number();
    foo.set_number(12.2);
*/

#define PROPERTY(type, name)         \
private:                             \
  type name##_;                      \
                                     \
public:                              \
  type name() const {                \
    return name##_;                  \
  }                                  \
  void set_##name(const type& val) { \
    name##_ = val;                   \
  }

#define PROPERTY_READ_ONLY(type, name) \
private:                               \
  type name##_;                        \
                                       \
public:                                \
  type name() const {                  \
    return name##_;                    \
  }

#define PROPERTY_WRITE_ONLY(type, name) \
private:                                \
  type name##_;                         \
                                        \
public:                                 \
  void set_##name(const type& val) {    \
    name##_ = val;                      \
  }