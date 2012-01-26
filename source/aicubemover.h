#ifndef AICUBEMOVER_H
#define AICUBEMOVER_H

#include "level.h"
#include "cube.h"
#include "pathfindinggraph.h"
#include <QThread>

class AICubeMover : public QThread
{
    Q_OBJECT

public:

    /**
     * @brief
     *
     * @param _level
     * @param _parent
     */
    explicit AICubeMover(Cube *_cube, Level *_level, QObject *_parent = 0);

    /**
     * @brief todo
     *
     */
    void controlCube();

private:

    QObject             *parent;                /**< It is a callback variable to the parent of AudioManager. */
    Cube                *cube;                  /**< TODO */
    Level               *level;                 /**< TODO */
    PathfindingGraph    *pathfindingGraph;      /**< TODO */
    Node                *tempNode;              /**< TODO */
    QTimer              *cubeControllingTimer;  /**< TODO */

    /**
     * @brief It is the reimplementation of QThread's run() method. It is empty because
     *        the AudioManager is a semi-thread, all actions are managed by signals.
     */
    void run();

private slots:

        /**
         * @brief
         *
         */
        void continueControl();

};

#endif // AICUBEMOVER_H
