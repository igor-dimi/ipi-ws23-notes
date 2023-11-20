(define (konto bilanz)
    (lambda (message)
      (case message
        ((kontostand) bilanz)
        ((abheben) (lambda (betrag)
                     (set! bilanz (- bilanz betrag)))))))
(define konto1 (konto 100))
(define konto2 (konto 200))
(konto1 'kontostand)  ; => 100
((konto1 'abheben) 20)
(konto1 'kontostand)  ; => 80
(konto2 'kontostand)  ; => 200