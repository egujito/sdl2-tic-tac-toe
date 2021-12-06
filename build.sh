#!/bin/sh

set -xe

cc src/main.c src/game.c -o ttt -Wall -std=c11 -lSDL2 -Iinclude
