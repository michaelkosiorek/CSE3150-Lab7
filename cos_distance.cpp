#include "cos_distance.h"


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double sum_of_products=0;
    for (int dimension_idx=0; dimension_idx < one.all_dimensions.size(); dimension_idx++) {
        sum_of_products += one.all_dimensions[dimension_idx]*two.all_dimensions[dimension_idx];
    }
    return sum_of_products;
}

double magnitude(const double_vector & my_vector) {
    double sum_of_squares=0;
    for (auto dimension : my_vector.all_dimensions) {
        sum_of_squares += square(dimension);
    }
    return sqrt(sum_of_squares);
};

double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude);
    if (d > .99999) 
        d = 1.0;
    if (d < -.99999)
        d = -1.0;


    return 1.0 - d;
}

std::vector<vector_pair> make_vec_pairs(const std::vector<double_vector>& vectors_original) {
    int vectors_original_size = vectors_original.size();
    std::vector<vector_pair> vec_pairs;
    
    for (int i = 0; i < vectors_original_size - 1; i++) {
        for (int j = i + 1; j < vectors_original_size; j++) {
            vector_pair new_pair(vectors_original[i], vectors_original[j], cosine_distance(vectors_original[i], vectors_original[j]));
            vec_pairs.push_back(new_pair);
        }
    }
    return vec_pairs;
}