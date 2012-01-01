//
//  meta/types/min_value.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MIN_VALUE_H
#define META_TYPES_MIN_VALUE_H

#include <meta/types/implementation/min_value.hpp>

namespace meta
{    
    //!
    /*!
     */
    template <typename Map>
    struct min_value
    {
        typedef typename impl::min_value<typename Map::root>::type type;
    };
} // namespace meta

#endif // META_TYPES_MIN_VALUE_H
