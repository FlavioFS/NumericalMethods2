#include "Matrix.h"

#define EXCEPTION_BOUNDS "Matrix: Out of bounds"
#define EXCEPTION_ORDER  "Matrix: Incompatible orders"

/* ==========================================================
                1. Constructors & Destructors
========================================================== */
// [1.1] - Constructor
Matrix::Matrix(unsigned int line_count, unsigned int row_count)
:_line_cursor(1), _row_cursor(1), _M(NULL)
{
    this->resize(line_count, row_count);
}

// [1.2] - Default Constructor
Matrix::Matrix()
:_line_cursor(1), _row_cursor(1), _M(NULL)
{
    this->resize(1,1);
}

// [1.3] - Destructor
Matrix::~Matrix()
{
    this->clear();
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
unsigned int Matrix::lines() const { return _lines; }     // [3.1] - Line Amount
unsigned int Matrix::rows() const { return _rows;  }      // [3.2] - Row Amount
double Matrix::get(unsigned int i, unsigned int j) const  // [3.3] - Element at position (i,j)
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
                    4. Overloaded Operations
========================================================== */
// [4.1] - Attribution
Matrix& Matrix::operator=(const Matrix &A)
{
    // Protection against self-assignment
    if (this != &A)
    {
        this->resize(A.lines(), A.rows());

        if (A._M != NULL)
            std::cout << A._M << std::endl;

        if (A._M[0] != NULL) {
            std::cout << A._M[0][0] << ", ";
            std::cout << A._M[0][1] << std::endl;
        }

        // Assignment of values
        for (unsigned int i = 0; i < this->lines(); i++)
        {
            for (unsigned int j = 0; j < this->rows(); j++)
            {
                /*std::cout << "A(" << A.lines() << "x" << A.rows() << ") -> A["
                          << i << "][" << j << "] = ";
                std::cout << A.get(i+1,j+1) << std::endl;*/

                this->put(A.get(i+1,j+1), i+1, j+1);
            }
        }
    }
    return *this;
}

// [4.2] - Sum
const Matrix Matrix::operator+(const Matrix& A) const
{
    // In order to sum, the lines and rows must match each other
    if (_lines != A.lines() ||
        _rows  != A.rows())
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
                std::cout << "--------------- (i,j) = (" << i << "," << j << ") ---------------\n"
                          << "aux = M[" << i << "][" << j << "] + A.get(" << i+1 << "," << j+1 << ")\n";
                std::cout << "aux = " << _M[i][j] << " + " << A.get(i+1,j+1) << "\n";

                double aux = this->_M[i][j] + A.get(i+1,j+1);

                std::cout << "aux = " << aux << "\n\n";
                sum.put(aux, i+1, j+1);
            }
        }
        return sum;
    }
}



/*+--------------------------------------------+*
 *|   Inaciane, implemente estas três funções, |*
 *| já que você quer aprender. :v              |*
 *+--------------------------------------------+*/

// [4.3] - Difference
Matrix Matrix::operator-(Matrix A){
    // In order to sum, the lines and rows must match each other
    if (_lines != A.lines() &&
        _rows  != A.rows())
    {
        std::cout << "Matrix difference failure. Matrix unchanged. Closing." << std::endl;
        std::cout << EXCEPTION_ORDER << std::endl;
        pause();
        throw EXCEPTION_ORDER;
    }
    else
    {
        // The result
        Matrix dif (_lines, _rows);

        // Calculating the result values
        for (unsigned int i = 0; i < _lines; i++)
        {

            for (unsigned int j = 0; j < _rows; j++)
            {
                double aux = get(i+1,j+1) - A.get(i+1,j+1);
                dif.put(aux, i+1, j+1);
            }
        }

        return dif;
    }

}



/* [4.4] - Product by Matrix
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
                    5. Other Operations
========================================================== */

// [5.1] Resizing
void Matrix::resize(unsigned int line_count, unsigned int row_count) {

    this->clear();

    // Sets the new line and row
    this->_lines = line_count;
    this->_rows = row_count;

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

/* ==========================================================
                           Private
========================================================== */
// Verifies if the given bounds are valid
bool Matrix::valid_bounds(unsigned int i, unsigned int j) const
{
    if (i == 0 || i > _lines ||
        j == 0 || j > _rows)
        return false;

    return true;
}

// Pauses console
void Matrix::pause() const
{
    std::cout << "\nSystem paused. Press Enter to proceed..." << std::endl;
    std::cin.get();
}

// Clears _M
void Matrix::clear()
{
    // If _M is not null
    if (_M) {

        // Deleting each internal dynamic array
        for (unsigned int i = 0; i < lines(); i++)
        {
            delete[] _M[i];
        }

        // Deleting external dynamic array
        delete[] _M;

        // Resize
        _lines = 0;
        _rows = 0;
        _line_cursor = 1;
        _row_cursor = 1;
        _M = NULL;
    }
}
