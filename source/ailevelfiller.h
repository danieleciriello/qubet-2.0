#ifndef AILEVELFILLER_H
#define AILEVELFILLER_H

#include <QObject>
#include "level.h"

#define Y_MAX 6
#define Z_GAP_MAX 10
#define Z_GAP_MIN 5

#define X_STATE_LEFT_EDGE               0x01
#define X_STATE_RIGHT_EDGE              0x02

/**
 * @brief todo
 *
 */
class AILevelFiller : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief todo
     *
     * @param parent
     */
    explicit AILevelFiller(QObject *parent = 0);

    /**
     * @brief todo
     *
     * @param level
     */
    void createObstaclesList(Level *_level);

private:

    Level                               *level;         /**< TODO */
    float                               difficulty;     /**< TODO */
    int                                 xState;         /**< TODO */

    /**
     * @brief todo
     *
     */
    void checkXState(int currentX);

    /**
     * @brief
     *
     * @return int
     */
    int updateZGap();

    /**
     * @brief todo
     *
     * @param _currentX
     * @param _currentY
     * @param _currentZ
     */
    void addObstacles(int _currentX,int _currentY,int _currentZ);

    /**
    * @brief
    *
    * @param _currentTempX
    * @param _currentTempY
    * @param _currentTempZ
    */
    void createAndAddObstacle(int _currentTempX,int _currentTempY,int _currentTempZ, bool red = false);

signals:

public slots:

};

#endif // AILEVELFILLER_H
