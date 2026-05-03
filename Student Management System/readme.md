# 📚 Student Management System — README
 
A **console-based Student Record Management System** written in **C**, using a **singly linked list** as the core data structure. Built with a multi-file modular architecture.
 
---
 
## 📁 Project Structure
 
```
.
├── main.c          → Entry point — reads data, runs the menu loop
├── menu.c / .h     → Menu display and UI helper functions
├── func.h          → Global struct definition + function declarations
├── read.c          → Reads student records from file into linked list
├── stud_add.c      → Add new student(s)
├── stud_show.c     → Display all students + helper print functions
├── stud_del.c      → Delete a student by roll or name
├── stud_mod.c      → Modify student name or percentage
├── stud_sort.c     → Sort list by roll, name, or percentage
├── stud_rev.c      → Reverse the list
├── stud_save.c     → Save list to binary file
├── stud_exit.c     → Exit with/without saving
├── delete_all.c    → Delete all records in memory
├── student.dat     → Binary data file (auto-created on save)
└── makefile        → Build configuration
```
 
---
 
## 🧱 Core Data Structure
 
```c
typedef struct student {
    int roll;           // Auto-assigned roll number
    char name[20];      // Student name
    float percent;      // Percentage marks
    struct student* next; // Pointer to next node (linked list)
} st;
```
 
This is a **singly linked list node**. Each student is one node. The list is accessed via a global head pointer `hptr`.
 
```
hptr → [roll|name|percent|next] → [roll|name|percent|next] → NULL
```
 
---
 
## 🔄 How It Works (Program Flow)
 
```
Program Start
     │
     ▼
read_data()         ← Load existing records from student.dat into linked list
     │
     ▼
menu() loop         ← Display menu, get user choice
     │
     ├─ A → stud_add()      Add new student node(s)
     ├─ S → stud_show()     Traverse and print all nodes
     ├─ D → stud_del()      Find and remove a node
     ├─ M → stud_mod()      Find and edit a node's data
     ├─ T → stud_sort()     Sort nodes (insertion sort on data)
     ├─ R → stud_rev()      Reverse node data order
     ├─ L → delete_all()    Free all nodes
     ├─ V → stud_save()     Write list to binary file
     └─ E → stud_exit()     Optional save, then exit
```
 
---
 
## 📄 File-by-File Explanation
 
### `main.c` — Entry Point
- Calls `read_data()` on startup to restore saved data.
- Runs an infinite `while(1)` loop showing the menu.
- Uses a `switch` on the character returned by `menu()` to dispatch functions.
---
 
### `func.h` — Shared Header
- Defines the `st` struct and `typedef`.
- Declares `hptr` (head pointer) and `rollno` as `extern` — so all `.c` files share the same global instance defined in `read.c`.
- Declares all function prototypes so every file knows the function signatures.
---
 
### `read.c` — Load from File
- Defines the actual global variables: `hptr = 0` and `rollno = 1`.
- Opens `student.dat` in binary read mode (`"rb"`).
- Reads one `st`-sized chunk at a time using `fread()`.
- Appends each node to the end of the linked list.
- Sets `rollno` to `last_read_roll + 1` so new additions don't clash.
---
 
### `stud_add.c` — Add Student
- `malloc()`s a new node for each student.
- Reads name using `scanf(" %[^\n]", ...)` — reads full line including spaces.
- Reads percentage with `scanf(" %f", ...)`.
- If list is empty (`hptr == 0`), the new node becomes the head.
- Otherwise, traverses to the last node and appends.
- Assigns `rollno++` as the roll number.
---
 
### `stud_show.c` — Display Students
Contains 3 print functions used across the program:
 
| Function | Purpose |
|---|---|
| `stud_show()` | Full-screen display with "press enter" wait |
| `stud_print()` | Compact table used inside delete/modify screens |
| `print_onestudent(st*)` | Prints a single student row with header |
 
---
 
### `stud_del.c` — Delete Student
- Offers two modes: **by roll number** or **by name**.
- `del_name()` handles duplicate names — if multiple students have the same name, it lists them and falls back to `del_roll()` for disambiguation.
- Core `delete(temp, prev)` function handles 3 cases:
  - Only node (head + no next) → `hptr = 0`
  - Head node with next → `hptr = temp->next`
  - Middle/tail node → `prev->next = temp->next`
- Calls `free(temp)` to release memory.
---
 
### `stud_mod.c` — Modify Student
- Same search logic as delete (by roll or name).
- `modify(int rollno)` finds the node and lets user choose:
  - `1` → update name
  - `2` → update percentage
- Edits the data in-place inside the linked list node — no deletion needed.
---
 
### `stud_sort.c` — Sort List
Uses **insertion sort** (stable, in-place). Three sort modes:
 
| Mode | Comparison |
|---|---|
| Roll | `node[j]->roll >= node[j-1]->roll` |
| Percentage | Descending: `node[j]->percent < node[j-1]->percent` |
| Name | `compare()` — case-insensitive `strcmp` |
 
**Key technique:** Builds a temporary array of pointers (`st** node`) pointing to existing nodes. Then swaps **data** between nodes using `memcpy()` (not the `next` pointers). This keeps the linked list structure intact.
 
```c
int size = sizeof(st) - sizeof(st*);  // Only copy data fields, NOT the next pointer
memcpy(swap, node[j], size);
memcpy(node[j], node[j-1], size);
memcpy(node[j-1], swap, size);
```
 
The `compare()` helper converts both strings to lowercase before comparing, making sort case-insensitive.
 
---
 
### `stud_rev.c` — Reverse List
- Same pointer-array + `memcpy` technique as sort.
- Uses two-pointer swap: `i` starts from front, `j` from back, meet in the middle.
- Copies only `size = sizeof(st) - 8` bytes to avoid overwriting `next` pointers.
> ⚠️ **Note:** `sizeof(st) - 8` assumes the `next` pointer is 8 bytes (64-bit system). A more portable way would be `sizeof(st) - sizeof(st*)`.
 
---
 
### `stud_save.c` — Save to File
- Opens `student.dat` in binary write mode (`"wb"`) — **overwrites** the file.
- Traverses the linked list and writes each node with `fwrite(temp, sizeof(st), 1, fp)`.
- The `next` pointer is also written to disk, but it's ignored on re-read (fresh pointers are assigned in `read_data()`).
---
 
### `stud_exit.c` — Exit Program
- Offers: Save+Exit, Exit without saving, or Cancel.
- Calls `delete_nodes()` before exiting to free all heap memory (good practice).
- Uses `exit(1)` to terminate.
---
 
### `delete_all.c` — Clear All Records
- Frees every node in the linked list.
- Resets `hptr = 0` and `rollno = 0`.
---
 
### `menu.c` — UI Helpers
 
| Function | What it does |
|---|---|
| `menu()` | Prints the main menu, returns user's choice character |
| `print(const char* s)` | Centers a string across 173-char wide terminal |
| `newline(int n)` | Prints `n` blank lines (for screen layout) |
| `space(int n)` | Prints `n` spaces using `printf("%*s", n, "")` |
 
---
 
## 🔑 Key Concepts Used
 
| Concept | Where Used |
|---|---|
| Singly Linked List | Core data structure (all files) |
| Dynamic Memory (`malloc`/`free`) | `stud_add`, `stud_del`, `stud_sort`, etc. |
| File I/O (`fread`/`fwrite`) | `read.c`, `stud_save.c` |
| `extern` globals | `hptr`, `rollno` shared across all files |
| `memcpy` for data swap | `stud_sort.c`, `stud_rev.c` |
| Pointer-to-pointer (`st**`) | Sorting/reversing via pointer arrays |
| `scanf(" %[^\n]", ...)` | Reading names with spaces |
| Multi-file compilation | Modular design with header guards |
 
---
 
## 🛠️ Build & Run
 
```bash
make        # Build using the makefile
./student     # Run the program 
```
 
To clean and rebuild:
```bash
make clean
make
```
 
---
 
## ⚠️ Known Limitations / Notes
 
- **Roll numbers never reuse** — after deletion, the gap in roll numbers remains.
- **No input validation** on name length (max 19 usable characters due to `char name[20]`).
- **`student.dat` is overwritten** on every save — no backup or append mode.
- **Terminal width assumed** to be wide enough for the centered layout (designed for ~173 chars).
 
