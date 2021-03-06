#!/bin/bash

# This bash script is used to encrypt a secret message.

#first read the codebook file as the first argument 
#note that the xargs command makes multiple lines into one line
#also the sed command removes all the spaces in the line (found on internet)

code=$(cat $1 | xargs | sed s/[[:space:]]//g)

#second read from the secret message and store it in a variable
msg=$(cat $2)


#translate 
echo msg | tr "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" "$code"

