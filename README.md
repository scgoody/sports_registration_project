# C++ Sports Registration System Project  
This repo contains a C++ program developed as part of an Object-Oriented Programming course. This project models a sports registration system by capturing the relationships between players, theirs families, and their teams using modular class design. It is structured for compilation and execulation in Visual Studio 2022.  

## Repo Structure  
sports_registration_project/  
├── .gitignore # Ignores unneeded build and IDE files  
├── README.md # Project overview and usage instructions  

├── Project1.sln # Visual Studio solution file  
├── Project1.vcxproj # Project configuration for Visual Studio  
├── Project1.vcxproj.filters # Visual Studio file organization  

├── Source.cpp # Main driver file (contains main())  

├── Person.h # Header for Person base class  
├── Person.cpp # Implementation of Person class  

├── Family.h # Header for Family class (inherits from Person)  
├── Family.cpp # Implementation of Family class  

├── Player.h # Header for Player class (inherits from Person)  
├── Player.cpp # Implementation of Player class  

## Key Concepts:  
- **Class Design**: constructors, destructors, and modular responsibilities
- **Encapsulation**: private class members with controlled access via getters/setters
- **Inheritance**: `Family` and `Player` inherit from a shared `Person` base class
- **Polymorphism**: derived class behaviors and overrides
- **Composition**: `Family` class can hold and manage multiple `Person` or `Player` objects
- **Separation of Interface and Implementation**: split `.h` and `.cpp` files for maintainability

## Technology Used
- C++
- Visual Studio 2022

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/scgoody/sports_registration_project.git
   cd sports_registration_project
2. Open `.sln` file in Visual Studio
3. Build & run project

## Author
Sarah Goodyear  
B.S. in Data Science  
www.linkedin.com/in/sgoodyear04  
