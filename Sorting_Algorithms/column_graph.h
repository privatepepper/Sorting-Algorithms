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

    int quick_sort(int low, int high);
    int partition(int left_index, int right_index);
    int right_index = 0;
    int left_index = 0;
    int pivot;
    bool one_time = true;
    bool decrease_one_time = true;
    QVector <QPair <int, int> > recursive_saver;


    void swap(int &x, int &y);
    void reset();

private:

    int end;
    bool swapped = false;
};

#endif // COLUMN_GRAPH_H
