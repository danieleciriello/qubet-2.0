#ifndef PATHFINDINGGRAPH_H
#define PATHFINDINGGRAPH_H

#include "QVector"
#include "level.h"

#define MAX_VALUE           65535
#define NODE_STATE_LEFT     0x01
#define NODE_STATE_RIGHT    0x02
#define NODE_STATE_FRONT    0x04
#define NODE_STATE_CHECKED  0x07


/**
 * @brief todo
 *
 */
class Corridor
{
public:

    /**
    * @brief todo
    *
    */
    Corridor()
    {}

    /**
    * @brief
    *
    * @param xPosition
    * @param zBegin
    * @param zEnd
    */
    Corridor(int _xPosition, int _zBegin, int _zEnd):
        xPosition(_xPosition),
        zBegin(_zBegin),
        zEnd(_zEnd)
    {}

    /**
     * @brief
     *
     * @param _xPosition
     */
    void setXPosition(int _xPosition)
    {
        xPosition = _xPosition;
    }

    /**
     * @brief
     *
     * @return int
     */
    int getXPosition()
    {
        return xPosition;
    }

    /**
     * @brief
     *
     * @param _zBegin
     */
    void setZBegin(int _zBegin)
    {
        zBegin = _zBegin;
    }

    /**
     * @brief
     *
     * @return int
     */
    int getZBegin()
    {
        return zBegin;
    }

    /**
     * @brief
     *
     * @param _zEnd
     */
    void setZEnd(int _zEnd)
    {
        zEnd = _zEnd;
    }

    /**
     * @brief
     *
     * @return int
     */
    int getZEnd()
    {
        return zEnd;
    }

private:
    int xPosition;  /**< TODO */
    int zBegin;     /**< TODO */
    int zEnd;       /**< TODO */
};

/**
 * @brief
 *
 */
class Node
{
public:

    /**
     * @brief
     *
     * @param _id
     * @param _zBegin
     * @param _zEnd
     */
    Node(unsigned int _id, int _xPosition, int _yPosition, int _zPosition):
        id(_id),
        xPosition(_xPosition),
        yPosition(_yPosition),
        zPosition(_zPosition),
        state(0),
        costSoFar(MAX_VALUE),
        shortestPathBeforeNode(NULL)
    {}

    unsigned int getId()
    {
        return id;
    }

    int getXPosition()
    {
        return xPosition;
    }

    int getYPosition()
    {
        return yPosition;
    }

    int getZPosition()
    {
        return zPosition;
    }

    unsigned char getState()
    {
        return state;
    }

    void setState(unsigned char _state)
    {
       state = state | _state;
    }

    void unSetState(unsigned char _state)
    {
        state = state & ~_state;
    }

    void setCostSoFar(int _costSoFar)
    {
        costSoFar = _costSoFar;
    }

    int getCostSoFar()
    {
        return costSoFar;
    }

    void setBeforeNode(Node * _shortestPathBeforeNode)
    {
        shortestPathBeforeNode = _shortestPathBeforeNode;
    }

    Node *getBeforeNode()
    {
        return shortestPathBeforeNode;
    }

private:
    unsigned int    id;         /**< TODO */
    int             xPosition;    /**< TODO */
    int             yPosition;    /**< TODO */
    int             zPosition;    /**< TODO */
    unsigned char   state;
    int             costSoFar;
    Node*           shortestPathBeforeNode;
};

/**
 * @brief
 *
 */
class Connection
{
public:
    /**
     * @brief
     *
     * @param _cost
     * @param _fromNode
     * @param _toNode
     */
    Connection(float _cost,
               Node *_fromNode,
               Node *_toNode):
        cost(_cost),
        fromNode(_fromNode),
        toNode(_toNode)
    {}

    /**
     * @brief
     *
     * @return unsigned int
     */
    float getCost()
    {
        return cost;
    }

    /**
     * @brief
     *
     * @return unsigned int
     */
    Node *getFromNode()
    {
        return fromNode;
    }

    /**
     * @brief
     *
     * @return unsigned int
     */
    Node *getToNode()
    {
        return toNode;
    }

private:
    float cost;      /**< TODO */
    Node        *fromNode;  /**< TODO */
    Node        *toNode;    /**< TODO */
};

/**
 * @brief
 *
 */
class PathfindingGraph
{
public:
    /**
     * @brief
     *
     */
    PathfindingGraph(Level *_level, int xPos);

    /**
     * @brief todo
     *
     */
    ~PathfindingGraph();

    /**
     * @brief
     *
     * @param _node
     */
    void insertNode(Node *_node);

    /**
     * @brief
     *
     * @param _connection
     */
    void insertConnection(Connection *_connection);

    /**
     * @brief todo
     *
     * @param _id
     * @return Node *
     */
    Node *getNode(unsigned int _id);

    /**
     * @brief
     *
     * @param _node
     * @return QVector<Connection *>
     */
    QVector<Connection*> *getConnections(Node *_node);

    /**
     * @brief
     *
     * @param aStarAlgorithm
     */
    void findPath(bool aStarAlgorithm = false);

    /**
     * @brief
     *
     * @return Node *
     */
    Node* pop();

    /**
     * @brief
     *
     * @param node
     * @return bool
     */
    bool isTheGoal(Node* node);

private:
    Level                               *level;         /**< TODO */
    Node                                *head;          /**< TODO */
    Node                                *goal;          /**< TODO */
    Node                                *tempNode;      /**< TODO */
    QVector<Corridor*>                  corridors;      /**< TODO */
    QMap<unsigned int, Node*>           nodes;          /**< TODO */
    QVector<Connection*>                connections;    /**< TODO */
    QStack<Node*>                       pathStack;      /**< TODO */

    /**
     * @brief todo
     *
     */
    void findCorridors();

    /**
     * @brief
     *
     */
    void createGraph(Node *node);

    /**
     * @brief todo
     *
     * @param _xPosition
     * @param _yPosition
     * @param _zPosition
     */
    void getNodeID(int _xPosition, int _yPosition, int _zPosition);

    /**
     * @brief
     *
     * @param _cost
     * @param _fromNode
     * @param _toNode
     */
    void appendConnectionIfNotExist(float _cost, Node *_fromNode, Node*_toNode);

    /**
     * @brief
     *
     */
    void createPathStack();
};

#endif // LEVELGRAPH_H

