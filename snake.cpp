#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// Function to set console text colors
void SetColor(const string& colorCode) {
    cout << "\033[" << colorCode << "m";  // Escape sequence for colors
}

// Function to display large text for "GAME OVER!!!!"
void DisplayGameOverMessage() {
    SetColor("31"); //Set color to Red
    cout << " GGGGG      AAA      M     M    EEEEE         OOO    V     V  EEEEE  RRRRR      !!!  " << endl;
    cout << " G         A   A     MM   MM    E            O   O   V     V  E      R   R      !!!   " << endl;
    cout << " G  GG    AAAAAAA    M M M M    EEEE         O   O   V     V  EEEE   RRRRR      !!!   " << endl;
    cout << " G   G    A     A    M  M  M    E            O   O    V   V   E      R    R     !!!   " << endl;
    cout << " GGGGG    A     A    M     M    EEEEE         OOO      VVV    EEEEE  R     R    !!!  " << endl;
    SetColor("0"); //Set color to Default
}

// Function to display instructions after Game Over
void DisplayInstructions() {
    cout << "\nPress 'R' to restart or any other key to exit." << endl;
}

class SnakeGame {
private:
    bool isGameOver;
    const int gridWidth;
    const int gridHeight;
    int gameSpeed;
    vector<pair<int, int>> snakeBody;
    int headX, headY, foodX, foodY, score;
    Direction currentDirection;
    

public:
    SnakeGame(int width, int height, int speed)
        : gridWidth(width), gridHeight(height), isGameOver(false), score(0), gameSpeed(speed), currentDirection(STOP) {
        InitializeGame();
    }

    void InitializeGame() {
        isGameOver = false;
        score = 0;
        currentDirection = STOP;
        headX = gridWidth / 2;
        headY = gridHeight / 2;
        snakeBody.clear();
        snakeBody.push_back({headX, headY});
        PlaceFood();
    }

    void PlaceFood() {
        foodX = rand() % gridWidth;
        foodY = rand() % gridHeight;

        // Ensure food is not placed where the snake is
        for (auto segment : snakeBody) {
            if (segment.first == foodX && segment.second == foodY) {
                PlaceFood();  // Retry if food is placed on snake body
                break;
            }
        }
    }

    void DrawGame() {
        // Clearing the screen cross-platform
        system("cls");

        // Draw top border
        SetColor("31");
        for (int i = 0; i < gridWidth + 2; i++) {
            cout << "- ";
        }
        SetColor("0");
        cout << endl;

        // Draw the grid
        for (int i = 0; i < gridHeight; i++) {
            SetColor("31");
            cout << "|";  // Left border
            SetColor("0");

            for (int j = 0; j < gridWidth; j++) {
                if (i == headY && j == headX) {
                    SetColor("32"); //Set color to Green
                    cout << "O "; // Snake head
                    SetColor("0");
                } else if (i == foodY && j == foodX) {
                    SetColor("33"); //Set color to yellow
                    cout << "F "; // Food
                    SetColor("0");
                } else {
                    bool isBodyPart = false;
                    for (auto part : snakeBody) {
                        if (part.first == j && part.second == i) {
                            SetColor("32");
                            cout << "o "; // Snake body
                            SetColor("0");
                            isBodyPart = true;
                            break;
                        }
                    }

                    if (!isBodyPart) cout << "  ";  // Empty space
                }
            }

            SetColor("31"); 
            cout << "|";  // Right border
            SetColor("0"); 
            cout << endl;
        }

        // Draw bottom border
        SetColor("31"); 
        for (int i = 0; i < gridWidth + 2; i++) {
            cout << "- ";
        }
        SetColor("0"); 
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void HandleInput() {
        if (_kbhit()) {
            Direction previousDirection = currentDirection;
            int key = _getch();

            // Handle arrow keys
            if (key == 224) {
                key = _getch();
                switch (key) {
                    case 75: currentDirection = LEFT; break;  // Left arrow
                    case 77: currentDirection = RIGHT; break; // Right arrow
                    case 72: currentDirection = UP; break;    // Up arrow
                    case 80: currentDirection = DOWN; break;  // Down arrow
                }
            } else {
                switch (key) {
                    case 'a': currentDirection = LEFT; break;
                    case 'd': currentDirection = RIGHT; break;
                    case 'w': currentDirection = UP; break;
                    case 's': currentDirection = DOWN; break;
                    case 'x': isGameOver = true; break;
                }
            }

            // Prevent the snake from reversing direction
            if ((previousDirection == UP && currentDirection == DOWN) ||
                (previousDirection == DOWN && currentDirection == UP) ||
                (previousDirection == LEFT && currentDirection == RIGHT) ||
                (previousDirection == RIGHT && currentDirection == LEFT)) {
                currentDirection = previousDirection;
            }
        }
    }

    void UpdateGame() {
        snakeBody.insert(snakeBody.begin(), {headX, headY});
        if (headX == foodX && headY == foodY) {
            score += 10;
            PlaceFood();
        } else {
            snakeBody.pop_back();
        }

        switch (currentDirection) {
            case LEFT: headX--; break;
            case RIGHT: headX++; break;
            case UP: headY--; break;
            case DOWN: headY++; break;
            default: break;
        }

        if (headX < 0 || headX >= gridWidth || headY < 0 || headY >= gridHeight)
            isGameOver = true;

        for (int i = 1; i < snakeBody.size(); i++) {
            if (snakeBody[i].first == headX && snakeBody[i].second == headY) {
                isGameOver = true;
                break;
            }
        }
    }

    void Run() {
        int maxScore = 0;
        while (true) {
            while (!isGameOver) {
                DrawGame();
                HandleInput();
                UpdateGame();
                Sleep(gameSpeed);
            }

            maxScore = max(maxScore, score);

            // Display Game Over Message
            DisplayGameOverMessage();
            DisplayInstructions();

            char choice;
            cout << "Your score: " << score << endl;
            cout << "Maximum Score: " << maxScore << endl;
            cout << "Press 'R' to restart or any other key to exit: ";
            cin >> choice;
            if (choice == 'R' || choice == 'r') {
                InitializeGame();
            } else {
                break;
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    int width, height;
    cout << "Enter grid width: ";
    cin >> width;
    cout << "Enter grid height: ";
    cin >> height;

    // Set game speed to 100 (fixed value)
    int speed = 100;

    SnakeGame game(width, height, speed);
    game.Run();

    return 0;
}