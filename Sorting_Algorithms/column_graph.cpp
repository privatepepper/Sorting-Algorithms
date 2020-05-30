#include "column_graph.h"


column_graph::column_graph() {

     qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
}

void column_graph::generate_random_columns(int max_value, int width) {

    if (columns.size() != 0)
        columns.clear();

    while (columns.size() != width)
        columns.push_back(qrand() % (max_value - 2) + 1);

    end = columns.size() - 1;
    recursive_saver.push_back({0, columns.size() - 1});
}

bool column_graph::bubble_sort() {

    if (columns[current_index] > columns[checking_right_now]){

        swap(columns[current_index], columns[checking_right_now]);
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

int column_graph::quick_sort(int low, int high) {

    if (low < high){

        int j = partition(low, high);

        if (j != -1){
            one_time = true;
            recursive_saver.pop_front();
            recursive_saver.push_back({low, j - 1});
            recursive_saver.push_back({j + 1, high});
            return 1;
        }

        return 0;
    }
    return -1;
}

int column_graph::partition(int low, int high) {

    if (one_time){
        pivot = columns[high];
        left_index = (low - 1);
        right_index = low;
        one_time = false;
    }

    if (right_index < high){

        if (columns[right_index] <= pivot){

            left_index++;
            swap(columns[left_index], columns[right_index]);
        }

        right_index++;
        return -1;
    }   else {

        swap(columns[left_index + 1], columns[high]);
        return (left_index + 1);
    }
}

void column_graph::swap(int &x, int &y) {

    int temp = x;
    x = y;
    y = temp;
}

void column_graph::reset() {

    one_time = true;
    decrease_one_time = true;
}




