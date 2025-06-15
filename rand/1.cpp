#include <iostream>
#include <type_traits>
#include <utility>

template<char... Cs> struct MetaString { 
    static constexpr char data[] = {Cs..., 0}; 
    constexpr operator const char*() const { return data; }
};
template<size_t N, const char (&S)[N], size_t... Is>
constexpr auto make_meta(std::index_sequence<Is...>) { 
    return MetaString<S[Is]...>{}; 
}
#define META_STRING(s) decltype(make_meta<sizeof(s), s>(std::make_index_sequence<sizeof(s)-1>{}))

constexpr char hello[] = "Hello World!";
using SecretType = META_STRING(hello);

template<typename T> struct Printer {
    void operator()() const noexcept(noexcept(std::cout << T{})) {
        []<size_t... Is>(std::index_sequence<Is...>){
            (std::cout << ... << static_cast<char>(T::data[Is]));
        }(std::make_index_sequence<sizeof(T::data)-1>{});
    }
};

int main() try {
    []<typename T>(T){ Printer<T>{}(); }(SecretType{});
} catch(...) { throw; }