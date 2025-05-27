# Library Management System 📚

This project is a simple **console-based library automation system** written in C++. It allows users to borrow and return books, manage the book list, and handle library membership operations.

## Features

### 📖 Book Operations
- Borrow a book
- Return a borrowed book
- Donate (add) a book to the library
- Remove a book from the library
- View all available books

### 👤 Member Operations
- Register as a new member
- Remove a member
- View all registered members

## Usage

After running the program:
1. Select whether to perform **book** or **member** operations.
2. Then, choose the specific operation (e.g., borrow book, view members).
3. Input required information (book name, user name) via the console.

## Build & Run

```bash
git clone https://github.com/your-username/library-management-system.git
cd library-management-system
g++ main.cpp kutuphaneIslemleri.cpp -o library
./library
Note: Requires a C++ compiler (such as g++) to compile and run.

## Future Improvements 🛠️
1. Save which user has borrowed which book (using text file logging)

2. Improved user interface (e.g., colored menus, better UX)

3. Persistent data storage using files

4. Ability to return to the main menu after an operation

## Contributing
Feel free to open issues or submit pull requests to contribute to this project.
