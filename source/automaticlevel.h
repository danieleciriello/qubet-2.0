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


#ifndef AUTOMATICLEVEL_H
#define AUTOMATICLEVEL_H

#include "skybox.h"
#include "obstacle.h"
#include "level.h"

/**
 * @brief This class rapresents a Level of Qubet, with its obstacle.
 *        It is able to draw itself simply using the draw function.
 *        It can also load the xml description file and parse it.
 *
 * @version 1.1
 * @author Daniele Ciriello
 */
class AutomaticLevel: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Creates a level from an id, a name, a length and a width.
     *        It is used to create a new Level from the LevelEditor.
     *
     * @param _width is the width of the Level.
     * @param _parent is the parent of the Level.
     * @param _asphaltSkin is the asphalt Skin for the Level.
    */
    explicit AutomaticLevel(GLfloat _width, Skin *_asphaltSkin = NULL, QObject *_parent = 0);


    /**
     * @brief Returns the width of the Level.
     *
     * @returns the width of the Level.
     */
    GLfloat getWidth();

    /**
     * @brief Returns the gravity of the Level.
     *
     * @returns the gravity of the Level.
     */
    GLfloat getGravity();

    /**
     * @brief Set the gravity of the Level.
     *
     * @param _gravity is the new gravity of the Level.
     */
    GLvoid setGravity(GLfloat _gravity);

    /**
     * @brief Returns the Skybox Name.
     *
     * @returns the skyboxName.
     */
    QString getSkyboxName();

    /**
     * @brief returns a pointter to the obstacleCells matrix
    */
    QVector<QVector<QVector<bool> > > & getObstacleCells();

    /**
     * @brief returns temporaryLevel
    */
    Level *getTemporaryLevel();

    /**
     * @brief Draws the Level and its obstacles.
     *
     * @param simplifyForPicking is used to state if you want to draw it simplified.
     */
    GLvoid draw(GLboolean simplifyForPicking);

    /**
     * @brief Safely destroies a AutomaticLevel instance.
     *
    */
    ~AutomaticLevel();

private:

    QObject *parent; /**< It is the parent of Level. */
    Level *temporaryLevel; /**< TODO */
    QMap<GLint, Level*> levelsSet; /**< TODO */
    QMap<GLint, Obstacle*> obstaclesList; /**< It is the Level List of obstacles. */
    GLint width; /**< It is the Level width. */
    GLfloat gravity; /**< It is the Level gravity. */
    QString ambientMusicFilename; /**< It is the Level ambient music filename. */
    QString skyboxName; /**< It is the name of the skybox to use. */
    Skin *asphaltSkin; /**< It is the asphalt Skin. */
    QVector<QVector<QVector<bool> > > obstacleCells; /**< It is the 3d matrix rappresent obstacle cells */
    GLint complexity;
    GLint fillingFactor;

    /**
     * @brief initialize the AutomaticLevel Object
    */
    void initAutomaticLevel();

    /**
     * @brief initialize the cellsMatrix
    */
    void createObstacleCells();
};

#endif // AUTOMATICLEVEL_H
