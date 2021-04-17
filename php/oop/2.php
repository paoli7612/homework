<?php

    class Sprite
    {
        public $image;
        public $position;

        public function draw()
        {
            echo "Sprite" . $position[0] . " " . $position[1] . "<br>";
        }
    }

    class Npc extends Sprite
    {
        
    }

    class Player extends Npc
    {

    }

