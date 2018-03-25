/******************************************************************************
* Copyright (C) 25/03/2018
*
* @file         main.cpp
* @project		TemplateMetaProgramming_PolicyClass
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <string>

struct LogInfo 
{
	LogInfo() : m_verbosity(0) {}
	LogInfo(size_t verbosity) : m_verbosity(verbosity) {}
	std::string getVerbosity() const
	{
		return 
			m_verbosity == 0 ? "M" :
			m_verbosity == 1 ? "W" :
			m_verbosity == 2 ? "E" :
			"-";
	}
	size_t m_verbosity;
};

struct SourceInfo
{
	SourceInfo(const std::string fileName, const size_t lineNumber)
		: m_fileName(fileName),
		m_lineNumber(lineNumber)
	{

	}
	const std::string m_fileName;
	const size_t m_lineNumber;
};

class Logger
{
public:
	virtual ~Logger() = default;
	virtual void Log(const LogInfo& logInfo, const SourceInfo& sourceInfo, const std::string message) = 0;
};


template<
	class FilterPolicy,
	class FormatPolicy,
	class WritePolicy
>
class LoggerImpl : public Logger
{
public:
	virtual void Log(const LogInfo& logInfo, const SourceInfo& sourceInfo, const std::string message) override
	{
		if (m_filter.Filter(logInfo))
		{
			const std::string formattedMsg = m_formatter.Format(logInfo, sourceInfo, message);
			m_writer.Write(formattedMsg);
		}
	}
private:
	FilterPolicy m_filter;
	FormatPolicy m_formatter;
	WritePolicy m_writer;
};


struct NoFilterPolicy
{
	bool Filter(const LogInfo& logInfo) { return true; }
};

struct SimpleFormatterPolicy
{
	std::string Format(const LogInfo& logInfo, const SourceInfo& sourceInfo, const std::string message)
	{
		return (
			"[" + logInfo.getVerbosity() + "]" +
			"[" + sourceInfo.m_fileName + ": " + std::to_string(sourceInfo.m_lineNumber) + "]" +
			" " + message.c_str() 
			);
	}
};

struct ConsoleWriterPolicy
{
	void Write(const std::string& message)
	{
		std::cout << message << std::endl;
	}
};

using SimpleLogger = LoggerImpl<NoFilterPolicy, SimpleFormatterPolicy, ConsoleWriterPolicy>;



int main()
{
	SimpleLogger logger;
	logger.Log(LogInfo(), SourceInfo("filename.cpp", 20), "random message");
	logger.Log(LogInfo(1), SourceInfo("filename.cpp", 30), "warning message");
	logger.Log(LogInfo(2), SourceInfo("filename.cpp", 33), "error message");

	std::cin.get();
	return 0;
}