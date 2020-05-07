#include "Cjt_estudiants.hh"
#include <iostream>
#include "Estudiant.hh"
using namespace std;

//pre: un cjt d'estudiants
//post: si pot afegir un estudiant ho fa sino escriu un missatge indicant-ho
void afegir_est(Cjt_estudiants& cjt)
{
        Estudiant aux;
        aux.llegir();
    if (not cjt.existeix_estudiant(aux.consultar_DNI()))
    {
        if (cjt.mida() == 5)
        {
            cout << "el conjunto esta lleno" << endl << endl;
        }
        else 
        {
            cjt.afegir_estudiant(aux);
        }
    }
    else cout << "el estudiante " << aux.consultar_DNI() << " ya estaba" << endl << endl;
}

//pre : un cjt d'est
//post: ens diu la nota d'un estudiant si aquest en te i existeix en cas contrari ens ho notificara
void cons_nota(const Cjt_estudiants& cjt)
{
    int dni;
    cin >> dni;
    if (cjt.existeix_estudiant(dni))
    {
        if (cjt.consultar_estudiant(dni).te_nota())
        {
        cout << "el estudiante " << dni << " tiene nota " << cjt.consultar_estudiant(dni).consultar_nota(); //es corecto usar esto?????
        }
        else cout << "el estudiante " << dni << " no tiene nota";
    }
    else cout << "el estudiante " << dni << " no esta";
    cout << endl << endl;
}

void mdf_nota(Cjt_estudiants& cjt)
{
    Estudiant aux;
    aux.llegir();
    if (cjt.existeix_estudiant(aux.consultar_DNI()))
    {
        cjt.modificar_estudiant(aux);
    }
    else cout << "el estudiante " << aux.consultar_DNI() << " no esta" << endl << endl;
}

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

Cjt_estudiants redondear_cjt(const Cjt_estudiants& cjt)
{
    Cjt_estudiants final;
    int n = cjt.mida();
    for (int i = 1; i <= n; ++i)
    {
        Estudiant aux = cjt.consultar_iessim(i);
        if (aux.te_nota())
        {
            aux.modificar_nota(redondear(aux.consultar_nota()));
        }
        final.afegir_estudiant(aux);
    }
    return final;
}

int main()
{
    Cjt_estudiants cjt;
    cjt.llegir();
    int n;
    while(cin >> n and n != -6)
    {
        if(n == -1) //afegir estudiant nou
        {
            afegir_est(cjt);
        }
        else if (n == -2) //consultar nota de un estudiante a partir de su dni
        {
            cons_nota(cjt);
        }
        else if (n == -3) //modificar nota de un estudiante 
        {
            mdf_nota(cjt);
        }
        else if (n == -4) //redondear la nota a todos los est
        {
            cjt = redondear_cjt(cjt);
        }
        else if (n == -5)  // escribir el conjunto
        {
            cjt.escriure();
            cout << endl;
        }
    }
}