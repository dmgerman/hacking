#!/bin/bash

grep -i "$1" restaurantsVictoria.txt | cut -d ';' -f 1 | lynx -dump -
