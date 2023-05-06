#include <stdexcept>
#include <string>

class DeportistaYaMatriculadoException : public std::exception
{
public:
    DeportistaYaMatriculadoException(std::string mensaje_);
    virtual const char* what() const noexcept override;
private:
    std::string mensaje;
};