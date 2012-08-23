#!/bin/sh

#
#   tests/untested.sh
#
#   Дмитрий Изволов.
#   23 августа 2012 года.
#

#       Скрипт находит все заголовки проекта, а затем пытается найти среди испытаний папку,
#   соответствующую этому заголовку. Если папка найдена, то заголовок считается испытанным.

files=(`find ../meta -name "*.hpp"`)
for file in ${files[@]};
do
    directory=${file#*meta/}
    directory=${directory%.hpp*}/
    if ! [ -d $directory ];
    then
        untested_file=${file#../}
        untested_file=${untested_file//\/\//\/}
        echo $untested_file
    fi
done
