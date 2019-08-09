#pragma once

#include "../Types/Types.h"

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace vn
{
	std::string getFileContents(const std::string& filePath)
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