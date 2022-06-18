#include "tracer.h"

double	**matrix_multpli(double **a, double **b, int line)
{
	double	**res;
	double	*var;

	res = (double **)malloc(sizeof(double *) * line);
	for (size_t i = 0; i < line; i++)
	{
		var = (double *)malloc(sizeof(double) * 4);
		for (size_t u = 0; u < 4; u++)
		{
			var[u] = 0;
			for (size_t j = 0; j < 4; j++)
			{
				var[u] += a[i][j] * b[j][u];
			}
		}
		res[i] = var;
	}
	return (res);
}

double	**matrix_transpose(double **a)
{
	double	b[4][4];

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			a[i][j] = b[j][i];
		}
	}
	return (a);
}

double	matrix_x_multpli(double a[2][2])
{
	return (a[0][0] * a[1][1] - (a[0][1] * a[1][0]));
}

double	matrix_cofactor(double a[3][3])
{
	double	res;
	int		jboo;
	double	signal;
	double	matrix[2][2];
	int		size = 2;

	res = 0.0;
	for (size_t u = 0; u < 3; u++)
	{
		signal = 1.0;
		if (u % 2 == 1)
			signal = -1.0;
		for (size_t i = 0; i < 2; i++)
		{
			jboo = 0;
			for (size_t j = 0; j < size; j++)
			{
				if (j == u)
					jboo = 1;
				matrix[i][j] = a[i + 1][j + jboo];
			}
		}
		res += (signal * a[0][u]) * matrix_x_multpli(matrix);
	}
	return (res);
}

double	matrix_determinant(double **a)
{
	double	res;
	int		jboo;
	int		size = 3;
	int		signal;
	double	matrix[3][3];

	res = 0.0;
	for (size_t u = 0; u < 4; u++)
	{
		signal = 1.0;
		if (u % 2 == 1)
			signal = -1.0;
		for (size_t i = 0; i < 3; i++)
		{
			jboo = 0;
			for (size_t j = 0; j < size; j++)
			{
				if (j == u)
					jboo = 1;
				matrix[i][j] = a[i + 1][j + jboo];
			}
		}
		res += (signal * a[0][u]) * matrix_cofactor(matrix);
	}
	return (res);
}

double	*vector_addition(double *a, double *b)
{
	double *res;

	res = (double *)malloc(sizeof(double));
	res[0] = a[0] + b[0];
	res[1] = a[1] + b[1];
	res[2] = a[2] + b[2];
	return (res);
}

double	*vector_multipli(double *a, double *b)
{
	double *res;

	res = (double *)malloc(sizeof(double));
	res[0] = a[0] * b[0];
	res[1] = a[1] * b[1];
	res[2] = a[2] * b[2];
	return (res);
}

double	*vector_subtration(double *a, double *b)
{
	double *res;

	res = (double *)malloc(sizeof(double));
	res[0] = a[0] - b[0];
	res[1] = a[1] - b[1];
	res[2] = a[2] - b[2];
	return (res);
}

double	*vector_multipli_scalar(double scalar, double *a)
{
	double *res;

	res = (double *)malloc(sizeof(double));
	res[0] = a[0] * scalar;
	res[1] = a[1] * scalar;
	res[2] = a[2] * scalar;
	return (res);
}

double	vector_lenght(double *a)
{
	return (sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]));
}
