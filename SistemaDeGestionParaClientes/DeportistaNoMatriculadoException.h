#include <stdexcept>
#include <string>

class DeportistaNoMatriculadoException : public std::exception
{
public:
    DeportistaNoMatriculadoException(std::string mensaje_);
    virtual const char* what() const noexcept override;
private:
    std::string mensaje;
};