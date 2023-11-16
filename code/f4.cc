int f4()
{
  int a = 0;     // a = fib(0)
  int b = 1;     // b = fib(1)
  int t;

  t = a+b; a = b; b = t;    // b = fib(2)
  t = a+b; a = b; b = t;    // b = fib(3)
  t = a+b; a = b; b = t;    // b = fib(4)
  return b;
}
