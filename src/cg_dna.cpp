/*
  Copyright (C) 2010,2011,2012,2013,2014 The ESPResSo project
  Copyright (C) 2002,2003,2004,2005,2006,2007,2008,2009,2010 
    Max-Planck-Institute for Polymer Research, Theory Group
  
  This file is part of ESPResSo.
  
  ESPResSo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  ESPResSo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

#include "cg_dna.hpp"
#include "communication.hpp"

int cg_dna_basepair_set_params(int bond_type, DoubleList *params) {
  if(bond_type < 0)
    return ES_ERROR;

  make_bond_type_exist(bond_type);

  bonded_ia_params[bond_type].p.cg_dna_basepair.r0 = params->e[0];
  bonded_ia_params[bond_type].p.cg_dna_basepair.alpha = params->e[1];
  bonded_ia_params[bond_type].p.cg_dna_basepair.E0 = params->e[2];
  bonded_ia_params[bond_type].p.cg_dna_basepair.kd = params->e[3];
  bonded_ia_params[bond_type].p.cg_dna_basepair.E01 = params->e[4];
  bonded_ia_params[bond_type].p.cg_dna_basepair.E02 = params->e[5];
  bonded_ia_params[bond_type].p.cg_dna_basepair.sigma1 = params->e[6];
  bonded_ia_params[bond_type].p.cg_dna_basepair.sigma2 = params->e[7];
  bonded_ia_params[bond_type].p.cg_dna_basepair.theta01 = params->e[8];
  bonded_ia_params[bond_type].p.cg_dna_basepair.theta02 = params->e[9];

  bonded_ia_params[bond_type].type = BONDED_IA_CG_DNA_BASEPAIR;
  bonded_ia_params[bond_type].num = 3;

  mpi_bcast_ia_params(bond_type, -1);
}