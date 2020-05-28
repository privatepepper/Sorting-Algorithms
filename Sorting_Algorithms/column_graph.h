#ifndef COLUMN_GRAPH_H
#define COLUMN_GRAPH_H

#include <QtCore>
#include <QtGui>

class column_graph {

public:

    column_graph();
    QVector <int> columns;
    void generate_random_columns(int max_value, int width);

    bool bubble_sort();
    int current_index = 0;
    int checking_right_now = 1;

private:

    int end;
    bool swapped = false;
};

#endif // COLUMN_GRAPH_H
