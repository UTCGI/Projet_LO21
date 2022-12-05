#ifndef CARTE_MONUMENT_H
#define CARTE_MONUMENT_H
#include "monument.h"
class CarteMonument {
  const Monument* monument;
  bool construit;

 public:
  // Constructors and destructors functions
  CarteMonument(Monument* monument);
  ~CarteMonument() = default;

  CarteMonument(const CarteMonument& c) = delete;
  CarteMonument& operator=(const CarteMonument& c) = delete;

  // Getters
  bool estConstruit() const;

  // Methods
  void construire();
};
#endif
