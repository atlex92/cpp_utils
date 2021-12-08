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

#define PROPERTY(type,name) \
private:\
    type _##name;\
public:\
    type #name() const {\
        return _##name;\
    }\
    void set_##name(const type& val) {\
        _##name = val;\
    }

#define PROPERTY_READ_ONLY(type,name) \
private:\
    type _##name;\
public:\
    type #name() const {\
        return _##name;\
    }

#define PROPERTY_WRITE_ONLY(type,name) \
private:\
    type _##name;\
public:\
    void set_##name(const type& val) {\
        _##name = val;\
    }