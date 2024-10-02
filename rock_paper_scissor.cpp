#include <bits/stdc++.h>
using namespace std;

enum Gesture : uint8_t {
  ROCK,
  PAPER,
  SCISSOR,
};

ostream& operator<<(ostream& stream, Gesture gesture) {
  if(gesture == ROCK) stream << "ROCK";
  else if(gesture == PAPER) stream << "PAPER";
  else if(gesture == SCISSOR) stream << "SCISSOR";
  else stream << "WHAT";
  return stream;
}

class Player {
public:
  Player(string name) {
    this->_name = name;
    this->_score = 0;
  }
  string name() {
    return _name;
  }
  void score(int n = 1) {
    this->_score += n;
  }
  int getScore(int n = 1) {
    return this->_score;
  }
  virtual Gesture play() = 0;
private:
  string _name;
  int _score;
};

class InteractivePlayer : public Player {
public:
  InteractivePlayer(string name) : Player(name) {}
  Gesture play() {
    string choice;
    do {
      cout << name() << "?? ";
      cin >> choice;
      if(choice == "rock" || choice == "r") return ROCK;
      if(choice == "paper" || choice == "p") return PAPER;
      if(choice == "scissor" || choice == "s") return SCISSOR;
    } while (true);
  }
};

class RandomPlayer : public Player {
public:
  RandomPlayer(string name) : Player(name) {
    srand(time(0));
  }
  Gesture play() {
     Gesture gesture = (Gesture)(rand() % 3);
     cout << name() << " plays " << gesture << endl;
     return gesture;
  }
};

class Game {
public:
  Player *a, *b;
  Game(Player* a, Player* b) {
    this->a = a;
    this->b = b;
  }
  void round() {
    Gesture aGesture = a->play();
    Gesture bGesture = b->play();
    if((aGesture + 1) % 3 == bGesture) {
      b->score();
      cout << b->name() << " wins" << endl;
    } else if((bGesture + 1) % 3 == aGesture) {
      a->score();
      cout << a->name() << " wins" << endl;
    }
  }
  void play(int n = 3) {
    for(int i = 0; i < n; i++)
      round();
    cout << "---SCOREBOARD---" << endl;
    cout << a->name() << ": " << a->getScore() << endl;
    cout << b->name() << ": " << b->getScore() << endl;
  }
};

int main() {
  Player* you = new InteractivePlayer("you");
  Player* computer = new RandomPlayer("compuer");
  Game game(you, computer);
  game.play();
}
