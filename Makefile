# debarray — Makefile
# Builds: libdebarray.so, libdebarray.a, and demo binary

CC       = gcc
CFLAGS   = -std=c99 -Wall -Wextra -pedantic -fPIC -Iinclude
LDFLAGS  = -lm

SRC      = src/debarray.c
OBJ      = build/debarray.o

STATIC   = build/libdebarray.a
SHARED   = build/libdebarray.so
DEMO     = build/demo

INSTALL_LIB     = /usr/local/lib
INSTALL_INCLUDE = /usr/local/include

.PHONY: all clean install uninstall demo

all: $(STATIC) $(SHARED)

# Compile object file
$(OBJ): $(SRC) | build
	$(CC) $(CFLAGS) -c $< -o $@

# Static library
$(STATIC): $(OBJ)
	ar rcs $@ $^

# Shared library
$(SHARED): $(OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)

# Demo / example binary
demo: $(DEMO)

$(DEMO): examples/demo.c $(STATIC) | build
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ldebarray -Wl,-rpath,build $(LDFLAGS)

# Create build dir if missing
build:
	mkdir -p build

# Install to system
install: all
	install -d $(INSTALL_LIB) $(INSTALL_INCLUDE)
	install -m 644 $(STATIC)  $(INSTALL_LIB)/libdebarray.a
	install -m 755 $(SHARED)  $(INSTALL_LIB)/libdebarray.so
	install -m 644 include/debarray.h $(INSTALL_INCLUDE)/debarray.h
	ldconfig

# Uninstall from system
uninstall:
	rm -f $(INSTALL_LIB)/libdebarray.a
	rm -f $(INSTALL_LIB)/libdebarray.so
	rm -f $(INSTALL_INCLUDE)/debarray.h
	ldconfig

# Clean build artifacts
clean:
	rm -rf build/
