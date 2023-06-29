#!/bin/bash

colors=("30" "31" "32" "33" "34" "35" "36" "37")
backgrounds=("40" "41" "42" "43" "44" "45" "46" "47")
mould=("160;82;45" "139;69;19" "128;0;0") 

echo -e "\033[3;4mbasic colors\033[0m:"
for c in "${colors[@]}"; do
	echo -ne "\033[${c}m${c}\033[0m"
done
echo -n "   "
for b in "${backgrounds[@]}"; do
	echo -ne "\033[${b}m${b}\033[0m"
done
echo
echo
echo -e "\033[3;4mmould pallete\033[0m:"
echo
for h in "${mould[@]}"; do
	echo -ne "  \033[48;2;${h}m${h}\033[0m"
done
echo

