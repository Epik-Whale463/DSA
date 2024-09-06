#!/bin/sh

file=$1  # The first argument passed to the script
gcc $file -o ${file%.c}

if [ $? -eq 0 ]; then
    echo "Compiled Successfully"
    ./${file%.c}  # Run the compiled file
else
    echo "Compilation failed"
fi
