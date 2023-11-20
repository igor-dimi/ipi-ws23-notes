int g( int x )
{
  int y = x*x;
  y = y*y;
  return h( y*(x+y) );
}

int h( int x )
{
  return cond( x<1000, g(x), 88 );
}
