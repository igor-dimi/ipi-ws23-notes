  #include "fcpp.hh"
  
      const int n = 50000000;
      bool prim[n]; // prim[0],...,prim[499999]
  
  int main ()
  {
  
      // Initialisierung
      prim[0] = false;
      prim[1] = false;
      for (int i=2; i<n; i=i+1)
          prim[i] = true;
  
      // Sieb
      for (int i=2; i<=sqrt((double) n); i=i+1)
          if (prim[i])
              for (int j=2*i; j<n; j=j+i)
                  prim[j] = false;
  
      // Ausgabe
      int m=0;
      for (int i=0; i<n; i=i+1)
        if (prim[i]) 
          m = m+1;
      print("Anzahl Primzahlen kleiner als",n,0);
      print(m);
      
      return 0;
  }
