#include <iostream>
#include <math.h>
using namespace std;
class RK
{
private:
	//一半步长
	double m_half_h;
	//变化的x，y
	double m_ptx, m_pty;
	//步长h
	double m_h;
	//初始点x0,y0
	double m_x0, m_y0;
	//x范围
	double m_max_x;
	//求解后的点
	//vector<double> m_x, m_y;
public:
	
	RK(double xend, double x0, double y0, double h = 1e-3)
	{
		m_max_x = xend;
		m_x0 = x0;
		m_y0 = y0;
		m_h = h;
		m_half_h = h / 2.0;
	}
	double Dd(double x, double y){
		return x+y;
	}
	double  K1(double x, double y)
	{
		double v = Dd(x, y);
		m_ptx = x;
		m_pty = y;
		return v;
	}
	double  K2(double _k1)
	{
		double v = Dd(m_ptx + m_half_h, m_pty + m_half_h*_k1);
		return v;
	}
	double  K3(double _k2)
	{

		double v = Dd(m_ptx + m_half_h, m_pty + m_half_h*_k2);
		return v;
	}
	double  K4(double _k3)
	{
		double v = Dd(m_ptx + m_h, m_pty + m_h*_k3);
		return v;
	}
	double  K(double x, double y)
	{
		double _k1 = K1(x, y), _k2 = K2(_k1), _k3 = K3(_k2), _k4 = K4(_k3);
		return  (_k1 + 2.0*_k2 + 2.0*_k3 + _k4) / 6.0;
	}
	void Solve()
	{
		double yn = m_y0, xstart = m_x0;
		while (xstart<=m_max_x)
		{
			double y = yn + K(xstart, yn)*m_h;//y(n+1)=y(n)+h*y'
			cout <<"x ="<< xstart <<"     y = "<< yn << endl;
			yn = y;
			xstart += m_h;
		}
	}
};
int _ppmain()
{
	RK s1(0.5, 0, 1,0.1);
	s1.Solve();
	system("pause");
	return 0;
}