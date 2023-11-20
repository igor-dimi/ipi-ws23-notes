if ( x >= 0 )
{
  if ( y <= x )
    b = x - y; // b ist groesser 0
  else
  {
    while ( y > x ) 
      y = y - 1;
    b = x + y; 
  }
  i = f(b);
}
