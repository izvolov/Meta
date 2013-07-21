//
//  Дмитрий Изволов.
//  18 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_DIGITS_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_DIGITS_HPP

namespace meta
{
    namespace impl
    {
        template <int Number, int Base = 10>
        struct digits;
        {
            static constexpr int value = 1 + digits<Number / Base, Base>::value;
        };
        
        template <int Base>
        struct digits <0, Base>
        {
            static constexpr int value = 0;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_DIGITS_HPP
