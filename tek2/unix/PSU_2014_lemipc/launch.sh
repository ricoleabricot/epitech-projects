#!/bin/bash

teams_name=("Administrazione" "Olympe" "Epitrafic" "Pierrick, l'AER solitaire")
teams_color=(0 "\033[34mBlue\033[0m" "\033[32mGreen\033[0m" "\033[31mRed\033[0m" "White")
team_id=1

./display &
echo "Team list:"
for team_name in "${teams_name[@]}"
do
    echo -e $team_name "->" ${teams_color[${team_id}]}
    player=1
    while [ $player -le 20 ]
    do
	./lemipc "$team_name" $team_id &
	((player++))
    done
    ((team_id++))
done
