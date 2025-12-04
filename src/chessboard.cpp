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

//getting path to pieces
QString ChessBoard::getPieceSvgPath(char piece){
    switch (piece) {
    case 'K': return ":/assets/pieces/w_king.svg";
    case 'Q': return ":/assets/pieces/w_queen.svg";
    case 'R': return ":/assets/pieces/w_rook.svg";
    case 'B': return ":/assets/pieces/w_bishop.svg";
    case 'N': return ":/assets/pieces/w_knight.svg";
    case 'P': return ":/assets/pieces/w_pawn.svg";
    case 'k': return ":/assets/pieces/b_king.svg";
    case 'q': return ":/assets/pieces/b_queen.svg";
    case 'r': return ":/assets/pieces/b_rook.svg";
    case 'b': return ":/assets/pieces/b_bishop.svg";
    case 'n': return ":/assets/pieces/b_knight.svg";
    case 'p': return ":/assets/pieces/b_.pawn";
    
    default: return "";
    }
}


//setting the initillposition of the pieces
void ChessBoard::setupInitialPosition(){
    for (int row=0;row<8;row++){
        for (int col=0;col<8;col++){
            char piece = initilPosition[row][col];
            QString svgPath = getPieceSvgPath(piece);
            if (!svgPath.isEmpty()) {
                QIcon icon(svgPath);
                squares[row][col]->setIcon(icon);
                squares[row][col]->setIconSize(QSize(36,36));
                squares[row][col]->setProperty("pieceType",QChar(piece));

                if (std::isupper(piece)){
                    squares[row][col]->setProperty("pieceColor","white");
                } else {
                    squares[row][col]->setProperty("pieceColor","black");
                }
            } else {
                    squares[row][col]->setIcon(QIcon());
                    squares[row][col]->setProperty("pieceColor","none");
                    squares[row][col]->setProperty("pieceType","Qchar");
                }

            }

        }
    }

