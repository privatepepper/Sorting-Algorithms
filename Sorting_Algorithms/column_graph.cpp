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
    end = columns.size() - 1;
}

bool column_graph::bubble_sort() {

    if (columns[current_index] > columns[checking_right_now]){

        int temp = columns[current_index];
        columns[current_index] = columns[checking_right_now];
        columns[checking_right_now] = temp;
        swapped = true;
    }
    current_index++;
    checking_right_now++;

    if (current_index == end){

        current_index = 0;
        checking_right_now = 1;
        end--;
        if (end == 0 || !swapped)
            return true;
        swapped = false;
    }

    return false;
}


