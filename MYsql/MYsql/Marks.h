#pragma once

#include <iostream>
#include <string>

class Marks {
private:
    std::string studentid;
    float isa1;
    float isa2;
    float esa;
    float project;

public:
    // Constructors
    Marks() : isa1(0), isa2(0), esa(0), project(0) {}

    Marks(std::string id, float i1, float i2, float e, float p)
        : studentid(id), isa1(i1), isa2(i2), esa(e), project(p) {}

    // Getters
    std::string getStudentId() const { return studentid; }
    float getIsa1() const { return isa1; }
    float getIsa2() const { return isa2; }
    float getEsa() const { return esa; }
    float getProject() const { return project; }

    // Setters
    void setStudentId(std::string id) { studentid = id; }
    void setIsa1(float i1) { isa1 = i1; }
    void setIsa2(float i2) { isa2 = i2; }
    void setEsa(float e) { esa = e; }
    void setProject(float p) { project = p; }


};


