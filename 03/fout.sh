 # quick script to outpout first $1 numbers of the fib sequence
 function fout { for i in $(seq $2); do echo "$i: $(./$1 $i)"; done; }