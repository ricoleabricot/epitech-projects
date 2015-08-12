#!/bin/bash

i=1

while [ $i -le 200 ]
do
    ./zappy_ai -p 8081 -n Team1 &
    (( i++ ))
done
