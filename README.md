# Roman Numeral Calculator

### Directory Structure

    Makefile
    README.md
    |___src
    |   |___main.c
    |   |___roman_numeral.c
    |   |___roman_numeral.h
    |
    |___test
        |___check_rncalc.check
        |___roman_numeral_test.c

### Software Required:

* GNU GCC Compiler
* GNU Make
* Check

### How to use

Edit **check_rncalc.check** to run different tests with _Check_

Example:

```C
ck_assert_int_eq(sumOfRoman("XLIX", "XXVI"), 75);
ck_assert_int_eq(diffOfRoman("XL", "VII"), 33);
```

After your edits, make sure you save. Then run these commands in your terminal:

    cd test
    checkmk check_rncalc.check > roman_numeral_test.c

This will create the C file needed for _Check_

To run program with test case, run this command from the main directory:

    make -f Makefile test

I recommend to clean the directory of the output files before running the program again

To clean directory run:

    make -f Makefile clean

