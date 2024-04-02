#ifndef _COS_DISTANCE_H_
#define _COS_DISTANCE_H_

#include <iostream>
#include <vector>
#include <cmath>


struct double_vector {
    int n_dimensions;
    std::vector<double> all_dimensions;

    double_vector() : n_dimensions(0), all_dimensions({}) {};
    double_vector(int n, std::vector<double> all_dimensions) :
        n_dimensions(n), all_dimensions(all_dimensions) {};
    double_vector(const double_vector& dv) {
        n_dimensions = dv.n_dimensions;
        all_dimensions = dv.all_dimensions;
    };
};

struct vector_pair {
    double_vector v1, v2;
    double vec_cos_distance;

    vector_pair() : v1(), v2(), vec_cos_distance() {};
    vector_pair(double_vector v1, double_vector v2, double vec_cos_distance) : v1(v1), v2(v2), vec_cos_distance(vec_cos_distance) {};
    vector_pair(const vector_pair & vp) : v1(vp.v1), v2(vp.v2), vec_cos_distance(vp.vec_cos_distance) {};
};

struct vector_distances {
    std::vector<vector_pair> vector_pairs;
    std::vector<double_vector> double_vectors;

    vector_distances() : vector_pairs({}), double_vectors({}) {};
    vector_distances(std::vector<vector_pair> vector_pairs, std::vector<double_vector> double_vectors) :
        vector_pairs(vector_pairs), double_vectors(double_vectors) {};
    vector_distances(const vector_distances& vd) {
        vector_pairs = vd.vector_pairs;
        double_vectors = vd.double_vectors;
    }
};

std::vector<vector_pair> make_vec_pairs(const std::vector<double_vector> &vectors);
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);
bool compare_doubles(double x, double y);

#endif