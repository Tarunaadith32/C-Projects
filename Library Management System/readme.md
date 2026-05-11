# 📚 Library Management System (LMS)

A terminal-based Library Management System written in **C**, featuring a doubly linked list data structure for managing books and issue records. Data is persisted across sessions using CSV files.

---

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Data Structures](#data-structures)
- [Getting Started](#getting-started)
- [Detailed Mode of Operation](#detailed-mode-of-operation)
- [CSV Format](#csv-format)
- [Known Disadvantages & Limitations](#known-disadvantages--limitations)
- [Topics Used — Interview Prep Guide](#topics-used--interview-prep-guide)

---

## Features

- Add new books to the library
- Update existing book details (title, author, count)
- Remove books by ID or title
- Search books by ID, title, or author
- View all books in a formatted table
- Issue books to users with automatic due date (7-day period)
- Return books with fine calculation (₹2/day for overdue returns)
- View all issued books with status
- Save data to CSV files for persistence

---

## Project Structure

```
lms/
├── main.c          # Entry point, menu loop (switch-case dispatch)
├── func.h          # Header — structs, macros, extern declarations, prototypes
├── menu.c          # Menu display and utility print/space/newline functions
├── read.c          # Load data from CSV files on startup; global pointer definitions
├── save.c          # Save linked list data to CSV files
├── add.c           # Add new book node to the book linked list
├── update.c        # Update book fields; bookprint() helper defined here
├── remove.c        # Remove a book node with proper pointer relinking
├── search.c        # Search books by ID, title, or author
├── show.c          # Traverse and display all book nodes
├── issue.c         # Issue a book — create issue node, decrement book count
├── issuedisplay.c  # Traverse and display all issue nodes
├── return.c        # Return a book — update returndate, calculate fine
├── duedate.c       # (Reserved for due date utilities)
├── booklist.csv    # Persistent book data
├── issuelist.csv   # Persistent issue records
└── makefile        # Build configuration using GCC
```

---

## Data Structures

Two **doubly linked lists** are maintained in memory at runtime.

### `book` struct

```c
typedef struct bookdata {
    unsigned int bookid;      // Unique ID starting from 1000
    char title[50];           // Book title
    char author[50];          // Author name
    unsigned int count;       // Available copies

    struct bookdata *prev;    // Pointer to previous node
    struct bookdata *next;    // Pointer to next node
} book;
```

### `issue` struct

```c
typedef struct issuedata {
    unsigned int issueid;     // Unique issue ID starting from 1
    unsigned int bookid;      // ID of issued book
    unsigned int userid;      // ID of user who borrowed
    char name[50];            // User name
    char issuedate[50];       // Date of issue (formatted string)
    char duedate[50];         // Due date = issue + 7 days (formatted)
    char returndate[50];      // Actual return date ("-" if not returned)
    long duecode;             // Unix timestamp of due date (for fine calc)
    int fine;                 // Fine in Rs
} issue;
```

### Global State (`read.c`)

```c
book  *bookptr  = 0;   // Head of book linked list
issue *issueptr = 0;   // Head of issue linked list
unsigned int bookid;   // Auto-increment book ID counter
unsigned int issueid;  // Auto-increment issue ID counter
```

These are defined once in `read.c` and declared as `extern` in `func.h` so all other `.c` files can access them.

---

## Getting Started

### Prerequisites

- GCC compiler
- Unix/Linux terminal (uses `system("clear")` and ANSI escape codes)
- `make` utility

### Build

```bash
make
```

### Run

```bash
./lms
```

### Clean build files

```bash
make clear
```

---

## Detailed Mode of Operation

### Startup — `read()` *(read.c)*

When the program launches, `read()` is the first function called from `main()`.

**What it does:**
1. Opens `booklist.csv` with `fopen()` in read mode.
2. If the file doesn't exist (`fp == NULL`), initializes `bookid = 1000`.
3. If it exists, reads each line with `fgets()`, parses it using `sscanf()`, dynamically allocates a `book` node with `malloc()`, and appends it to the tail of the doubly linked list.
4. After all books are loaded, `bookid` is set to `lastnode->bookid + 1` to continue from where it left off.
5. Repeats the same process for `issuelist.csv` to rebuild the issue linked list.

**Key logic:** To append at the tail, the code traverses to the last node each time:
```c
while(end->next) end = end->next;
end->next = temp;
temp->prev = end;
temp->next = 0;
```
This is O(n) per insertion — rebuilding N books from file takes O(n²) total. A tail pointer would reduce this to O(n).

---

### [1] Add New Book — `add()` *(add.c)*

**What it does:**
1. Dynamically allocates a new `book` node using `malloc()`.
2. Assigns the current global `bookid` to the node, then increments `bookid`.
3. Reads title, author, and count from stdin via `scanf()`.
4. If the list is empty (`bookptr == 0`), sets the new node as the head with `prev = NULL` and `next = NULL`.
5. Otherwise, traverses to the tail and appends, linking `prev` and `next` correctly.
6. Wraps in a `do-while` loop — asks if the user wants to add another book after each addition.

**Linked list operation:** Tail insertion — O(n) per insert (no tail pointer maintained).

---

### [2] Update Book Details — `update()` *(update.c)*

**What it does:**
1. Search by Book ID (integer match) or Book Title (`strcmp()`).
2. Traverses the list linearly until a match is found.
3. Displays the found book using `bookprint()`.
4. Prompts choice: update title, author, or count.
5. Directly overwrites the field in the existing in-memory node using `scanf()`.

**Key concept:** No pointer relinking needed — it's just a field assignment on an existing node. The node stays in place in the list.

**`bookprint()`** is a shared helper defined in `update.c` and declared in `func.h`. It's reused by `remove.c` and `search.c` to display a single book row.

---

### [3] Remove Book — `book_remove()` *(remove.c)*

**What it does:**
1. User removes by Book ID or Book Title.
2. Traverses to find the target node.
3. Displays the book and asks for confirmation.
4. Handles **four pointer relinking cases**:

| Case | Condition | Action |
|------|-----------|--------|
| Only node in list | `prev == NULL && next == NULL` | `free(temp)`, set `bookptr = 0` |
| Head node | `prev == NULL` | `next->prev = NULL`, `bookptr = temp->next`, `free(temp)` |
| Tail node | `next == NULL` | `prev->next = NULL`, `free(temp)` |
| Middle node | both non-NULL | `prev->next = next`, `next->prev = prev`, `free(temp)` |

**Key concept:** Proper pointer relinking before `free()` is critical. Freeing without relinking leaves dangling pointers in neighboring nodes.

---

### [4] Search Book — `book_search()` *(search.c)*

Three search modes:

**By Book ID:** Linear scan comparing `temp->bookid == id`. Stops at first match.

**By Book Title:** Linear scan using `strcmp(s, temp->title) == 0`. Stops at first match.

**By Author:** Traverses the **entire list** and prints all books matching the author name. A `flag` counter tracks if any result was found — used to print the table header only before the first match:
```c
if(flag == 1) { /* print header */ }
printf("|| ... ||\n", temp->bookid, temp->title, ...);
```

**Time complexity:** O(n) for all three modes — sequential search on an unsorted linked list.

---

### [5] View All Books — `show()` *(show.c)*

**What it does:**
1. If `bookptr == 0`, prints "NO BOOKS AVAILABLE".
2. Otherwise, traverses the full book linked list from head to tail, printing each node in a formatted row using `printf()` with width specifiers.

**Key format specifier:**
```c
printf("|| %-4u | %-33s | %-19s | %-4u ||\n", bookid, title, author, count);
```
`%-Ns` means: left-align, minimum N characters wide, pad with spaces. This keeps columns aligned regardless of content length.

---

### [6] Issue a Book — `book_issue()` *(issue.c)*

**What it does:**
1. User enters a Book ID; the book list is traversed to locate it.
2. Checks `count > 0`. If zero, rejects the request.
3. Collects User ID and User Name.
4. Captures the current Unix timestamp: `long currdate = time(NULL)`.
5. Calculates due date: `duedate = currdate + (3600 * 24 * 7)` (7 days in seconds).
6. Stores `duedate` as a raw Unix timestamp in `duecode` — this is used later in `return.c` to compute overdue days without re-parsing date strings.
7. Converts timestamps to human-readable strings:
   ```c
   struct tm *curr = localtime(&currdate);
   strftime(temp1->issuedate, sizeof(temp1->issuedate), "%d %b %Y", curr);
   ```
8. Sets `returndate = "-"` and `fine = 0`.
9. Appends a new `issue` node to the issue linked list (tail insertion).
10. Decrements `temp->count` on the book node.

**Key concept:** The design stores the due date both as a human-readable string (for display) AND as a Unix timestamp (for arithmetic). This avoids needing to parse date strings during return.

---

### [7] Return a Book — `book_return()` *(return.c)*

**What it does:**
1. User enters Book ID and User ID.
2. Traverses the issue list to find the matching record.
3. Gets current time with `time(NULL)`.
4. Finds the book node and increments `count` (restoring one available copy).
5. Calculates overdue: `int days = (curr - temp->duecode) / (3600 * 24)`.
6. If `days > 0`, shows fine: `days * 2` rupees.
7. On confirmation, records the return date using `strftime()` and stores the computed fine.

---

### [8] List Issued Books — `issue_display()` *(issuedisplay.c)*

**What it does:**
1. Traverses the issue linked list.
2. For each issue node, does an inner traversal of the book list to find the matching book by `bookid` — needed to print the book title.
3. Prints all fields in a wide formatted table including return status and fine.

**Key concept:** This is a **join** between two linked lists — for every issue, a full book list scan happens. Time complexity: O(n × m) where n = number of issues, m = number of books. With a hash map on `bookid`, this could be O(n).

---

### [9] Save — `save()` *(save.c)*

**What it does:**
1. Opens `booklist.csv` in write mode (`"w"`) — this truncates and overwrites the existing file entirely.
2. Traverses the book linked list from head to tail, writing each node as a comma-separated line with `fprintf()`.
3. Closes the file, then repeats for `issuelist.csv` and the issue list.

**Key concept:** The entire in-memory state is serialized to disk. On next launch, `read()` deserializes it back. This is a simple but fragile persistence model — a crash mid-write would corrupt the file.

> **Always save before exiting.** Option `[0] Exit` does not auto-save.

---

## CSV Format

**booklist.csv**
```
<bookid>,<title>,<author>,<count>
1000,The C Programming Language,Brian W. Kernighan,5
```

**issuelist.csv**
```
<issueid>,<bookid>,<userid>,<name>,<issuedate>,<duedate>,<returndate>,<duecode>,<fine>
1,1000,201,John Doe,01 May 2025,08 May 2025,-,1746662400,0
```

---

## Known Disadvantages & Limitations

### 1. O(n) Linear Search — No Indexing
Every lookup (by ID, title, author) is a full sequential scan. For large datasets, a hash map (O(1) average) or a BST (O(log n)) would be significantly faster.

### 2. O(n × m) Issue Display
`issue_display()` does a nested traversal — for each issue record it searches through all books to fetch the title. This is an unoptimized join. A `bookid`-keyed hash map would reduce this to O(n).

### 3. No Duplicate Detection
The same book can be added multiple times with different IDs. There's no check for duplicate titles or authors.

### 4. No Input Validation
Non-numeric input for IDs or counts, empty strings, or negative values are not handled. They lead to silent corruption or undefined behavior.

### 5. Data Loss Risk on Crash
All data lives in memory (the linked lists). A crash or power failure between edits and a save means all changes since the last save are permanently lost.

### 6. Dangling Pointer Risk in `issue_display()`
If a book is deleted (`book_remove()`) after being issued but before the issue is returned, `issue_display()` will traverse the issue list and attempt to find that book — but the node is freed. The pointer dereference causes undefined behavior / segfault.

### 7. No Authentication or Access Control
Any terminal user can add, delete, or modify any record. There are no admin/librarian vs. student roles.

### 8. `system()` Is a Security Risk
`system("clear")` spawns a shell subprocess. In larger programs that take user input and pass it to `system()`, this opens shell injection vulnerabilities. The safer alternative is `printf("\033[2J\033[H")` directly.

---

