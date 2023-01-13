#ifndef CPP_SP2_CONCEPTS_H
#define CPP_SP2_CONCEPTS_H
#include <cstdlib>

/** Used with MPInt for 'unlimited' precision */
constexpr size_t UNLIMITED = 0;

template<size_t S>
concept AtLeastFourBytes = (S >= 4) || (S == UNLIMITED);

#endif //CPP_SP2_CONCEPTS_H
