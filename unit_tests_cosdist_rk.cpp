#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "read_vectors.h"
#include "cos_distance.h"


TEST_CASE("cos-distance-r^k") {

    SUBCASE("read one double vector") {
        std::ifstream single_line_stream;
        single_line_stream.open("single_double_vector.txt");
        double_vector actual_dv = read_dv_from_line(single_line_stream);

        double_vector expected_dv = {5, {-1, 1, 10000, 0, 3.1415926}};

        CHECK_EQ(actual_dv.all_dimensions, expected_dv.all_dimensions);
    };

    SUBCASE("read one empty double vector") {

    };

}