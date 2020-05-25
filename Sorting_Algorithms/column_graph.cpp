#include "column_graph.h"

column_graph::column_graph() {

     qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
}

void column_graph::generate_random_columns(int max_value, int width) {

    if (columns.size() != 0)
        columns.clear();

    while (columns.size() != width){
        columns.push_back(qrand() % max_value);
    }
}
