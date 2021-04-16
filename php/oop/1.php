<?php

    class Marca
    {

    }

    class Modello extends Marca
    {

    }

    class Auto
    {
        public $targa;
        public $anno;
    }

    class Azienda
    {
        private array $macchine;
        
        public function __construct(... $macchine)
        {
            $this->macchine = $macchine;
        }

        public function aggiungi($macchina)
        {

        }
    }