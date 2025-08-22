#include <iostream>


class Element
{
public:
	int i;
	int j;
	int x;
};

class Sparse
{
	int n, m, num;
	Element* ele;
public:
	Sparse(int n, int m, int num);
	Sparse(const Sparse& other);
	Sparse& operator=(const Sparse& other);
	friend std::istream& operator>>(std::istream& is, Sparse& s);
	friend std::ostream& operator<<(std::ostream& is, Sparse& s);
	Sparse operator+(Sparse& s);
	~Sparse();
};

Sparse::Sparse(int n, int m, int num) {
	this->n = n;
	this->m = m;
	this->num = num;
	this->ele = new Element[num];
}

//Copy constructor
Sparse::Sparse(const Sparse& other) {
	n = other.n; m = other.m; num = other.num;
	ele = new Element[num];
	for (int i = 0; i < num; i++) ele[i] = other.ele[i];
}

//Copy assignment
Sparse& Sparse::operator=(const Sparse& other) {
	if (this != &other) {
		delete[] ele;
		n = other.n; m = other.m; num = other.num;
		ele = new Element[num];
		for (int i = 0; i < num; i++) ele[i] = other.ele[i];
	}
	return *this;
}

std::istream& operator>>(std::istream& is, Sparse& s){
	std::cout << "Enter dimension of sparse matrix: ";
	std::cin >> s.m >> s.n;
	std::cout << "Enter number of non-zero elements: ";
	std::cin >> s.num;
	delete[] s.ele; //giải phóng trước khi cấp phát lại: tránh ele có thể trỏ đến vùng nhớ cũ → bị memory leak.
	s.ele = new struct Element[s.num];
	for (size_t i = 0; i < s.num; i++)
	{
		std::cout << "Choose position and enter value for position: ";
		std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Sparse& s) {
	int k = 0;
	for (size_t i = 0; i < s.m; i++)
	{
		for (size_t j = 0; j < s.n; j++)
		{
			if (k < s.num && i == s.ele[k].i && j == s.ele[k].j)
			{
				std::cout << s.ele[k].x << " ";
				k++;
			}
			else
			{
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return os;
}

Sparse Sparse::operator+(Sparse& matrix2) {
	Sparse sum(m, n, num + matrix2.num); // cấp phát đủ chỗ
	int i, j, k;
	i = j = k = 0;
	while (i < num && j < matrix2.num)
	{
		if (ele[i].i < matrix2.ele[j].i)
		{
			sum.ele[k++] = ele[i];
			i++;
		}
		else if (ele[i].i > matrix2.ele[j].i)
		{
			sum.ele[k++] = matrix2.ele[j];
			j++;
		}
		else
		{
			if (ele[i].j < matrix2.ele[j].j)
			{
				sum.ele[k++] = ele[i];
				i++;
			}
			else if (ele[i].j > matrix2.ele[j].j)
			{
				sum.ele[k++] = matrix2.ele[j];
				j++;
			}
			else
			{
				sum.ele[k] = ele[i];
				sum.ele[k].x = ele[i].x + matrix2.ele[j].x;
				i++; j++; k++;
			}
		}
	}

	//xử lý phần tử dư sau vòng while lớn ở trên
	//copy các phần tử còn dư trong matrix1 (nếu matrix1 dài hơn).
	while (i < num)
		sum.ele[k++] = ele[i++];
	//copy các phần tử còn dư trong matrix2 (nếu matrix2 dài hơn).
	while (j < matrix2.num)
		sum.ele[k++] = matrix2.ele[j++];

	sum.m = m;
	sum.n = n;
	sum.num = k;
	return sum;
}

Sparse::~Sparse() {
	delete[] ele;
}

int main() {
	Sparse s1(4, 4, 4);
	Sparse s2(4, 4, 4);

	std::cin >> s1;
	std::cin >> s2;

	Sparse sum = s1 + s2;

	std::cout << "First Matrix" << std::endl << s1;
	std::cout << "Second MAtrix" << std::endl << s2;
	std::cout << "Sum Matrix" << std::endl << sum;
	return 0;
}