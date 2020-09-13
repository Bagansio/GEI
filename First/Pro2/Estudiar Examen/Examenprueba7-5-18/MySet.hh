#ifndef Myset  // per evitar fer mes d'un include
#define Myset

#include <iostream>
#include <exception>

using namespace std;

template <class T> class MySet {
private:
  struct node {
    T info;
    node* seguent;
  }; 
  node* primer;
  node* ult;

  static node* salta(node* p , int k );
public:

    MySet() 
    {
        primer = nullptr;
        ult = nullptr;
    }
    
    MySet galopar() const;

    void llegir(int mark)
    {
        int x;
        cin >> x;
        if (x != mark)
        {
            demanar_torn(x);
            cin >> x;
        }
    }

     void demanar_torn (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node* aux;
    aux = new node; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= NULL;
    if (primer == NULL) primer = aux;
    else ult->seguent= aux;
    ult = aux;

  }

  void escriure ()
  {
      node* aux = primer;
      while(aux != nullptr)
      {
          cout << aux->info << endl;
          aux = aux -> seguent;
      }
  }
    #include "problema20.hh"
};

#endif
