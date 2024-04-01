#include "read_vectors.h"


double_vector read_dv_from_line(std::istream& in_stream) {
    double_vector dv;
    std::string line;

    std::getline(in_stream, line);
    std::istringstream is(line);
    std::string next;

    while (is >> next) dv.all_dimensions.push_back(stod(next));

    return dv;
}

