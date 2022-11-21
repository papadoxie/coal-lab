#!/bin/bash

gcc main.c \
-o bin/assembler \
source/OnStartup.c \
source/Assembler.c \
source/HashMap.c \
source/Lookups.c \
source/Cleanup.c \
-Wall -g