#include "base.hpp"
#include "demo_1.hpp"

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

using std::vector;

int main(int argc, char** argv)
{
	vector<std::unique_ptr<Demo>> demos;
	demos.push_back(make_unique<Demo_1>());
	
	if(argc < 2)
	{
		LOGE("Not enough arguments (" << argc << ")!");
		return EXIT_FAILURE;
	}
	
	int demo_n = str_to<int>(argv[1]);
	if(demo_n < 1 || demo_n > demos.size())
	{
		LOGE("Incorrect demo number (" << demo_n << ")!");
		return EXIT_FAILURE;
	}
	
	LOGI("Preparing demo #" << demo_n << "...");
	if(!demos[demo_n-1]->prepare())
	{
		LOGE("Demo #" << demo_n << " failed to prepare. Aborting...");
		return EXIT_FAILURE;
	}
	
	LOGI("Running demo #" << demo_n << "...");
	demos[demo_n-1]->run();
	
	demos.clear();
	return EXIT_SUCCESS;
}
