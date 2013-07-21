//
//  Дмитрий Изволов.
//  31 декабря 2011 года.
//

#ifndef META_IDENTITY_H
#define META_IDENTITY_H

namespace meta
{
    //!     Тождественная метафункция.
    /*!
            Возвращает тот же самый тип, который был передан ей на вход.
            Время компиляции постоянно, то есть O(1).
     */
    template <typename Type>
    struct identity
    {
        typedef Type type;
    };
} // namespace meta

#endif // META_IDENTITY_H
