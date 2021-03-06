/* ************************************************************************* *
 *   This file is part of the `agop` library.                                *
 *                                                                           *
 *   Copyright 2013-2014 Marek Gagolewski, Anna Cena                         *
 *                                                                           *
 *   'agop' is free software: you can redistribute it and/or modify          *
 *   it under the terms of the GNU Lesser General Public License             *
 *   as published by the Free Software Foundation, either version 3          *
 *   of the License, or (at your option) any later version.                  *
 *                                                                           *
 *   'agop' is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the             *
 *   GNU Lesser General Public License for more details.                     *
 *                                                                           *
 *   You should have received a copy of the GNU Lesser General Public        *
 *   License along with 'agop'. If not, see <http://www.gnu.org/licenses/>.  *
 * ************************************************************************* */



#include "agop.h"


/** Check if a binary relation is reflexive
 *
 * @param x square logical matrix
 * @return logical scalar
 *
 * @version 0.2 (Marek Gagolewski)
 */
SEXP rel_is_reflexive(SEXP x)
{
   x = prepare_arg_logical_square_matrix(x, "R");
   SEXP dim = Rf_getAttrib(x, R_DimSymbol);
   R_len_t n = INTEGER(dim)[0];
   int* xp = INTEGER(x);
   for (R_len_t i=0; i<n; ++i) {
      if (xp[i+i*n] == NA_LOGICAL)
         return Rf_ScalarLogical(NA_LOGICAL);
      else if (!xp[i+i*n])
         return Rf_ScalarLogical(FALSE);
   }
   return Rf_ScalarLogical(TRUE);
}



/** Get the reflexive closure of a binary relation
 *
 * @param x square logical matrix
 * @return square logical matrix
 *
 * @version 0.2 (Marek Gagolewski)
 */
SEXP rel_closure_reflexive(SEXP x)
{
   x = prepare_arg_logical_square_matrix(x, "R");
   SEXP dim = Rf_getAttrib(x, R_DimSymbol);
   R_len_t n = INTEGER(dim)[0];
   int* xp = INTEGER(x);

   SEXP y = Rf_allocVector(LGLSXP, n*n);
   int* yp = INTEGER(y);
   Rf_setAttrib(y, R_DimSymbol, dim);
   Rf_setAttrib(y, R_DimNamesSymbol, Rf_getAttrib(x, R_DimNamesSymbol)); // preserve dimnames

   for (R_len_t i=0; i<n*n; ++i) {
      yp[i] = xp[i];
   }

   for (R_len_t i=0; i<n; ++i)
      yp[i+n*i] = TRUE;

   return y;
}


/** Get the reflexive reduction of a binary relation
 *
 * @param x square logical matrix
 * @return square logical matrix
 *
 * @version 0.2 (Marek Gagolewski)
 */
SEXP rel_reduction_reflexive(SEXP x)
{
   x = prepare_arg_logical_square_matrix(x, "R");
   SEXP dim = Rf_getAttrib(x, R_DimSymbol);
   R_len_t n = INTEGER(dim)[0];
   int* xp = INTEGER(x);

   SEXP y = Rf_allocVector(LGLSXP, n*n);
   int* yp = INTEGER(y);
   Rf_setAttrib(y, R_DimSymbol, dim);
   Rf_setAttrib(y, R_DimNamesSymbol, Rf_getAttrib(x, R_DimNamesSymbol)); // preserve dimnames

   for (R_len_t i=0; i<n*n; ++i) {
      yp[i] = xp[i];
   }

   for (R_len_t i=0; i<n; ++i)
      yp[i+n*i] = FALSE;

   return y;
}
