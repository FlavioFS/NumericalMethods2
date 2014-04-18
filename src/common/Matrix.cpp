#include "Matrix.h"

#define EXCEPTION_BOUNDS "Matrix: Out of bounds"
#define EXCEPTION_ORDER  "Matrix: Incompatible orders"

/* ==========================================================
                1. Constructors & Destructors
========================================================== */
// [1.1] - Constructor
Matrix::Matrix(unsigned int line_count, unsigned int row_count)
:_line_cursor(1), _row_cursor(1)
{
    this->resize(line_count, row_count);
}

// [1.2] - Default Constructor
Matrix::Matrix()
:_line_cursor(1), _row_cursor(1)
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
        _row_cursor++;

        // Row over
        if (_row_cursor > rows())
        {
            // Matrix over -> Back to the first position
            if (_line_cursor == lines())
            {
                _line_cursor = 1;
                _row_cursor = 1;
            }

            // Line over -> Go to next line
            else
            {
                _row_cursor = 1;
                _line_cursor++;
            }
        }
    }
}

/* ==========================================================
                            3. Get
========================================================== */
unsigned int Matrix::lines() const { return _M.size(); }        // [3.1] - Line Amount
unsigned int Matrix::rows() const { return _M.at(0).size(); }   // [3.2] - Row Amount
double Matrix::get(unsigned int i, unsigned int j) const        // [3.3] - Element at position (i,j)
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
Matrix& Matrix::operator=(const Matrix A)
{
    // Protection against self-assignment
    if (this != &A)
    {
        this->resize(A.lines(), A.rows());
        this->_line_cursor = A._line_cursor;
        this->_row_cursor = A._row_cursor;

        // Assignment of values
        for (unsigned int i = 0; i < this->lines(); i++)
        {
            for (unsigned int j = 0; j < this->rows(); j++)
            {
                this->put(A.get(i+1,j+1), i+1, j+1);
            }
        }
    }
    return *this;
}

// [4.2] - Sum
const Matrix Matrix::operator+(const Matrix A) const
{
    // In order to sum, the lines and rows must match each other
    if (lines() != A.lines() ||
        rows()  != A.rows())
    {
        std::cout << "Matrix sum failure. Matrix unchanged. Closing." << std::endl;
        std::cout << EXCEPTION_ORDER << std::endl;
        pause();
        throw EXCEPTION_ORDER;
    }
    else
    {
        // The result
        Matrix sum (lines(), rows());

        for (unsigned int i = 0; i < lines(); i++)
        {
            for (unsigned int j = 0; j < rows(); j++)
            {
                // Calculating the result values
                double aux = this->get(i+1, j+1) + A.get(i+1,j+1);

                // Assigning to respective positions
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
const Matrix Matrix::operator-(const Matrix A) const{
    // In order to sum, the lines and rows must match each other
    if (lines() != A.lines() &&
        rows()  != A.rows())
    {
        std::cout << "Matrix difference failure. Matrix unchanged. Closing." << std::endl;
        std::cout << EXCEPTION_ORDER << std::endl;
        pause();
        throw EXCEPTION_ORDER;
    }
    else
    {
        // The result
        Matrix dif (lines(), rows());

        // Calculating the result values
        for (unsigned int i = 0; i < lines(); i++)
        {

            for (unsigned int j = 0; j < rows(); j++)
            {
                // Calculating the result values
                double aux = get(i+1,j+1) - A.get(i+1,j+1);

                // Assigning to respective positions
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
std::ostream& operator << (std::ostream& out, const Matrix& M)
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
    _M.resize(line_count);

    for (unsigned int i = 0; i < line_count; i++)
    {
        _M[i].resize(row_count);

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
    if (i == 0 || i > lines() ||
        j == 0 || j > rows())
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
    _M.clear();
    _line_cursor = 1;
    _row_cursor = 1;
}
