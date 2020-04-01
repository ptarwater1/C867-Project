#pragma once
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student {
protected: Degree degree = SECURITY;
public: Degree getDegree() override;
};