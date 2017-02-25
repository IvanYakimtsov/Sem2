#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include <string>
#include <math.h>

using namespace std;
///----------------------------------------------------------------------------

class GameHelper
{
private:
	vector <vector <string> > game_field;
	vector <vector <string> > ship_list;
	int single_ship, double_ship, triple_ship, quadruple_ship;
public:

	void random_create(int x)
	{
        game_field.resize(12);
		for (int i(0); i < 12; i++) { game_field[i].resize(12); }
		game_field[0][0] = ("W");
		game_field[0][1] = game_field[1][0] = ("0");
		game_field[0][2] = game_field[2][0] = ("1");
		game_field[0][3] = game_field[3][0] = ("2");
		game_field[0][4] = game_field[4][0] = ("3");
		game_field[0][5] = game_field[5][0] = ("4");
		game_field[0][6] = game_field[6][0] = ("5");
		game_field[0][7] = game_field[7][0] = ("6");
		game_field[0][8] = game_field[8][0] = ("7");
		game_field[0][9] = game_field[9][0] = ("8");
		game_field[0][10] = game_field[10][0] = ("9");
		for (int i(1); i < 11; i++)
		{
			for (int j(1); j < 11; j++)
			{
				game_field[i][j] = (" ");
			}
		}
	//	ship_list.clear();
		ship_list.resize(10);

		//ship_list.clear();
		srand(x);
		int random_i, random_j, position, relocation_j, relocation_i;
		string data;
		while (quadruple_ship != 1)
		{
			random_i = rand() % 10 + 1; random_j = rand() % 10 + 1; position = rand() % 2;
			switch (position)
			{
			case(0) :
				if (random_j < 4)
				{
					for (int j(0); j < 4; j++)
					{
						game_field[random_i][random_j + j] = ("X");
						data = game_field[random_i][0];
						data += game_field[0][random_j + j];
						ship_list[quadruple_ship].push_back(data);
					}
					for (int cheak(0); cheak < 4; cheak++)
					{
						if (game_field[random_i][random_j - 1 + cheak] == " ")
							game_field[random_i][random_j - 1 + cheak] = "O";
						if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
							game_field[random_i - 1][random_j - 1 + cheak] = "O";
						if (game_field[random_i - 1][random_j + cheak] == " ")
							game_field[random_i - 1][random_j + cheak] = "O";
						if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
							game_field[random_i - 1][random_j + 1 + cheak] = "O";
						if (game_field[random_i][random_j + 1 + cheak] == " ")
							game_field[random_i][random_j + 1 + cheak] = "O";
						if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
							game_field[random_i + 1][random_j + 1 + cheak] = "O";
						if (game_field[random_i + 1][random_j + cheak] == " ")
							game_field[random_i + 1][random_j + cheak] = "O";
						if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
							game_field[random_i + 1][random_j - 1 + cheak] = "O";
					}
				}
					if (random_j >= 4 && random_j <= 7)
					{
						relocation_j = rand() % 2;
						switch (relocation_j)
						{
						case(0) :
							for (int j(0); j < 4; j++)
							{
								game_field[random_i][random_j - j] = ("X");
								data = game_field[random_i][0];
								data += game_field[0][random_j - j];
								ship_list[0].push_back(data);
							}
								for (int cheak(0); cheak < 4; cheak++)
								{
									if (game_field[random_i][random_j - 1 - cheak] == " ")
										game_field[random_i][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
										game_field[random_i - 1][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - cheak] == " ")
										game_field[random_i - 1][random_j - cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
										game_field[random_i - 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i][random_j + 1 - cheak] == " ")
										game_field[random_i][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
										game_field[random_i + 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j - cheak] == " ")
										game_field[random_i + 1][random_j - cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
										game_field[random_i + 1][random_j - 1 - cheak] = "O";
								}
								break;
						case(1) :
							for (int j(0); j < 4; j++)
							{
								game_field[random_i][random_j + j] = ("X");
								data = game_field[random_i][0];
								data += game_field[0][random_j + j];
								ship_list[0].push_back(data);
							}
								for (int cheak(0); cheak < 4; cheak++)
								{
									if (game_field[random_i][random_j - 1 + cheak] == " ")
										game_field[random_i][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
										game_field[random_i - 1][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j + cheak] == " ")
										game_field[random_i - 1][random_j + cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
										game_field[random_i - 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i][random_j + 1 + cheak] == " ")
										game_field[random_i][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
										game_field[random_i + 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + cheak] == " ")
										game_field[random_i + 1][random_j + cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
										game_field[random_i + 1][random_j - 1 + cheak] = "O";
								}
								break;
						}
					}
					if (random_j > 7)
					{
						for (int j(0); j < 4; j++)
						{
							game_field[random_i][random_j - j] = ("X");
							data = game_field[random_i][0];
							data += game_field[0][random_j - j];
							ship_list[0].push_back(data);
						}
						for (int cheak(0); cheak < 4; cheak++)
						{
							if (game_field[random_i][random_j - 1 - cheak] == " ")
								game_field[random_i][random_j - 1 - cheak] = "O";
							if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
								game_field[random_i - 1][random_j - 1 - cheak] = "O";
							if (game_field[random_i - 1][random_j - cheak] == " ")
								game_field[random_i - 1][random_j - cheak] = "O";
							if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
								game_field[random_i - 1][random_j + 1 - cheak] = "O";
							if (game_field[random_i][random_j + 1 - cheak] == " ")
								game_field[random_i][random_j + 1 - cheak] = "O";
							if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
								game_field[random_i + 1][random_j + 1 - cheak] = "O";
							if (game_field[random_i + 1][random_j - cheak] == " ")
								game_field[random_i + 1][random_j - cheak] = "O";
							if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
								game_field[random_i + 1][random_j - 1 - cheak] = "O";
						}
					}
					break;
			case(1) :
				if (random_i < 4)
				{
					for (int i(0); i < 4; i++)
					{
						game_field[random_i + i][random_j] = ("X");
						data = game_field[random_i + i][0];
						data += game_field[0][random_j];
						ship_list[0].push_back(data);
					}
					for (int cheak(0); cheak < 4; cheak++)
					{
						if (game_field[random_i + cheak][random_j - 1] == " ")
							game_field[random_i + cheak][random_j - 1] = "O";
						if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
							game_field[random_i - 1 + cheak][random_j - 1] = "O";
						if (game_field[random_i - 1 + cheak][random_j] == " ")
							game_field[random_i - 1 + cheak][random_j] = "O";
						if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
							game_field[random_i - 1 + cheak][random_j + 1] = "O";
						if (game_field[random_i + cheak][random_j + 1] == " ")
							game_field[random_i + cheak][random_j + 1] = "O";
						if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
							game_field[random_i + 1 + cheak][random_j + 1] = "O";
						if (game_field[random_i + 1 + cheak][random_j] == " ")
							game_field[random_i + 1 + cheak][random_j] = "O";
						if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
							game_field[random_i + 1 + cheak][random_j - 1] = "O";
					}
				}

					if (random_i >= 4 & random_i <= 7)
					{
						int relocation_i = rand() % 2;
						switch (relocation_i)
						{
						case(0) :
							for (int i(0); i < 4; i++)
							{
								game_field[random_i - i][random_j] = ("X");
								data = game_field[random_i - i][0];
								data += game_field[0][random_j];
								ship_list[0].push_back(data);
							}
								for (int cheak(0); cheak < 4; cheak++)
								{
									if (game_field[random_i - cheak][random_j - 1] == " ")
										game_field[random_i - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
										game_field[random_i - 1 - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j] == " ")
										game_field[random_i - 1 - cheak][random_j] = "O";
									if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
										game_field[random_i - 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i - cheak][random_j + 1] == " ")
										game_field[random_i - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
										game_field[random_i + 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j] == " ")
										game_field[random_i + 1 - cheak][random_j] = "O";
									if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
										game_field[random_i + 1 - cheak][random_j - 1] = "O";
								}
								break;
						case(1) :
							for (int i(0); i < 4; i++)
							{
								game_field[random_i + i][random_j] = ("X");
								data = game_field[random_i + i][0];
								data += game_field[0][random_j];
								ship_list[0].push_back(data);
							}
								for (int cheak(0); cheak < 4; cheak++)
								{
									if (game_field[random_i + cheak][random_j - 1] == " ")
										game_field[random_i + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
										game_field[random_i - 1 + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j] == " ")
										game_field[random_i - 1 + cheak][random_j] = "O";
									if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
										game_field[random_i - 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + cheak][random_j + 1] == " ")
										game_field[random_i + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
										game_field[random_i + 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j] == " ")
										game_field[random_i + 1 + cheak][random_j] = "O";
									if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
										game_field[random_i + 1 + cheak][random_j - 1] = "O";
								}

								break;
						}
					}
					if (random_i > 7)
					{
						for (int i(0); i < 4; i++)
						{
							game_field[random_i - i][random_j] = ("X");
							data = game_field[random_i - i][0];
							data += game_field[0][random_j];
							ship_list[0].push_back(data);
						}
						for (int cheak(0); cheak < 4; cheak++)
						{
							if (game_field[random_i - cheak][random_j - 1] == " ")
								game_field[random_i - cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
								game_field[random_i - 1 - cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 - cheak][random_j] == " ")
								game_field[random_i - 1 - cheak][random_j] = "O";
							if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
								game_field[random_i - 1 - cheak][random_j + 1] = "O";
							if (game_field[random_i - cheak][random_j + 1] == " ")
								game_field[random_i - cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
								game_field[random_i + 1 - cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 - cheak][random_j] == " ")
								game_field[random_i + 1 - cheak][random_j] = "O";
							if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
								game_field[random_i + 1 - cheak][random_j - 1] = "O";
						}
					}

					break;
			}
			++quadruple_ship;
		}
		while (triple_ship != 2)
		{
			random_i = rand() % 10 + 1;
			random_j = rand() % 10 + 1;
			position = rand() % 2;
			switch (position)
			{
			case(0) :
				if (random_j < 3)
				{
					if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j + 1] != "O" && game_field[random_i][random_j + 2] != "O")
					{
						for (int j(0); j < 3; j++)
						{
							game_field[random_i][random_j + j] = ("X");
							data = game_field[random_i][0];
							data += game_field[0][random_j + j];
							ship_list[1 + triple_ship].push_back(data);
						}
						for (int cheak(0); cheak < 3; cheak++)
						{
							if (game_field[random_i][random_j - 1 + cheak] == " ")
								game_field[random_i][random_j - 1 + cheak] = "O";
							if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
								game_field[random_i - 1][random_j - 1 + cheak] = "O";
							if (game_field[random_i - 1][random_j + cheak] == " ")
								game_field[random_i - 1][random_j + cheak] = "O";
							if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
								game_field[random_i - 1][random_j + 1 + cheak] = "O";
							if (game_field[random_i][random_j + 1 + cheak] == " ")
								game_field[random_i][random_j + 1 + cheak] = "O";
							if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
								game_field[random_i + 1][random_j + 1 + cheak] = "O";
							if (game_field[random_i + 1][random_j + cheak] == " ")
								game_field[random_i + 1][random_j + cheak] = "O";
							if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
								game_field[random_i + 1][random_j - 1 + cheak] = "O";
						}
						triple_ship++;
					}
				}
					if (random_j >= 3 && random_j <= 8)
					{
						relocation_j = rand() % 2;
						switch (relocation_j)
						{
						case(0) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j - 1] != "O" && game_field[random_i][random_j - 2] != "O")
							{
								for (int j(0); j < 3; j++)
								{
									game_field[random_i][random_j - j] = ("X");
									data = game_field[random_i][0];
									data += game_field[0][random_j - j];
									ship_list[1 + triple_ship].push_back(data);
								}
								for (int cheak(0); cheak < 3; cheak++)
								{
									if (game_field[random_i][random_j - 1 - cheak] == " ")
										game_field[random_i][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
										game_field[random_i - 1][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - cheak] == " ")
										game_field[random_i - 1][random_j - cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
										game_field[random_i - 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i][random_j + 1 - cheak] == " ")
										game_field[random_i][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
										game_field[random_i + 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j - cheak] == " ")
										game_field[random_i + 1][random_j - cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
										game_field[random_i + 1][random_j - 1 - cheak] = "O";
								}
								triple_ship++;
							}
								break;
						case(1) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j + 1] != "O" && game_field[random_i][random_j + 2] != "O")
							{
								for (int j(0); j < 3; j++)
								{
									game_field[random_i][random_j + j] = ("X");
									data = game_field[random_i][0];
									data += game_field[0][random_j + j];
									ship_list[1 + triple_ship].push_back(data);
								}
								for (int cheak(0); cheak < 3; cheak++)
								{
									if (game_field[random_i][random_j - 1 + cheak] == " ")
										game_field[random_i][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
										game_field[random_i - 1][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j + cheak] == " ")
										game_field[random_i - 1][random_j + cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
										game_field[random_i - 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i][random_j + 1 + cheak] == " ")
										game_field[random_i][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
										game_field[random_i + 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + cheak] == " ")
										game_field[random_i + 1][random_j + cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
										game_field[random_i + 1][random_j - 1 + cheak] = "O";
								}
								triple_ship++;
							}
								break;
						}
					}
					if (random_j > 8)
					{
						if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j - 1] != "O" && game_field[random_i][random_j - 2] != "O")
						{
							for (int j(0); j < 3; j++)
							{
								game_field[random_i][random_j - j] = ("X");
								data = game_field[random_i][0];
								data += game_field[0][random_j - j];
								ship_list[1 + triple_ship].push_back(data);
							}
							for (int cheak(0); cheak < 3; cheak++)
							{
								if (game_field[random_i][random_j - 1 - cheak] == " ")
									game_field[random_i][random_j - 1 - cheak] = "O";
								if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
									game_field[random_i - 1][random_j - 1 - cheak] = "O";
								if (game_field[random_i - 1][random_j - cheak] == " ")
									game_field[random_i - 1][random_j - cheak] = "O";
								if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
									game_field[random_i - 1][random_j + 1 - cheak] = "O";
								if (game_field[random_i][random_j + 1 - cheak] == " ")
									game_field[random_i][random_j + 1 - cheak] = "O";
								if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
									game_field[random_i + 1][random_j + 1 - cheak] = "O";
								if (game_field[random_i + 1][random_j - cheak] == " ")
									game_field[random_i + 1][random_j - cheak] = "O";
								if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
									game_field[random_i + 1][random_j - 1 - cheak] = "O";
							}
							triple_ship++;
						}
					}
					break;
			case(1) :
				if (random_i < 3)
				{
					if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i + 1][random_j] != "O" && game_field[random_i + 2][random_j] != "O")
					{
						for (int i(0); i < 3; i++)
						{
							game_field[random_i + i][random_j] = ("X");
							data = game_field[random_i + i][0];
							data += game_field[0][random_j];
							ship_list[1 + triple_ship].push_back(data);
						}
						for (int cheak(0); cheak < 3; cheak++)
						{
							if (game_field[random_i + cheak][random_j - 1] == " ")
								game_field[random_i + cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
								game_field[random_i - 1 + cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 + cheak][random_j] == " ")
								game_field[random_i - 1 + cheak][random_j] = "O";
							if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
								game_field[random_i - 1 + cheak][random_j + 1] = "O";
							if (game_field[random_i + cheak][random_j + 1] == " ")
								game_field[random_i + cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
								game_field[random_i + 1 + cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 + cheak][random_j] == " ")
								game_field[random_i + 1 + cheak][random_j] = "O";
							if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
								game_field[random_i + 1 + cheak][random_j - 1] = "O";
						}
						triple_ship++;
					}
				}
					if (random_i >= 3 & random_i <= 8)
					{
						int relocation_i = rand() % 2;
						switch (relocation_i)
						{
						case(0) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i - 1][random_j] != "O" && game_field[random_i - 2][random_j] != "O")
							{
								for (int i(0); i < 3; i++)
								{
									game_field[random_i - i][random_j] = ("X");
									data = game_field[random_i - i][0];
									data += game_field[0][random_j];
									ship_list[1 + triple_ship].push_back(data);
								}
								for (int cheak(0); cheak < 3; cheak++)
								{
									if (game_field[random_i - cheak][random_j - 1] == " ")
										game_field[random_i - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
										game_field[random_i - 1 - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j] == " ")
										game_field[random_i - 1 - cheak][random_j] = "O";
									if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
										game_field[random_i - 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i - cheak][random_j + 1] == " ")
										game_field[random_i - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
										game_field[random_i + 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j] == " ")
										game_field[random_i + 1 - cheak][random_j] = "O";
									if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
										game_field[random_i + 1 - cheak][random_j - 1] = "O";
								}
								triple_ship++;
							}

								break;
						case(1) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i + 1][random_j] != "O" && game_field[random_i + 2][random_j] != "O")
							{
								for (int i(0); i < 3; i++)
								{
									game_field[random_i + i][random_j] = ("X");
									data = game_field[random_i + i][0];
									data += game_field[0][random_j];
									ship_list[1 + triple_ship].push_back(data);
								}
								for (int cheak(0); cheak < 3; cheak++)
								{
									if (game_field[random_i + cheak][random_j - 1] == " ")
										game_field[random_i + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
										game_field[random_i - 1 + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j] == " ")
										game_field[random_i - 1 + cheak][random_j] = "O";
									if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
										game_field[random_i - 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + cheak][random_j + 1] == " ")
										game_field[random_i + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
										game_field[random_i + 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j] == " ")
										game_field[random_i + 1 + cheak][random_j] = "O";
									if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
										game_field[random_i + 1 + cheak][random_j - 1] = "O";
								}
								triple_ship++;
							}


								break;
						}
					}
					if (random_i > 8)
					{
						if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i - 1][random_j] != "O" && game_field[random_i - 2][random_j] != "O")
						{
							for (int i(0); i < 3; i++)
							{
								game_field[random_i - i][random_j] = ("X");
								data = game_field[random_i - i][0];
								data += game_field[0][random_j];
								ship_list[1 + triple_ship].push_back(data);
							}
							for (int cheak(0); cheak < 3; cheak++)
							{
								if (game_field[random_i - cheak][random_j - 1] == " ")
									game_field[random_i - cheak][random_j - 1] = "O";
								if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
									game_field[random_i - 1 - cheak][random_j - 1] = "O";
								if (game_field[random_i - 1 - cheak][random_j] == " ")
									game_field[random_i - 1 - cheak][random_j] = "O";
								if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
									game_field[random_i - 1 - cheak][random_j + 1] = "O";
								if (game_field[random_i - cheak][random_j + 1] == " ")
									game_field[random_i - cheak][random_j + 1] = "O";
								if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
									game_field[random_i + 1 - cheak][random_j + 1] = "O";
								if (game_field[random_i + 1 - cheak][random_j] == " ")
									game_field[random_i + 1 - cheak][random_j] = "O";
								if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
									game_field[random_i + 1 - cheak][random_j - 1] = "O";
							}
							triple_ship++;
						}

					}

					break;
			}
		}
		while (double_ship != 3)
		{
			random_i = rand() % 10 + 1;
			random_j = rand() % 10 + 1;
			position = rand() % 2;
			switch (position)
			{
			case(0) :
				if (random_j < 2)
				{
					if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j + 1] != "O" && game_field[random_i][random_j + 2] != "O")
					{
						for (int j(0); j < 3; j++)
						{
							game_field[random_i][random_j + j] = ("X");
							data = game_field[random_i][0];
							data += game_field[0][random_j + j];
							ship_list[3 + double_ship].push_back(data);
						}
						for (int cheak(0); cheak < 2; cheak++)
						{
							if (game_field[random_i][random_j - 1 + cheak] == " ")
								game_field[random_i][random_j - 1 + cheak] = "O";
							if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
								game_field[random_i - 1][random_j - 1 + cheak] = "O";
							if (game_field[random_i - 1][random_j + cheak] == " ")
								game_field[random_i - 1][random_j + cheak] = "O";
							if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
								game_field[random_i - 1][random_j + 1 + cheak] = "O";
							if (game_field[random_i][random_j + 1 + cheak] == " ")
								game_field[random_i][random_j + 1 + cheak] = "O";
							if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
								game_field[random_i + 1][random_j + 1 + cheak] = "O";
							if (game_field[random_i + 1][random_j + cheak] == " ")
								game_field[random_i + 1][random_j + cheak] = "O";
							if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
								game_field[random_i + 1][random_j - 1 + cheak] = "O";
						}
						double_ship++;
					}
				}
					if (random_j >= 2 && random_j <= 9)
					{
						relocation_j = rand() % 2;
						switch (relocation_j)
						{
						case(0) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j - 1] != "O")
							{
								for (int j(0); j < 2; j++)
								{
									game_field[random_i][random_j - j] = ("X");
									data = game_field[random_i][0];
									data += game_field[0][random_j - j];
									ship_list[3 + double_ship].push_back(data);
								}
								for (int cheak(0); cheak < 2; cheak++)
								{
									if (game_field[random_i][random_j - 1 - cheak] == " ")
										game_field[random_i][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
										game_field[random_i - 1][random_j - 1 - cheak] = "O";
									if (game_field[random_i - 1][random_j - cheak] == " ")
										game_field[random_i - 1][random_j - cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
										game_field[random_i - 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i][random_j + 1 - cheak] == " ")
										game_field[random_i][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
										game_field[random_i + 1][random_j + 1 - cheak] = "O";
									if (game_field[random_i + 1][random_j - cheak] == " ")
										game_field[random_i + 1][random_j - cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
										game_field[random_i + 1][random_j - 1 - cheak] = "O";
								}
								double_ship++;
							}
								break;
						case(1) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j + 1] != "O")
							{
								for (int j(0); j < 2; j++)
								{
									game_field[random_i][random_j + j] = ("X");
									data = game_field[random_i][0];
									data += game_field[0][random_j + j];
									ship_list[3 + double_ship].push_back(data);
								}
								for (int cheak(0); cheak < 2; cheak++)
								{
									if (game_field[random_i][random_j - 1 + cheak] == " ")
										game_field[random_i][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j - 1 + cheak] == " ")
										game_field[random_i - 1][random_j - 1 + cheak] = "O";
									if (game_field[random_i - 1][random_j + cheak] == " ")
										game_field[random_i - 1][random_j + cheak] = "O";
									if (game_field[random_i - 1][random_j + 1 + cheak] == " ")
										game_field[random_i - 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i][random_j + 1 + cheak] == " ")
										game_field[random_i][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + 1 + cheak] == " ")
										game_field[random_i + 1][random_j + 1 + cheak] = "O";
									if (game_field[random_i + 1][random_j + cheak] == " ")
										game_field[random_i + 1][random_j + cheak] = "O";
									if (game_field[random_i + 1][random_j - 1 + cheak] == " ")
										game_field[random_i + 1][random_j - 1 + cheak] = "O";
								}
								double_ship++;
							}
								break;
						}
					}
					if (random_j > 9)
					{
						if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i][random_j - 1] != "O")
						{
							for (int j(0); j < 2; j++)
							{
								game_field[random_i][random_j - j] = ("X");
								data = game_field[random_i][0];
								data += game_field[0][random_j - j];
								ship_list[3 + double_ship].push_back(data);
							}
							for (int cheak(0); cheak < 2; cheak++)
							{
								if (game_field[random_i][random_j - 1 - cheak] == " ")
									game_field[random_i][random_j - 1 - cheak] = "O";
								if (game_field[random_i - 1][random_j - 1 - cheak] == " ")
									game_field[random_i - 1][random_j - 1 - cheak] = "O";
								if (game_field[random_i - 1][random_j - cheak] == " ")
									game_field[random_i - 1][random_j - cheak] = "O";
								if (game_field[random_i - 1][random_j + 1 - cheak] == " ")
									game_field[random_i - 1][random_j + 1 - cheak] = "O";
								if (game_field[random_i][random_j + 1 - cheak] == " ")
									game_field[random_i][random_j + 1 - cheak] = "O";
								if (game_field[random_i + 1][random_j + 1 - cheak] == " ")
									game_field[random_i + 1][random_j + 1 - cheak] = "O";
								if (game_field[random_i + 1][random_j - cheak] == " ")
									game_field[random_i + 1][random_j - cheak] = "O";
								if (game_field[random_i + 1][random_j - 1 - cheak] == " ")
									game_field[random_i + 1][random_j - 1 - cheak] = "O";
							}
							double_ship++;
						}
					}
					break;
			case(1) :
				if (random_i < 2)
				{
					if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i + 1][random_j] != "O")
					{
						for (int i(0); i < 2; i++)
						{
							game_field[random_i + i][random_j] = ("X");
							data = game_field[random_i + i][0];
							data += game_field[0][random_j];
							ship_list[3 + double_ship].push_back(data);
						}
						for (int cheak(0); cheak < 2; cheak++)
						{
							if (game_field[random_i + cheak][random_j - 1] == " ")
								game_field[random_i + cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
								game_field[random_i - 1 + cheak][random_j - 1] = "O";
							if (game_field[random_i - 1 + cheak][random_j] == " ")
								game_field[random_i - 1 + cheak][random_j] = "O";
							if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
								game_field[random_i - 1 + cheak][random_j + 1] = "O";
							if (game_field[random_i + cheak][random_j + 1] == " ")
								game_field[random_i + cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
								game_field[random_i + 1 + cheak][random_j + 1] = "O";
							if (game_field[random_i + 1 + cheak][random_j] == " ")
								game_field[random_i + 1 + cheak][random_j] = "O";
							if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
								game_field[random_i + 1 + cheak][random_j - 1] = "O";
						}
						double_ship++;
					}
				}
					if (random_i >= 2 & random_i <= 9)
					{
						int relocation_i = rand() % 2;
						switch (relocation_i)
						{
						case(0) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i - 1][random_j] != "O")
							{
								for (int i(0); i < 2; i++)
								{
									game_field[random_i - i][random_j] = ("X");
									data = game_field[random_i - i][0];
									data += game_field[0][random_j];
									ship_list[3 + double_ship].push_back(data);
								}
								for (int cheak(0); cheak < 2; cheak++)
								{
									if (game_field[random_i - cheak][random_j - 1] == " ")
										game_field[random_i - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
										game_field[random_i - 1 - cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 - cheak][random_j] == " ")
										game_field[random_i - 1 - cheak][random_j] = "O";
									if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
										game_field[random_i - 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i - cheak][random_j + 1] == " ")
										game_field[random_i - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
										game_field[random_i + 1 - cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 - cheak][random_j] == " ")
										game_field[random_i + 1 - cheak][random_j] = "O";
									if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
										game_field[random_i + 1 - cheak][random_j - 1] = "O";
								}
								double_ship++;
							}

								break;
						case(1) :
							if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i + 1][random_j] != "O")
							{
								for (int i(0); i < 2; i++)
								{
									game_field[random_i + i][random_j] = ("X");
									data = game_field[random_i + i][0];
									data += game_field[0][random_j];
									ship_list[3 + double_ship].push_back(data);
								}
								for (int cheak(0); cheak < 2; cheak++)
								{
									if (game_field[random_i + cheak][random_j - 1] == " ")
										game_field[random_i + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j - 1] == " ")
										game_field[random_i - 1 + cheak][random_j - 1] = "O";
									if (game_field[random_i - 1 + cheak][random_j] == " ")
										game_field[random_i - 1 + cheak][random_j] = "O";
									if (game_field[random_i - 1 + cheak][random_j + 1] == " ")
										game_field[random_i - 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + cheak][random_j + 1] == " ")
										game_field[random_i + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j + 1] == " ")
										game_field[random_i + 1 + cheak][random_j + 1] = "O";
									if (game_field[random_i + 1 + cheak][random_j] == " ")
										game_field[random_i + 1 + cheak][random_j] = "O";
									if (game_field[random_i + 1 + cheak][random_j - 1] == " ")
										game_field[random_i + 1 + cheak][random_j - 1] = "O";
								}
								double_ship++;
							}


								break;
						}
					}
					if (random_i > 9)
					{
						if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X" && game_field[random_i - 1][random_j] != "O")
						{
							for (int i(0); i < 2; i++)
							{
								game_field[random_i - i][random_j] = ("X");
								data = game_field[random_i - i][0];
								data += game_field[0][random_j];
								ship_list[3 + double_ship].push_back(data);
							}
							for (int cheak(0); cheak < 2; cheak++)
							{
								if (game_field[random_i - cheak][random_j - 1] == " ")
									game_field[random_i - cheak][random_j - 1] = "O";
								if (game_field[random_i - 1 - cheak][random_j - 1] == " ")
									game_field[random_i - 1 - cheak][random_j - 1] = "O";
								if (game_field[random_i - 1 - cheak][random_j] == " ")
									game_field[random_i - 1 - cheak][random_j] = "O";
								if (game_field[random_i - 1 - cheak][random_j + 1] == " ")
									game_field[random_i - 1 - cheak][random_j + 1] = "O";
								if (game_field[random_i - cheak][random_j + 1] == " ")
									game_field[random_i - cheak][random_j + 1] = "O";
								if (game_field[random_i + 1 - cheak][random_j + 1] == " ")
									game_field[random_i + 1 - cheak][random_j + 1] = "O";
								if (game_field[random_i + 1 - cheak][random_j] == " ")
									game_field[random_i + 1 - cheak][random_j] = "O";
								if (game_field[random_i + 1 - cheak][random_j - 1] == " ")
									game_field[random_i + 1 - cheak][random_j - 1] = "O";
							}
							double_ship++;
						}

					}

					break;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while (single_ship != 4)
		{
			random_i = rand() % 10 + 1; random_j = rand() % 10 + 1; position = rand() % 2;
			if (game_field[random_i][random_j] != "O" && game_field[random_i][random_j] != "X")
			{
				game_field[random_i][random_j] = ("X");
				data = game_field[random_i][0];
				data += game_field[0][random_j];
				ship_list[6 + single_ship].push_back(data);
				if (game_field[random_i][random_j - 1] == " ")
					game_field[random_i][random_j - 1] = "O";
				if (game_field[random_i - 1][random_j - 1] == " ")
					game_field[random_i - 1][random_j - 1] = "O";
				if (game_field[random_i - 1][random_j] == " ")
					game_field[random_i - 1][random_j] = "O";
				if (game_field[random_i - 1][random_j + 1] == " ")
					game_field[random_i - 1][random_j + 1] = "O";
				if (game_field[random_i][random_j + 1] == " ")
					game_field[random_i][random_j + 1] = "O";
				if (game_field[random_i + 1][random_j + 1] == " ")
					game_field[random_i + 1][random_j + 1] = "O";
				if (game_field[random_i + 1][random_j] == " ")
					game_field[random_i + 1][random_j] = "O";
				if (game_field[random_i + 1][random_j - 1] == " ")
					game_field[random_i + 1][random_j - 1] = "O";
				single_ship++;
			}
		}
	}


	vector < vector <string> > setLocation()
	{
	    srand(time(NULL)+rand());
	    int x=rand()%1000;
	    random_create(x);
	    for(int i=0;i<ship_list.size();i++)
        {
            ship_list[i].size();
            for(int j=0;j<ship_list[i].size();j++) cout<<ship_list[i][j]<<" ";
            cout<<endl;
        }
		return ship_list;
	}



};

class Ship
{
private:
    vector<string> locationCells;
public:
    void setShip(vector<string>);
    string checkYourself(string);
};


class Player
{
private:
    vector<Ship> ShipList;
    bool loose=false;
public:
    void setShip(vector< vector<string> >);
    string checkUserGuess(string);
    bool checkLoose();
};






class GameBust
{
private:
    GameHelper *helper = new GameHelper();
    Player *player1 = new Player();
    Player *player2 = new Player();
    bool player1_loose = false;
    bool player2_loose = false;
    int coord_X,coord_Y;
    bool player_swap=false;
public:
    string startCalc(int,int);
    void gameSetUp();
    int get_X();
    int get_Y();
};




#endif // GAME_H_INCLUDED
