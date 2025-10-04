# emel_lib

My very own attempt to re-learn C through implementation of basic Machine Learning algorithms in pure C.

## Structured

```
emel_lib/
├── src/                 # Source files (.c)
│   ├── core/           # Fundamental data structures
│   │   ├── array.c
│   │   ├── matrix.c
│   │   └── vector.c
│   ├── linear_algebra/ # BLAS-like operations
│   │   ├── blas_level1.c
│   │   ├── blas_level2.c
│   │   └── blas_level3.c
│   ├── models/         # ML algorithms
│   │   ├── linear_regression.c
│   │   ├── logistic_regression.c
│   │   └── neural_net.c
│   ├── utils/          # Utilities
│   │   ├── csv_parser.c
│   │   ├── metrics.c
│   │   └── random.c
│   └── main.c          # Demo/test programs
├── include/            # Header files (.h)
│   ├── core/
│   │   ├── array.h
│   │   ├── matrix.h
│   │   └── vector.h
│   ├── linear_algebra/
│   │   └── blas.h
│   ├── models/
│   │   ├── linear_regression.h
│   │   └── neural_net.h
│   └── utils/
│       ├── csv_parser.h
│       └── metrics.h
├── tests/              # Test programs
│   ├── test_array.c
│   ├── test_matrix.c
│   └── test_linear_regression.c
├── build/              # Build artifacts (gitignore this)
├── data/               # Datasets for testing
│   ├── iris.csv
│   └── synthetic.csv
├── Makefile            # Build system
├── README.md
└── .gitignore
```

# Resources

- [Numerical Recipes in C]()

# Study Plan

### Phase 1: C Refresher and the "C for Data Science" Mindset

- Pointers and Memory Management: malloc, calloc, free. Understanding stack vs. heap.
- Arrays vs. Pointers: How they relate, pointer arithmetic.
- Structures (struct): For bundling data (e.g., a Dataset struct holding features, labels, num_samples, num_features).
- Functions and Pass-by-Value vs. Pass-by-Reference.
- Basic File I/O: Reading CSV files into your custom data structures.
- The Math Library (math.h): exp, log, pow, sqrt.

**Practical Exercises (Week 1-2):**

- Dynamic Matrix: Write functions to allocate, free, and perform basic operations (addition, multiplication) on a 2D matrix of dynamic size.
- CSV Parser: Write a function that reads a simple CSV file (like the Iris dataset) and loads it into your dynamic matrix structure. This is a crucial and non-trivial step.
- Basic Statistics: Implement functions to compute the mean, variance, and standard deviation of an array. Then, write a function to standardize (z-score normalize) a dataset.

### Phase 2: Foundational Math & Linear Algebra in C

- Vector and Matrix operations.
- Matrix Multiplication (the cornerstone of many ML algorithms).
- Solving systems of equations (for Linear Regression).

**Practical Exercises (Week 3-4):**

- BLAS-like Functions: Implement a subset of the Basic Linear Algebra Subprograms (BLAS).

  - Level 1: daxpy (scalar multiplication and addition of vectors), ddot (dot product).
  - Level 2: dgemv (General Matrix-Vector multiplication). This is key for predictions.
  - Level 3: dgemm (General Matrix-Matrix multiplication). Key for batch operations and neural networks.

- Matrix Inversion: Implement Gaussian Elimination or LU Decomposition to find the inverse of a small square matrix. (You'll use this for the "normal equation" in linear regression).
