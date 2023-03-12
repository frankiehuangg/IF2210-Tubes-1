#include "header/Ability_Reverse.hpp"

// Reverse player's turn RoundRobin 
void useAbility(const Game &game)
{
	int cur_player = game.turn;
	string cur_name = game.players[cur_player].getPlayerName();

	vector<Player> current;
	for(int i=0; i<=cur_player; i++)
	{
		current.push_back(game.players[i]);
	}
	for(int i=game.getPlayerCount(); i>cur_player; i--)
	{
		current.push_back(game.players[i]);
	}

	cout<<cur_name<<" melakukan reverse!"<<endl;
	cout<<"(sisa) urutan eksekusi giliran ini : ";

	for(int i=cur_player+1; i<=game.getPlayerCount(); i++)
	{
		cout<<"<p"<<current.players[i].getPlayerNumber()<<"> "
	}

	cout<<endl;
	cout<<"urutan giliran eksekusi selanjutnya : ";
	for(int i = 1; i<=game.getPlayerCount(); i++)
	{
		if(i == cur_player)
		{
			cout<<"<p"<<game.player[0].getPlayerNumber()<<"> ";
		}
		else{
			cout<<"<p"<<game.player[i].getPlayerNumber()<<"> ";
		}
	}
	cout<<"<p"<<game.player[cur_player].getPlayerNumber()<<">"<<endl;

	// change current round's turn
	game.players[i] = current;

	// Case needs to handle changing the round robin method
	// karena dia ada yang ngubah urutan saat di round
	// dan ubah urutan setelah round berakhir

	// It's the player's turn again 
	game.players[cur_player].doAction();
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void printCard()
{
	// tidak bisa cek round, tdk ada passing parameter :(
	// MUNGKIN klo butuh jadi void printCard(const Game&) ?
	// jadi implemennya
	/*
	if(game.round==1){
		cout<<"NOT AVAILABLE"<<endl;
	}
	else{
		cout << "NAME     : Reverse" << endl;
        cout << "STATUS   : " << this->status << endl;
        cout << "ABILITY  : Memutar arah giliran eksekusi perintah oleh pemain." << endl;
	*/
}