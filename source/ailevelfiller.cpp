#include "ailevelfiller.h"

AILevelFiller::AILevelFiller(QObject *parent) :
    QObject(parent),
    difficulty(0.0f),
    xState(0)
{
}

void AILevelFiller::createObstaclesList(Level *_level)
{
    level = _level;
    int currentX            = (int)(((level->getWidth() / 3.0f) - 1) / 2);
    int currentY            = 0;
    int currentZ            = 0;

    addObstacles(currentX, currentY, currentZ);
}

void AILevelFiller::addObstacles(int _currentX,int _currentY,int _currentZ)
{
    if (_currentZ >= (int)(level->getLength() / 3.0f))
        return;

    int currentTempX    = _currentX;
    int currentTempY    = _currentY;
    int currentTempZ    = _currentZ;
    int zGap            = updateZGap();
    qDebug()<<"xgap: " + QString::number(zGap) + "\n";
    checkXState(currentTempX);

    if(difficulty <= 1.0f)
        difficulty += 0.002f;

    qDebug()<< difficulty;
    if(qrand() % 100 < (int)(difficulty * 100))
    {
        if( xState & X_STATE_LEFT_EDGE )
        {
            if( xState & X_STATE_RIGHT_EDGE )
            {
                addObstacles(currentTempX, currentTempY, (currentTempZ + zGap + 1));
            }
            else
            {
                for (int i = 1; i < (int)(level->getWidth() / 3.0f); i++)
                    for (int j = currentTempZ; j < (currentTempZ + zGap +1); j++)
                        if( qrand() % 100 < difficulty)
                            createAndAddObstacle(i, currentTempY, j);

                createAndAddObstacle(currentTempX, currentTempY, (currentTempZ + zGap +1));
                addObstacles((++currentTempX), currentTempY, (currentTempZ + zGap + 1));
            }
        }
        else if( xState & X_STATE_RIGHT_EDGE )
        {
            for (int i = (int)(level->getWidth() / 3.0f) -1; i >= 0; i--)
                for (int j = currentTempZ; j < (currentTempZ + zGap +1); j++)
                    if( qrand() % 100 < difficulty)
                        createAndAddObstacle(i, currentTempY, j);

            createAndAddObstacle(currentTempX, currentTempY, (currentTempZ + zGap +1));
            addObstacles((--currentTempX), currentTempY, (currentTempZ + zGap + 1));
        }
        else
        {
            for (int i = 0; i < currentTempX -1; i++)
                for (int j = currentTempZ; j < (currentTempZ + zGap +1); j++)
                    if( qrand() % 100 < difficulty)
                        createAndAddObstacle(i, currentTempY, j);

            for (int i = currentTempX +1; i < (int)(level->getWidth() / 3.0f); i++)
                for (int j = currentTempZ; j < (currentTempZ + zGap +1); j++)
                    if( qrand() % 100 < difficulty)
                        createAndAddObstacle(i, currentTempY, j);

            createAndAddObstacle(currentTempX, currentTempY, (currentTempZ + zGap +1));
            qrand() % 100 < 50 ? addObstacles((++currentTempX), currentTempY, (currentTempZ + zGap + 1)):
                                 addObstacles((--currentTempX), currentTempY, (currentTempZ + zGap + 1));
        }
    }
    else
    {
        addObstacles(currentTempX, currentTempY, currentTempZ + 3);
    }
}

int AILevelFiller::updateZGap()
{
    return (int)(((Z_GAP_MIN - Z_GAP_MAX) * difficulty) + Z_GAP_MAX);
}

void AILevelFiller::checkXState(int currentX)
{
    if (currentX == 0)
        xState = xState | X_STATE_LEFT_EDGE;
    else
        xState = xState & ~X_STATE_LEFT_EDGE;
    if (currentX == (int)((level->getWidth() / 3.0f) - 1) )
        xState = xState | X_STATE_RIGHT_EDGE;
    else
        xState = xState & ~X_STATE_RIGHT_EDGE;
}

void AILevelFiller::createAndAddObstacle(int _currentTempX,int _currentTempY,int _currentTempZ)
{
    Obstacle *obstacle = new Obstacle(1, new Vector3f(_currentTempX, _currentTempY, _currentTempZ ));

    QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 255);

    if (color.lightness() < 100)
        color = color.lighter();

    if (color.lightness() > 150)
        color = color.darker();

    obstacle->setColor(color);

    level->addObstacle(obstacle, false);

    qDebug()<<"obstacle added";
}
