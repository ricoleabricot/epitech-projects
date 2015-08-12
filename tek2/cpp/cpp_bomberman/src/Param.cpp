// Author : zagabe.ed@gmail.com (Eddy Zagabe)
//
// Implementation de la class Param. Cette class permet de configurer
// tous les parametres du jeu. (Equipes, temps de jeu, Mode de jeu...)
// et interagit avec le GameEngine et le menu.

#include "Param.hh"

// Constructeur par defaut
Param::Param() : countdown_(DEFAULT_TIME), level_(1), mode_(Unknown), byTeam_(false), height_(DEFAULT_HEIGHT), length_(DEFAULT_LENGTH) {}

// Construteur avec le mode, niveau, hauteur et largeur en parametre
Param::Param(eMode mode, int level, int height, int length) : countdown_(DEFAULT_TIME), level_(level), mode_(mode), byTeam_(false), height_(height), length_(length) {}

// Destructeur
Param::~Param() {}

// Definit le temps en seconde
void Param::setTime(int secondes) { countdown_ = secondes; }

// Retourne le nombre de seconde
int Param::time() const { return countdown_; }

// Ajoute un niveau (number) en plus au niveau (level_) courant
bool Param::addLevel(int number) {
  if ((level_ + number) > MAX_LEVEL) return false;
  level_ += number;
  return true;
}

// Enleve un niveau (number) au niveau actuel (level_)
bool Param::removeLevel(int number) {
  if ((level_ - number) < 1) return false;
  level_ -= number;
  return true;
}

// Retourne le niveau actuel du joueur
int Param::level() const { return level_; }

// Definit le mode de jeu (Aventure, multiplayer, ou unknown)
void Param::changeMode(eMode mode) { mode_ = mode; }

// Retourne le  mode de jeu (Voir enum eMode)
eMode Param::mode() const { return mode_; }

// Definit le jeu par equipe ou non
void Param::setByTeam(bool state) { byTeam_ = state; }

// Retourne vrai si le jeu est en equipe
bool Param::byTeam() const { return byTeam_; }

// Definit la hauteur de la map
void Param::setHeight(int size) { height_ = size; }

// Definit la largeur de la map
void Param::setLength(int size) { length_ = size; }

// Retourne la hauteur de la map
int Param::getHeight() const { return height_; }

// Retourne la largeur de la map
int Param::getLength() const { return length_; }
