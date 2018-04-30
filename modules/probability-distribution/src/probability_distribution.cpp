// Copyright 2018 Kuznetsov Konstantin

#include "include/probability_distribution.h"

#include <limits>
#include <string>
#include <vector>

DescretePD::DescretePD() {}

DescretePD::DescretePD(const std::vector<double> &values,
  const std::vector<double> &probabilities) {
    if (values.size() != probabilities.size()) {
        throw std::string("sizes of vectors do not match");
    } else {
        if (sumOfProbabilities(probabilities)) {
        values_ = values;
        probabilities_ = probabilities;
        } else {
            throw std::string("sum of probabilities != 1");
        }
    }
  }

bool DescretePD::sumOfProbabilities(const std::vector<double> &probabilities)
                                                                      const {
  double eps = std::numeric_limits<double>::epsilon();
  double sum = 0.0;

  for (int i = 0; i < static_cast<int>(probabilities.size()); i++)
    sum += probabilities[i];

  return (sum > 1.0 - eps) && (sum < 1.0 + eps);
}
