// assemled with NASM
extern "C" unsigned int AddFour(unsigned int x);

unsigned short int add_four(unsigned short int x) {
    unsigned int y; 
    __asm__ __volatile__(
        "movw %w1, %%ax\n"
        "addw $4, %%ax\n"
        "movw %%ax, %w0\n"
        : "=r" (y)
        : "r" (x)
        );
    return y;
}

void print_A() {
    __asm__ __volatile__(
        "movw $0x0a00, %ax\n"
        "addw $0x41, %ax\n"
        "movw $0, %bx\n"
        "movw $1, %cx\n"
        "int $0x10\n"
        );
}

void print_char(unsigned char ch) {
    unsigned char out;
    __asm__ __volatile__(
        "addw $0x0a00, %%ax\n"
        "movw $0, %%bx\n"
        "movw $1, %%cx\n"
        "int $0x10\n"
        :
        : "a" (ch)
        );
}
