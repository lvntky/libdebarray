# debarray

Minimal C99 library to debug and visualize 2D/3D arrays on the terminal. Designed with zero dependency to easly integrate into your project.

## Features
- Pretty print: any array with indexed rows and type-aware formatting
- Stats: min, max, mean, median, sum, standart derivation
- Histogram: ANSI colored histogram and heatmaps
- Generic: `void *` API with type tag.

## Building

```sh
# Build static and shared libraries
make

# Build and run the demo
make demo

# Install system-wide (requires sudo)
sudo make install

# Uninstall
sudo make uninstall

# Clean build artifacts
make clean
```

Output files after make:

```sh
build/
├── debarray.o
├── libdebarray.a    ← static library
└── libdebarray.so   ← shared library
```

## API Referance

### Type Tags

```c
typedef enum {
    DBGA_INT,
    DBGA_LONG,
    DBGA_FLOAT,
    DBGA_DOUBLE
} dbga_type_t;
```

All functions share the same signature:

```c
void dbga_print     (const void *arr, size_t len, adbg_type_t type);
void dbga_stats     (const void *arr, size_t len, adbg_type_t type);
void dbga_histogram (const void *arr, size_t len, adbg_type_t type);
```

## Linking

Static:
```sh
gcc main.c -Iinclude -Lbuild -ldebarray -lm -o myapp
```
Shared:
```sh
gcc main.c -Iinclude -Lbuild -ldebarray -lm -Wl,-rpath,build -o myapp
```

After `sudo make install`, no -L flag needed:
```sh
gcc main.c -larraydebug -lm -o myapp
```

## License
MIT