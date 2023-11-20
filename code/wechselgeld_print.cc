  #include "fcpp.hh"
  
  // uebersetze Muenzart in Muenzwert
  int nennwert (int nr)
  {
    return cond(nr==1, 1,
            cond(nr==2, 2,
             cond(nr==3, 5,
              cond(nr==4, 10,
                   cond(nr==5, 20,
                    cond(nr==6, 50, 0))))));
  }
  
  std::string zeichen (int nr)
  {
    return cond(nr==1, "1|",
            cond(nr==2, "2|",
             cond(nr==3, "5|",
              cond(nr==4, "10|",
                   cond(nr==5, "20|",
                    cond(nr==6, "50|", 0))))));
  }
  
  int wg (int betrag, int muenzarten,std::string s)
  {
    return cond(betrag==0, print(s,1),
            cond(betrag<0 || muenzarten==0, 0,
             wg(betrag,muenzarten-1,s) +
             wg(betrag-nennwert(muenzarten),muenzarten,s+zeichen(muenzarten))));
  }
  
  int wechselgeld (int betrag) 
  {
    return wg(betrag,6,"");
  }
  
  int main (int argc, char** argv) {
    return print(wechselgeld(readarg_int(argc,argv,1)));
  }
