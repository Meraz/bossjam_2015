#pragma once

#include <map>
#include <string>

template <class T>
class DataManager
{
public:
	DataManager(){}
	~DataManager()
	{
		std::vector<T*> all = GetAllElements();
		for (unsigned int i = 0; all.size(); ++i)
		{
			delete all[i];
		}
		all.clear();
	}
	
private:
	std::map<std::string, T*> m_map;

	T* RetrieveEntryLocal(const std::string& name)
	{
		return m_map[name];
	}

	void AddEntryLocal(const std::string& name, T* data)
	{
		m_map[name] = data;
	}

	void RemoveEntryLocal(const std::string& name)
	{
		m_map.erase(name);
	}

public:
	typedef typename std::map <std::string, T*>::iterator myIterator;
	std::vector<T*> GetAllElements()
	{
		std::vector<T*> returnVector;
		for (myIterator i = m_map.begin(); i != m_map.end(); ++i)
		{
			returnVector.push_back(i->second);
		}
		return returnVector;
	}

	typename std::map <std::string, T*>::iterator GetBegin()
	{
		return m_map.begin();
	}

	typename std::map <std::string, T*>::iterator GetEnd()
	{
		return m_map.end();
	}

	bool AddEntry(const std::string& name, T* data)
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

	bool RetrieveEntry(const std::string& name, T** outData)
	{
		bool successful = true;
		try
		{
			*outData = RetrieveEntryLocal(name);
		}
		catch (std::exception e)
		{
			*outData = nullptr;
			successful = false;
		}
		return successful;
	}
};
