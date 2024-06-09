#pragma once

#include <ranges>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <charconv>
#include <system_error>

namespace SDLUtils {
    std::vector<std::string> split(const std::string &input) noexcept {
        std::istringstream buffer(input);
        std::vector<std::string> ret;

        std::copy(std::istream_iterator<std::string>(buffer),
                  std::istream_iterator<std::string>(),
                  std::back_inserter(ret));

        return ret;
    }

    inline std::string ltrim(const std::string &s) noexcept {
        std::string sCopy = s;
        sCopy.erase(sCopy.begin(), std::find_if(sCopy.begin(), sCopy.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        return sCopy;
    }

    inline std::string rtrim(const std::string &s) noexcept {
        std::string sCopy = s;
        sCopy.erase(std::find_if(sCopy.rbegin(), sCopy.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), sCopy.end());
        return sCopy;
    }

    inline std::string trim(const std::string &s) noexcept {
        std::string trim = rtrim(s);
        return ltrim(trim);
    }

    std::vector<std::string> splitn(const std::string &s, char delimiter, int max_splits) {
        std::vector<std::string> result;
        size_t start = 0;
        size_t end = s.find(delimiter);
        int splits = 0;

        while (end != std::string::npos && splits < max_splits) {
            result.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(delimiter, start);
            splits++;
        }
        
        result.push_back(s.substr(start));
        
        return result;
    }


    std::vector<std::string> splitf(const std::string& s, char delimiter) {
        std::vector<std::string> parts;
        size_t start = 0;
        size_t end = 0;

        while (end != std::string::npos) {
            end = s.find(delimiter, start);
            if (end != std::string::npos) {
                parts.push_back(s.substr(start, end - start));
                start = end + 1;
            }
        }

        parts.push_back(s.substr(start));

        return parts;
    }

    template <typename T>
    std::optional<T> strToInt(const std::string& str) {
        T result;

        auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);

        if (ec == std::errc()) {
            return result;
        } else {
            return std::nullopt;
        }
    }

    template <typename T>
    std::optional<T> hexStrToInt(const std::string& str) {
        if (str.size() < 3 || (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))) {
            return std::nullopt;
        }

        T result;
        auto [ptr, ec] = std::from_chars(str.data() + 2, str.data() + str.size(), result, 16);

        if (ec == std::errc()) {
            return result;
        } else {
            return std::nullopt;
        }
    }

    /// Counts how many bits an integer uses.
    template<typename T>
    size_t countBitsTaken(T val) noexcept {
        size_t i = 0;
        while (val != 0) {
            val = val >> 1;
            i++;
        }
        return i;
    }
}
