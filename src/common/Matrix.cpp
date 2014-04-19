#include "Matrix.h"

#define EXCEPTION_BOUNDS "Matrix: Out of bounds"
#define EXCEPTION_ORDER  "Matrix: Incompatible orders"

/* ==========================================================
                1. Constructors & Destructors
========================================================== */
// [1.1] - Constructor
/*+-------------------------------------------------------+*
 *|   Matrix mtx (3,5);                                   |*
 *|   // mtx has 3 lines and 4 rows                       |*
 *|   // First element: 1,1 (not 0,0)                     |*
 *|   // Last element:  5,5                               |*
 *+-------------------------------------------------------+*/
Matrix::Matrix(unsigned int line_count, unsigned int row_count)
:_line_cursor(1), _row_cursor(1)
{
    this->resize(line_count, row_count);
}


// [1.2] - Empty Constructor
/*+-------------------------------------------------------+*
 *|   Matrix mtx;                                         |*
 *+-------------------------------------------------------+*/
Matrix::Matrix()
:_line_cursor(1), _row_cursor(1)
{
    this->resize(1,1);
}


// [1.3] - Destructor
/*+-------------------------------------------------------+*
 *|   Matrix mtx (10,10);                                 |*
 *|   (...)                                               |*
 *|   delete mtx;                                         |*
 *+-------------------------------------------------------+*/
Matrix::~Matrix()
{
    this->clear();
}

/* ==========================================================
                            2. Set
========================================================== */
// [2.1] - Put (set element)
// If i and j are invalid, nothing happens.
/*+-------------------------------------------------------+*
 *|   Matrix mtx (2,3);                                   |*
 *|   // mtx's element at (1,1) receives 8000             |*
 *|   mtx.put(8000, 1, 1);                                |*
 *+-------------------------------------------------------+*/
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


// [2.2] - Puts value at cursor 
// Use "[4.6] operator >>" instead of "[2.2] put_next"
//    When the cursor arrives at the end, it goes back to
// the first element: (1,1);
/*+-------------------------------------------------------+*
 *|   Matrix mtx (2,2);                                   |*
 *|   mtx.put_next(7); // mtx(1,1) contains 7             |*
 *|   mtx.put_next(3); // mtx(1,2) contains 3             |*
 *+-------------------------------------------------------+*/
void Matrix::put_next(double value)
{
    // If cursor position is valid
    if (valid_bounds(_line_cursor, _row_cursor))
    {
        // Puts the new value at that position
        this->put(value, _line_cursor, _row_cursor);

        // Moves the cursor to the right
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


// [2.3] - Moves cursor to element (i,j)
// If i and j are invalid, nothing happens.
/*+-------------------------------------------------------+*
 *|   Matrix mtx (3,3);                                   |*
 *|   mtx << 7; // mtx(1,1) contains 7                    |*
 *|   mtx << 3; // mtx(1,2) contains 3                    |*
 *|   mtx.move_cursor(3,3);                               |*
 *|   mtx << 5; // mtx(3,3) contains 5                    |*
 *+-------------------------------------------------------+*/
void Matrix::move_cursor(unsigned int i, unsigned int j)
{
    if (valid_bounds(i, j))
    {
        _line_cursor = i;
        _row_cursor = j;
    }
}

/* ==========================================================
                            3. Get
========================================================== */
// [3.1] - Line amount
// [3.2] - Row  amount
/*+-------------------------------------------------------+*
 *|   Matrix mtx(2,3);                                    |*
 *|   unsigned int l = mtx.lines(); // l contains 2       |*
 *|   unsigned int r = mtx.rows();  // r contains 3       |*
 *+-------------------------------------------------------+*/
unsigned int Matrix::lines() const { return _M.size(); }
unsigned int Matrix::rows() const { return _M.at(0).size(); }


// [3.3] - Element at position (i,j)
// If i and j are invalid, warning and returns 0.
/*+-------------------------------------------------------+*
 *|   Matrix mtx(2,2);                                    |*
 *|   mtx >> 11;                                          |*
 *|   mtx >> 12;                                          |*
 *|   mtx >> 21;                                          |*
 *|   mtx >> 22;                                          |*
 *|   // mtx:                                             |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *|                                                       |*
 *|   double v = mtx.get(1,2); // v contains 12           |*
 *+-------------------------------------------------------+*/
double Matrix::get(unsigned int i, unsigned int j) const
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
/*+-------------------------------------------------------+*
 *|   Matrix mtx(2,2);                                    |*
 *|   mtx >> 11;                                          |*
 *|   mtx >> 12;                                          |*
 *|   mtx >> 21;                                          |*
 *|   mtx >> 22;                                          |*
 *|   // mtx:                                             |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *|                                                       |*
 *|  // Copy by value:                                    |*
 *|  Matrix copy;                                         |*
 *|  copy = mtx;                                          |*
 *|  // copied: elements, cursor, size                    |*
 *|   // copy:                                            |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *+-------------------------------------------------------+*/
Matrix& Matrix::operator=(const Matrix A)
{
    // Protection against self-assignment
    if (this != &A)
    {
        this->resize(A.lines(), A.rows());
        move_cursor(A._line_cursor, A._row_cursor);

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
// If i and j are invalid, warns and throws exception.
/*+-------------------------------------------------------+*
 *|   Matrix m1(1,2);                                     |*
 *|   m1 >> 11;                                           |*
 *|   m1 >> 12;                                           |*
 *|                                                       |*
 *|   Matrix m2(1,2);                                     |*
 *|   m2 >> 21;                                           |*
 *|   m2 >> 22;                                           |*
 *|                                                       |*
 *|   Matrix sum = m1 + m2;                               |*
 *|   Matrix *sump = new Matrix;                          |*
 *|   *sump = sum;                                        |*
 *|                                                       |*
 *|   std::cout << m1 + m2 << std::endl;                  |*
 *|   std::cout << sum     << std::endl;                  |*
 *|   std::cout << *sump   << std::endl;                  |*
 *|   // Result:                                          |*
 *|     32 34                                             |*
 *|     32 34                                             |*
 *|     32 34                                             |*
 *+-------------------------------------------------------+*/
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
// Details: works the same way as "[4.2] operator+". 
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
/*+-------------------------------------------------------+*
 *|   Matrix mtx(2,2);                                    |*
 *|   mtx >> 11;                                          |*
 *|   mtx >> 12;                                          |*
 *|   mtx >> 21;                                          |*
 *|   mtx >> 22;                                          |*
 *|   // mtx:                                             |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *+-------------------------------------------------------+*/
void Matrix::operator >> (const double& value)
{
    put_next(value);
}


// [4.7] - Stream output
/*+-------------------------------------------------------+*
 *|   // mtx contains:                                    |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *|                                                       |*
 *|   std::cout << mtx << std::endl;                      |*
 *|   // Result:                                          |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *+-------------------------------------------------------+*/
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
// If line_count or row_count is 0, does nothing.
/*+-------------------------------------------------------+*
 *|   // mtx contains:                                    |*
 *|   //  11 12                                           |*
 *|   //  21 22                                           |*
 *|                                                       |*
 *|   mtx.resize(3,3);                                    |*
 *|   // mtx contains:                                    |*
 *|   //  11 12 0                                         |*
 *|   //  21 22 0                                         |*
 *|   //   0  0 0                                         |*
 *|                                                       |*
 *|   mtx.resize(1,1);                                    |*
 *|   // mtx contains:                                    |*
 *|   //  11                                              |*
 *+-------------------------------------------------------+*/
void Matrix::resize(unsigned int line_count, unsigned int row_count)
{    
    if (line_count != 0 && row_count != 0)
    {
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
}

/* ==========================================================
                           Private
========================================================== */
// Verifies if the given low level bounds (0 to n-1) are valid
/*+-------------------------------------------------------+*
 *|   Matrix mtx (2,3);                                   |*
 *|                                                       |*
 *|   mtx.valid_bounds(2,2);  // Returns false            |*
 *|   mtx.valid_bounds(0,2);  // Returns true             |*
 *|   mtx.valid_bounds(1,1);  // Returns true             |*
 *|                                                       |*
 *+-------------------------------------------------------+*/
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
    // Clears each line
    for (std::vector< std::vector<double> >::iterator it = _M.begin(); it != _M.end(); it++)
    {
        it->clear();
    }

    // Clears Matrix
    _M.clear();

    // Reset cursor to element (1,1)
    move_cursor(1,1);
}
