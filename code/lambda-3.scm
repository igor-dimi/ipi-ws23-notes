
;;; Definition of the factorial function

(define factorial
    ;; The following is pure Lambda Calculus with a little
    ;; bit of syntactic sugar (let*).
    (let* ((identity (lambda (x) x))
	   (constantly (lambda (x) (lambda (y) x)))
	   (true constantly)
	   (false (constantly identity))
	   (_if_ (lambda (b x y) ((b x) y)))
	   (cons (lambda (a b)
		   (lambda (boolean)
		     (_if_ boolean a b))))
	   (car (lambda (pair) (pair true)))
	   (cdr (lambda (pair) (pair false)))
	   ;; the number n is represented by the map f |-> f^n
	   (zero (constantly identity))
	   (one identity)
	   (+ (lambda (n1 n2)
		(lambda (f)
		  (lambda (x)
		    ((n1 f) ((n2 f) x))))))
	   (* (lambda (n1 n2)
		(lambda (f)
		  (n1 (n2 f))))))
      ;;
      ;; now we build n! by n-fold shifting (a,b)->(a+1,b*a)
      ;;
      (let* ((next-pair
	      (lambda (pair)
		(cons (+ (car pair) one)
		      (* (cdr pair) (car pair))))))
	(lambda (n)
	  (cdr ((n next-pair) (cons one one)))))))

;;; Communication with the exterior world

(define (number->numeral n)
    (lambda (f)
      (lambda (x)
	(if (= n 0)
	    x
	    (f (((number->numeral (- n 1)) f) x))))))

(define (numeral->number n)
  ((n (lambda (x) (+ x 1))) 0))

;;; Finally, the application

(numeral->number (factorial (number->numeral 10)))


