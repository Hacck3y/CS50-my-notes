# Installing C in windows
### Option 1 — Install MinGW (recommended for gcc)
```bash
winget install -e --id BrechtSanders.WinLibs

# Add GCC to PATH 
# TEMP : 
$env:Path += ";C:\Program Files\WinLibs\mingw64\bin"

# permanent : 
- Search Environment Variables
- Edit Path
  

C:\Program Files\WinLibs\mingw64\bin
```

### Option 2 — Install via MSYS2 (more powerful, package manager)
```bash
winget install -e --id MSYS2.MSYS2

# in windows search and open **MSYS2 MINGW64** shell and run:

pacman -S mingw-w64-x86_64-gcc

# Path to add to  Environment Variables

C:\msys64\mingw64\bin
```

Install VS code + code runner extension :
Open vs code setting, `Code-runner: Save File Before Run`  and turn on it.
# Source Code 
 Where humans write _source code_, a list of instructions for the computer that is human readable, machines only understand what we can now call _machine code_. This machine code is a pattern of ones and zeros that produces a desired effect.
 IN `C`: 
 ```
 source code -> compile -> machine code -> run
 ```

# HEll0 world
Basic code :
```c
#include <stdio.h> // Include the standard input/output library

int main(void) { // The main function is the entry point of the program
    printf("Hello, World!\n");
    return 0; // Return 0 indicates that the program ended successfully
}
```

`#include <stdio.h>` -> Header file !! standard I/O
https://www.w3schools.com/c/c_ref_stdio.php

`void` means **“no parameters”**.

` return 0` ? // Return 0 indicates that the program ended successfully
When the program execute done run :
```bash
# powershell
echo $LASTEXITCODE 
# cmd 
echo %ERRORLEVEL%
# linux
echo $?
```

U can use other word instant 0 too and if return same MEAN program run successfully no error. probably can help in debugging too.  BUT u can't write like `09` error `90` or `9` is OK!!

`\n` -> For next line.
`\r` -> move cursue to left
`\"` -> escape char to print `"`
`\'` -> escape char to print `'`
`\\` -> escape char to print `\`

### User Input : 
```c
#include <stdio.h>

int main(void) {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("You entered: %d\n", x);
    return 0;
}
```

`%d` -> input INT. So on !! 
```
| Specifier | Data Type     |
|-----------|--------------|
| %d        | int          |
| %f        | float        |
| %lf       | double       |
| %c        | char         |
| %s        | char[]       |
| %u        | unsigned int |
| %p        | void *       |
| %x        | int          |
```

> Store INPUT into a variable

First declare it . `int x;`   `scanf("%d", &x);`
`&x` -> address of variable (mandatory) so input value can store on it.

## Types
There are many data types that are available within C:
```bash
bool
char
float
int
long
string
```


`printf` allows for many format codes. Here is a non-comprehensive list of ones you may utilize in this course:
```
%c
%f
%i
%li
%s
```

`%c` is used for char (character) variables. 
`%f` is used for float (floating-point) variables. 
`%i` is used for int or integer variables. 
`%li` is used for long integer variables. 
`%s` is used for string variables. 
You can find out more about this on the [Manual Pages](https://manual.cs50.io/).

# Conditions 
SYNTEX :
```c
if (condition)
{
    /* code */
}

else if (condition)
{
    /* code */
}
else {
    /* code */
}
```
CODE : U can play with it.
```c

#include <stdio.h>

int main(){
    if (22 == 22)
{
    printf("left one winn!");
}

else if (2==2)
{
    printf("really 2=2");
}

else{
    printf("righ win!");
}

}
```
