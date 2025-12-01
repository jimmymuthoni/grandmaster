#include "chessboard.h"
#include <QtDebug>
#include <QIcon>
#include <cctype>
#include <QMap>
#include <QMediaPlayer>

QMap<QPushButton*, QString> squareOriginalStyles;


//structure of chessboard
ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent),selectedPiece(nullptr),currentTurn("white"){
    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    moveSound = new QMediaPlayer(this);
    moveSound-> setSource(QUrl("grc:/assets/sounds/move-self.mp3"));
    initializeBoard();
    setupInitialPosition();

}

//initilizing the chessboard
void ChessBoard::initializeBoard(){
    squares.resize(8, std::vector<QPushButton*>(8));

    for(int row=0; row<8; row++){
        for (int col=0;col<8;col++){
        QPushButton* square = new QPushButton(this);
        square->setFixedSize(50,50);
        square->setProperty("row",row);
        square->setProperty("col",col);

        QString style = ((row + col) % 2 == 0)
            ? "background-color: #7c4c3e; font-size: 32px;"
            : "background-color: #512a2a; font-size: 32px;";
        square-> setStyleSheet(style);
        squareOriginalStyles[square] = style;

        connect(square, &QPushButton::clicked, this, &ChessBoard::squareClicked);
        squares[row][col] = square;
        layout->addWidget(square,row,col);
        }

    }

}


