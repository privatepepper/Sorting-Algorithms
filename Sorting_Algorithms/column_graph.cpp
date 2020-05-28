#include "column_graph.h"


column_graph::column_graph() {

     qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
}

void column_graph::generate_random_columns(int max_value, int width) {

    if (columns.size() != 0)
        columns.clear();

    while (columns.size() != width){
        columns.push_back(qrand() % (max_value - 2) + 1);
    }

 //  columns = {0, 50, 40, 30, 20, 10};
   end = columns.size() - 1;
}

void column_graph::bubble_sort() {

    if (current_index == end){
        current_index = 1;
        checking_right_now = 2;
        end--;
    }

    if (columns[current_index] > columns[checking_right_now]){

        int temp = columns[current_index];
        columns[current_index] = columns[checking_right_now];
        columns[checking_right_now] = temp;
    }
    current_index++;
    checking_right_now++;
}
