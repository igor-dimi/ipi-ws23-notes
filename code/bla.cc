int bla( int x )
{
  int y = 3;           // Zeile 1
  const int x1 = y*x;  // Zeile 2
  y = 5;               // Zeile 3
  const int x2 = y*x;  // Zeile 4
  return x1*x2;        // Zeile 5
}
