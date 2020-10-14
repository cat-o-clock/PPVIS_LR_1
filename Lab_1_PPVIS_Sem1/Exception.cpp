#include "Exception.h"


RException::RException(const std::string& error)
	: error(error)
{}

RException::~RException() throw() {}

const char* RException::what() const throw()
{
	return error.c_str();
}
