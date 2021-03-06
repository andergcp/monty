# Monty
[![Contributors][contributors-shield]][contributors-url]

<h3 align="center"> Stack, Queues - LIFO, FIFO </h3>

#### Description
I built a monty files (.m) interpreter with C programming language. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. We implement some op_codes like add, pop and print elements from the stack/queue.

**Monty byte code files**

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

#### Usage
You have to clone this repo and compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic 
``` bash
$ git clone https://github.com/andergcp/monty
$ cd monty
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty 000.m
```
000.m is the file containing monty commands

#### Valid op_codes
- [X] **push**: pushes an element to the stack
- [X] **pall**: prints all the values on the stack
- [X] **pint**: prints the value at the top of the stack
- [X] **pop**:  removes the top element of the stack
- [X] **swap**: swaps the top two elements of the stack
- [X] **add**: adds the top two elements of the stack
- [X] **nop**: doesn’t do anything
- [X] **sub**: subtracts the top element of the stack from the second top element of the stack
- [X] **div**: divides the second top element of the stack by the top element of the stack
- [X] **mul**: multiplies the second top element of the stack with the top element of the stack
- [X] **mod**: computes the rest of the division of the second top element of the stack by the top element of the stack
- [X] **\#:** Every good language comes with the capability of commenting. 
- [X] **pchar**: prints the char at the top of the stack
- [X] **pstr**: prints the string starting at the top of the stack
- [X] **rotl**: rotates the stack to the top
- [X] **rotr**: rotates the stack to the bottom
- [X] **stack**: sets the format of the data to a stack (LIFO). This is the default behavior of the program
- [X] **queue**: sets the format of the data to a queue (FIFO)

#### Examples

``` bash
$ cat 00.m
push 0 working with stacks
push 1
push 2
  push 3
                   pall
      push    4        
pall
pint
$ ./monty 00.m
3
2
1
0
4
3
2
1
0
4
```
``` bash
$ cat 01.m
push 1
push 2
push 3
pall
pop
pint
$ ./monty 01.m
3
2
1
2
```
``` bash
$ cat 02.m
push 1
push 2
push 3
pall
swap
$ ./monty 02.m
3
2
1
2
3
1
```
``` bash
$ cat 03.m
push 1
push 2
push 3
pall
add
pall
$ ./monty 03.m
3
2
1
5
1
```

### Authors
* Anderson Castiblanco [Github](https://github.com/andergcp) - [LinkedIn](https://www.linkedin.com/in/andergcp)

[contributors-shield]: https://img.shields.io/github/contributors/andergcp/monty?style=social&logo=appveyor
[contributors-url]: https://github.com/andergcp/monty/graphs/contributors