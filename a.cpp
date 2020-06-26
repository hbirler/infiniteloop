void loop_start();
void loop_kernel1();
void loop_kernel2();

int entrance(bool b) {
    loop_start();
}

void helper(bool b) {
    if (__builtin_expect(b, true)) {
        loop_kernel1();
        __builtin_unreachable();
    } else {
        loop_kernel2();
    }
}
