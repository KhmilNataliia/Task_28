#include<vector>

using namespace std;

class bacteria {
protected:
	int amount_of_youngs;
	int amount_of_middle_aged;
	int amount_of_olds;
public:
	virtual void calculate(int global_amount) 
	{
		amount_of_youngs = global_amount*0.3;
		amount_of_middle_aged = global_amount*0.5;
		amount_of_olds = global_amount*0.2;
	}
	int get_youngs() { return amount_of_youngs; }
	int get_middles() { return amount_of_middle_aged; }
	int get_olds() { return amount_of_olds; }
};

//let's imagine that in dry area the amount of bacterias increases by 30%, in middle - by 55% and in wet by 90%
//it's only for example, can differ from reality

class dry_area :public bacteria
{
public:
	dry_area(int start_amount)
	{
		start_amount += start_amount*0.3;
		calculate(start_amount);
	}
};

class middle_area :public bacteria
{
public:
	middle_area(int start_amount)
	{
		start_amount += start_amount*0.55;
		calculate(start_amount);
	}
};

class wet_area :public bacteria
{
public:
	wet_area(int start_amount)
	{
		start_amount += start_amount*0.9;
		calculate(start_amount);
	}
};


class bacteria_factory
{
	vector<bacteria*> in_areas_;
public:
	void add(int area,int amount)
	{
		switch (area)
		{
		case 1:
		{
			bacteria* n_a = new dry_area(amount);
			in_areas_.push_back(n_a);
			break;
		}
		case 2:
		{
			bacteria* n_a = new middle_area(amount);
			in_areas_.push_back(n_a);
			break;
		}
		case 3:
		{
			bacteria* n_a = new wet_area(amount);
			in_areas_.push_back(n_a);
			break;
		}
		}
	}
	int get_youngs(int indx)
	{
		return in_areas_[indx]->get_youngs();
	}
	int get_middles(int indx)
	{
		return in_areas_[indx]->get_middles();
	}
	int get_olds(int indx)
	{
		return in_areas_[indx]->get_olds();
	}
	void next_level(int indx)
	{
		in_areas_[indx]->calculate(in_areas_[indx]->get_middles() + in_areas_[indx]->get_youngs());
		//let's suppose that only middle-aged and youngs can multiply
	}
};
