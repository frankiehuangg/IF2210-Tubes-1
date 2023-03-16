#include "header/Ability_Reverse.hpp"
#include "header/Game.hpp"

Reverse::Reverse()
{
	type = "REVERSE";
}

// Reverse player's turn RoundRobin
void Reverse::useAbility(Game &game)
{

	if (!this->getStatus())
	{
		cout << "Kartu ini telah dipakai sebelumnya." << endl;
	}
	else
	{
		int cur_turn = game.getTurn();
		string cur_name = game.getPlayerInTurn().getPlayerName();

		vector<Player> current;

		for (int i = cur_turn; i >= 0; i--)
		{
			current.push_back(game.getPlayerInTurn(i));
		}

		for (int i = game.getPlayerCount() - 1; i > cur_turn; i--)
		{
			current.push_back(game.getPlayerInTurn(i));
		}

		cout << cur_name << " melakukan reverse!" << endl;
		cout << "(sisa) urutan eksekusi giliran ini : ";

		for (int i = cur_turn + 2; i < game.getPlayerCount(); i++)
		{
			cout << "<p" << current[i].getPlayerNumber() << "> ";
		}

		cout << endl;
		cout << "urutan giliran eksekusi selanjutnya : ";
		for (int i = 1; i <= (int)current.size() - 1; i++)
		{
			cout << "<p" << current[i].getPlayerNumber() << "> ";
		}
		cout << "<p" << current[0].getPlayerNumber() << "> " << endl;

		game.setPlayerTurn(current);

		status = false;

		game.getPlayerInTurn().doAction(game);
	}
}

void Reverse::printCard()
{
	std::cout << "NAME     \t: " << this->type << std::endl;
	std::cout << "STATUS   \t: " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << std::endl;
	std::cout << "ABILITY  \t: Mengubah urutan permainan" << std::endl;
}
