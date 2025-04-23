# 🎮 C Project: Number Guessing Game & Stone Paper Scissors

Welcome to a fun-filled C programming project featuring **two classic mini-games** – a **Number Guessing Game** and a **Stone Paper Scissors Game**. Whether you're brushing up on your C skills or just want to show off a simple terminal-based game collection, this project is a great place to start!

---

## 📌 Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [How to Run](#how-to-run)
- [Code Structure](#code-structure)
- [Screenshots](#screenshots)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

## 🧠 About the Project

This C project includes two engaging terminal-based games:

1. **Number Guessing Game**  
   The program generates a random number, and you try to guess it within limited attempts. Feedback is given after each guess to help you find the correct number.

2. **Stone Paper Scissors Game**  
   A digital take on the childhood classic. You play against the computer, which randomly chooses its move. Best of three rounds wins the match!

---

## ✨ Features

- Simple CLI-based UI
- Random number generation using `rand()`
- Input validation
- Score tracking in Stone Paper Scissors
- Modular and beginner-friendly code

---

## 🛠️ Technologies Used

- **Language**: C
- **Compiler**: GCC / Turbo C (if you're feeling retro 😎)
- **Platform**: Cross-platform (Windows / Linux / macOS)

---

## 🚀 How to Run

### Prerequisites

- A C compiler (like `gcc`)
- Basic terminal usage

### Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/c-games-project.git
cd c-games-project

# Compile
gcc number_guessing_game.c -o guess
gcc stone_paper_scissors.c -o sps

# Run
./guess
./sps
