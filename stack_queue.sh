#!/bin/sh

# stack push
set -- apple "$@"
set -- banana "$@"
set -- carrot "$@"
# stack pop
echo $1; shift;

# queue push
set -- "$@" apple
set -- "$@" banana
set -- "$@" carrot
# queue pop
echo $1; shift;
