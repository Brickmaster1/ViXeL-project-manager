#pragma once

#include <memory>
#include <typeinfo>
#include <variant>
#include <type_traits>

struct Rect2d {
    int x;
    int y;
};

struct Pos2d {
    int x;
    int y;
};

// template <typename Variant>
// decltype(auto) getSpecificType(Variant& v) {
//     return std::visit([](auto& obj) -> decltype(auto) {
//         return *obj; // Dereference shared_ptr and return the specific type
//     }, v);
// }