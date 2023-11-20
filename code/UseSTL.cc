  #include<iostream>
  #include<vector>
  #include<list>
  #include<queue>
  #include<iostream>
  
  int main ()
  {
    std::vector<int> x(10,77); // 10 Elemente mit Wert 77
    x[0] = x[5];
  
    for (int i=0; i<x.size(); ++i) x[i] = i;
  
    std::vector<int> y(0); // leerer Container
    for (int i=0; i<10; ++i) y.push_back(i);
  
    int sum = 0;
    for (std::vector<int>::iterator it=x.begin(); it!=x.end(); ++it)
      sum += *it;
  
    std::list<int> l;
    for (int i=0; i<10; ++i) l.push_back(i);
  
    sum = 0;
    for (std::list<int>::iterator it=l.begin(); it!=l.end(); ++it)
      sum += *it;
  
    std::list<int>::iterator it1 = l.begin();
    ++it1;
    l.insert(it1,17); // füge neues Element *vor* ein
  }
