//
//  meta/types/rational.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_RATIONAL_HPP
#define META_TYPES_RATIONAL_HPP

namespace meta
{
    //!     Рациональное число.
    /*!
     */
    template <int Numerator, int Denominator>
    struct rational
    {
//        static constexpr double value = static_cast<double>(Numerator) / Denominator;
        
        static constexpr int numerator = Numerator;
        static constexpr int denominator = Denominator;
    };
} // namespace meta

#endif // META_TYPES_RATIONAL_HPP
