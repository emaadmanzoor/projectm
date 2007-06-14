/**
 * projectM -- Milkdrop-esque visualisation SDK
 * Copyright (C)2003-2007 projectM Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * See 'LICENSE.txt' included within this release
 *
 */
/**
 * $Id$
 *
 * Per-frame equation
 *
 * $Log$
 */

#ifndef _PER_FRAME_EQN_H
#define _PER_FRAME_EQN_H

#define PER_FRAME_EQN_DEBUG 0

class GenExpr;
class Param;
class PerFrameEqn;

class PerFrameEqn {
public:
    int index;
    Param *param; /* parameter to be assigned a value */
    GenExpr *gen_expr;   /* expression that paremeter is equal to */
    
    ~PerFrameEqn();
    static PerFrameEqn * new_per_frame_eqn(int index, Param *param, GenExpr * gen_expr);
    void eval_per_frame_eqn();
    void eval_per_frame_init_eqn( PerFrameEqn *per_frame_eqn );
  };

/** Splaytree traversal helpers */
inline void eval_per_frame_eqn_helper( void *per_frame_eqn ) {
    ((PerFrameEqn *)per_frame_eqn)->eval_per_frame_eqn();
  }

inline void free_per_frame_eqn_helper( void *per_frame_eqn ) {
    delete (PerFrameEqn *)per_frame_eqn;
  }

#endif /** !_PER_FRAME_EQN_H */