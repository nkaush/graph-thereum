# Executable names:
EXE = project
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o src/graph.o src/edge.o src/vertex.o src/betweenness.o src/bfs.o src/dijkstras.o src/utils.o src/argument_parser.o

# Generated files
CLEAN_RM = actual-*.png

data:
	wget -O /data/data.csv https://storageaccountrgfuna61f.blob.core.windows.net/cs225/data.csv

# Use the cs225 makefile template:
include cs225/make/cs225.mk
