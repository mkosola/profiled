
/*
* This file is part of profile-qt
*
* Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
*
* Contact: Sakari Poussa <sakari.poussa@nokia.com>
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
* in the documentation  and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors may be used to endorse or promote products derived 
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
* BUT NOT LIMITED TO, THE * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
* IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, * INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR * * BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#include "profiled_config.h"

#include <stdlib.h>

#include "xutil.h"
#include "profileval.h"

/* ------------------------------------------------------------------------- *
 * profileval_ctor
 * ------------------------------------------------------------------------- */

void
profileval_ctor(profileval_t *self)
{
  self->pv_key  = 0;
  self->pv_val  = 0;
  self->pv_type = 0;
}

/* ------------------------------------------------------------------------- *
 * profileval_ctor_ex
 * ------------------------------------------------------------------------- */

void
profileval_ctor_ex(profileval_t *self, const char *key, const char *val, const char *type)
{
  profileval_ctor(self);
  xstrset(&self->pv_key,  key);
  xstrset(&self->pv_val,  val);
  xstrset(&self->pv_type, type);
}

/* ------------------------------------------------------------------------- *
 * profileval_dtor
 * ------------------------------------------------------------------------- */

void
profileval_dtor(profileval_t *self)
{
  free(self->pv_key);
  free(self->pv_val);
  free(self->pv_type);
}

/* ------------------------------------------------------------------------- *
 * profileval_free_vector
 * ------------------------------------------------------------------------- */

void
profileval_free_vector(profileval_t *vec)
{
  if( vec != 0 )
  {
    for( size_t i = 0; vec[i].pv_key != 0; ++i )
    {
      profileval_dtor(&vec[i]);
    }
    free(vec);
  }
}
