#pragma once

#include <tuple>

inline bool operator<(const FIntVector& lhs, const FIntVector& rhs)
{
    return std::tie(lhs.X, lhs.Y, lhs.Z) < std::tie(rhs.X, rhs.Y, rhs.Z);
}
