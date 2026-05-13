# Lexical Analyzer

A simple Lexical Analyzer (Lexer) implemented in C that reads a C-like source code file and identifies each token — classifying it as a keyword, identifier, constant, operator, relational operator, assignment operator, brace, delimiter, or unknown symbol.

A lexical analyzer is the first phase of a compiler. It scans the input source code character by character and groups them into meaningful units called **tokens**.

---

## Table of Contents

- [What is a Lexical Analyzer?](#what-is-a-lexical-analyzer)
- [Token Types Recognized](#token-types-recognized)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Build](#build)
- [Run](#run)
- [Sample Input and Output](#sample-input-and-output)
- [Supported Keywords](#supported-keywords)
- [Limitations](#limitations)
- [Author](#author)

---

## What is a Lexical Analyzer?

In compiler design, the **lexical analysis** phase (also called scanning or tokenization) is the very first step. It reads raw source code as a stream of characters and produces a sequence of tokens — each token representing a meaningful unit like a variable name, a number, an operator, or a language keyword.

This project simulates that process for a subset of the C programming language.

---

## Token Types Recognized

| Token Type | Description | Examples |
|---|---|---|
| **Keyword** | Reserved words of the C language | `int`, `for`, `while`, `if` |
| **Identifier** | Variable or function names | `x1`, `sum`, `main` |
| **Constant** | Numeric integer values | `0`, `10`, `42` |
| **Relational Operator** | Comparison operators (two characters) | `<=`, `>=`, `==`, `!=` |
| **Assignment Operator** | Single `=` sign | `=` |
| **Operator** | Arithmetic operators | `+`, `-`, `*`, `/`, `<`, `>` |
| **O_BRACE / C_BRACE** | Opening and closing brackets/braces | `(`, `)`, `{`, `}` |
| **Delimiter** | Statement separators | `;`, `,` |
| **Unknown Symbol** | Any character not in the above categories | `@`, `#`, etc. |

---

## Project Structure

```
.
├── lex.c       # Main source file — full lexical analyzer implementation
├── input.txt   # Sample input file containing C-like source code to analyze
└── secret.txt  # Another sample input file for testing
```

---

## How It Works

1. The program takes a filename as a command-line argument and opens it for reading.
2. The entire file content is read into a character buffer (up to 1000 characters).
3. The buffer is scanned character by character in a loop:
   - **Whitespace** (spaces, tabs, newlines) is skipped.
   - **Letters** trigger word collection — characters are gathered until a non-alphanumeric character is found, then checked against the keyword list. If matched, it's a Keyword; otherwise it's an Identifier.
   - **Digits** trigger number collection — all consecutive digits are grouped into a Constant.
   - **Operators** are checked: if the next character is `=`, it forms a two-character Relational Operator; a standalone `=` is an Assignment Operator; all others are plain Operators.
   - **Braces** `( ) { }` are labeled as O_BRACE or C_BRACE.
   - **Delimiters** `;` and `,` are labeled as Delimiter.
   - Anything else is labeled as Unknown Symbol.
4. Each recognized token is printed to the terminal with its classification.

---

## Build

```bash
gcc lex.c -o lex
```

---

## Run

```bash
./lex input.txt
```

You can pass any `.txt` file containing C-like source code as the argument.

---

## Sample Input and Output

**input.txt:**
```c
for(x1 = 0; x1 <= 10; x1++);
```

**Output:**
```
for : Keyword
( : O_BRACE
x1 : Identifier
= : Assignment operator
0 : Constant
; : Delimiter
x1 : Identifier
<= : Relational operator
10 : Constant
; : Delimiter
x1 : Identifier
+ : Operator
+ : Operator
) : C_BRACE
; : Delimiter
```

---

**secret.txt:**
```c
for(int i=0;i<5;i++)
{
    printf("Hello");
}
```

**Output:**
```
for : Keyword
( : O_BRACE
int : Keyword
i : Identifier
= : Assignment operator
0 : Constant
; : Delimiter
i : Identifier
< : Operator
5 : Constant
; : Delimiter
i : Identifier
+ : Operator
+ : Operator
) : C_BRACE
{ : O_BRACE
printf : Identifier
( : O_BRACE
" : Unknown Symbol
Hello : Identifier
" : Unknown Symbol
) : C_BRACE
; : Delimiter
} : C_BRACE
```

---

## Supported Keywords

The following 10 C keywords are recognized:

```
if, else, while, for, int, float, char, return, void, do
```

---

## Limitations

- Input file size is limited to **1000 characters**
- Only **integer constants** are recognized; floating-point numbers (e.g., `3.14`) are not handled
- **String literals** (e.g., `"Hello"`) are not recognized as a token type — quotes appear as Unknown Symbols
- **Comments** (`//` or `/* */`) are not handled and will be tokenized character by character
- Only a subset of C keywords (10 total) is supported
- Multi-character identifiers must be alphanumeric only — underscores (`_`) are not supported

---

## Author

**Delna Joseph**
