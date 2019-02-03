#include <stdexcept>

class FailedToLoadGlException : public std::runtime_error{
    public:
        FailedToLoadGlException() : std::runtime_error("Failed To Load Gl Exception"){}
        FailedToLoadGlException(const std::string& str) : std::runtime_error(str){}
};