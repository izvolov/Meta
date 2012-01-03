//
//  meta/common/identity.h
//
//  Дмитрий Изволов.
//  31 декабря 2011 года.
//

#ifndef META_IDENTITY_H
#define META_IDENTITY_H

namespace meta
{
    //!
    /*!
     */
    template <typename Type>
    struct identity
    {
        typedef Type type;
    };
} // namespace meta

#endif // META_IDENTITY_H
