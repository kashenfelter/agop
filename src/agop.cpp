/* ************************************************************************* *
 *   This file is part of the `agop` library.                                *
 *                                                                           *
 *   Copyright 2013 Marek Gagolewski, Anna Cena                              *                                                                   *
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




#define MAKE_CALL_METHOD(name, args) \
   {#name, (DL_FUNC)&name, args}
   



/**
 * List of functions available in R via .Call()
 * 
 * Form:
 * \code{\{"method_name", (DL_FUNC)pointer, number_of_args\}} - 
 * this is generated by the MAKE_CALL_METHOD macro.
 */
static const R_CallMethodDef cCallMethods[] = {
   
   MAKE_CALL_METHOD(owa,                        2),
   MAKE_CALL_METHOD(wam,                        2),
   MAKE_CALL_METHOD(wmax,                       2),
   MAKE_CALL_METHOD(wmin,                       2),
   MAKE_CALL_METHOD(owmax,                      2),
   MAKE_CALL_METHOD(owmin,                      2),
   MAKE_CALL_METHOD(index_h,                    1),
   MAKE_CALL_METHOD(index_g,                    1),
   MAKE_CALL_METHOD(index_g_zi,                 1),
   MAKE_CALL_METHOD(index_maxprod,              1),
   MAKE_CALL_METHOD(index_w,                    1),
   MAKE_CALL_METHOD(index_rp,                   2),
   MAKE_CALL_METHOD(index_lp,                   2),
   MAKE_CALL_METHOD(d2owa_checkwts,             1),
   MAKE_CALL_METHOD(pord_weakdom,               2),
   MAKE_CALL_METHOD(pord_spread,                2),
   MAKE_CALL_METHOD(pord_spreadsym,             2),
   MAKE_CALL_METHOD(exp_test_statistic,         1),
   
   // the list must be NULL-terminated:
   {NULL,                           NULL,                  0}
};


extern "C" void R_init_agop(DllInfo *dll)
{
	R_registerRoutines(dll, NULL, cCallMethods, NULL, NULL);
   R_useDynamicSymbols(dll, Rboolean(FALSE));
}
