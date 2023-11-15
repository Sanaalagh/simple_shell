Simple Shell Project 

It is about a simple UNIX command interpreter.

A shell is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program of the type sh (Bourne Shell) will be developed. Users typically interact with a shell using a terminal emulator that is used for entering data into and displaying or printing data from, a computer or a computing system.

TASKS:

Task 0. README, man, AUTHORS
Task 1. Betty would be proud
Task 2. Simple shell 0.1
Task 3. Simple shell 0.2
Task 4. Simple shell 0.3
Task 5. Simple shell 0.4
Task 6. Simple shell 1.0
Task 7. What happens when you type ls -l in the shell

Allowed Functions : 

execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fork (man 2 fork)
free (man 3 free)
getline (man 3 getline)
isatty (man 3 isatty)
malloc (man 3 malloc)
perror(man 3 perror)
signal (man 2 signal)
stat (__ xstat) (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
write (man 2 write)
Compilation :

The hell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Testing :

The shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
