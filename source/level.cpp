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


#include "level.h"
#include "defines.h"

#include <QDomElement>

Level::Level(QString _filename, QObject *_parent, Skin *_asphaltSkin) :
    parent(_parent),
    filename(_filename),
    currentObstacleId(0),
    isLoaded(false),
    asphaltSkin(_asphaltSkin),
    skyboxName("nebula")
{
    name = "not yet loaded";
}

Level::Level(QString _name, GLfloat _length, GLfloat _width, QObject *_parent, Skin *_asphaltSkin) :
    parent(_parent),
    name(_name),
    isInStory(false),
    length(_length),
    width(_width),
    currentObstacleId(0),
    isLoaded(false),
    asphaltSkin(_asphaltSkin),
    skyboxName("nebula")
{
    if (name != "")
    {
        filename = name + ".xml";
        filename.replace(" ", "_");
    }
}

Level::~Level()
{
#ifdef USE_DISPLAY_LISTS

    for (int i = 0; i < obstaclesDisplayLists.count(); i++)
        if (obstaclesDisplayLists.at(i) != 0)
            glDeleteLists(obstaclesDisplayLists.at(i), 1);

#endif
    for (QMap<GLint,Obstacle*>::iterator i = obstaclesList.begin(); i != obstaclesList.end(); i++)
    {
        if (i.value() != NULL)
            dynamic_cast<Obstacle*>(i.value())->~Obstacle();
    }

    obstaclesList.~QMap();
}

QString Level::getFilename()
{
    return filename;
}

void Level::setFilename(QString _filename)
{
    filename = _filename;
}

QString Level::getName()
{
    return name;
}

void Level::setName(QString _name)
{
    name = _name;
}

bool Level::getIsInStory()
{
    return isInStory;
}

void Level::setIsInStory(bool _isInStory)
{
    isInStory = _isInStory;
}

GLfloat Level::getWidth()
{
    return width;
}

GLfloat Level::getLength()
{
    return length;
}

GLfloat Level::getGravity()
{
    return gravity;
}

GLvoid Level::setGravity(GLfloat _gravity)
{
    gravity = _gravity;
}

QString Level::getSkyboxName()
{
    return skyboxName;
}

void Level::setAsphaltSkin(Skin *_asphaltSkin)
{
    asphaltSkin = _asphaltSkin;
}

GLuint Level::createObstacleDisplayList(Obstacle *_obstacle)
{
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
        glPushName(_obstacle->getId());
            _obstacle->draw(false);
        glPopName();
    glEndList();
    return list;
}

void Level::addObstacle(Obstacle *_obstacle, bool inTemp)
{
    GLint id = ++currentObstacleId;
    _obstacle->setId(id);
    if (inTemp)
        tempObstaclesList.insert(id, _obstacle);
    else
        obstaclesList.insert(id, _obstacle);

    #ifdef USE_DISPLAY_LISTS
        if (!inTemp)
        {
            obstaclesDisplayLists.append(createObstacleDisplayList(_obstacle));
            _obstacle->setDisplayListID(obstaclesDisplayLists.size());
        }
    #endif
}

void Level::deleteObstacle(GLint _id)
{
    QMap<GLint,Obstacle*>::iterator i = obstaclesList.find(_id);

    i = tempObstaclesList.find(_id);

    if (i != tempObstaclesList.end())
    {
        dynamic_cast<Obstacle*>(i.value())->~Obstacle();
        tempObstaclesList.remove(_id);
    }
}

void Level::moveObstacle(GLint _id, Vector3f *newCell)
{
    QMap<GLint,Obstacle*>::iterator i = obstaclesList.find(_id);

    if (i != obstaclesList.end())
        dynamic_cast<Obstacle*>(i.value())->setCell(newCell);
}

QMap<GLint,Obstacle*> Level::getObstaclesList()
{
    return obstaclesList;
}

bool Level::load()
{
    if (isLoaded)
        return true;

    QDomDocument document(filename);
    QFile file("resources/levels/xml/" + filename);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    if (!document.setContent(&file))
    {
        file.close();
        return false;
    }

    file.close();

    QDomElement levelElement = document.documentElement();
    width = levelElement.attribute("width", QString::number(LEVEL_WIDTH_DEFAULT)).toInt();
    length = levelElement.attribute("length", QString::number(LEVEL_LENGTH_DEFAULT)).toInt();
    gravity = levelElement.attribute("gravity", QString::number(LEVEL_GRAVITY_DEFAULT)).toInt();

    QDomElement obstacleElement = levelElement.firstChildElement("obstacle");

    while(!obstacleElement.isNull())
    {
        GLint modelId = obstacleElement.attribute("model", "1").toInt();

        Vector3f *cells = new Vector3f(obstacleElement.attribute("x", "0").toInt(),
                                       obstacleElement.attribute("y", "0").toInt(),
                                       obstacleElement.attribute("z", "0").toInt());

        Obstacle *obstacle = new Obstacle(modelId, cells);

        QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 255);

        if (color.lightness() < 100)
            color = color.lighter();

        if (color.lightness() > 150)
            color = color.darker();

        obstacle->setColor(color);

        GLint obstacleId = obstacleElement.attribute("id", "1").toInt();
        obstacle->setId(obstacleId);

        if (obstacleId > currentObstacleId)
            currentObstacleId = obstacleId;

        obstacle->setType(1);

        obstaclesList.insert(obstacleId, obstacle);
        #ifdef USE_DISPLAY_LISTS
            obstaclesDisplayLists.append(createObstacleDisplayList(obstacle));
            obstacle->setDisplayListID(obstaclesDisplayLists.size()-1);
        #endif
        obstacleElement = obstacleElement.nextSiblingElement("obstacle");
    }

    isLoaded = true;
    return true;
}

bool Level::save(bool *newlyCreated)
{
    for (QMap<GLint,Obstacle*>::iterator i = tempObstaclesList.begin(); i != tempObstaclesList.end(); i++)
    {
        #ifdef USE_DISPLAY_LISTS
            obstaclesDisplayLists.append(createObstacleDisplayList(dynamic_cast<Obstacle*>(i.value())));
            dynamic_cast<Obstacle*>(i.value())->setDisplayListID(obstaclesDisplayLists.size());
        #endif
        obstaclesList.insert(i.key(),i.value());
    }
    tempObstaclesList.clear();

    QDomDocument document;

    QDomElement levelElement = document.createElement("level");
    levelElement.setAttribute("width", width);
    levelElement.setAttribute("length", length);
    levelElement.setAttribute("gravity", gravity);
    document.appendChild(levelElement);

    Obstacle *obstacle = NULL;
    Vector3f *cells = NULL;

    for (QMap<GLint,Obstacle*>::iterator i = obstaclesList.begin(); i != obstaclesList.end(); i++)
    {
        obstacle = dynamic_cast<Obstacle*>(i.value());
        QDomElement obstacleElement = document.createElement("obstacle");
        cells = obstacle->getCell();
        obstacleElement.setAttribute("id", obstacle->getId());
        obstacleElement.setAttribute("model", obstacle->getModelId());
        obstacleElement.setAttribute("x", cells->x);
        obstacleElement.setAttribute("y", cells->y);
        obstacleElement.setAttribute("z", cells->z);
        levelElement.appendChild(obstacleElement);
    }

    QFile file("resources/levels/xml/" + filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream stream(&file);
        document.save(stream, 4);
        file.close();
    }
    else
    {
        return false;
    }

    if (!isInStory)
    {
        QDomDocument levels("levels");
        QFile levelsFile("resources/levels/levels.xml");
        if (!levelsFile.open(QIODevice::ReadOnly))
            return false;

        if (!levels.setContent(&levelsFile))
        {
            levelsFile.close();
            return false;
        }

        levelsFile.close();

        QDomElement rootElement = levels.documentElement();
        QDomElement levelElement = rootElement.firstChildElement("level");

        bool found = false;
        while (!levelElement.isNull())
        {
            if (levelElement.attribute("name") == name)
            {
                found = true;
                break;
            }

            levelElement = levelElement.nextSiblingElement("level");
        }

        if (newlyCreated != NULL)
            *newlyCreated = !found;

        if (!found)
        {
            levelElement = levels.createElement("level");
            levelElement.setAttribute("filename", filename);
            levelElement.setAttribute("name", name);
            rootElement.appendChild(levelElement);

            QFile levelsFileWrite("resources/levels/levels.xml");
            if (levelsFileWrite.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                QTextStream stream(&levelsFileWrite);
                levels.save(stream, 4);
                levelsFileWrite.close();
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

GLvoid Level::draw(GLboolean simplifyForPicking)
{
    glPushName(LEVEL);
    drawPrism(width, LEVEL_HEIGHT, length, asphaltSkin, false, true);
    glPopName();

    glPushMatrix();
        glTranslatef(-(width / 2.0f), (LEVEL_HEIGHT / 2.0f), (length / 2.0f));
        glPushName(OBSTACLES);

        #ifdef USE_DISPLAY_LISTS

        for (int i = 0; i < obstaclesDisplayLists.size(); i++)
                    glCallList(obstaclesDisplayLists.at(i));
        #else

        for (QMap<GLint,Obstacle*>::iterator i = obstaclesList.begin(); i != obstaclesList.end(); i++)
        {
            glPushName(i.key());
            dynamic_cast<Obstacle*>(i.value())->draw(simplifyForPicking);
            glPopName();
        }
        #endif

        for (QMap<GLint,Obstacle*>::iterator i = tempObstaclesList.begin(); i != tempObstaclesList.end(); i++)
        {
            glPushName(i.key());
            dynamic_cast<Obstacle*>(i.value())->draw(simplifyForPicking);
            glPopName();
        }

        glPopName();
    glPopMatrix();
}

GLint Level::getObstacleListCount()
{
    return obstaclesList.count();
}

GLvoid Level::clearObstaclesList()
{
    obstaclesList.clear();
    #ifdef USE_DISPLAY_LISTS
        obstaclesDisplayLists.clear();
    #endif
    clearTempObstaclesList();
}

GLvoid Level::clearTempObstaclesList()
{
    tempObstaclesList.clear();
}

void Level::createObstacleCells()
{
    int xMax = (int)(width / 3) + 2;
    int yMax = 5;
    int zMax = (int)(length / 3) + 5;

    obstacleCells.resize(xMax);

    for (int x = 0; x < xMax; x++)
    {
        obstacleCells[x].resize(yMax);

        for (int y = 0; y < yMax; y++)
        {
            obstacleCells[x][y].resize(zMax);

            for (int z = 0; z < zMax; z++)
            {
                obstacleCells[x][y][z] = false;
            }
        }
    }

    for (QMap<GLint,Obstacle*>::iterator i = obstaclesList.begin(); i != obstaclesList.end(); i++)
    {
        Obstacle *obstacle = dynamic_cast<Obstacle*>(i.value());
        Vector3f *cell = obstacle->getCell();

        obstacleCells[cell->x][cell->y][cell->z] = true;

        switch (obstacle->getModelId())
        {
        case OBSTACLE_I:
            obstacleCells[cell->x]    [cell->y + 1][cell->z]     = true;
            break;

        case OBSTACLE_L:
            obstacleCells[cell->x + 1][cell->y]    [cell->z]     = true;
            obstacleCells[cell->x + 1][cell->y + 1][cell->z]     = true;
            break;

        case OBSTACLE_CUBE_BIG:
            obstacleCells[cell->x]    [cell->y + 1][cell->z]     = true;

            obstacleCells[cell->x + 1][cell->y]    [cell->z]     = true;
            obstacleCells[cell->x + 1][cell->y + 1][cell->z]     = true;

            obstacleCells[cell->x]    [cell->y]    [cell->z + 1] = true;
            obstacleCells[cell->x]    [cell->y + 1][cell->z + 1] = true;

            obstacleCells[cell->x + 1][cell->y]    [cell->z + 1] = true;
            obstacleCells[cell->x + 1][cell->y + 1][cell->z + 1] = true;
            break;
        }
    }
}

QVector<QVector<QVector<bool> > > Level::getObstacleCells()
{
    createObstacleCells();
    return obstacleCells;
}
