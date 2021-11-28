# FILE-SEARCH | COMPILE | DEBUG | CLEAN | #

CC = g++

# FILE PATHS
util = src/util.cpp
file = src/file.cpp
ui = src/ui.cpp
main = src/main.cpp

# USING AREA VARIABLES
lib = $(util) $(file) $(ui) # ALL IN ONE LIBRARIES

# CROSS PLATFORM STATEMENT #
ifeq ($(OS),Windows_NT)
omain = fsearch.exe # OUTPUT MAIN
else
omain = fsearch
endif

# USING AREA
.PHONY: run clean

run:
	$(CC) $(main) $(lib) -o $(omain)

clean: $(omain)
	del $(omain)

# MADE BY @hanilr #