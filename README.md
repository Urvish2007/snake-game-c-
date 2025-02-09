# 🐍 Snake Game in C++

## 🏆 Group: *Teen Tigda Kam Bigda!*

### 👥 Team Members:
- *Urvish Babariya* - 202401020
- *Jenish Kavad* - 202401088
- *Dhruv Nagani* - 202401124

Welcome to the *Snake Game* built in *C++*! 🎮 This is a classic snake game with modern enhancements like color-coded UI, real-time movement, and a high-score tracker. 🚀

## 🎯 Features

- ✅ *Self-Collision Detection* – The game ends when the snake bites itself.  
- ✅ *Wall Collision Detection* – Hitting the wall ends the game.  
- ✅ *Food Consumption & Growth* – Eat food to grow and increase your score.  
- ✅ *Max Score Tracking* – Your highest score is saved for the session.  
- ✅ *Smooth Real-Time Controls* – Use *arrow keys* or *WASD* to move.  
- ✅ *Restart Option* – Press *'R'* to restart the game after losing.  
- ✅ *Dynamic Food Placement* – The food appears randomly on the grid.  
- ✅ *Colored UI* – Snake 🟢, Food 🟡, and Borders 🔴 for better visuals.  
- ✅ *Adjustable Grid Size* – Set custom grid width and height before playing.  
- ✅ *Game Speed Control* – The snake moves at a fixed but adjustable speed.  

## 🕹 Controls

| *Key*  | *Action*              |
| -------- | ----------------------- |
| ⬅ / 'A' | Move Left               |
| ➡ / 'D' | Move Right              |
| ⬆ / 'W' | Move Up                 |
| ⬇ / 'S' | Move Down               |
| ❌ 'X'    | Quit the game           |
| 🔄 'R'   | Restart after game over |

## 🌜 How to Play

1. Run the program.  
2. Enter the *grid width* and *height*.  
3. Control the *snake* 🐍 to eat *food* 🍎 and grow.  
4. Avoid hitting *walls* or *yourself*.  
5. Press *'X'* to exit at any time.  
6. Try to *beat your high score*! 🏆  

## ⚡ Installation & Execution

1. *Compile the code* using a C++ compiler (like g++):
   bash
   g++ -o SnakeGame snake_game.cpp
   
2. *Run the game*:
   bash
   ./SnakeGame
   

## 🛠 Requirements

- *C++ Compiler* (e.g., MinGW for Windows, g++ for Linux/macOS)  
- Windows OS (for conio.h & system("cls"), modify for Linux/Mac)  

## 📊 Data Structure Analysis

The game uses *vector<pair<int, int>>* to store the snake’s body segments. This allows *dynamic growth* when food is eaten and *efficient movement* using insertions and deletions. The *Direction enum* is used to track the snake’s movement.

## 🔍 Function Breakdown

### 1️⃣ InitializeGame() 🛠
- Resets the game variables.  
- Places the snake at the center of the grid.  
- Calls PlaceFood() to generate food.  

### 2️⃣ PlaceFood() 🍎
- Generates food at a random position.  
- Ensures food doesn’t appear on the snake.  

### 3️⃣ DrawGame() 🎨
- Clears the screen and redraws the grid.  
- Displays the snake, food, and borders using colors.  

### 4️⃣ HandleInput() 🎮
- Detects key presses (Arrow keys / WASD / X).  
- Prevents the snake from reversing direction.  

### 5️⃣ UpdateGame() 🔄
- Moves the snake in the current direction.  
- Checks for *food consumption, **wall collision, and **self-collision*.  
- Ends the game if a collision occurs.  

### 6️⃣ Run() 🚀
- Runs the game loop until the player quits.  
- Displays the *Game Over* message and *restart option*.  

## 🎨 Future Enhancements

- 🔹 *Pause/Resume feature* ⏸ ▶  
- 🔹 *Sound effects* 🎵  
- 🔹 *Custom difficulty levels* 🎧  
- 🔹 *Multiplayer mode* 🎮  

Enjoy the game & happy coding! 🚀🐍
