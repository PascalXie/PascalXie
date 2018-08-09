#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// Eigen
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;

int main()
{
	cout<<"Hello"<<endl;

	// stage 1 : import data
	ifstream fread("data.txt");

	if(fread.fail()) 
	{
		cout<<"Data File dose not exist."<<endl;
		return 0;
	}

	double x=0;
	double y=0;
	vector<double> xs;
	vector<double> ys;

	while(!fread.eof())
	{
		fread>>x>>y;

		if(fread.eof()) break;

		xs.push_back(x);
		ys.push_back(y);
	}

	// stage 2 : make matrix
	int len = xs.size();

	Eigen::MatrixXd A(len, 2);
	Eigen::MatrixXd B(len, 1);

	for(int i=0; i<len; i++)
	{
		A(i,0) = xs[i];	
		A(i,1) = 1.;	

		B(i,0) = ys[i];
	}

	/*
	cout<<"A"<<endl;
	cout<<A<<endl;

	cout<<"B"<<endl;
	cout<<B<<endl;
	*/

	// stage 3 : LMS
	Eigen::MatrixXd f(2, 1);
	f = (A.transpose()*A).inverse() * A.transpose() * B;
	cout<<"f"<<endl;
	cout<<f<<endl;

	return 0;
}
