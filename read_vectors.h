#ifndef _READ_VECTORS_H_
#define _READ_VECTORS_H_

#include <istream>
#include <sstream>
#include <fstream>
#include <vector>

#include "cos_distance.h"


double_vector read_dv_from_line(std::istream& in_stream);
vector_distances read_all_dvs_from_file(std::istream& in_stream);

#endif