#include "figure.h"

bool fig[7][4][4][4] = {
//====================================
{
    {0, 0, 0, 0,
     0, 1, 1, 0,
     0, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 1, 0,
     0, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 1, 0,
     0, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 1, 0,
     0, 1, 1, 0,
     0, 0, 0, 0}
},
//====================================
{
    {0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0},

    {0, 0, 0, 0,
     0, 0, 0, 0,
     1, 1, 1, 1,
     0, 0, 0, 0},

    {0, 0, 1, 0,
     0, 0, 1, 0,
     0, 0, 1, 0,
     0, 0, 1, 0},

    {0, 0, 0, 0,
     1, 1, 1, 1,
     0, 0, 0, 0,
     0, 0, 0, 0},
},
//====================================
{
    {0, 1, 1, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     1, 0, 0, 0,
     1, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 0, 1, 0,
     0, 0, 1, 0,
     0, 1, 1, 0},

    {0, 0, 0, 0,
     0, 1, 1, 1,
     0, 0, 0, 1,
     0, 0, 0, 0}
},
//====================================
{
    {0, 1, 1, 0,
     0, 0, 1, 0,
     0, 0, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     1, 1, 1, 0,
     1, 0, 0, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 1, 0},

    {0, 0, 0, 0,
     0, 0, 0, 1,
     0, 1, 1, 1,
     0, 0, 0, 0}
},
//====================================
{
    {0, 0, 0, 0,
     0, 1, 1, 0,
     0, 0, 1, 1,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 0, 1, 0,
     0, 1, 1, 0,
     0, 1, 0, 0},

    {0, 0, 0, 0,
     1, 1, 0, 0,
     0, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 0, 1, 0,
     0, 1, 1, 0,
     0, 1, 0, 0},
},
//====================================
{
    {0, 0, 0, 0,
     0, 1, 1, 0,
     1, 1, 0, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 0, 0,
     0, 1, 1, 0,
     0, 0, 1, 0},

    {0, 0, 0, 0,
     0, 1, 1, 0,
     1, 1, 0, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 0, 0,
     0, 1, 1, 0,
     0, 0, 1, 0},
},
//====================================
{
    {0, 0, 0, 0,
     0, 1, 0, 0,
     1, 1, 1, 0,
     0, 0, 0, 0},

    {0, 0, 1, 0,
     0, 1, 1, 0,
     0, 0, 1, 0,
     0, 0, 0, 0},

    {0, 0, 0, 0,
     0, 1, 1, 1,
     0, 0, 1, 0,
     0, 0, 0, 0},

    {0, 1, 0, 0,
     0, 1, 1, 0,
     0, 1, 0, 0,
     0, 0, 0, 0}
}
};

Figure::Figure()
{
    newFigure();
    for (int i = 0; i < 20; i++)
        for (int j = 1; j < 11; j++)
            Field[i][j] = 0;
    for (int j = 0; j < 12; j++)
        Field[20][j] = 2;
    for (int i = 0; i < 21; i++)
    {
        Field[i][0] = 1;
        Field[i][11] = 1;
    }
}

void Figure::newFigure()
{
    x = 4; y = 0;
    srand(time(0));
    number = rand()%7;
    srand(time(0));
    stage = rand()%4;
}

bool Figure::canMove(int x)
{
    int dy = getY() + 1, dx = getX() + x;
    int num = getNumber(), st = getStage();

    for (int i = dy; i < dy + 4; i++)
        for (int j = dx; j < dx + 4; j++)
            if (Field[i][j] && fig[num][st][i - dy][j - dx])
                return false;
    return true;
}

bool Figure::canTurn()
{
    int dy = getY(), dx = getX();
    int num = getNumber(), st = getStage();

    if(st != 3)
        ++st;
    else
        st = 0;
    for (int i = dy; i < dy + 4; i++)
        for (int j = dx; j < dx + 4; j++)
            if (Field[i][j] && fig[num][st][i - dy][j - dx])
                return false;
    return true;
}

void Figure::fixFigure()
{
    int dx_now = getX(), dy_now = getY();
    int dx = getX(), dy = getY() + 1;
    int num = getNumber(), st = getStage();

    bool flag = false;
    for (int i = dy; i < dy + 4; i++)
        for (int j = dx; j < dx + 4; j++)
            if (Field[i][j] == 2 && fig[num][st][i - dy][j - dx] == 1)
            {
                flag = true;
                break;
            }

    if(flag)
    {
        for (int i = dy_now; i < dy_now + 4; i++)
            for (int j = dx_now; j < dx_now + 4; j++)
                if(Field[i][j] == 0 && fig[num][st][i - dy_now][j - dx_now] == 1)
                    Field[i][j] = 2;
    }
}

void Figure::deleteLine()
{
    bool res = false;
    int line = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (Field[i][j] == 2)
            {
                res = true;
                line = i;
            }
            else
            {
                res = false;
                break;
            }
        }

        if (res)
        {
            for (int i = 1; i < 11; i++)
                Field[line][i] = 0;
            for (int i = line; i > 1; i--)
                for (int j = 1; j < 11; j++)
                    Field[i][j] = Field[i - 1][j];
            for (int i = 1; i < 11; i++)
                Field[0][i] = 0;
            line = 0;
            res = false;
        }
    }
}

void Figure::next(int dy)
{
    if (canMove())
        y += dy;
    fixFigure();
    deleteLine();
}

void Figure::goLeft()
{
    if (canMove(-1))
        x -= 1;
}

void Figure::goRight()
{
    if (canMove(1))
        x += 1;
}

void Figure::makeTurn()
{
    int st = getStage();
    if (canTurn())
    {
        if(st != 3)
            stage += 1;
        else
            stage = 0;
    }
}

bool Figure::gover()
{
    for (int i = 0; i < 3; i++)
        for (int j = 1; j < 11; j++)
            if (Field[i][j])
                return true;
    return false;
}

void Figure::show(QPainter &p)
{
    p.save();
    p.setBrush(QBrush(Qt::color0, Qt::SolidPattern));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a = (x + j) * 20;
            int b = (y + i) * 20;
            if (fig[number][stage][i][j])
                p.drawRect(a, b, 20, 20);
        }
    }
    p.setBrush(QBrush(Qt::color1, Qt::SolidPattern));
    for(int i = 0; i < 21; i++)
        for(int j = 0; j < 12; j++)
            if(Field[i][j])
            {
                int a = j * 20;
                int b = i * 20;
                p.drawRect(a ,b, 20, 20);
            }
    p.restore();
}

void Figure::keypress(int key)
{
    switch(key)
    {
    case Qt::Key_Right:
        goRight();
        break;
    case Qt::Key_Left:
        goLeft();
        break;
    case Qt::Key_Up:
        makeTurn();
        break;
    case Qt::Key_Down:
        next(1);
        break;
    }
}
