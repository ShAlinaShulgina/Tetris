#ifndef Figure_H
#define Figure_H

#include <QWidget>
#include <QPainter>

class Figure
{
private:
    int x, y;
    int stage, number;
    int Field[21][12];

public:
    Figure();
    void newFigure();

    int getX() const {return x;}
    int getY() const {return y;}
    int getStage() const {return stage;}
    int getNumber() const {return number;}

    bool canMove(int x = 0);
    bool canTurn();

    void fixFigure();
    void deleteLine();
    void next(int);
    void goLeft();
    void goRight();
    void makeTurn();


    bool gover();

    void show(QPainter &);
    void keypress(int);
};

#endif // Figure_H
