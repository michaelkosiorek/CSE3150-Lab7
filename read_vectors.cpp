#include "read_vectors.h"


double_vector read_dv_from_line(std::istream& in_stream) {
    double_vector dv;
    std::string line;

    std::getline(in_stream, line);
    std::istringstream is(line);
    double next;

    while (is >> next) dv.all_dimensions.push_back(next);

    return dv;
}

vector_distances read_all_dvs_from_file(std::istream& in_stream) {
    vector_distances vec_distances;
    std::string line;

    while (! in_stream.eof()) {
        double_vector next_d_vec = read_dv_from_line(in_stream);
        if (next_d_vec.all_dimensions.size() > 0) vec_distances.double_vectors.push_back(next_d_vec);
    }

    vec_distances.vector_pairs = make_vec_pairs(vec_distances.double_vectors);
    

    return vec_distances;
}
