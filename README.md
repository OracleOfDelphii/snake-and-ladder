![Game Screenshot](https://github.com/ariaman5/snake-and-ladder/blob/master/Screenshot%20from%202018-03-03%2019-00-34.png?raw=true "Screenshot")
![Game Screenshot](https://raw.githubusercontent.com/ariaman5/snake-and-ladder/master/Screenshot%20from%202019-05-29%2011-33-36.png)
# Snake and Ladder
This is a simple terminal snake & ladder game.
I made it for basics of computer course and it is my first c++ project.I tried my best to write code with good-readability and learned many things from it.
# Game Features
Highly customizable.You can define number of snakes , ladders , cells and players.

It uses an implemention of BFS algorithm to find shortest path from player P to last cell(I wrote an implemention of djikstra algorithm for fun too).You can take average of distances as a factor of game difficulty(for simplicity).

Colorful with simple animations thanks to ANSI escape sequences(some enviornments may or may not support all of them).

playing sound and music with SDL library.
# libraries/frameworks used:
-SDL2 : playing dice sound and music.Background music is from Mount and Blade : With Fire and Sword.

QT : QDir and QString to work on directories and files.

C++ standard library.

# How to play
Each play presses enter on his turn to throw dice.

# TO-DO :
Designing game levels based on Marcov chain.
