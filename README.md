# C++ - Module 06

## C++ casts

_Summary:
This document contains the exercises of Module 06 from C++ modules._

```
Version: 5.
```

## Contents

- I Introduction
- II General rules
- III Additional rule
- IV Exercise 00: Conversion of scalar types
- V Exercise 01: Serialization
- VI Exercise 02: Identify real type


# Chapter I

# Introduction

_C++ is a general-purpose programming language created by Bjarne Stroustrup as an ex-
tension of the C programming language, or "C with Classes" (source: Wikipedia)._

The goal of these modules is to introduce you to **Object-Oriented Programming**.
This will be the starting point of your C++ journey. Many languages are recommended
to learn OOP. We decided to choose C++ since it’s derived from your old friend C.
Because this is a complex language, and in order to keep things simple, your code will
comply with the C++98 standard.
We are aware modern C++ is way different in a lot of aspects. So if you want to
become a proficient C++ developer, it’s up to you to go further after the 42 Common
Core!


# Chapter II

# General rules

**Compiling**

- Compile your code withc++and the flags-Wall -Wextra -Werror
- Your code should still compile if you add the flag-std=c++

```
Formatting and naming conventions
```
- The exercise directories will be named this way:ex00, ex01, ... , exn
- Name your files, classes, functions, member functions and attributes as required in
    the guidelines.
- Write class names in **UpperCamelCase** format. Files containing class code will
    always be named according to the class name. For instance:
    ClassName.hpp/ClassName.h,ClassName.cpp, orClassName.tpp. Then, if you
    have a header file containing the definition of a class "BrickWall" standing for a
    brick wall, its name will beBrickWall.hpp.
- Unless specified otherwise, every output messages must be ended by a new-line
    character and displayed to the standard output.
- _Goodbye Norminette!_ No coding style is enforced in the C++ modules. You can
    follow your favorite one. But keep in mind that a code your peer-evaluators can’t
    understand is a code they can’t grade. Do your best to write a clean and readable
    code.

```
Allowed/Forbidden
```
```
You are not coding in C anymore. Time to C++! Therefore:
```
- You are allowed to use almost everything from the standard library. Thus, instead
    of sticking to what you already know, it would be smart to use as much as possible
    the C++-ish versions of the C functions you are used to.
- However, you can’t use any other external library. It means C++11 (and derived
    forms) andBoostlibraries are forbidden. The following functions are forbidden
    too:*printf(),*alloc()andfree(). If you use them, your grade will be 0 and
    that’s it.


C++ - Module 06 C++ casts

- Note that unless explicitly stated otherwise, theusing namespace <ns_name>and
    friendkeywords are forbidden. Otherwise, your grade will be -42.
- **You are allowed to use the STL in the Module 08 and 09 only.** That means:
    no **Containers** (vector/list/map/and so forth) and no **Algorithms** (anything that
    requires to include the<algorithm>header) until then. Otherwise, your grade will
    be -42.

```
A few design requirements
```
- Memory leakage occurs in C++ too. When you allocate memory (by using thenew
    keyword), you must avoid **memory leaks**.
- From Module 02 to Module 09, your classes must be designed in the **Orthodox**
    **Canonical Form, except when explicitely stated otherwise**.
- Any function implementation put in a header file (except for function templates)
    means 0 to the exercise.
- You should be able to use each of your headers independently from others. Thus,
    they must include all the dependencies they need. However, you must avoid the
    problem of double inclusion by adding **include guards**. Otherwise, your grade will
    be 0.

```
Read me
```
- You can add some additional files if you need to (i.e., to split your code). As these
    assignments are not verified by a program, feel free to do so as long as you turn in
    the mandatory files.
- Sometimes, the guidelines of an exercise look short but the examples can show
    requirements that are not explicitly written in the instructions.
- Read each module completely before starting! Really, do it.
- By Odin, by Thor! Use your brain!!!

```
You will have to implement a lot of classes. This can seem tedious,
unless you’re able to script your favorite text editor.
```
```
You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don’t be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.
```

# Chapter III

# Additional rule

The following rule applies to the entire module and is not optional.

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense.


# Chapter IV

# Exercise 00: Conversion of scalar

# types

```
Exercise 00
```
```
Conversion of scalar types
Turn-in directory : ex 00 /
Files to turn in :Makefile, *.cpp, *.{h, hpp}
Allowed functions : Any function to convert from a string to an int, a
float or a double. This will help, but won’t do the whole job.
```
Write astaticclass ScalarConverter that will contain a method "convert" takes as
parameter a string representation of a C++ literal in its most common form. This literal
must belong to one of the following a scalar types:

- char
- int
- float
- double

Except for char parameters, only the decimal notation will be used.

Examples of char literals:’c’,’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.

```
Examples of int literals: 0 ,-42, 42 ...
```
Examples of float literals:0.0f,-4.2f,4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff,+inff
andnanf.


C++ - Module 06 C++ casts

Examples of double literals:0.0,-4.2,4.2...
You have to handle these pseudo literals as well (you know, for fun):-inf,+infandnan.


C++ - Module 06 C++ casts

```
Write a program to test that your class works as expected.
```
You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it **explicitly** to the three other data types. Lastly,
display the results as shown below.

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char:'*'
int: 42
float: 42.0f
double: 42.
```

# Chapter V

# Exercise 01: Serialization

```
Exercise : 01
```
```
Serialization
Turn-in directory : ex 01 /
Files to turn in :Makefile, *.cpp, *.{h, hpp}
Forbidden functions :None
```
```
Implement a static class Serializer with the following methods:
```
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer typeuintptr_t.

Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer toData.

```
Write a program to test that your class works as expected.
```
```
You must create a non-empty (it means it has data members)Datastructure.
```
Useserialize()on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value ofdeserialize()compares equal to the
original pointer.

```
Do not forget to turn in the files of yourDatastructure.
```

# Chapter VI

# Exercise 02: Identify real type

```
Exercise : 02
```
```
Identify real type
Turn-in directory : ex 02 /
Files to turn in :Makefile, *.cpp, *.{h, hpp}
Forbidden functions :std::typeinfo
```
Implement a **Base** class that has a public virtual destructor only. Create three empty
classes **A** , **B** and **C** , that publicly inherit from Base.

```
These four classes don’t have to be designed in the Orthodox
Canonical Form.
```
```
Implement the following functions:
```
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.

void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C".

void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.

```
Including thetypeinfoheader is forbidden.
```
```
Write a program to test that everything works as expected.
```

