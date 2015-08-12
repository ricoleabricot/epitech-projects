// Author : zagabe.ed@gmail.com (Eddy Zagabe)
//
// Implementation de la class Param. Cette class permet de configurer
// tous les parametres du jeu. (Equipes, temps de jeu, Mode de jeu...)
// et interagit avec le GameEngine

#ifndef PARAM_HH_
#define PARAM_HH_

#define DEFAULT_TIME (30)
#define MAX_LEVEL (50)
#define DEFAULT_HEIGHT (200)
#define DEFAULT_LENGTH (200)

// Different mode de jeu
enum eMode {
  Aventure = 0,
  Multiplayer,
  Unknown
};

class Param {
 public:
  // Constructeur
  Param();
  Param(eMode mode, int level, int height, int length);
  ~Param();

  // Gerer le temps en seconde
  void setTime(int secondes);
  int time() const;

  // Gerer le niveau
  bool addLevel(int number);
  bool removeLevel(int number);
  int level() const;

  // Gerer les modes (voir enum eMode)
  void changeMode(eMode mode);
  eMode mode() const;

  // Gerer mode equipe
  void setByTeam(bool state);
  bool byTeam() const;

  // Gerer la taille de la map
  void setHeight(int size);
  void setLength(int size);
  int getHeight() const;
  int getLength() const;
  
 private:
  int countdown_;
  int level_;
  eMode mode_;
  bool byTeam_;
  int height_;
  int length_;
};

#endif  // PARAM_HH_
