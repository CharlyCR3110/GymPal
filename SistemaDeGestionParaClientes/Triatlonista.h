#pragma once
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"
 
class Triatlonista :
    public Ciclista
{
private:
    int cantidadParticipacionesIronMan; //ironMan es una competicion de triatlon
    int cantidadTriatlonesGanados;
    //delegate
    Nadador* nadador;
    Corredor* corredor;
    //fecha de la ultima actualizacion los datos biometricos de nadador o corredor (se debe de poner el mas actualizado)
    Fecha* fechaUltimaActualizacion;
public:
    //Constructores
    Triatlonista(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, int horasEntrenamiento_ = 0, double temperaturaPromedio_ = 0.0, int cantidadParticipacionesIronMan_ = 0, int cantidadTriatlonesGanados_ = 0.0, char sexo_ = ' ', double estatura_ = 0.0, double masaMuscular_ = 0.0, double peso_ = 0.0, double porcentajeGrasaCorporal_ = 0.0, Fecha* fechaUltimaActualizacion_ = nullptr);
    Triatlonista(const Triatlonista& triatlonista_);
    virtual ~Triatlonista();
    //Setters
    // Propios
    virtual void setCantidadParticipacionesIronMan(int cantidadParticipacionesIronMan_);
    virtual void setCantidadTriatlonesGanados(int cantidadTriatlonesGanados_);
    // Corredor
    virtual void setCorredor(Corredor* corredor_);
    virtual void setSexo(char sexo_);
    virtual void setEstatura(double estatura_);
    virtual void actualizarEstatura(double estatura_, Fecha* fechaActualizacion_);
    // Nadador1
    virtual void setNadador(Nadador* nadador_);
    virtual void setMasaMuscular(double masaMuscular_);
    virtual void actualizarMasaMuscular(double masaMuscular_, Fecha* fechaActualizacion_);
    virtual void setPeso(double peso_);
    virtual void actualizarPeso(double peso_, Fecha* fechaActualizacion_);
    virtual void setPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_);
    virtual void actualizarPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_, Fecha* fechaActualizacion_);
    // Corredor y Nadador
    virtual void actualizarDatosBiometricos(double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_, Fecha* fechaUltimaActualizacion_);
    //Getters
    // Propios
    virtual const int getCantidadParticipacionesIronMan() const;
    virtual const int getCantidadTriatlonesGanados() const;
    // Corredor
    virtual Corredor* getCorredor();
    virtual const char getSexo() const;
    virtual const double getEstatura() const;
    // Nadador
    virtual Nadador* getNadador();
    virtual const double getMasaMuscular() const;
    virtual const double getPeso() const;
    virtual const double getPorcentajeGrasaCorporal() const;
    // Metodos
    virtual const string toString() const override;
    virtual const string detalleDeportista() const override;
    // archivos
        // archivos
    virtual const string toStringParaGuardar() const override;
    virtual const string toStringParaGuardarConPagos() const override;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& out, const Triatlonista& triatlonista_);
};