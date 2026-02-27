# Lessons Learned — OS Journey

This file is maintained throughout the project. After every breakthrough, bug, or concept that clicks, add an entry. Claude should reference this to avoid re-explaining things and to build on what's already understood.

---

## How to Use This File

After a difficult debugging session or a concept finally clicking, add an entry under the current milestone using this format:

**Date — Short title**
- **What confused me:** (what you thought was happening)
- **What was actually happening:** (the root cause or correct mental model)
- **Key takeaway:** (one sentence you'd tell yourself before starting)
- **Syscalls/concepts involved:** (for quick reference later)

---

## Project 1: Custom Shell

### Milestone 1: The Skeleton
Entry 1 — Buffers in C

What confused me: Tried char input = "" and char* input = malloc(n) — didn't understand the difference between a single char, a pointer to a string literal, and an actual writable buffer
What was actually happening: read() needs a writable block of memory to store bytes into. A string literal is read-only, a single char is one byte. A stack-allocated array like char input[1024] gives you a writable buffer of known size
Key takeaway: When a syscall needs a buffer, declare an array with a fixed size on the stack
Syscalls/concepts involved: read(), stack vs heap memory, arrays vs pointers

Entry 2 — Detecting EOF (Ctrl+D)

What confused me: Tried comparing the input buffer contents to detect Ctrl+D (input == 0, input == "Ctrl + D")
What was actually happening: Ctrl+D signals EOF to the terminal. It doesn't put any text in the buffer. read() returns 0 when there's nothing left to read. You detect it by checking the return value, not the buffer
Key takeaway: Always check the return value of read() — 0 means EOF, -1 means error, positive means bytes read
Syscalls/concepts involved: read(), EOF, ssize_t vs size_t (signed vs unsigned return)

### Milestone 2: Tokenizer & Simple Execution

### Milestone 3: Built-in Commands

### Milestone 4: I/O Redirection

### Milestone 5: Pipes

### Milestone 6: Environment Variables

### Milestone 7: Signals

### Milestone 8: Background Processes & Job Control

### Milestone 9: Polish & Edge Cases

### Milestone 10: Reflection & Documentation

---

## Syscall Cheat Sheet (fill in as you go)

| Syscall | What it does | Where I used it | Gotchas |
|---------|-------------|-----------------|---------|
| read() | Reads up to count bytes from fd into buffer | main.c — reading user input from stdin (fd 0) | Returns ssize_t not size_t. Returns 0 on EOF, -1 on error |
| write() | Writes count bytes from buffer to fd | main.c — printing prompt and echoing input to stdout (fd 1) | Count must match actual bytes. Off-by-one writes past your data |

---

## Patterns to Remember

_(Add recurring patterns here, e.g. "always check return values", "close unused pipe ends")_

---

## Questions for Future Projects

_(Things that came up during the shell that you want to understand deeper when building the kernel, memory allocator, etc.)_
