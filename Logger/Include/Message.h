#pragma once


#include <string>

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
}