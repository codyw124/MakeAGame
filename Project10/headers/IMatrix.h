//Cody Ware
//1/8/19 

#pragma once  

class IMatrix
{
public:
	virtual void transpose() = 0;
	virtual int getRows() const = 0;
	virtual int getColumns() const = 0;
	virtual double** getData() const = 0;
};