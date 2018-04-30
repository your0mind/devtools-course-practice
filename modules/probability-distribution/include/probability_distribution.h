// Copyright 2018 Kuznetsov Konstantin

#ifndef MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_
#define MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_

#include <vector>

class DescretePD {
 public:
    DescretePD();
    DescretePD(const std::vector<double> &values,
      const std::vector<double> &probabilities);

 private:
    bool sumOfProbabilities(const std::vector<double> &probabilities) const;
    std::vector<double> values_;
    std::vector<double> probabilities_;
};

#endif  // MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_
