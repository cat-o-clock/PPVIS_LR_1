#pragma once

#include <exception>
#include <string>

class RException : public std::exception
{
private:
	std::string error;

public:
	RException(const std::string& error);

	~RException() throw();

	const char* what() const throw();
};
