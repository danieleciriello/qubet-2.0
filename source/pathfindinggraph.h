#ifndef PATHFINDINGGRAPH_H
#define PATHFINDINGGRAPH_H

#include "QVector"
#include "level.h"

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
    Node(unsigned int _id, float _zBegin, float _zEnd):
        id(_id),
        zBegin(_zBegin),
        zEnd(_zEnd)
    {}

private:
    unsigned int    id;         /**< TODO */
    float           zBegin;     /**< TODO */
    float           zEnd;       /**< TODO */
    float           xPosition;  /**< TODO */
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
    Connection(unsigned int _cost,
               unsigned int _fromNode,
               unsigned int _toNode):
        cost(_cost),
        fromNode(_fromNode),
        toNode(_toNode)
    {}

    /**
     * @brief
     *
     * @return unsigned int
     */
    unsigned int getCost()
    {
        return cost;
    }

    /**
     * @brief
     *
     * @return unsigned int
     */
    unsigned int getFromNode()
    {
        return fromNode;
    }

    /**
     * @brief
     *
     * @return unsigned int
     */
    unsigned int getToNode()
    {
        return toNode;
    }

private:
    unsigned int cost;      /**< TODO */
    unsigned int fromNode;  /**< TODO */
    unsigned int toNode;    /**< TODO */
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
    PathfindingGraph(Level *_level);

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
     * @brief
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

private:
    Level                   *level;         /**< TODO */
    QVector<Node*>          nodes;          /**< TODO */
    QVector<Connection*>    connections;    /**< TODO */
};

#endif // LEVELGRAPH_H

