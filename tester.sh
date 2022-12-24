#!/bin/bash
ARG=$(seq -2500 2500 | sort -R | tail -500 | tr '\n'  ' ')
./push_swap $ARG | wc -l
