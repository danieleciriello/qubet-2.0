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


#ifndef LEVEL_H
#define LEVEL_H

#include "obstacle.h"
#include "skybox.h"

#define STANDARD_LENGHT 450.0f
#define STANDARD_WIDTH  15.0f

/**
 * @brief This class rapresents a Level of Qubet, with its obstacle.
 *        It is able to draw itself simply using the draw function.
 *        It can also load the xml description file and parse it.
 *
 * @version 1.1
 * @author \#34
 */
class Level : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Creates a level from an id, a name, a length and a width.
     *        It is used to create a new Level from the LevelEditor.
     *
     * @param _name is the name of the Level.
     * @param _length is the length of the Level.
     * @param _width is the width of the Level.
     * @param _parent is the parent of the Level.
     * @param _asphaltSkin is the asphalt Skin for the Level.
    */
    explicit Level(QString _name = "", GLfloat _length = STANDARD_LENGHT, GLfloat _width = STANDARD_WIDTH, QObject *_parent = 0, Skin *_asphaltSkin = NULL);

    /**
     * @brief Creates a Level from a filename.
     *        It is used in the Loader.
     *
     * @param _filename is the filename to load.
     * @param _parent is the parent of the Level.
     * @param _asphaltSkin is the asphalt Skin for the Level.
     */
    explicit Level(QString _filename, QObject *_parent = 0, Skin *_asphaltSkin = NULL);

    /**
     * @brief Safely destroies a Level instance.
     */
    ~Level();

    /**
     * @brief Returns the filename of the Level.
     *
     * @returns the filename of the Level.
     */
    QString getFilename();

    /**
     * @brief Set the Level filename.
     *
     * @param _filename is the filename to set.
     */
    void setFilename(QString _filename);

    /**
     * @brief Returns the name of the Level.
     *
     * @returns the name of the Level.
     */
    QString getName();

    /**
     * @brief Set the name of the Level.
     *
     * @param _name is the name to set.
     */
    void setName(QString _name);

    /**
     * @brief Returns the a variable that states if the Level is in the story.
     *
     * @returns true if the Level is in the story, else false.
     */
    bool getIsInStory();

    /**
     * @brief Set the a variable that states if the Level is in the story.
     *
     * @param _isInStory is the variable to set. (true if the Level is in the story, else false).
     */
    void setIsInStory(bool _isInStory);

    /**
     * @brief Returns the width of the Level.
     *
     * @returns the width of the Level.
     */
    GLfloat getWidth();

    /**
     * @brief Returns the length of the Level.
     *
     * @returns the length of the Level.
     */
    GLfloat getLength();

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
     * @brief todo
     *
     * @param _asphaltSkin
     */
    void setAsphaltSkin(Skin *_asphaltSkin);

    /**
     * @brief Adds an obstacle to the Level.
     *
     * @param _obstacle is the obstacle to add.
     * @param inTemp if is true, obstacle will be put in tempObstaclesList, else in obstaclesList.
     */
    void addObstacle(Obstacle *_obstacle, bool inTemp = true);

    /**
     * @brief Deletes an obstacle.
     *
     * @param _id is the obstacle id.
     */
    void deleteObstacle(GLint _id);

    /**
     * @brief Moves an obstacle to a new position.
     *
     * @param _id is the id of the obstacle to move.
     * @param newCell is the new cell.
     */
    void moveObstacle(GLint _id, Vector3f *newCell);

    /**
     * @brief Returns the Level's Obstacles List.
     *
     * @return the Level's Obstacles List.
     */
    QMap<GLint,Obstacle*> getObstaclesList();

    /**
     * @brief Loads the Level from xml form using the filename as input.
     *
     * @returns true if the load is successful, else false.
     */
    bool load();

    /**
     * @brief Saves the Level in a xml form using the filename as output.
     *
     * @param newlyCreated is the return variable that is true is the level has been
     *        newly created, else false.
     *
     * @returns true if save is successful, else false.
     */
    bool save(bool *newlyCreated = 0);

    /**
     * @brief Draws the Level and its obstacles.
     *
     * @param simplifyForPicking is used to state if you want to draw it simplified.
     */
    GLvoid draw(GLboolean simplifyForPicking);

    /**
     * @brief Returns the number of obstacles in the level.
     *
     * @returns the number of obstacles in the level.
    */
    GLint getObstacleListCount();

    /**
     * @brief Returns the number of obstacles in the level.
    */
    GLvoid clearObstaclesList();

    /**
     * @brief Clears the not saves obstacles.
    */
    GLvoid clearTempObstaclesList();

    /**
     * @brief return obstacleCells
     *
     * @return QVector<QVector<QVector<bool> > > obstacleCells
     */
    QVector<QVector<QVector<bool> > > getObstacleCells();


private:
    QObject                             *parent;            /**< It is the parent of Level. */
    QString                             filename;           /**< It is the Level xml description filename. */
    QString                             name;               /**< It is the Level name. */
    bool                                isInStory;          /**< It is the variable that states if the Level is in the story. */
    QMap<GLint,Obstacle*>               obstaclesList;      /**< It is the Level List of obstacles. */
    QMap<GLint,Obstacle*>               tempObstaclesList;  /**< It is the Level List of obstacles. */
    GLint                               length;             /**< It is the Level length. */
    GLint                               width;              /**< It is the Level width. */
    GLfloat                             gravity;            /**< It is the Level gravity. */
    GLint                               currentObstacleId;  /**< It is the current Obstacle Id (used to generate new IDs). */
    bool                                isLoaded;           /**< It is the variable that states if the level has already been fully loaded. */
    Skin                                *asphaltSkin;       /**< It is the asphalt Skin. */
    QString                             skyboxName;         /**< It is the name of the skybox to use. */
    QVector<QVector<QVector<bool> > >   obstacleCells;      /**< It is the 3d matrix rappresent obstacle cells */

    #ifdef USE_DISPLAY_LISTS
    QList<GLuint>                       obstaclesDisplayLists; /**< It is a list to save the Display List ID of each letter. */
    #endif

    /**
     * @brief Create the 3D Matrix of ObstacleCells.
     *
     * @return GLvoid
     */
    GLvoid createObstacleCells();

    /**
     * @brief It is an internal function to create the OpenGL displayList of an Obstacle.
     *
     * @param obstacle is the Obstacle you want to create a displayList for.
     * @return GLuint the displayList ID
     */
    GLuint createObstacleDisplayList(Obstacle* obstacle);
};

#endif // LEVEL_H
