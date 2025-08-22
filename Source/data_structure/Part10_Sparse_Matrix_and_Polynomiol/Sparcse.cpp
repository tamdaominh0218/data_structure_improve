#include <iostream>

struct Element
{
	int i;
	int j;
	int x;
};

struct Sparse
{
	int n, m, num;
	struct Element* ele;
};

void create_sparse(struct Sparse* s) {
	std::cout << "Enter dimension of sparse matrix: ";
	std::cin >> s->m >> s->n;
	std::cout << "Enter number of non-zero elements: ";
	std::cin >> s->num;
	s->ele = new struct Element[s->num];
	for (size_t i = 0; i < s->num; i++)
	{
		std::cout << "Choose position and enter value for position: ";
		std::cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
	}
}

void display(struct Sparse s) {
	int k = 0;
	for (size_t i = 0; i < s.m; i++)
	{
		for (size_t j = 0; j < s.n; j++)
		{
			if (k < s.num && i==s.ele[k].i && j==s.ele[k].j)
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
}

struct Sparse* add(struct Sparse* matrix1, struct Sparse* matrix2) {
	struct Sparse* sum = new struct Sparse;
	sum->ele = new Element[matrix1->num + matrix2->num];
	int i, j, k;
	i = j = k = 0;
	while (i<matrix1->num&&j<matrix2->num)
	{
		if (matrix1->ele[i].i<matrix2->ele[j].i)
		{
			sum->ele[k++] = matrix1->ele[i];
			i++;
		}
		else if (matrix1->ele[i].i > matrix2->ele[j].i)
		{
			sum->ele[k++] = matrix2->ele[j];
			j++;
		}
		else
		{
			if (matrix1->ele[i].j < matrix2->ele[j].j)
			{
				sum->ele[k++] = matrix1->ele[i];
				i++;
			}
			else if (matrix1->ele[i].j > matrix2->ele[j].j)
			{
				sum->ele[k++] = matrix2->ele[j];
				j++;
			}
			else
			{
				sum->ele[k] = matrix1->ele[i];
				sum->ele[k].x = matrix1->ele[i].x+matrix2->ele[j].x;
				i++; j++; k++;
			}
		}
	}

	//xử lý phần tử dư sau vòng while lớn ở trên
	//copy các phần tử còn dư trong matrix1 (nếu matrix1 dài hơn).
	while (i < matrix1->num)
		sum->ele[k++] = matrix1->ele[i++];
	//copy các phần tử còn dư trong matrix2 (nếu matrix2 dài hơn).
	while (j < matrix2->num)
		sum->ele[k++] = matrix2->ele[j++];

	sum->m = matrix1->m;
	sum->n = matrix1->n;
	sum->num = k;
	return sum;
}

int main() {
	struct Sparse s1, s2, *s3;
	create_sparse(&s1);
	display(s1);
	create_sparse(&s2);
	display(s2);

	s3 = add(&s1, &s2);
	display(*s3);

	return 0;
}