# DEScrypt-CPU-Collision-Cracker
## What is DEScrypt-CPU-Collision-Cracker?
A linux based DEScrypt CPU cracker that uses a password list to crack hashes
## Features
+ Ability to crack hashes both from a file and individual 
+ Detects CPU cores
+ Adjustable number of threads

## Commands 
        Command         Description
        -------         -----------
        -l=             File Location of HashList
        -i=             Individual Hash
        -w=             File Location of Wordlist
        -o=             File Location of Output File
        -t=             Number of Threads(Default is 10)

## Getting started
###### To Compile: g++ -std=c++11 main.cpp -pthread -pcrypt -o DEScrypt

## Screenshots
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/Start1.png)
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/start2.png)
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/end1.png)
