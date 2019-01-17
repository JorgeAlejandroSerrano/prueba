#include<iostream>

using namespace std;

//Clase Empleado
class Empleado{
    //Miembros Privados
    protected: //para acceder a el ya que no tiene un getter
        float fSueldo;
        
        //Miembros Publicos
    public:
    
        //Constructor
        Empleado(float fSueldo){
            //Asigna el Sueldo
            this->fSueldo=fSueldo;
        }
        
        //Funcion Virtual Pura, Declarada pero NO definida; el =0 la definé como Pura
        virtual float CalculaSueldo()=0;
        
        //Función Test Solo para mostrar que no todas las funciones deben ser virtuales, 
        //Con una funcion virtual, ya la clase es abstracta.
        void Test(){
            cout << "Test Clase Base..."<<endl<<endl;
        }
};

//Clase Derivada "Empleado de Ventas"

class EmpleadoVtas(float fSueldo, float fComision) : Empleado(fSueldo){
    //Asigna la comision 
    this->fComision=fComision;
    
    //Calcula el Sueldo, Si tiene otro nombre manda error por la propiedad virtual =0 de la clase Base.
    float CalculaSueldo(){
        //Retorna el Sueldo
        return (fSueldo * 30 * (1+fComision));
    }
};

//Clase Derivada Empleado de Contabilidad

class EmpleadoContab: public Empleado{
    private:
        float fComision;
        float fBono;
    
    public:
    
        //Constructor
        EmpleadoContab(float fSueldo, float fComision, float fBono) : Empleado(fSueldo){
            //Asignar la comision y el Bono
            this->fComision = fComision;
            this->fBono = fBono;
        }
        //Calcula el Sueldo
        float CalculaSueldo(){
            //Retornamos el Sueldo
            return ((fSueldo * 30 * (1+fComision)) + fBono);
        }
};


int main(){
    
    //Creamos los Objetos
    //Con Funciones Puras no podemos instanciar la clase base de esta manera:
    //Empleado xEmpleado(400); // Pero es posible crear Apuntadores a la clase Base
    EmpleadoVtas xEmpleadoVtas(400,.20);
    EmpleadoContab xEmpleadoContab(400,.20,500);
    
    //Apuntador de la clase Base
    Empleado *pEmpleado;
    
    //Asignamos la dirección de la clase Base.
    pEmpleado = &xEmpleadoVtas;
    
    //Desplegar el sueldo del Empleado
    
    cout<<"Sueldo del Empleado: "<< pEmpleado->CalculaSueldo() <<endl;
    pEmpleado->Test();
    
    //Asignamos la dirección de la clase Base.
    pEmpleado = &xEmpleadoContab;
    
    //Desplegar el sueldo del Empleado
    
    cout<<"Sueldo del Empleado: "<< pEmpleado->CalculaSueldo() <<endl;
    pEmpleado->Test();
    
    
    return 0;
    
}