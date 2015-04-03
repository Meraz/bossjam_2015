#pragma once

#include <map>
#include <string>

template <class T>
class Manager
{
//private:
public:
	Manager(){}
	virtual ~Manager()
	{
	}
	
private:
	std::map<std::string, const T const*> m_map;

	const T* RetrieveEntryLocal(const std::string& name)
	{
		return m_map[name];
	}

	void AddEntryLocal(const std::string& name, const T* data)
	{
		m_map[name] = data;
	}

	void RemoveEntryLocal(const std::string& name)
	{
		m_map.erase(name);
	}

public:
	bool AddEntry(const std::string& name, const T const* data)
	{
		bool successful = true;
		try
		{
			AddEntryLocal(name, data);
		}
		catch (std::exception e)
		{
			successful = false;
		}
		return successful;
	}

	bool RemoveEntry(const std::string& name)
	{
		bool successful = true;
		try
		{
			RemoveEntryLocal(name);
		}
		catch (std::exception e)
		{
			successful = false;
		}
		return successful;
	}

	bool RetrieveEntry(const std::string& name, const T const* outData)
	{
		bool successful = true;
		try
		{
			outData = RetrieveEntryLocal(name);
		}
		catch (std::exception e)
		{
			outData = nullptr;
			successful = false;
		}
		return successful;
	}
};
