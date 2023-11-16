  #include<iostream>
  #include<vector>
  #include"Bubblesort.cc"
  #include"Selectionsort.cc"
  #include"Insertionsort.cc"
  #include"Mergesort.cc"
  #include"Heapsort.cc"
  #include"Quicksort.cc"
  #include"Zufall.cc"
  #include"timestamp.cc"
  #include"fcpp.hh"
  
  int seed=8267;
  
  void initialize (std::vector<int>& a) {
    Zufall z(seed);
    for (int i=0; i<a.size(); ++i)
      a[i] = z.ziehe_zahl();
  }
  
  void check (std::vector<int>& a) {
    for (int i=1; i<a.size(); ++i)
      if (a[i-1]>a[i])
        std::cout << "Feld nicht sortiert: i=" << i << " " << a[i-1] << " " << a[i] << std::endl;
  }
  
  int main (int argc, char **argv)
  {
    int n = 50000;
    if (argc>=2) n = readarg_int(argc,argv,1);
    if (argc>=3) seed = readarg_int(argc,argv,2);
    std::vector<int> a(n);
  
    initialize(a);
    time_stamp();
    quicksort(a);
    std::cout << "n=" << n << " quicksort t=" 
          << time_stamp() << std::endl;  
  
    initialize(a);
    time_stamp();
    mergesort_improved(a);
    std::cout << "n=" << n << " mergesort_improved t=" 
          << time_stamp() << std::endl;
    check(a);
  
    initialize(a);
    time_stamp();
    mergesort(a);
    std::cout << "n=" << n << " mergesort t=" 
          << time_stamp() << std::endl;  
  
    initialize(a);
    time_stamp();
    heapsort(a);
    std::cout << "n=" << n << " heapsort t=" 
          << time_stamp() << std::endl;
  
    if (n>50000) return 0;
    
    initialize(a);
    time_stamp();
    bubblesort(a);
    std::cout << "n=" << n << " bubblesort t=" 
          << time_stamp() << std::endl;  
  
    initialize(a);
    time_stamp();
    insertionsort(a);
    std::cout << "n=" << n << " insertionsort t=" 
          << time_stamp() << std::endl;  
  
    initialize(a);
    time_stamp();
    selectionsort(a);
    std::cout << "n=" << n << " selectionsort t=" 
          << time_stamp() << std::endl;  
  }
