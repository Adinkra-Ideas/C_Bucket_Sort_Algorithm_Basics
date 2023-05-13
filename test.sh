#!/bin/sh
make
make checker
clear

echo "=================== Testing Sorter =================="
echo "This First Test Should Output The Shortest Possible Moves Required to sort"
echo "the input '20 400 56 89 0 98' in ascending order on a stack"
echo 
ARG="20 400 56 89 0 98"; ./sorter $ARG
echo
# The "tester" executable copies the moves outputed by the "sorter" executable,
# then it attempts to use these moves to sort the integers that were received by
# the "sorter" executaböe initially. If the numbers got sorted after applying
# the moves, it outputs "OK", else it outputs "Error"
echo "=================== Testing With Tester =================="
echo "This Next Test Should Output 'OK'"
ARG="20 400 56 89 0 98"; ./sorter $ARG | ./tester $ARG
echo
echo "The Next Test Should Output 'Error'"
echo "pb ra rra" | ./tester $ARG
