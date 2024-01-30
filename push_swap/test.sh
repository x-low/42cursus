#!/bin/bash

num_runs=1000
total_lines=0

for ((i=1; i<=$num_runs; i++)); do
    random_numbers=$(shuf -i 1-1000 -n 500)
    args=($random_numbers)
    line_count=$(./push_swap "${args[@]}" | wc -l)
    total_lines=$((total_lines + line_count))
done

average_lines=$((total_lines / num_runs))

echo "average result per run: $average_lines"
