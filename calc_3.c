#include "tracer.h"

double	**rotation_y(double r)
{
	double	**matrix;

	matrix = create_matrix(4, 4);
	matrix[0][0] = cos(r);
	matrix[1][1] = 1.0;
	matrix[0][2] = sin(r);
	matrix[2][0] = sin(r);
	matrix[2][2] = cos(r);
	matrix[3][3] = 1.0;
	return (matrix);
}

double	vector_abs(double *a, double *b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2]* b[2]);
}

double	*vector_cross(double *a, double *b)
{
	double	*res;

	res = (double *)malloc(sizeof(double));
	res[0] = (a[1] * b[2]) - (a[2] * b[1]);
	res[1] = (a[2] * b[0]) - (a[0] * b[2]);
	res[2] = (a[0] * b[1]) - (a[1] * b[0]);
	return (res);
}

double	*vector_normalize(double *a)
{
	double	*res;
	double	lenght;

	lenght = vector_lenght(a);
	res = (double *)malloc(sizeof(double));
	res[0] = a[0] / lenght;
	res[1] = a[1] / lenght;
	res[2] = a[2] / lenght;
	return (res);
}

double	*creat_vector(double x, double y, double z)
{
	double	*res;

	res = (double *)malloc(sizeof(double));
	res[0] = x;
	res[1] = y;
	res[2] = z;
	return (res);
}

