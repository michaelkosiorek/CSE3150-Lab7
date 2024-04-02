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
    };

    SUBCASE("test simple 5d vectors") {
        double_vector v1 = {5, {1, 1, 1, 1, 1}};
        double_vector v2 = {5, {1, 1, 1, 1, 0}};

        vector_distances vec_distances;
        vec_distances.double_vectors.push_back(v1);
        vec_distances.double_vectors.push_back(v2);


        CHECK(compare_doubles(cosine_distance(v1, v2), .463648));        
    };

    SUBCASE("test 5d vectors in full structure") {
        double_vector v1 = {5, {1, 2.5, 0.5, 0.99, 1.5}};
        double_vector v2 = {5, {1, 3.6, 1.9, 0.98, -4}};
        double_vector v3 = {5, {1, 4.5, 3.2, 0.71, 8.2}};

        vector_distances vec_distances;
        vec_distances.double_vectors.push_back(v1);
        vec_distances.double_vectors.push_back(v2);
        vec_distances.double_vectors.push_back(v3);

        vec_distances.vector_pairs = make_vec_pairs(vec_distances.double_vectors);

        sort(vec_distances.vector_pairs.begin(), vec_distances.vector_pairs.end(), [](const vector_pair &v1, const vector_pair &v2) -> bool {
            return v1.vec_cos_distance < v2.vec_cos_distance;
        }
        );

        std::vector<double> expected_sorted_distances = {.604261, 1.25817, 1.72212};

        for (int i=0; i < vec_distances.vector_pairs.size(); i++) {
            // std::cout << vec_distances.vector_pairs[i].vec_cos_distance << std::endl;
            // std::cout << expected_sorted_distances[i] << std::endl;
            CHECK(compare_doubles(vec_distances.vector_pairs[i].vec_cos_distance, expected_sorted_distances[i]));
        }
    };


}
