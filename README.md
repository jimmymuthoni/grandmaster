### Grandmaster:

![grandmaster](https://github.com/jimmymuthoni/grandmaster/blob/7342d47ce1eaf6ff2625105a1efdf169bda33307/granmaster.png)


Grandmaster is a Qt6-based chess game written in C++. It provides a fully interactive chessboard with piece movement validation, highlighting, and sound effects.

#### Features
- Complete chessboard with 8x8 grid.
- Correct initial piece setup.
- Piece movement validation for all chess pieces (Pawn, Rook, Knight, Bishop, Queen, King).
- Path checking for pieces like Rook, Bishop, and Queen.
- Visual highlighting of selected squares.
- Turn-based system (White/Black).
- Sound effects on moves.

#### Technologies
- C++17
- Qt6 Widgets, Svg, Multimedia
- Object-oriented design with proper use of Qt signals and slots.

#### Instructions to Set up and run this project:

1. clone this repo:

```
git clone https://github.com/jimmymuthoni/grandmaster.git

```

2. Install the dependencies.

```
sudo apt update
sudo apt-install qt6-base-dev build-essential cmake qt6-svg-dev

```

3. Build the project:

```
cd grandmaster
mkdir build
cd build
cmake ..
make

```

4. Run the project:

```
./grandmaster
```