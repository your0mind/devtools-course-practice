// Copyright 2018 Gribov Pavel

#ifndef MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_
#define MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_

#include <vector>

class LMetricsFloat {
 public:
    static float linf_vec_distance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2);
    static float l1_vec_distance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float l2_vec_distance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float l3_vec_distance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float l4_vec_distance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
 private:
    static std::vector<float> vec_substract_mod(const std::vector<float> vec1,
                                                const std::vector<float> vec2);
};

#endif  // MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_
