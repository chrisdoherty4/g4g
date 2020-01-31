#!/bin/bash

root_dir="$(readlink -f $(dirname "$BASH_SOURCE"))"
build_dir="$root_dir/build"

if [[ -f  "$build_dir" ]]
then
    echo "-- Cleaning 'build' directory"
    rm -rf "$build_dir"
fi

meson "$build_dir"
ninja -C "$build_dir"