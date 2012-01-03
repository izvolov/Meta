//
//  meta/common/max.h
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_MAX_H
#define META_MAX_H

namespace meta
{
    //!
    /*!
     */
    template <int ... Numbers>
    struct max;
    
    template <int First, int ... Others>
    struct max <First, Others ...>
    {
        static constexpr int others_max = max<Others ...>::value;
        
        static constexpr int value = First > others_max ? First : others_max;
    };
    
    template <int First, int Second>
    struct max <First, Second>
    {
        static constexpr int value = First > Second ? First : Second;
    };
    
    template <int Number>
    struct max <Number>
    {
        static constexpr int value = Number;
    };
} // namespace meta

#endif // META_MAX_H
