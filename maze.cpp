#include <iostream>
#include <stdio.h> 
using namespace std;

class Maze {
    private:
    int max;
    //       y  x
    int maze[10][10];
    int x;
    int y;

    public: Maze() {
        max = 10;
        for (int x = 0; x < max; x++) {
            for (int y = 0; y < max; y++) {
                maze[y][x] = 0;
            }
        }
        x = 2;
        y = 2;
        maze[y][x] = 1;
    }

    public: void draw() {
    
        for (int yy = 0; yy < max; yy++) {
            for (int xx = 0; xx < max; xx++) {
                cout << " " << maze[yy][xx] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        
    }

    public: void up() {
            if (y == 0) return;
            maze[y][x] = 0;
            y--;
            maze[y][x] = 1;
    }

    public: void down() {
        if (y == max-1) return;
        maze[y][x] = 0;
        y++;
        maze[y][x] = 1;
    }

    public: void left() {
        if (x == 0) return;
        maze[y][x] = 0;
        x--;
        maze[y][x] = 1;
    }

    public: void right() {
        if (x == max-1) return;
        maze[y][x] = 0;
        x++;
        maze[y][x] = 1;
    }


};







int main() {
    system("stty sane"); // normal mode
 

    Maze *maze = new Maze();
    
 
   maze->draw();

   while (true) {
        // Wait for single character 
        system("stty raw"); // to allow keypress
        cout << "==>";
        char input = getchar();
        if (input == 'x') break;
        switch (input) {
            case 'a': 
                maze->left();
                break;
            case 's':
                maze->down();
                break;
            case 'd': 
                maze->right();
               break;
            case 'w': 
                maze->up();
               
        }
        system("stty sane"); // normal terminal mode again
        cout << "\n";
        maze->draw() ;

        
   }




}