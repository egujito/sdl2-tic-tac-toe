#!/bin/sh

set -xe

cc src/main.c src/game.c -o a -Wall -std=c11 -lSDL2 -Iinclude
