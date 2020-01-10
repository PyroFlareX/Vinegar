#pragma once

#include <unordered_map>

template<typename T>
class Registry
{
public:
	Registry()
	{

	}

	void addToRegistry(T res, const std::string& resName)
	{
		m_registry.insert({ resName, res });
	}

	T& getAsset(const std::string& resName)
	{
		return m_registry.find(resName)->second;
	}

	~Registry() = default;
private:
	std::unordered_map<std::string, T> m_registry;
};