#include <iostream>
#include <string>
#include <vector>

class Teacher {
private:
    std::string name;
    std::vector<Student*> students;

public:
    Teacher(std::string name) : name(name) {}

    void addStudent(Student* student) {
        students.push_back(student);
        student->setTeacher(this);
    }

    void removeStudent(Student* student) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == student) {
                students.erase(students.begin() + i);
                student->removeTeacher();
                break;
            }
        }
    }

    std::string getName() {
        return name;
    }

    std::vector<Student*> getStudents() {
        return students;
    }
};

class Student {
private:
    std::string name;
    Teacher* teacher;

public:
    Student(std::string name) : name(name), teacher(nullptr) {}

    void setTeacher(Teacher* teacher) {
        this->teacher = teacher;
    }

    void removeTeacher() {
        this->teacher = nullptr;
    }

    std::string getName() {
        return name;
    }

    Teacher* getTeacher() {
        return teacher;
    }
};

