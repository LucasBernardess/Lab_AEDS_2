# Defines C Compiler
CC := gcc

# Final file name
BINARY := out

# Code directory structure
BINDIR := bin
BUILDDIR := build
INCDIR := include	
SRCDIR := src

# Compiler flags
CFLAGS := -Wall -I $(INCDIR)

# Linker flags
LDFLAGS := -lm

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.c)))
OBJECTS :=$(patsubst %,$(BUILDDIR)/%.o,$(NAMES))


# Rule for link and generate the binary file
all: main.c conjunto.c conjunto.h
	gcc main.c conjunto.c conjunto.h -o conjunto

# Rule for object binaries compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@ if [ ! -d ./$(BUILDDIR) ]; then mkdir -p $(BUILDDIR);fi
	$(CC) -c $^ -o $@ $(CFLAGS) 


# Clean BIN and BUILD dirs
.PHONY: clean
clean: 
	rm -rf $(BUILDDIR) $(BINDIR) $(BINDIR)/$(BINARY)