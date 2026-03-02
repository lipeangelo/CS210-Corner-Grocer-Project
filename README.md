CS 210 – Project Three
Corner Grocer Item Tracking Program
Project Summary

This project is a C++ item-tracking program developed for the fictional Corner Grocer. The purpose of the program is to analyze daily purchase records from a text file and determine how frequently each grocery item was purchased. The program reads data from an input file, processes the information using a std::map container, and generates both numerical and histogram-based outputs. It also automatically creates a backup file (frequency.dat) that stores item counts for persistence and record-keeping.

The problem this program solves is helping a grocery store analyze purchasing patterns so they can reorganize their produce section more effectively. By calculating frequency counts, the store can make data-driven decisions about product placement.


What I Did Particularly Well

One area I performed particularly well in was applying object-oriented design principles. I created a GroceryTracker class with properly encapsulated private data members and clearly defined public member functions. I also implemented file input/output handling with error checking to ensure reliability.

Additionally, I focused heavily on code readability and maintainability by:

- Using meaningful variable and function names

- Applying const-correctness

- Implementing structured bindings (C++20 feature)

- Adding detailed inline comments

- Avoiding magic numbers by using constants

- Designing a clear and user-friendly menu system

I also configured the project using CMake, ensuring modern C++20 standards were enforced.


Areas for Improvement

While the program functions correctly, there are areas where it could be enhanced.

One improvement would be implementing case-insensitive search for item names to improve user experience. Currently, the user must enter the exact case as stored in the file. I could also improve input handling by allowing multi-word items using getline instead of cin.

Another enhancement would be separating the project into multiple files (.h and .cpp) for better modularity and scalability. This would align more closely with industry-level C++ project organization.

Additional improvements could include:

- Adding unit testing

- Implementing exception handling instead of simple error messages

- Improving performance if processing significantly larger datasets

These improvements would make the program more secure, efficient, and production-ready.


Most Challenging Aspects

The most challenging part of this project was handling file paths and understanding how CLion executes programs from the cmake-build-debug directory. Initially, the program could not locate the input file. I resolved this by learning how CMake manages build directories and adding a command to copy the input file into the binary directory automatically.

Another challenge was ensuring proper input validation and preventing runtime errors from invalid user input. I overcame this by using cin.fail(), clearing the input stream, and enforcing menu boundaries with constants.

Through this project, I strengthened my understanding of:

- CMake build systems

- File I/O in C++

- Data structures (std::map)

- Defensive programming techniques


Transferable Skills

This project strengthened several transferable skills that will apply to future coursework and professional development:

- Writing clean, maintainable C++ code

- Designing object-oriented programs

- Implementing secure file input/output

- Using associative containers like std::map

- Applying input validation and error handling

- Configuring projects with CMake

These skills are directly transferable to larger software engineering projects, backend development, systems programming, and any application requiring structured data processing.


Maintainability, Readability, and Adaptability

I made the program maintainable and readable by following industry best practices:

- Clear naming conventions (PascalCase for classes, camelCase for variables)

- Logical separation of responsibilities

- Private data encapsulation

- Inline documentation explaining functionality

- Consistent formatting and indentation

- Avoiding global variables

The use of std::map also makes the program adaptable because it automatically maintains alphabetical order and allows for efficient lookups. The modular class design ensures that additional reporting features or data-processing logic could be added without restructuring the entire program.

Overall, this project demonstrates my ability to write structured, secure, and efficient C++ code while following modern software engineering principles.
