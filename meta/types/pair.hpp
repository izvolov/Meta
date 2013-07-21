//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_PAIR_HPP
#define META_TYPES_PAIR_HPP

namespace meta
{
    //!     Пара.
    /*!
     */
    template <typename First, typename Second>
    struct pair
    {
        typedef First first;
        typedef Second second;
    };
} // namespace meta

#endif // META_TYPES_PAIR_HPP
