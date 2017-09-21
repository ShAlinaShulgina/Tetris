#ifndef GAME_H
#define GAME_H

#include <figure.h>
#include <QKeyEvent>
#include <QMessageBox>
#include <QIcon>
#include <QTimerEvent>

class Game : public QWidget
{
protected:
    Figure *fig;
    int timer;

public:
    Game();
    ~Game();

    void timerEvent(QTimerEvent*);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // GAME_H
