#!/usr/bin/env bash
g++ $1 -O2 -Wall -lm -std=gnu++20 -DONLINE_JUDGE -DBOJ -fsanitize=address
