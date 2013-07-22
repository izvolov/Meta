#!/bin/sh

#
#   Дмитрий Изволов.
#   21 июля 2013 года.
#

USAGE="Использование: $0 файл"

if [[ $# != 1 ]];
then
    echo $USAGE
else
    GUARD=$1
    GUARD=${GUARD////_}
    GUARD=${GUARD//./_}
    GUARD=`echo $GUARD | tr "[:lower:]" "[:upper:]"`

    echo $GUARD
fi
