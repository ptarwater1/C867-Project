#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {
protected: Degree degree = NETWORK;
public: Degree getDegree() override;
};