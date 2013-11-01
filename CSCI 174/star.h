#ifndef STAR_H
#define STAR_H



class STAR
{
public:
	STAR();
	~STAR();

	int findStar(vector <vector <int>>);
private:

};

int STAR::findStar(vector <vector <int>> star)
{
	int j;
	bool isStar;
	for (int i = 0; i < star.size(); i++)
	{
		j = 0;
		if(star[j][i] == 1)
		{
			while(j < star.size())
			{
				if(star[j][i] == 1)
					j++;
				else
					break;
			}
		}

		if (j == star[i].size())
			return i;
	}
	return -1;
}

STAR::STAR()
{
}

STAR::~STAR()
{
}

#endif