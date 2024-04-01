#ifndef _COS_DISTANCE_H_
#define _COS_DISTANCE_H_


#include <iostream>
#include <vector>


struct double_vector {
    int n_dimensions;
    std::vector<double> all_dimensions;

    double_vector() : n_dimensions(0), all_dimensions({}) {};
    double_vector(int n, std::vector<double> all_dimensions) :
        n_dimensions(n), all_dimensions(all_dimensions) {};
    double_vector(const double_vector& dv) {
        n_dimensions = dv.n_dimensions;
        all_dimensions = dv.all_dimensions; };
};

struct vector_distances {
    std::vector<double> cos_distances;
    std::vector<double_vector> double_vectors;
};

#endif