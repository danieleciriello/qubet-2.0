//    Qubet  -  Copyright (C) 2011
//    Enrico Bacis
//    Daniele Ciriello

//    Qubet is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include "automaticlevel.h"
#include "defines.h"

AutomaticLevel::AutomaticLevel(GLfloat _width, Skin *_asphaltSkin, QObject *_parent) :
    parent(_parent),
    width(_width),
    asphaltSkin(_asphaltSkin)
{
    initAutomaticLevel();
}

AutomaticLevel::~AutomaticLevel()
{
}

GLfloat AutomaticLevel::getWidth()
{
    return width;
}

GLfloat AutomaticLevel::getGravity()
{
    return gravity;
}

GLvoid AutomaticLevel::setGravity(GLfloat _gravity)
{
    gravity = _gravity;
}

QString AutomaticLevel::getSkyboxName()
{
    return skyboxName;
}

Level *AutomaticLevel::getTemporaryLevel()
{
    return temporaryLevel;
}

GLvoid AutomaticLevel::draw(GLboolean simplifyForPicking)
{
    temporaryLevel->draw(simplifyForPicking);
}

void AutomaticLevel::initAutomaticLevel()
{
    complexity = 90;
    fillingFactor = 20;
    temporaryLevel = new Level("", 300.0f, width);
    temporaryLevel->setGravity(10.0f);
    createObstacleCells();
}

void AutomaticLevel::createObstacleCells()
{
    int xMax                = (int)(width / 3.0f);
    int yMax                = 5;
    int zMax                = (int)(temporaryLevel->getLength() / 3.0f);
    int freeingXCell        = qrand() % xMax;
    int nextFreeingXCell    = 0;
    int k                   = 2;

    obstacleCells.resize(xMax);

    for (int x = 0; x < xMax; x++)
    {
        obstacleCells[x].resize(yMax);

        for (int y = 0; y < yMax; y++)
        {
            obstacleCells[x][y].resize(zMax);

            for (int z = 0; z < zMax; z++)
            {
                if(y > 0 || z < 2)
                    obstacleCells[x][y][z] = false;
                else
                    obstacleCells[x][y][z] = (qrand() % 100 < fillingFactor ? true : false);
            }
        }
    }

    while(k < zMax)
    {
        nextFreeingXCell =  freeingXCell +  (freeingXCell == 0 ? (qrand() % 100 < complexity ? 1 : 0) :
                                                                 (freeingXCell == (xMax -1) ? (qrand() % 100 < complexity ? -1 : 0) :
                                                                                              (qrand() % 100 < complexity ? (qrand() % 100 < 50 ? 1 : -1) : 0)));
        obstacleCells[freeingXCell]     [yMax - 1][k] = true;

        for (int nextFreeingZCell = 0; nextFreeingZCell < 4; nextFreeingZCell++)
        {
            if (k < zMax)
            {
                obstacleCells[freeingXCell]     [0][k] = false;
                obstacleCells[nextFreeingXCell] [0][k] = false;
            }
            k++;
        }

        freeingXCell = nextFreeingXCell;
        if (k < zMax)
        {
            obstacleCells[freeingXCell][0][++k] = false;
            //k++;
        }

        //for (int nextFreeingZCell = 0; nextFreeingZCell < qrand() % 3; nextFreeingZCell++)
        for (int nextFreeingZCell = 0; nextFreeingZCell < 3; nextFreeingZCell++)
        {
            if (k < zMax)
            {
                obstacleCells[freeingXCell][0][k++] = false;
            }
        }
    }

    Obstacle *obstacle = NULL;

    for (int x = 0; x < xMax; x++)
    {
        for (int y = 0; y < yMax; y++)
        {
            for (int z = 0; z < zMax; z++)
            {
                if (obstacleCells[x][y][z] == true)
                {
                    obstacle = new Obstacle(0, new Vector3f(x, y, z));

                    QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 255);

                    if (color.lightness() < 100)
                        color = color.lighter();

                    if (color.lightness() > 150)
                        color = color.darker();

                    obstacle->setColor(color);

                    temporaryLevel->addObstacle(obstacle);
                }
            }
        }
    }
}

QVector<QVector<QVector<bool> > > &  AutomaticLevel::getObstacleCells()
{
    return obstacleCells;
}
