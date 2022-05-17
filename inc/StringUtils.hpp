#pragma once

#include "stdint.h"
#include <string>
#include <cstdarg>

class StringUtils {

    public:
        static std::string newLineStr(const char* const = "");
        static bool containsSpace(const std::string& str);
        static bool caseInsEquals (const std::string& first, const std::string& second);
        static bool toUint32(const std::string& str, uint32_t &val);
        static bool toUint64(const std::string& str, uint64_t &val);
        static bool hexToUint64(const std::string& str, uint64_t &out);
        static void removeEndingPaddings(std::string& in);

        static std::string fromUint32(const uint32_t val);
        static std::string fromUint64(const uint64_t val);
        static std::string uint64ToHex(const uint64_t val);
        static std::string binaryToHex(const uint8_t* bytes, const size_t len);

        static std::string format(const char* const fmt, ...);
        static std::string format(const char* const fmt, va_list args);

        static size_t replace(std::string& src, const std::string& from, const std::string& to);

        static size_t countSymbols(const std::string& str, const char sym);
};