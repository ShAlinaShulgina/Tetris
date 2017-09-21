#include "game.h"

Game::Game():QWidget(0)
{
    fig = new Figure;
    setFixedSize(240,420);
    timer = startTimer(400);
    QIcon ico("ico.ico");
    setWindowIcon(ico);
}

void Game::timerEvent(QTimerEvent *)
{
    if (fig->canMove())
    {
        fig->next(1);
        update();
    }
    else
    {
        fig->newFigure();
    }
    if (fig->gover())
    {
        killTimer(timer);
        QMessageBox::information(0, "Status", "Game over");
    }
}

void Game::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    fig->show(p);
}

void Game::keyPressEvent(QKeyEvent *e)
{
    fig->keypress(e->key());
}


Game::~Game()
{
    delete fig;
}
