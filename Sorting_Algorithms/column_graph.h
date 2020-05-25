#ifndef COLUMN_GRAPH_H
#define COLUMN_GRAPH_H

#include <QtCore>
#include <QtGui>

class column_graph {

public:

    column_graph();
    QVector <int> columns;
    void generate_random_columns(int max_value, int width);
};

#endif // COLUMN_GRAPH_H
