#pragma once
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student {
protected: Degree degree = SOFTWARE;
public: Degree getDegree() override;
};