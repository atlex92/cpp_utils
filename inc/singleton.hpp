
#pragma once
/*
    Meyer's threadsafe Singleton pattern
    Usage:
    class Foo : public Singleton<Foo> {
        friend class Singleton;
        private:
            Foo();
    };
*/

template <typename T>
class Singleton {
public:
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  static T& instance() {
    static T instance;
    return instance;
  }

protected:
  Singleton() = default;
};