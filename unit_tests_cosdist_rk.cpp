#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "read_vectors.h"
#include "cos_distance.h"


std::ostream& operator<<(std::ostream& os, const std::vector<double>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

TEST_CASE("cos-distance-r^k") {

    SUBCASE("read one double vector") {
        std::ifstream single_line_stream;
        single_line_stream.open("single_double_vector.txt");
        double_vector actual_dv = read_dv_from_line(single_line_stream);

        double_vector expected_dv = {5, {-1, 1, 10000, 0, 3.1415926}};

        CHECK_EQ(actual_dv.all_dimensions, expected_dv.all_dimensions);
    };

    SUBCASE("read one empty double vector") {
        std::ifstream single_line_stream;
        single_line_stream.open("empty_vector.txt");
        double_vector actual_dv = read_dv_from_line(single_line_stream);

        double_vector expected_dv = {0, {}};

        CHECK_EQ(actual_dv.all_dimensions, expected_dv.all_dimensions); 
    };

    SUBCASE("new dot-product func") {
        double_vector v1 = {3, {2, 0, 1}};
        double_vector v2 = {3, {2, 0, 1}};

        CHECK_EQ(dot_product(v1, v2), 5.0);
    };

    SUBCASE("basic cos-distance calc") {
        double_vector v1 = {3, {0, 0, 1}};
        double_vector v2 = {3, {0, 0, 1}};

        CHECK_EQ(cosine_distance(v1, v2), 0.0);

        double_vector v3 = {3, {1, 0, 0}};
        double_vector v4 = {3, {0, 0, 1}};

        CHECK_EQ(cosine_distance(v3, v4), 1.0);
    };

    SUBCASE("read many double vectors") {
        std::ifstream dv_stream;
        dv_stream.open("many_double_vectors.txt");
        vector_distances actual_dvs = read_all_dvs_from_file(dv_stream);

        vector_distances expected_dvs = {{}, {{5, {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {0, 0, 0, 0, 1}},
                                             {5,  {10.0, 10, 10.0, 10, 10.0}},
                                             {5,  {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {0, 0, 0, 0, 1}},
                                             {5,  {10.0, 10, 10.0, 10, 10.0}},
                                             {5,  {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {-1, 1, 10000, 0, 3.1415926}},
                                             {5,  {0, 0, 0, 0, 1}},
                                             {5,  {10.0, 10, 10.0, 10, 10.0}}}};

        // test all coordinates of all dv's
        for (int i=0; i < actual_dvs.double_vectors.size(); i++) {
            CHECK_EQ(actual_dvs.double_vectors[i].all_dimensions, expected_dvs.double_vectors[i].all_dimensions); 
        }

        // test for cos_distances
        /*
        for (int j=0; j < actual_dvs.vector_pairs.size(); j++) {
            std::cout << "Dist of these vectors below:" << actual_dvs.vector_pairs[j].v1.all_dimensions << "<->" << actual_dvs.vector_pairs[j].v2.all_dimensions << std::endl;
            std::cout << "DISTANCE:" << actual_dvs.vector_pairs[j].vec_cos_distance << std::endl;
        }
        */

    };

    SUBCASE("test 5d vectors") {
        double_vector v1 = {5, {1, 2, 3, 4, 5}};
        double_vector v2 = {5, {5, 4, 3, 2, 1}};
        double_vector v3 = {5, {0, 0, 1, 0, 0}};

        vector_distances vec_distances;
        vec_distances.double_vectors.push_back(v1);
        vec_distances.double_vectors.push_back(v2);
        vec_distances.double_vectors.push_back(v3);

        
    }

}
