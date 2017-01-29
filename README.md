About
=====

Fix32 is a collection of highly optimized fixed-point mathematical functions
for embedded systems. These functions operate on 32-bit fixed-point numbers,
whose format, with rare exceptions, may vary from Q1 to Q31. To utilize all
the features of a target CPU and achieve faster execution speeds and smaller
memory footprint, all the functions are written in an assembly language.

Simply put, this software library is aimed at those who want to perform fast
and precise non-integer calculations on devices lacking a FPU. But even with
a presence of FPU, this library may still be useful, as most of the library
functions are considerably faster than standard floating-point alternatives.
In addition, 32-bit signed fixed-point numbers have more significant digits
than single-precision floating-point numbers.


Reference
=========

The header file contains a brief description of each function. If you have
already know what fixed-point numbers are, this should be enough. Otherwise,
it is a good idea to read up on them a little bit, so you can understand the
basic principles and terminology. For more information about the execution
time and accuracy, as well as the other implementation details of a certain
function, you may refer to the comments in the corresponding source file.


Usage
=====

Download the library binaries for the required CPU architecture and compiler
toolchain, and simply add them to your project. The library does not require
any initialization or configuration routines. If you want, you can include
the original source files instead of the precompiled library.


Alternatives
============

### libfixmath

As stated in the description, this is a tried and tested cross platform fixed
point maths library. It is written in the C programming language, so it will
work considerably slower and will take up more space in memory. Another major
drawback is that this library supports only Q16 fixed-point format, while the
current library supports a full range of formats starting from Q1 and ending
with Q31.

The advantage of the libfixmath library is that it includes several functions
that are not (yet) implemented in the current library. These are the tangent
function, a few inverse trigonometric functions, and a set of basic saturated
arithmetic functions.

### ARM CMSIS DSP

The CMSIS DSP software library is a collection of common signal processing
functions for use on Cortex-M based devices. Just like the previous library,
it is also written in C language. So it will perform slower and will occupy
more space in memory, especially because it uses a larger lookup tables.

One more drawback is that the CMSIS DSP library supports only two fixed-point
formats, namely the Q15 and Q31. A set of supported mathematical functions is
also very poor and includes only the sine, cosine, and square root function.
There are other functions, but they are designed to work with vector values
or complex numbers.

### IQmath Library

The Texas Instruments IQmath Library is a collection of highly-optimized and
high-precision mathematical functions. Like its counterpart, it is writen in
assembly language and supports a full range of fixed-point formats starting
from Q1 and ending with Q31. Furthermore, the library provides a large set
of functions, including those that are absent in the current library. These
are the tangent function, several inverse trigonometric functions, and the
exponent function.

Despite these advantages, many functions in the IQmath library tend to be
a few cycles slower and little less accurate than their counterparts from
the current library. Also, the IQmath library uses a larger lookup tables,
which significantly increases the size of the library.


Attention!
==========

* The library functions do not check their inputs. A function will silently
  return an undefined value if you violate the requirements given in the
  function description. This is not a defect but a conscious design choice
  to increase the library performance. Thus, all the passed values should
  be checked in a higher software level.

* Since the lowest negative two's complement 32-bit signed integer does not
  have its positive counterpart, some of the library functions may not work
  properly if you specify this value.

* All cycle counts are based on a system with zero wait states, yet the real
  systems usually have memory with more than zero wait states. In such cases
  the execution times can increase by several times. Also, time measurements
  do not include the function call overhead.


Contributing
============

If you find a bug, ensure this bug was not already submitted by searching on
the issue tracker. If it is not, be sure to include a meaningful title, clear
description, and a code sample demonstrating the incorrect behavior.

If you wrote a patch that fixes a bug — feel free to send a pull request with
this patch. Ensure the pull request description clearly describes the problem
and solution. Include the relevant issue number if applicable.

In the case if you intend to add a new feature or change existing one, you
can submit a new issue on the issue tracker or send me an email to discuss
the proposed changes.


License
=======

 This is free and unencumbered software released into the public domain.
 For more information, see the LICENSE file.