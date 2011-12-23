//
//  meta/types/type_list.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TYPES_TYPE_LIST_H
#define META_TYPES_TYPE_LIST_H

namespace meta
{
    //!     Список типов.
    /*!
            Предназначен для хранения типов и передачи их между метафункциями.
     */
    template <typename ... Types>
    struct type_list
    {
    };
} // namespace meta

#endif // META_TYPES_TYPE_LIST_H
