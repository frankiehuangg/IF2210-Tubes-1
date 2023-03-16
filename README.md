# Kompetisi Kartu ala Kerajaan Permen

Dalam rangka merayakan pesta panen gula di kerajaan permen, akan diadakan kompetisi massal permainan kartu ala Kerajaan Permen. Ratu kerajaan permen ingin mencari pemain kartu terhebat di kerajaannya. Namun karena Ratu tidak bisa memantau permainan satu-persatu, kalian diminta untuk membuatkan sistem agar permainan dapat berjalan dengan adil. Bantulah ratu kerajaan permen untuk membuatkan permainan ala kerajaan permen.

## Group Members
| NIM      | Name                        |
| -------- | ----------------------------|
| 13521082 | Farizki Kurniawan			 |
| 13521092 | Frankie Huang               |
| 13521138 | Johann Christian Kandani    |
| 13521150 | I Putu Bakta Hari Sudewa    |
| 13521170 | Haziq Abiyyu Mahdy			 |

## Task 

## About this project
- TUI-based card game coded in C++
- Uses the following Object Oriented Programming concepts:
	- Inheritance and polymorphism;
	- Exception and exception handling;
	- Function overloading and Operator overloading
	- Abstract Class and Virtual Function
	- Generic Function and Generic Class
	- C++ STL (Standard Template Library)
- Coded in C++ v12.2.1, compiled with g++ v12.2.1 on Linux-based OS

## Features

The features below are 100% done and implemented.
- Poker-like game with abilities
- Cangkul card game
- A simple yet aesthetically pleasing TUI

## Requirements
- C++ v12 or up
- g++ v12 or up
- Preferably linux based OS

## Setup
Make sure all requirements are installed in your local machine beforehand. Then, clone this repository.
```bash
git clone git@github.com:frankiehuangg/IF2210-Tubes-1.git
```

Change to the repository directory, then use the `makefile` file.
```bash
cd IF2210-Tubes-1/
make run
```

## Program Structure

```
│ makefile
│ README.md
│ .gitignore
│
├─── bin
│     └─ main
│
└─── src
      ├─ ascii
      │    ├─ cards.txt
      │    └─ cards2.txt
      ├─ header
      │    ├─ Ability_Abilityless.hpp
      │    ├─ Ability_Quadruple.hpp
      │    ├─ Ability_Quarter.hpp
      │    ├─ Ability_ReRoll.hpp
      │    ├─ Ability_Reverse.hpp
      │    ├─ Ability_Swap.hpp
      │    ├─ Ability_Switch.hpp
      │    ├─ AbilityCard.hpp
      │    ├─ Action.hpp
      │    ├─ Cangkul.hpp
      │    ├─ Combo.hpp
      │    ├─ Comparable.hpp
      │    ├─ Deck.hpp
      │    ├─ Exception.hpp
      │    ├─ Game.hpp
      │    ├─ Inventory.hpp
      │    ├─ Io_Handler.hpp
      │    ├─ MainCard.hpp
      │    ├─ Player.hpp
      │    ├─ Poker.hpp
      │    └─ Table.hpp
      ├─ Ability_Abilityless.cpp
      ├─ Ability_Quadruple.cpp
      ├─ Ability_Quarter.cpp
      ├─ Ability_ReRoll.cpp
      ├─ Ability_Reverse.cpp
      ├─ Ability_Swap.cpp
      ├─ Ability_Switch.cpp
      ├─ AbilityCard.cpp
      ├─ Action.cpp
      ├─ Cangkul.cpp
      ├─ Combo.cpp
      ├─ Comparable.cpp
      ├─ Deck.cpp
      ├─ Exception.hpp
      ├─ Game.cpp
      ├─ Inventory.cpp
      ├─ Main.cpp
      ├─ MainCard.hpp
      ├─ Player.hpp
      ├─ Poker.cpp
      └─ Table.cpp
```

## Project Status
This project is *finished*.

*There are no plans to change, add, or optimize the program in the near future.*

## Room for Improvement
- More efficient divide and conquer algorithm
- Snappier GUI

## Acknowledgements
- This project is spearheaded by the IF2210 Informatics major at Institut Teknologi Bandung, which has been well organized by the IF2210 - 2023 professors and assistants.
- README template by [@flynerdpl](https://www.flynerd.pl/): [README](https://github.com/ritaly/README-cheatsheet)
