#!/usr/bin/env bash
g++ $1 -g -O2 -Wall -lm -std=gnu++26 -DONLINE_JUDGE -DBOJ -fsanitize=address