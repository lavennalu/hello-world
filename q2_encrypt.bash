#!/bin/bash

# This bash script is used to encrypt a secret message.

#first read the codebook file as the first argument 
#note that the xargs command makes multiple lines into one line
#also the sed command removes all the spaces in the line (found on internet)

1=$(cat codebook.txt | xargs | sed s/[[:space:]]//g)

#second read from the secret message and store it in a variable
2=$(cat secret_message.txt)


#translate 
echo $2 | tr "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" "$1"

