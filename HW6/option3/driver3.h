#pragma once

#include <string>
#include "Course.h"

Course loadFileToCourses(std::string fileName);

void driver3() {
	MyBag<Course> courses;
}
