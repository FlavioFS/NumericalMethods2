#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
    public:

		/* ==========================================================
                         Constructors & Destructors
        ========================================================== */
    	Matrix(unsigned int line_count, unsigned int row_count);        // [1.1] - Constructor
    	Matrix();                                                       // [1.2] - Default Constructor
        ~Matrix();                                                      // [1.3] - Destructor

        /* ==========================================================
                                     Set
        ========================================================== */
        void put(double value, unsigned int i, unsigned int j);         // [2.1] - Put (set element)
        void read_next(double value);                                   // [2.2] - Reads next element

         /* ==========================================================
                                     Get
        ========================================================== */
        unsigned int lines() const;                                     // [3.1] - Line Amount
        unsigned int rows() const;                                      // [3.2] - Row Amount
        double get(unsigned int i, unsigned int j) const;               // [3.3] - Element at position (i,j)

        /* ==========================================================
                            Overloaded Operations
        ========================================================== */
        Matrix& operator = (const Matrix&);                             // [4.1] - Attribution
        const Matrix  operator + (const Matrix&) const;                 // [4.2] - Sum
        Matrix  operator - (Matrix);                                    // [4.3] - Difference
        Matrix  operator * (Matrix);                                    // [4.4] - Product by Matrix
        Matrix  operator * (const double alpha);                        // [4.5] - Product by number
        void operator >> (const double& value);                         // [4.6] - Input
        friend std::ostream&                                            // [4.7] - Stream output
            operator << (std::ostream&, Matrix&);

        /* ==========================================================
                              Other Operations
        ========================================================== */
        void resize(unsigned int line_count, unsigned int row_count);   // [5.1] - Resizing


    private:
        bool valid_bounds(unsigned int i, unsigned int j) const;        // Check bounds
        void pause() const;                                             // Pauses console
        void clear();                                                   // Clears _M

        // Matrix order
        unsigned int
            _lines,         // Line Amount
            _rows;          // Row Amount

        // Input stream reading this position
        unsigned int
            _line_cursor,
            _row_cursor;

        // Low level dynamic matrix
        double **_M;
};

#endif // MATRIX_H
