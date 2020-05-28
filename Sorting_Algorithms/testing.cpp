//#include "catch.hpp"
//#include "column_graph.h"
//#include <vector>
//#include <QVector>

//std::vector <int> convert(QVector <int> qvec){

//    std::vector <int> vec;
//    for (int i = 0; i < qvec.size(); i++){
//        vec.push_back(qvec[i]);
//    }
//    return vec;
//}

//std::vector <int> theAnswer(QVector <int> vec)
//{
//    column_graph graph;
//    vec = graph.bubble_sort(vec);

//    return convert(vec);
//}

//TEST_CASE("Bubble sort", "") {

//    REQUIRE_THAT(theAnswer({}), Catch::Equals<int>({}));
//    REQUIRE_THAT(theAnswer({1, 2, 3, 4, 5, 6}), Catch::Equals<int>({1, 2, 3, 4, 5, 6}));
//    REQUIRE_THAT(theAnswer({6, 5, 4, 3, 2, 1}), Catch::Equals<int>({1, 2, 3, 4, 5, 6 }));
//    REQUIRE_THAT(theAnswer({1}), Catch::Equals<int>({1}));
//    REQUIRE_THAT(theAnswer({1, 5, 6, 4, 3, 2}), Catch::Equals<int>({1, 2, 3, 4, 5, 6}));
//}




