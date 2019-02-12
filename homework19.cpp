#include <iostream>
using namespace std;

class Matrix {
	friend bool operator+=(Matrix& t1, Matrix& t2) {
		int i, j;
		if (t1.row == t2.row && t1.col == t2.col) {
			for (i = 0; i < t1.row; ++i)
				for (j = 0; j < t1.col; ++j)
					t1.p[i][j] += t2.p[i][j];
			return true;
		}
		else {
			cout << "ERROR!";
			return false;
		}
	};
	friend bool operator*=(Matrix& t1, Matrix& t2) {
		int i, j, k, t;
		if (t1.col == t2.row) {
			Matrix temp(t1.row, t2.col);
			t = t1.col;

			for (i = 0; i < temp.row; ++i)
				for (j = 0; j < temp.col; ++j)
					temp.p[i][j] = 0;

			for (i = 0; i < temp.row; ++i)
				for (j = 0; j < temp.col; ++j)
					for (k = 0; k < t; ++k)
						temp.p[i][j] += t1.p[i][k] * t2.p[k][j];

			t1 = temp;
			return true;
		}
		else {
			cout << "ERROR!";
			return false;
		}
	};
private:
	int row, col;
	double **p;
public:
	Matrix(int r, int c);
	void in();
	void out();
	Matrix& operator=(const Matrix& t);
	int operator()(int m, int n);
	~Matrix();
};


Matrix::Matrix(int r, int c) {
	int i;
	row = r;
	col = c;
	p = new double*[row];
	for ( i = 0; i < row; ++i)
		p[i] = new double[col];
}

Matrix::~Matrix() {
	int i;
	for (i = 0; i < row; ++i)
		delete []p[i];
	delete []p;
}

void Matrix::in() {
	int i, j;
	for (i = 0; i < row; ++i)
		for (j = 0; j < col; ++j)
			cin >> p[i][j];
}

void Matrix::out() {
	int i, j;
	for (i = 0; i < row - 1; ++i) {
		for (j = 0; j < col - 1; ++j)
			cout << p[i][j] << " ";
		cout << p[i][col - 1] << endl;
	}
	for (j = 0; j < col - 1; ++j)
		cout << p[row - 1][j] << " ";
	cout << p[row - 1][col - 1];
}

Matrix& Matrix::operator=(const Matrix& t) {
	if (this == &t) return *this;
	int i, j;
	for (i = 0; i < row; ++i)
		delete[]p[i];
	delete[]p;

	row = t.row;
	col = t.col;

	p = new double*[row];
	for (i = 0; i < row; ++i)
		p[i] = new double[col];

	for (i = 0; i < row; ++i)
		for (j = 0; j < col; ++j)
			p[i][j] = t.p[i][j];

	return *this;
};

int Matrix::operator()(int m, int n) {
	if (m >= row || m < 0 || n >= col || n < 0) return -1;
	else return p[m][n];
}

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1;
	Matrix m1(r1, c1);
	m1.in();
	cin >> r2 >> c2;
	Matrix m2(r2, c2);
	m2.in();


	cout << m1(r1 / 2, c1 / 2) << endl;
	cout << endl;
	if(m1 *= m2) m1.out();
	cout << endl << endl;
	if(m1 += m2) m1.out();
	cout << endl << endl;
	m1 = m2;
	m1.out();
	

	return 0;
}