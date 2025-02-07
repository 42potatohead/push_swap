#!/bin/bash

while IFS= read -r line; do
    if [ ! -z "$line" ]; then
        echo "Testing set: $line"
        ARG="$line"
        ./push_swap $ARG | ./checker_linux $ARG
    fi
done < "sets.txt"
