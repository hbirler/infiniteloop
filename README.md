
# Infinite Loops without while/for/goto/setjmp

This code executes an infinite loops that outputs

```
loop start
loop kernel 1
loop kernel 2
loop kernel 1
loop kernel 2
...
```

indefinitely when compiled with g++ 9.3.0.

But the code has no while/for/goto/setjmp or other normal constructs. Just undefined behaviour magic.

You can compile using `make` and run `looper`.

Binary for a.cpp:

```
_Z8entranceb:
        subq    $8, %rsp
        call    _Z10loop_startv
_Z6helperb:
        testb   %dil, %dil
        je      .L5
        subq    $8, %rsp
        call    _Z12loop_kernel1v
.L5:
        jmp     _Z12loop_kernel2v
```

The magic happens because `entrance` function has no return statement, so the execution falls through to the `helper` function, which moves the stack pointer down again, making the return address for the call to `loop_start` the return address for `helper`.
