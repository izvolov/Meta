//
//  meta/types/integer.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_INTEGER_H
#define META_TYPES_INTEGER_H

namespace meta
{
    //!     Целое число.
    /*!
     */
    template <int Number>
    struct integer
    {
        static constexpr int value = Number;
    };
} // namespace meta

#endif // META_TYPES_INTEGER_H
