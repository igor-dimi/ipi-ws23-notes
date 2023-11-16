  template <class C> 
  void rec_merge_sort (C& a, int o, int n) 
  {   // sortiere Eintraege [o,o+n-1]
    if (n==1) return;
      
    // teile und sortiere rekursiv
    int n1=n/2;
    int n2=n-n1;
    rec_merge_sort(a,o,n1);
    rec_merge_sort(a,o+n1,n2);
  
    // zusammenfuegen
    C b(n); // Hilfsfeld
    int i1=o, i2=o+n1;
    for (int k=0; k<n; k=k+1)
      if ((i2>=o+n) || (i1<o+n1 && a[i1]<=a[i2]))
        b[k] = a[i1++];
      else
        b[k] = a[i2++]; 
  
    // umkopieren
    for (int k=0; k<n; k=k+1) a[o+k] = b[k];
  }
  
  template <class C> 
  void mergesort (C& a) 
  {
    rec_merge_sort(a,0,a.size());
  }
  
  template <class C> 
  void rec_merge_sort_improved (C& a, C& b, int o, int n, int level) 
  {   // sortiere Eintraege [o,o+n-1]
    if (n==1) return; // nichts zu tun; Einträge sind in a und b
      
    // teile und sortiere rekursiv
    int n1=n/2;
    int n2=n-n1;
    rec_merge_sort_improved(a,b,o,n1,level+1);
    rec_merge_sort_improved(a,b,o+n1,n2,level+1);
  
    // zusammenfuegen
    C *pdest, *psource;
    if (level%2==0)
      {
        pdest = &a; psource = &b;
      }
    else
      {
        pdest = &b; psource = &a;
      }  
    int i1=o, i2=o+n1, endk=o+n;
    for (int k=o; k<endk; k=k+1)
      if ((i2>=o+n) || (i1<o+n1 && (*psource)[i1]<=(*psource)[i2]))
        (*pdest)[k] = (*psource)[i1++];
      else
        (*pdest)[k] = (*psource)[i2++]; 
  }
  
  template <class C> 
  void mergesort_improved (C& a) 
  {
    C b(a); // Kopie in Hilfsfeld
    rec_merge_sort_improved(a,b,0,a.size(),0);
  }
