#include "chessboard.h"
#include <QtDebug>
#include <QIcon>
#include <cctype>
#include <QMap>
#include <QMediaPlayer>

QMap<QPushButton*, QString> squareOriginalStyles;


//initial stste of chessbord during new game
ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent),selectedPiece(nullptr),currentTurn("white"){
    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    moveSound = new QMediaPlayer(this);
    moveSound-> setSource(QUrl("grc:/assets/sounds/move-self.mp3"));
    initializeBoard();
    setupInitialPosition();

}


