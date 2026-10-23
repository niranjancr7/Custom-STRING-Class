Custom STRING Class in C++

This project implements a custom `STRING` class in C++ to demonstrate object-oriented programming concepts, dynamic memory allocation, deep copying, operator overloading, and string manipulation.

The class manages strings using dynamically allocated character arrays instead of relying on the standard C++ `string` class or standard C string manipulation functions for the required operations.

Features

1. Constructors and Destructor

Default Constructor: Creates an empty string.
Parameterized Constructor: Initializes a string using a character array.
Copy Constructor: Creates a deep copy of an existing `STRING` object.
Destructor: Releases dynamically allocated memory.

2. Operator Overloading
The following operators are overloaded:

`=` — Assignment
`+` — String concatenation
`[]` — Character access and modification
`==` — Equality comparison
`!=` — Inequality comparison
`>` — Greater-than comparison
`<` — Less-than comparison
`>=` — Greater-than-or-equal comparison
`<=` — Less-than-or-equal comparison
`>>` — Input
`<<` — Output

3. Custom String Manipulation Functions

The project implements the following functions using the custom `STRING` class:

  Function                Description 

`strcpy()` - Copies one string into another.
`strncpy()` - Copies at most a specified number of characters. 
`strcmp()` - Compares two strings.
`strncmp()` - Compares up to a specified number of characters.
`strcat()` - Appends one string to another.
`strncat()` - Appends at most a specified number of characters.
`strrev()` - Reverses a string.
`strupr()` - Converts lowercase English letters to uppercase.
`strlwr()` - Converts uppercase English letters to lowercase.
`strchr()` - Finds the first occurrence of a character.
`strrchr()` - Finds the last occurrence of a character.
`strstr()` - Finds the first occurrence of a substring.
`strlen()` - Calculates the length of a string.

Technologies Used

- Programming Language: C++
- Memory Management: Dynamic memory allocation using `new[]` and `delete[]`
- Concepts:** Classes, objects, constructors, destructors, deep copying, friend functions, and operator overloading
- Development Environment: Ubuntu Linux
- Compiler: GNU C++ Compiler (`g++`)

Concepts Demonstrated

This project demonstrates practical applications of:

- Object-oriented programming in C++.
- Dynamic memory allocation and deallocation.
- Deep copying using a copy constructor.
- Assignment operator overloading.
- String concatenation and comparison through operator overloading.
- Friend functions for accessing private class members.
- Character arrays and null-terminated strings.
- Manual string manipulation using loops and pointers.
- Memory management and resource ownership.

earning Objectives

The main objective of this project is to understand how string handling works internally and how a custom string class can be implemented without depending on standard string manipulation functions for its core operations.

It also provides practical experience with dynamic memory management, operator overloading, constructors, destructors, and deep copying in C++.

Author

Niranjan DN

GitHub: [@niranjancr7](https://github.com/niranjancr7)

*This project was developed for learning and practicing C++ programming concepts.*
