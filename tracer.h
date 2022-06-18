# ifndef TRACER_H
#define TRACER_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_material
{
	double	*color;
	double	ambient;
	double	diffuse;
	double	specular;
}	t_material;

typedef struct s_light
{
	double	*intensity;
	double	*posi;
}	t_light;

typedef struct s_intersec
{
	int		cont;
	double	t1;
	double	t2;
}	t_intersec;

typedef struct s_ray
{
	double	*origin;
	double	*direction;
}	t_ray;

typedef struct s_hit
{
	double			t;
}	t_hit;

typedef struct s_object
{
	double		radius;
	double		**matrix;
	char		type;
	double		*position;
	t_material	*material;
}	t_obj;

typedef struct s_seine
{
	t_light			**light;
	t_obj			**object;
	int				cont;
}	t_seine;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;



# define RESOLUTION 600
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17
# define EXPOSE 2
# define ESC 65307
# define BUTTON_RELEASE (1L << 1)
# define EXPOSURE_MASK (1L << 15)
# define NO_EVENT 0L

t_seine	*init_seine(void);
double	**create_matrix(int col, int line);
double	**matrix_inverter(double **a, double abs);
double	**matrix_multiply(double **a, double **b, int line);
double	**matrix_transpose(double **a);
double	matrix_x_multiply(double a[2][2]);
double	matrix_cofactor(double a[3][3]);
double	matrix_determinant(double **a);
double	**rotation_y(double r);
double	vector_abs(double *a, double *b);
double	*vector_cross(double *a, double *b);
double	*vector_normalize(double *a);
double	*creat_vector(double x, double y, double z);
double	*vector_addition(double *a, double *b);
double	*vector_multipli(double *a, double *b);
double	*vector_subtraction(double *a, double *b);
double	*vector_multipli_scalar(double scalar, double *a);
double	vector_length(double *a);
double	*make_point(double x, double y, double z);
double	*reflect(double *v, double *n);
void	render(t_seine *seine, t_img_data *img, int resolution);
#endif
