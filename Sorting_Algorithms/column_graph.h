#ifndef COLUMN_GRAPH_H
#define COLUMN_GRAPH_H

#include <QtCore>
#include <QtGui>

class column_graph {

public:

    column_graph();
    QVector <int> columns;
    void generate_random_columns(int max_value, int width);

    void bubble_sort();
    int current_index = 1;
    int checking_right_now = 2;
    int end;
};

#endif // COLUMN_GRAPH_H
