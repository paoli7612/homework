<?php
 
    class Person
    {
        public $name;

        public function __construct($name) {
            $this->name = $name;
        }

        public static function generate($name)
        {
            return new static($name);
        }

        public function job()
        {
            
        }

        public function favouriteTeam()
        {

        }

        private function thingsThatKeepUpAtNight()
        {

        }
    }

    $bob = new Person('Bob');
    $gas = Person::generate('Gas');

    var_dump($bob);
    var_dump($gas);