#include "aicubemover.h"

AICubeMover::AICubeMover(Cube *_cube, Level *_level, QObject *_parent):
    parent(_parent),
    cube(_cube),
    level(_level)
{
    pathfindingGraph = new PathfindingGraph(level, (int)(round(cube->getPosition()->x / 3.0f)));
    tempNode = pathfindingGraph->getNode(0);
    cubeControllingTimer = new QTimer(this);
    connect(cubeControllingTimer, SIGNAL(timeout()), this, SLOT(continueControl()));
    cubeControllingTimer->setSingleShot(true);
}

void AICubeMover::run()
{}

void AICubeMover::controlCube()
{
    cubeControllingTimer->start(30);
}

void AICubeMover::continueControl()
{

    if (!cube->isMoving() &&
            (round(cube->getPosition()->x / 3.0f) == tempNode->getXPosition()) &&
            ((cube->getPosition()->z / 3.0f) -3)  >= tempNode->getZPosition())
    {
        tempNode = pathfindingGraph->pop();
        qDebug()<<tempNode->getZPosition()<<tempNode->getXPosition();

        if(tempNode->getXPosition() < (int)(round(cube->getPosition()->x / 3.0f)))
        {
            cube->moveLeft();
            qDebug()<<"cube->moveLeft()";
        }

        else if(tempNode->getXPosition() > (int)(round(cube->getPosition()->x / 3.0f)))
        {
            cube->moveRight();
            qDebug()<<"cube->moveRight()";
        }
    }
    if(cube->getZ() < level->getLength() - 3 )
    cubeControllingTimer->start(30);
}
