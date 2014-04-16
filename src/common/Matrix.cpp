#include "Matrix.h"

#define EXCEPTION_BOUNDS "Matrix: Out of bounds"
#define EXCEPTION_ORDER  "Matrix: Incompatible orders"

/* ==========================================================
                1. Constructors & Destructors
========================================================== */
// [1.1] - Constructor
Matrix::Matrix(unsigned int line_count, unsigned int row_count)
:_lines(line_count), _rows(row_count), _line_cursor(1), _row_cursor(1)
{
    // Allocating external dynamic array of internal dynamic arrays (lines)
    _M = new double*[line_count];

    for (unsigned int i = 0; i < line_count; i++)
    {
        // Allocating each internal dynamic array (rows)
        _M[i] = new double[row_count];

        // Default: Zero matrix
        for (unsigned int j = 0; j < row_count; j++)
        {
            _M[i][j] = 0;
        }
    }
}

// [1.2] - Destructor
Matrix::~Matrix()
{
    // Deleting each internal dynamic array
    for (unsigned int i = 0; i < lines(); i++)
    {
        delete _M[i];
    }

    // Deleting external dynamic array
    delete _M;
}

/* ==========================================================
                            2. Set
========================================================== */
// [2.1] - Put (set element)
void Matrix::put(double value, unsigned int i, unsigned int j)
{
    if (!valid_bounds(i, j))
    {
        std::cout << "Put(" << value << ", " << i << ", " << j << ") failure. Element unchanged." << std::endl;
        std::cout << EXCEPTION_BOUNDS << std::endl;
        pause();
    }
    else
        { _M[i-1][j-1] = value; }
}

// [2.2] - Reads next element
void Matrix::read_next(double value)
{
    // If cursor position is valid
    if (valid_bounds(_line_cursor, _row_cursor))
    {
        // Puts the new value at that position
        this->put(value, _line_cursor, _row_cursor);

        // Moves the cursor to the next position
        _line_cursor++;
        if (_line_cursor > _lines)
        {
            _line_cursor = 1;
            _row_cursor++;
        }
    }
}

/* ==========================================================
                            3. Get
========================================================== */
unsigned int Matrix::lines() { return _lines; }     // [3.1] - Line Amount
unsigned int Matrix::rows()  { return _rows;  }     // [3.2] - Row Amount
double Matrix::get(unsigned int i, unsigned int j)  // [3.3] - Element at position (i,j)
{
    if (!valid_bounds(i, j))
    {
        std::cout << "Get(" << i << ", " << j << ") failure. Returning 0." << std::endl;
        std::cout << EXCEPTION_BOUNDS << std::endl;
        pause();

        return 0;
    }
    else
        { return _M[i-1][j-1]; }
}

/* ==========================================================
                        4. Operations
========================================================== */
// [4.1] - Attribution
void Matrix::operator=(Matrix A)
{
    // In order to attribute, the lines and rows must match each other
    if (_lines != A.lines() ||
        _rows  != A.rows())
    {
        std::cout << "Matrix attribution failure. Matrix unchanged." << std::endl;
        std::cout << EXCEPTION_ORDER << std::endl;
        pause();
    }
    else
    {
        // Calculating the result values
        for (unsigned int i = 0; i < _lines; i++)
        {
            for (unsigned int j = 0; j < _rows; j++)
            {
                double aux = _M[i][j] + A.get(i+1,j+1);
                this->put(aux, i+1, j+1);
            }
        }
    }
}

// [4.2] - Sum
Matrix Matrix::operator+(Matrix A)
{
    // In order to sum, the lines and rows must match each other
    if (_lines == A.lines() &&
        _rows  == A.rows())
    {
        std::cout << "Matrix sum failure. Matrix unchanged. Closing." << std::endl;
        std::cout << EXCEPTION_ORDER << std::endl;
        pause();
        throw EXCEPTION_ORDER;
    }
    else
    {
        // The result
        Matrix sum (_lines, _rows);

        // Calculating the result values
        for (unsigned int i = 0; i < _lines; i++)
        {
            for (unsigned int j = 0; j < _rows; j++)
            {
                double aux = _M[i][j] + A.get(i+1,j+1);
                sum.put(aux, i+1, j+1);
            }
        }

        return sum;
    }
}

/*+--------------------------------------------+*
 *|   Inaciane, implemente estas três funções, |*
 *| já que você quer aprender. :v              |*
 *+--------------------------------------------+*

// [4.3] - Difference
Matrix Matrix::operator-(Matrix A){}

// [4.4] - Product by Matrix
Matrix Matrix::operator*(Matrix A){}

// [4.5] - Product by number
Matrix Matrix::operator*(Matrix A){}

-------------------------------------------- */

// [4.6] - Stream input

void Matrix::operator >> (const double& value)
{
    read_next(value);
}


// [4.7] - Stream output
std::ostream& operator << (std::ostream& out, Matrix& M)
{
    for (unsigned int i = 0; i < M.lines(); i++)
    {
        for (unsigned int j = 0; j < M.rows(); j++)
        {
            out << M.get(i+1,j+1) << " ";
        }

        out << "\n";
    }

    return out;
}

/* ==========================================================
                           Private
========================================================== */
// Verifies if the given bounds are valid
bool Matrix::valid_bounds(unsigned int i, unsigned int j)
{
    if (i == 0 || i > _lines ||
        j == 0 || j > _rows)
        return false;

    return true;
}

// Pauses console
void Matrix::pause()
{
    std::cout << "\nSystem paused. Press Enter to proceed..." << std::endl;
    std::cin.get();
}
