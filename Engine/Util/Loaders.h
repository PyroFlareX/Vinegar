#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace vn
{
	std::string getFileString(const std::string& filePath)
	{
		std::ifstream inFile(filePath);
		if (!inFile.is_open())
		{
			throw std::runtime_error("Unable to open file: " + filePath);
		}

		std::stringstream stream;

		stream << inFile.rdbuf();
		return stream.str();
	}

	

}