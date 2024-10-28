#!/usr/bin/env bash
g++ $1 -O2 -Wall -lm -static -std=gnu++20 -DONLINE_JUDGE -DBOJ
