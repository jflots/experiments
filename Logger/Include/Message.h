#pragma once

/*!
 * \file Message.h
 * \date 2018/01/14 15:17
 *
 * \author jflots
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/

#include <string>
#include <memory>

namespace Logger
{
	using LogLevel = int;

	class Message
	{
		private:
		// date time details
		std::string m_details;
		std::string m_module;

		public:
		Message() = default;

		~Message() = default;

		Message(const Message& message) = delete;

		Message& operator=(const Message& message) = delete;

		void setModule(const std::string& module);

		void setDetails(const std::string& details);

		void setDetails(std::string&& details);

		const std::string& getDetails();

		void appendMessage(const std::string& msg);
	};

	void Message::setModule(const std::string& module)
	{
		m_module = module;
	}

	void Message::setDetails(const std::string& details)
	{
		m_details = details;
	}

	void Message::setDetails(std::string&& details)
	{
		m_details = std::move(details);
	}

	const std::string& Message::getDetails()
	{
		return m_details;
	}

	void Message::appendMessage(const std::string& msg)
	{
		m_details += msg;
	}

	using MessagePtr = std::shared_ptr<Message>;


	class LogStream
	{
		public:
		LogStream() = default;

		
	};

	LogStream& operator<<(LogStream& logStream, const std::string& msg)
	{

	}

	
}

