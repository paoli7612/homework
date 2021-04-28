<?php

    class A
    {
        public $istruzioni;
        public $cicli;

        public function __construct($istruzioni, $cicli)
        {
            $this->istruzioni = $istruzioni;
            $this->cicli = $cicli;
        }

        public static function conK($istruzioni, B $k)
        {
            return new static ($istruzioni, $k->get());
        }
    }

    class B
    {
        private $totale;

        private $L1;
        private $L2;
        private $MM;

        public function __construct($totale, A $L1, A $L2, A $MM)
        {
            $this->totale = $totale;

            $this->L1 = $L1;
            $this->L2 = $L2; 
            $this->MM = $MM; 
        }

        public function get()
        {
            return ($this->L1->istruzioni
                + $this->L2->istruzioni
                + $this->MM->istruzioni)/$this->totale;
        }
    }

    class CPI
    {
        private A $aritmetiche;
        private A $loadstore;
        private A $branch;

        public function __construct(A $aritmetiche, A $loadstore, A $branch)
        {
            $this->aritmetiche = $aritmetiche;
            $this->loadstore = $loadstore;
            $this->branch = $branch;
        }

        public function medio()
        {
            return ($this->aritmetiche->istruzioni
                + $this->loadstore->istruzioni
                + $this->branch->istruzioni)/100;
        }
    }

    echo (new CPI(
        new A(80, 1),
        new A(20, (new B(110, 
            new A(80, 1.5),
            new A(20, 5),
            new A(10, 55)
        ))->get()),
        new A(10, 3)
    ))->medio();

