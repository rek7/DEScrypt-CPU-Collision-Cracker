# DEScrypt-CPU-Collision-Cracker
## What is DEScrypt-CPU-Collision-Cracker?
A linux based high performance DEScrypt CPU cracker written in c++, it deduces the salt and uses a password list to crack hashes.
### Why not use a rainbow table?
DEScrypt uses by default a two byte salt(comprised of characters [a-zA-Z0-9./] [1]) which would mean that you would need to produce roughly 65,536 unique rainbow tables, as a result its more efficient to use collision cracking to find out the unhashed password.
## Features
+ Ability to crack hashes both from a file and individually 
+ Detects CPU cores
+ Adjustable number of threads
+ Colon-separated output file
+ Clear readable display
+ Average hash rate of 22,000/s with the default 10 threads
## Commands 
        Command         Description
        -------         -----------
        -l=             File Location of HashList
        -i=             Individual Hash
        -w=             File Location of Wordlist
        -o=             File Location of Output File
        -t=             Number of Threads(Default is 10)

## Getting started
###### To Compile: g++ -std=c++11 src/main.cpp -pthread -pcrypt -o DEScrypt
## Screenshots
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/Start1.png)
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/start2.png)
![alt text](https://github.com/rek7/DEScrypt-CPU-Collision-Cracker/blob/master/images/end1.png)

## Citations
[1] - http://man7.org/linux/man-pages/man3/crypt.3.html
