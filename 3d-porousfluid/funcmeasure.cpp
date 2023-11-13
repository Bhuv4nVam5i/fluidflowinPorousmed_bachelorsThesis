#include "func/funcmeasure.h"

double func::Measure::measure_wetting_fluid_proportion(const Tdouble& radius, const TMns& mnsc)
{
	const int depth = radius.size();
	const int rows = radius.front().size();
	const int cols = radius.front().front().size();

	double total = 0;
	double type_first = 0;

	
	for (int d = 0; d < depth; ++d)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				
				const double rsq = std::pow(radius[d][i][j], 2);

				
				type_first += mnsc[d][i][j].sum_type_first() * rsq;

		
				total += rsq;
			}
		}
	}

	
	return type_first / total;
}

func::Measure::FluidPpr func::Measure::fluid_ppr(
	const Tdouble& radius,
	const TMns& mnsc,
	const double time,
	const int row_b,
	const int col_b,
	const int row_e,
	const int col_e,
	const dst::Diamension& dm
)
{
	FluidPpr fluidp(time);

	const int rmin = std::min(row_b, row_e);
	const int rmax = std::max(row_b, row_e);
	const int cmin = std::min(col_b, col_e);
	const int cmax = std::max(col_b, col_e);

	for (int depth = 0; depth < dm.depth; ++depth)
	{
		for (int row = 0; row < dm.rows; ++row)
		{
			for (int col = 0; col < dm.cols; ++col)
			{
				const double rad = radius[depth][row][col];
				const double blue_ppr = mnsc[depth][row][col].sum_type_first();

				const bool inside
					= is_inside(rmin, row, rmax)
					&& is_inside(cmin, col, cmax);

				fluidp.add_blue(rad, blue_ppr, inside);
			}
		}
	}

	return fluidp;

func::Measure::FluidPpr::FluidPpr(const double time) :
	ctime(time),
	xvol_inner(0),
	xvol_outer(0),
	xvol_blue_inner(0),
	xvol_blue_outer(0)
{}


void func::Measure::FluidPpr::add_blue(const double rad, const double ppr_blue, bool is_inner)
{
	const double area = std::pow(rad, 2.0);
	const double vol = area * 1.0;

	if (is_inner)
	{
		xvol_inner += vol;
		xvol_blue_inner += vol * ppr_blue;
	}
	else
	{
		xvol_outer += vol;
		xvol_blue_outer += vol * ppr_blue;
	}
}

double func::Measure::FluidPpr::time() const
{
	return ctime;
}

double func::Measure::FluidPpr::vol_tube_outer() const
{
	return xvol_outer;
}

double func::Measure::FluidPpr::vol_tube_inner() const
{
	return xvol_inner;
}

double func::Measure::FluidPpr::vol_tube_total() const
{
	return vol_tube_inner() + vol_tube_outer();
}

double func::Measure::FluidPpr::vol_blue_inner() const
{
	return xvol_blue_inner;
}

double func::Measure::FluidPpr::vol_blue_outer() const
{
	return xvol_blue_outer;
}

double func::Measure::FluidPpr::vol_blue_total() const
{
	return vol_blue_inner() + vol_blue_outer();
}

double func::Measure::FluidPpr::vol_grey_inner() const
{
	return vol_tube_inner() - vol_blue_inner();
}

double func::Measure::FluidPpr::vol_grey_outer() const
{
	return vol_tube_outer() - vol_blue_outer();
}

double func::Measure::FluidPpr::vol_grey_total() const
{
	return vol_grey_inner() + vol_grey_outer();
}

double func::Measure::FluidPpr::ppr_blue_inner() const
{
	return vol_blue_inner() / vol_tube_inner();
}

double func::Measure::FluidPpr::ppr_blue_outer() const
{
	return vol_blue_outer() / vol_tube_outer();
}

double func::Measure::FluidPpr::ppr_blue_total() const
{
	return vol_blue_total() / vol_tube_total();
}

double func::Measure::FluidPpr::ppr_grey_inner() const
{
	return vol_grey_inner() / vol_tube_inner();
}

double func::Measure::FluidPpr::ppr_grey_outer() const
{
	return vol_grey_outer() / vol_tube_outer();
}

double func::Measure::FluidPpr::ppr_grey_total() const
{
	return vol_grey_total() / vol_tube_total();
}

bool func::Measure::is_inside(
	const int val_min,
	const int val,
	const int val_max
)
{
	return (val >= val_min) && (val <= val_max);
}

std::vector<std::string> func::Measure::FluidPpr::header()
{
	return std::vector<std::string>
	{
		"time",

			"vol_tube_outer",
			"vol_tube_inner",
			"vol_tube_total",

			"vol_blue_inner",
			"vol_blue_outer",
			"vol_blue_total",

			"vol_grey_inner",
			"vol_grey_outer",
			"vol_grey_total",

			"ppr_blue_inner",
			"ppr_blue_outer",
			"ppr_blue_total",

			"ppr_grey_inner",
			"ppr_grey_outer",
			"ppr_grey_total"
	};
}
std::vector<double> func::Measure::FluidPpr::val_vec() const
{
	return std::vector<double>
	{
		time(),
			vol_tube_outer(),
			vol_tube_inner(),
			vol_tube_total(),

			vol_blue_inner(),
			vol_blue_outer(),
			vol_blue_total(),

			vol_grey_inner(),
			vol_grey_outer(),
			vol_grey_total(),

			ppr_blue_inner(),
			ppr_blue_outer(),
			ppr_blue_total(),

			ppr_grey_inner(),
			ppr_grey_outer(),
			ppr_grey_total()
	};
}