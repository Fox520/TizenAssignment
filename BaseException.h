#pragma once
#include <exception>

class BaseException : public std::exception
{
    const char* what(const char* msg) const throw()
    {
        return msg;
    }
};