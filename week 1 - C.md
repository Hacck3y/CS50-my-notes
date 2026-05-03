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
 
 `\n` → newline (goes to next line)
 `\r` → carriage return (goes to start of same line)
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

- If user enters a valid integer (like `5`)  
    → `scanf` successfully reads **1 value**  
    → returns **1**
- If user enters invalid input (like `abc`)  
    → `scanf` reads **0 values**  
    → returns **0**

| Input  | What happens | `scanf` return |
| ------ | ------------ | -------------- |
| `10`   | valid int    | 1              |
| `-3`   | valid int    | 1              |
| `abc`  | invalid      | 0              |
| `5abc` | reads `5`    | 1              |
it all used in to detect if input is int or sring
```c

// this detect if input if number or not.
if (scanf("%d", &num) != 1)
        {
            printf("Enter number only\n");

            break; // exit loop on invalid input
        }
```
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

# Loops
### For loop
```c
#include <stdio.h>

int main() {
    
    // Loop to print numbers from 1 to 5
    for (int i = 0; i < 5; i++) {
        printf( "%d ", i + 1);
    }
    
    return 0;
}
```

### While loop
```c
#include <stdio.h>
int main() {
    
  // Initialization expression
  int i = 0; 
 
  // Test expression
  while(i <= 5) {
    printf("%d ", i + 1);   
    
    // update expression
    i++;
  } 
  
  return 0;
}
```

### Do while loop
```c
#include <stdio.h>
 
int main() {
    
  // Initialization expression
  int i = 0; 
  
  do
  {
    // loop body
    printf( "%d ", i);   
 
    // Update expression
    i++;
    
    // Condition to check
  }  while (i <= 10);   
  
  return 0;
}
```

## Infinite Loop using all 3 loops
```c
// for loop 

for ( ; ; ) {
		printf("This loop will run forever.");
	}

// while loop
while (1)
		printf("This loop will run forever.\n");
		

// do-while loop
do {
		printf("This loop will run forever.");
	} while (1);
```
## Break 

```c
#include <stdio.h>

int main() {
    for(int i = 1; i <= 10; i++) {
        if(i == 6) {
            break;   // loop stops when i becomes 6
        }
        printf("%d ", i);
    }
    return 0;
}
```

## Break with Nested Loops 

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j > 3)
                break;
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

## Continue
```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 6) {
            continue;   // skip when i is 6
        }
        printf("%d ", i);
    }
    return 0;
}
```

# Functions
```c
// Abstraction

#include <stdio.h>

void meow(void); // prototype [meow fun is at bootom but it still works due to this line.]

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

// Meow once
void meow(void)
{
    printf("meow\n");
}
```
- The initial `void` means that the function does not return any values. The `(void)` means that no values are being provided to the function.
- `void meow(void);`  prototype meow fun is at bootom but it still works due to this line.

# Boring plan case:
Boring plan using `int` software that after can't store value after 4M so it gonna overflow integer and crash .
Solution : use `long int` or `long long`
**Pro-Tip:** Before you swap the types, do a "Find and Replace" carefully. Changing a variable from `int` to `long long` might also require you to update your print statements (e.g., changing `%d` to `%lld` in C).
**EASY SOLUTION:**
reboot the system it start from 0.

# calendar overflow
computer user 32bit integer to track time , 1st JAN 1917 when pc starts. so at 19 JAN 2038 we will overflow 32bit counter . 
Result in crash or more probably data change to 13 DEC 1901.

# GUI program
U can use `gtk`
` sudo apt install libgtk-3-dev`

```c
#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "My First GUI");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.gui", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}
```

```bash
gcc app.c `pkg-config --cflags --libs gtk+-3.0` -o app
```
