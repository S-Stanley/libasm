- [Instructions](#instructions)
- [Registers](#registers)
  - [How to use registers](#how-to-use-registers)
  - [Register for functions](#register-for-functions)
  - [Register for syscall](#register-for-syscall)

## Instructions

## Registers

* ret is used for data return
* result of syscall are stored in rax

### How to use registers ?

This is one of the most difficult thing to crasp, at leat from my experience.
Not because it's complicated, but because it's difficult to find the information
when you don't understand.

Registers are just memory available rapidly for the cpu, but more than that.
They can have a specific purpose.

### Register for functions

When a assembly fonction receive parameter
it store it in register, in this order:

1. rdi
1. rsi
1. rdx
1. rcx
1. r8
1. r9

The rest is stored in the stack.

### Register for syscall

When we make a syscall, we have to put some data in some register in a specific
order to make it work. For example for write, in `C`, the man tell us:

```c
ssize_t write(int fildes, const void *buf, size_t nbyte);
```

* The first parameter is the file description.
* The seconds one is the string to write.
* The third argument is the size of the string.

In assembly it will be "almost" the same, we have to put the write syscall in
one specific register, and each parameter on others, and it a specific order.

For x64_86 it will be:
* rax for the number of the syscall
* rdi for the first argument
* rsi for the second argument
* rdx for the third one
* r10 for the argument 4
* r8 for the argument 5
* And r9 for the argument 6

[You can find the list here](https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md#calling-conventions)